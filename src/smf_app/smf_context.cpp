/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file smf_context.cpp
  \brief
  \author  Lionel GAUTHIER, Tien-Thinh NGUYEN
  \company Eurecom
  \date 2019
  \email: lionel.gauthier@eurecom.fr, tien-thinh.nguyen@eurecom.fr
 */

#include "itti.hpp"
#include "logger.hpp"
#include "smf_app.hpp"
#include "smf_n11.hpp"
#include "smf_config.hpp"
#include "smf_context.hpp"
#include "smf_paa_dynamic.hpp"
#include "smf_procedure.hpp"
#include "ProblemDetails.h"
#include "3gpp_29.502.h"
#include "3gpp_24.501.h"
#include "SmContextCreatedData.h"
#include <algorithm>
#include "smf_n1_n2.hpp"

extern "C"{
#include "Ngap_PDUSessionResourceSetupResponseTransfer.h"
#include "Ngap_PDUSessionResourceModifyResponseTransfer.h"
#include "Ngap_GTPTunnel.h"
#include "Ngap_AssociatedQosFlowItem.h"
#include "Ngap_QosFlowAddOrModifyResponseList.h"
#include "Ngap_QosFlowAddOrModifyResponseItem.h"
}
using namespace smf;

extern itti_mw *itti_inst;
extern smf::smf_app *smf_app_inst;
extern smf::smf_n11 *smf_n11_inst;
extern smf::smf_config smf_cfg;

//------------------------------------------------------------------------------
void smf_pdu_session::set(const paa_t& paa)
{
  switch (paa.pdn_type.pdn_type) {
  case PDN_TYPE_E_IPV4:
    ipv4 = true;
    ipv6 = false;
    ipv4_address = paa.ipv4_address;
    break;
  case PDN_TYPE_E_IPV6:
    ipv4 = false;
    ipv6 = true;
    ipv6_address = paa.ipv6_address;
    break;
  case PDN_TYPE_E_IPV4V6:
    ipv4 = true;
    ipv6 = true;
    ipv4_address = paa.ipv4_address;
    ipv6_address = paa.ipv6_address;
    break;
  case PDN_TYPE_E_NON_IP:
    ipv4 = false;
    ipv6 = false;
    break;
  default:
    Logger::smf_app().error( "smf_pdu_session::set(paa_t) Unknown PDN type %d", paa.pdn_type.pdn_type);
  }
}


//------------------------------------------------------------------------------
void smf_pdu_session::add_qos_flow(smf_qos_flow& flow)
{
  if ((flow.qfi.qfi >= QOS_FLOW_IDENTIFIER_FIRST) and (flow.qfi.qfi <= QOS_FLOW_IDENTIFIER_LAST)) {
    qos_flows.erase(flow.qfi.qfi);
    qos_flows.insert(std::pair<uint8_t,smf_qos_flow>((uint8_t)flow.qfi.qfi, flow));
    Logger::smf_app().trace( "smf_pdu_session::add_qos_flow(%d) success", flow.qfi.qfi);
  } else {
    Logger::smf_app().error( "smf_pdu_session::add_qos_flow(%d) failed, invalid QFI", flow.qfi.qfi);
  }
}

//------------------------------------------------------------------------------
bool smf_pdu_session::get_qos_flow(const pfcp::pdr_id_t& pdr_id, smf_qos_flow& q) {
  for (auto it : qos_flows) {
    if (it.second.pdr_id_ul.rule_id == pdr_id.rule_id) {
      q = it.second;
      return true;
    }
    if (it.second.pdr_id_dl.rule_id == pdr_id.rule_id) {
      q = it.second;
      return true;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
bool smf_pdu_session::get_qos_flow(const pfcp::far_id_t& far_id, smf_qos_flow& q) {
  for (auto it : qos_flows) {
    if ((it.second.far_id_ul.first) && (it.second.far_id_ul.second.far_id == far_id.far_id)) {
      q = it.second;
      return true;
    }
    if ((it.second.far_id_dl.first) && (it.second.far_id_dl.second.far_id == far_id.far_id)) {
      q = it.second;
      return true;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
bool smf_pdu_session::get_qos_flow(const pfcp::qfi_t& qfi, smf_qos_flow& q) {
  for (auto it : qos_flows) {
    if (it.second.qfi == qfi) {
      q = it.second;
      return true;
    }
  }
  return false;
}


//------------------------------------------------------------------------------
smf_qos_flow& smf_pdu_session::get_qos_flow(const pfcp::qfi_t& qfi)
{
  return qos_flows[qfi.qfi];
}

//------------------------------------------------------------------------------
void smf_pdu_session::get_qos_flows(std::vector<smf_qos_flow>& flows){
  flows.clear();
  for (auto it : qos_flows) {
      flows.push_back(it.second);
    }
}

//------------------------------------------------------------------------------
bool smf_pdu_session::find_qos_flow(const pfcp::pdr_id_t& pdr_id, smf_qos_flow& flow)
{
  for (std::map<uint8_t,smf_qos_flow>::iterator it=qos_flows.begin(); it!=qos_flows.end(); ++it) {
    if ((it->second.pdr_id_ul == pdr_id) || (it->second.pdr_id_dl == pdr_id)) {
      flow = it->second;
      return true;
    }
  }
  return false;
}
//------------------------------------------------------------------------------
bool smf_pdu_session::has_qos_flow(const pfcp::pdr_id_t& pdr_id, pfcp::qfi_t& qfi)
{
  for (std::map<uint8_t,smf_qos_flow>::iterator it=qos_flows.begin(); it!=qos_flows.end(); ++it) {
    if ((it->second.pdr_id_ul == pdr_id) || (it->second.pdr_id_dl == pdr_id)) {
      qfi = it->second.qfi;
      return true;
    }
  }
  return false;
}
//------------------------------------------------------------------------------
void smf_pdu_session::remove_qos_flow(const pfcp::qfi_t& qfi)
{
  smf_qos_flow& flow = qos_flows[qfi.qfi];
  flow.deallocate_ressources();
  qos_flows.erase(qfi.qfi);
}
//------------------------------------------------------------------------------
void smf_pdu_session::remove_qos_flow(smf_qos_flow& flow)
{
  pfcp::qfi_t qfi = {.qfi = flow.qfi.qfi};
  flow.deallocate_ressources();
  qos_flows.erase(qfi.qfi);
}

//------------------------------------------------------------------------------
void smf_pdu_session::deallocate_ressources(const std::string& apn)
{

  for (std::map<uint8_t,smf_qos_flow>::iterator it=qos_flows.begin(); it!=qos_flows.end(); ++it) {
    it->second.deallocate_ressources();
  }
  qos_flows.clear();
  if (ipv4) {
    paa_dynamic::get_instance().release_paa(apn, ipv4_address);
  }
  //smf_app_inst->free_s5s8_cp_fteid(pgw_fteid_s5_s8_cp);
  clear();
}
//------------------------------------------------------------------------------
void smf_pdu_session::generate_seid()
{
  // DO it simple now:
  // seid = pgw_fteid_s5_s8_cp.teid_gre_key | (((uint64_t)smf_cfg.instance) << 32);
}

void smf_pdu_session::set_seid(const uint64_t& s){
  seid = s;
}

//------------------------------------------------------------------------------
// TODO check if prd_id should be uniq in the UPF or in the context of a pdn connection
void smf_pdu_session::generate_far_id(pfcp::far_id_t& far_id)
{
  far_id.far_id = far_id_generator.get_uid();
}
//------------------------------------------------------------------------------
// TODO check if prd_id should be uniq in the UPF or in the context of a pdn connection
void smf_pdu_session::release_far_id(const pfcp::far_id_t& far_id)
{
  far_id_generator.free_uid(far_id.far_id);
}
//------------------------------------------------------------------------------
// TODO check if prd_id should be uniq in the UPF or in the context of a pdn connection
void smf_pdu_session::generate_pdr_id(pfcp::pdr_id_t& pdr_id)
{
  pdr_id.rule_id = pdr_id_generator.get_uid();
}
//------------------------------------------------------------------------------
// TODO check if prd_id should be uniq in the UPF or in the context of a pdn connection
void smf_pdu_session::release_pdr_id(const pfcp::pdr_id_t& pdr_id)
{
  pdr_id_generator.free_uid(pdr_id.rule_id);
}

//------------------------------------------------------------------------------
void smf_pdu_session::generate_qos_rule_id(uint8_t& rule_id)
{
  rule_id = qos_rule_id_generator.get_uid();
}

//------------------------------------------------------------------------------
void smf_pdu_session::release_qos_rule_id(const uint8_t& rule_id)
{
  qos_rule_id_generator.free_uid(rule_id);
}

//------------------------------------------------------------------------------
std::string smf_pdu_session::toString() const
{
  std::string s = {};
  s.append("PDN CONNECTION:\n");
  s.append("\tPDN type:\t\t\t").append(pdn_type.toString()).append("\n");
  if (ipv4)
    s.append("\tPAA IPv4:\t\t\t").append(conv::toString(ipv4_address)).append("\n");
  if (ipv6)
    s.append("\tPAA IPv6:\t\t\t").append(conv::toString(ipv6_address)).append("\n");
  s.append("\tDefault EBI:\t\t\t").append(std::to_string(default_bearer.ebi)).append("\n");
  s.append("\tSEID:\t\t\t").append(std::to_string(seid)).append("\n");

  return s;
}

//------------------------------------------------------------------------------
void smf_pdu_session::set_pdu_session_status (const pdu_session_status_e& status)
{
  pdu_session_status = status;
}
//------------------------------------------------------------------------------
pdu_session_status_e smf_pdu_session::get_pdu_session_status () const
{
  return pdu_session_status;
}

//------------------------------------------------------------------------------
void smf_pdu_session::set_upCnx_state (const upCnx_state_e& state)
{
  upCnx_state = state;
}

//------------------------------------------------------------------------------
upCnx_state_e smf_pdu_session::get_upCnx_state () const
{
  return upCnx_state;
}

//------------------------------------------------------------------------------
void smf_context::insert_procedure(std::shared_ptr<smf_procedure>& sproc)
{
  std::unique_lock<std::recursive_mutex> lock(m_context);
  pending_procedures.push_back(sproc);
}
//------------------------------------------------------------------------------
bool smf_context::find_procedure(const uint64_t& trxn_id, std::shared_ptr<smf_procedure>& proc)
{
  std::unique_lock<std::recursive_mutex> lock(m_context);
  auto found = std::find_if(pending_procedures.begin(), pending_procedures.end(),
      [trxn_id](std::shared_ptr<smf_procedure> const& i) -> bool { return i->trxn_id == trxn_id;});
  if (found != pending_procedures.end()) {
    proc = *found;
    return true;
  }
  return false;
}
//------------------------------------------------------------------------------
void smf_context::remove_procedure(smf_procedure* proc)
{
  std::unique_lock<std::recursive_mutex> lock(m_context);
  auto found = std::find_if(pending_procedures.begin(), pending_procedures.end(), [proc](std::shared_ptr<smf_procedure> const& i) {
    return i.get() == proc;
  });
  if (found != pending_procedures.end()) {
    pending_procedures.erase(found);
  }
}


//------------------------------------------------------------------------------
void smf_context::handle_itti_msg (itti_n4_session_establishment_response& seresp)
{
  std::shared_ptr<smf_procedure> proc = {};
  if (find_procedure(seresp.trxn_id, proc)) {
    Logger::smf_app().debug("Received N4 SESSION ESTABLISHMENT RESPONSE sender teid " TEID_FMT "  pfcp_tx_id %" PRIX64"", seresp.seid, seresp.trxn_id);
    proc->handle_itti_msg(seresp, shared_from_this());
    remove_procedure(proc.get());
  } else {
    Logger::smf_app().debug("Received N4 SESSION ESTABLISHMENT RESPONSE sender teid " TEID_FMT "  pfcp_tx_id %" PRIX64", smf_procedure not found, discarded!", seresp.seid, seresp.trxn_id);
  }
}
//------------------------------------------------------------------------------
void smf_context::handle_itti_msg (itti_n4_session_modification_response& smresp)
{
  std::shared_ptr<smf_procedure> proc = {};
  if (find_procedure(smresp.trxn_id, proc)) {
    Logger::smf_app().debug("Received N4 SESSION MODIFICATION RESPONSE sender teid " TEID_FMT "  pfcp_tx_id %" PRIX64" ", smresp.seid, smresp.trxn_id);
    proc->handle_itti_msg(smresp, shared_from_this());
    remove_procedure(proc.get());
  } else {
    Logger::smf_app().debug("Received N4 SESSION MODIFICATION RESPONSE sender teid " TEID_FMT "  pfcp_tx_id %" PRIX64", smf_procedure not found, discarded!", smresp.seid, smresp.trxn_id);
  }
  Logger::smf_app().info("Handle N4 SESSION MODIFICATION RESPONSE with SMF context %s", toString().c_str());
}
//------------------------------------------------------------------------------
void smf_context::handle_itti_msg (itti_n4_session_deletion_response& sdresp)
{
  std::shared_ptr<smf_procedure> proc = {};
  if (find_procedure(sdresp.trxn_id, proc)) {
    Logger::smf_app().debug("Received N4 SESSION DELETION RESPONSE sender teid " TEID_FMT "  pfcp_tx_id %" PRIX64" ", sdresp.seid, sdresp.trxn_id);
    proc->handle_itti_msg(sdresp, shared_from_this());
    remove_procedure(proc.get());
  } else {
    Logger::smf_app().debug("Received N4 SESSION DELETION RESPONSE sender teid " TEID_FMT "  pfcp_tx_id %" PRIX64", smf_procedure not found, discarded!", sdresp.seid, sdresp.trxn_id);
  }
  std::cout << toString() << std::endl;
}
//------------------------------------------------------------------------------
void smf_context::handle_itti_msg (std::shared_ptr<itti_n4_session_report_request>& req)
{
}

//------------------------------------------------------------------------------
std::string smf_context::toString() const
{
  std::unique_lock<std::recursive_mutex> lock(m_context);
  std::string s = {};
  s.append("SMF CONTEXT:\n");
  s.append("\tIMSI:\t\t\t\t").append(imsi.toString()).append("\n");
  s.append("\tIMSI UNAUTHENTICATED:\t\t").append(std::to_string(imsi_unauthenticated_indicator)).append("\n");
  for (auto it : dnns) {
    s.append(it->toString());
  }
  s.append("\tSUPI:\t\t\t\t").append(smf_supi_to_string(supi)).append("\n");

  //s.append("\tIMSI:\t"+toString(p.msisdn));
  //apns.reserve(MAX_APN_PER_UE);
  return s;
}


//------------------------------------------------------------------------------
void smf_context::get_default_qos(const snssai_t& snssai, const std::string& dnn, subscribed_default_qos_t &default_qos)
{
  Logger::smf_app().info( "get_default_qos, key %d", (uint8_t)snssai.sST);
  //get the default QoS profile
  std::shared_ptr<session_management_subscription> ss = {};
  std::shared_ptr<dnn_configuration_t> sdc = {};
  find_dnn_subscription(snssai, ss);

  if (nullptr != ss.get()){
    ss.get()->find_dnn_configuration(dnn, sdc);
    if (nullptr != sdc.get()){
      default_qos =  sdc.get()->_5g_qos_profile;
    }
  }

}

//------------------------------------------------------------------------------
void smf_context::get_default_qos_rule(QOSRulesIE &qos_rule, uint8_t pdu_session_type)
{
  //TODO, update according to PDU Session type
  Logger::smf_app().info( "Get default QoS rule");
  //see section 9.11.4.13 @ 3GPP TS 24.501 and section 5.7.1.4 @ 3GPP TS 23.501
  qos_rule.qosruleidentifer = 0;
  qos_rule.ruleoperationcode = CREATE_NEW_QOS_RULE;
  qos_rule.dqrbit = THE_QOS_RULE_IS_DEFAULT_QOS_RULE;
  if ((pdu_session_type == PDU_SESSION_TYPE_E_IPV4) or (pdu_session_type == PDU_SESSION_TYPE_E_IPV4V6) or (pdu_session_type == PDU_SESSION_TYPE_E_IPV6) or (pdu_session_type == PDU_SESSION_TYPE_E_ETHERNET)){
    qos_rule.numberofpacketfilters = 1;
    Create_ModifyAndAdd_ModifyAndReplace create_modifyandadd_modifyandreplace[1];
    create_modifyandadd_modifyandreplace[0].packetfilterdirection = 0b11; //bi-directional
    create_modifyandadd_modifyandreplace[0].packetfilteridentifier = 1;
    create_modifyandadd_modifyandreplace[0].packetfiltercontents.component_type = QOS_RULE_MATCHALL_TYPE;
    qos_rule.packetfilterlist.create_modifyandadd_modifyandreplace = (Create_ModifyAndAdd_ModifyAndReplace *)calloc (1, sizeof (Create_ModifyAndAdd_ModifyAndReplace));
    qos_rule.packetfilterlist.create_modifyandadd_modifyandreplace =  create_modifyandadd_modifyandreplace;
    qos_rule.qosruleprecedence = 255;
  }

  if (pdu_session_type == PDU_SESSION_TYPE_E_UNSTRUCTURED){
    qos_rule.numberofpacketfilters = 0;
    qos_rule.qosruleprecedence = 255;
  }

  qos_rule.segregation = SEGREGATION_NOT_REQUESTED;

}


//------------------------------------------------------------------------------
void smf_context::handle_pdu_session_create_sm_context_request (std::shared_ptr<itti_n11_create_sm_context_request> smreq)
{
  Logger::smf_app().info("Handle a PDU Session Create SM Context Request message from AMF");
  pdu_session_create_sm_context_request sm_context_req_msg = smreq->req;
  oai::smf_server::model::SmContextCreateError smContextCreateError;
  oai::smf_server::model::ProblemDetails problem_details;
  std::string n1_sm_message; //N1 SM container
  std::string n1_sm_msg_hex;
  smf_n1_n2 smf_n1_n2_inst;
  bool request_accepted = true;

  //Step 1. get necessary information
  std::string dnn = sm_context_req_msg.get_dnn();
  snssai_t snssai  =  sm_context_req_msg.get_snssai();
  std::string request_type = sm_context_req_msg.get_request_type();
  supi_t supi =  sm_context_req_msg.get_supi();
  supi64_t supi64 = smf_supi_to_u64(supi);
  uint32_t pdu_session_id = sm_context_req_msg.get_pdu_session_id();

  //Step 2. check the validity of the UE request, if valid send PDU Session Accept, otherwise send PDU Session Reject to AMF
  if (!verify_sm_context_request(smreq)){ //TODO: Need to implement this function
    // Not a valid request...
    Logger::smf_app().warn("Received PDU_SESSION_CREATESMCONTEXT_REQUEST, the request is not valid!");
    problem_details.setCause(pdu_session_application_error_e2str[PDU_SESSION_APPLICATION_ERROR_SUBSCRIPTION_DENIED]);
    smContextCreateError.setError(problem_details);

    //PDU Session Establishment Reject
    //TODO: check cause
    smf_n1_n2_inst.create_n1_sm_container(sm_context_req_msg, PDU_SESSION_ESTABLISHMENT_REJECT, n1_sm_message, cause_value_5gsm_e::CAUSE_82_MAXIMUM_DATA_RATE_PER_UE_FOR_USER_PLANE_INTEGRITY_PROTECTION_IS_TOO_LOW);
    smf_n11_inst->send_pdu_session_create_sm_context_response(smreq->http_response, smContextCreateError, Pistache::Http::Code::Forbidden, n1_sm_message);
    //TODO:
    //SMF unsubscribes to the modifications of Session Management Subscription data for (SUPI, DNN, S-NSSAI)
    //using Nudm_SDM_Unsubscribe()
    return;
  }

  //store HttpResponse and session-related information to be used when receiving the response from UPF
  itti_n11_create_sm_context_response *sm_context_resp = new itti_n11_create_sm_context_response(TASK_SMF_APP, TASK_SMF_N11, smreq->http_response);
  std::shared_ptr<itti_n11_create_sm_context_response> sm_context_resp_pending = std::shared_ptr<itti_n11_create_sm_context_response>(sm_context_resp);
  sm_context_resp->res.set_supi(supi);
  sm_context_resp->res.set_supi_prefix(sm_context_req_msg.get_supi_prefix());
  sm_context_resp->res.set_cause(REQUEST_ACCEPTED);
  sm_context_resp->res.set_pdu_session_id(pdu_session_id);
  sm_context_resp->res.set_snssai(snssai);
  sm_context_resp->res.set_dnn(dnn);
  sm_context_resp->set_scid(smreq->scid);

  //Step 3. find pdu_session
  std::shared_ptr<dnn_context> sd;
  bool find_dnn = find_dnn_context (snssai, dnn, sd);

  //step 3.1. create dnn context if not exist
  //At this step, this context should be existed
  if (nullptr == sd.get()) {
    Logger::smf_app().debug("DNN context (dnn_in_use %s) is not existed yet!", dnn.c_str());
    sd = std::shared_ptr<dnn_context> (new dnn_context());
    sd.get()->in_use = true;
    sd.get()->dnn_in_use = dnn;
    sd.get()->nssai = snssai;
    //ambr
    insert_dnn(sd);
  } else {
    sd.get()->dnn_in_use = dnn;
    Logger::smf_app().debug("DNN context (dnn_in_use %s) is already existed", dnn.c_str());
  }

  //step 3.2. create pdn connection if not exist
  std::shared_ptr<smf_pdu_session> sp;
  bool find_pdn = sd.get()->find_pdu_session(pdu_session_id, sp);

  if (nullptr == sp.get()){
    Logger::smf_app().debug("Create a new PDN connection!");
    //create a new pdn connection
    sp = std::shared_ptr<smf_pdu_session>( new smf_pdu_session());
    sp.get()->pdn_type.pdn_type = sm_context_req_msg.get_pdu_session_type();
    sp.get()->pdu_session_id = pdu_session_id; //should check also nas_msg.pdusessionidentity ??
    //amf id
    sp.get()->amf_id = sm_context_req_msg.get_serving_nf_id();
    sd->insert_pdu_session(sp);
  } else{
    Logger::smf_app().debug("PDN connection is already existed!");
    //TODO:
  }

  //pending session??
  //Step 4. check if supi is authenticated

  //TODO: if "Integrity Protection is required", check UE Integrity Protection Maximum Data Rate
  //TODO: (Optional) Secondary authentication/authorization

  //TODO: Step 5. PCF selection
  //TODO: Step 5.1. SM Policy Association Establishment to get default PCC rules for this PDU session from PCF
  //For the moment, SMF uses the local policy (e.g., default QoS rule)

  //address allocation based on PDN type
  //Step 6. paa
  bool set_paa = false;
  paa_t paa = {};

  //Step 6. pco
  //section 6.2.4.2, TS 24.501
  //If the UE wants to use DHCPv4 for IPv4 address assignment, it shall indicate that to the network within the Extended
  //protocol configuration options IE in the PDU SESSION ESTABLISHMENT REQUEST
  //Extended protocol configuration options: See subclause 10.5.6.3A in 3GPP TS 24.008.

  //ExtendedProtocolConfigurationOptions extended_protocol_options = (sm_context_req_msg.get_nas_msg()).extendedprotocolconfigurationoptions;
  //TODO: PCO
  protocol_configuration_options_t pco_resp = {};
  protocol_configuration_options_ids_t pco_ids = {
      .pi_ipcp = 0,
      .ci_dns_server_ipv4_address_request = 0,
      .ci_ip_address_allocation_via_nas_signalling = 0,
      .ci_ipv4_address_allocation_via_dhcpv4 = 0,
      .ci_ipv4_link_mtu_request = 0};

  //smf_app_inst->process_pco_request(extended_protocol_options, pco_resp, pco_ids);

  //Step 7. Address allocation based on PDN type
  switch (sp->pdn_type.pdn_type) {
  case PDN_TYPE_E_IPV4: {
    if (!pco_ids.ci_ipv4_address_allocation_via_dhcpv4) { //use SM NAS signalling
      //use NAS signalling
      //static or dynamic address allocation
      bool paa_res = false; //how to define static or dynamic
      //depend of subscription information: staticIpAddress in DNN Configuration
      //TODO: check static IP address is available in the subscription information (SessionManagementSubscription) or in DHCP/DN-AAA

      std::shared_ptr<session_management_subscription> ss;
      std::shared_ptr<dnn_configuration_t> sdc;
      find_dnn_subscription(snssai, ss);
      if (nullptr != ss.get()){
        ss.get()->find_dnn_configuration(sd->dnn_in_use, sdc);
        if (nullptr != sdc.get()){
          paa.pdn_type.pdn_type = sdc.get()->pdu_session_types.default_session_type.pdu_session_type;
          //TODO: static ip address
        }
      }

      if ((not paa_res) || (not paa.is_ip_assigned())) {
        bool success = paa_dynamic::get_instance().get_free_paa(sd->dnn_in_use, paa);
        if (success) {
          set_paa = true;
        } else {
          //cause: ALL_DYNAMIC_ADDRESSES_ARE_OCCUPIED; //check for 5G?
        }
        // Static IP address allocation
      } else if ((paa_res) && (paa.is_ip_assigned())) {
        set_paa = true;
      }
      Logger::smf_app().info( "PAA, Ipv4 Address: %s", inet_ntoa (*((struct in_addr *)&paa.ipv4_address)));
    } else { //use DHCP
      //TODO: DHCP
    }

  }
  break;

  case PDN_TYPE_E_IPV6: {
    //TODO:
  }
  break;

  case PDN_TYPE_E_IPV4V6: {
    //TODO:
  }
  break;

  default:
    Logger::smf_app().error( "Unknown PDN type %d", sp->pdn_type.pdn_type);
    problem_details.setCause(pdu_session_application_error_e2str[PDU_SESSION_APPLICATION_ERROR_PDUTYPE_DENIED]);
    smContextCreateError.setError(problem_details);
    //PDU Session Establishment Reject
    smf_n1_n2_inst.create_n1_sm_container(sm_context_req_msg, PDU_SESSION_ESTABLISHMENT_REJECT, n1_sm_message, cause_value_5gsm_e::CAUSE_28_UNKNOWN_PDU_SESSION_TYPE);
    smf_n11_inst->send_pdu_session_create_sm_context_response(sm_context_resp->http_response, smContextCreateError, Pistache::Http::Code::Forbidden, n1_sm_message);
    request_accepted = false;
    break;
  }

  //TODO: Step 8. SMF-initiated SM Policy Modification (with PCF)

  //Step 9. Create session establishment procedure and run the procedure
  //if request is accepted
  if (request_accepted){
    if (set_paa) {
      sm_context_resp_pending->res.set_paa(paa); //will be used when procedure is running
      sp->set(paa);
    } else {
      // Valid PAA sent in CSR ?
      //bool paa_res = csreq->gtp_ies.get(paa);
      //if ((paa_res) && ( paa.is_ip_assigned())) {
      //	sp->set(paa);
      //}
    }

    //(step 5 (4.3.2.2.1 TS 23.502)) Send reply to AMF (PDUSession_CreateSMContextResponse including Cause, SMContextId)
    //location header contains the URI of the created resource
    oai::smf_server::model::SmContextCreatedData smContextCreatedData;
    //include only SmfServiceInstanceId (See section 6.1.6.2.3, 3GPP TS 29.502 v16.0.0)
    //Enable to test with tester
    //	std::string smContextRef = sm_context_req_msg.get_supi_prefix() + "-" + smf_supi_to_string(sm_context_req_msg.get_supi());
    std::string smContextRef = std::to_string(smreq->scid);
    //headers: Location: contains the URI of the newly created resource, according to the structure: {apiRoot}/nsmf-pdusession/{apiVersion}/sm-contexts/{smContextRef}
    std::string uri = sm_context_req_msg.get_api_root() + "/" + smContextRef.c_str();
    sm_context_resp->http_response.headers().add<Pistache::Http::Header::Location>(uri);
    smf_n11_inst->send_pdu_session_create_sm_context_response(sm_context_resp->http_response, smContextCreatedData, Pistache::Http::Code::Created);

    //TODO: PDU Session authentication/authorization (Optional)
    //see section 4.3.2.3@3GPP TS 23.502 and section 6.3.1@3GPP TS 24.501

    Logger::smf_app().info( "Create a procedure to process this message!");
    session_create_sm_context_procedure* proc = new session_create_sm_context_procedure(sp);
    std::shared_ptr<smf_procedure> sproc = std::shared_ptr<smf_procedure>(proc);

    insert_procedure(sproc);
    if (proc->run(smreq, sm_context_resp_pending, shared_from_this())) {
      // error !
      Logger::smf_app().info( "PDU SESSION CREATE SM CONTEXT REQUEST procedure failed");
      remove_procedure(proc);
      //Set cause to error to trigger PDU session establishment reject (step 9)
      sm_context_resp->res.set_cause(UNKNOWN_ERROR);
    }

  }else{ //if request is rejected
    //TODO:
    //un-subscribe to the modifications of Session Management Subscription data for (SUPI, DNN, S-NSSAI)
  }

  //step 10. if error when establishing the pdu session,
  //send ITTI message to APP to trigger N1N2MessageTransfer towards AMFs (PDU Session Establishment Reject)
  if (sm_context_resp->res.get_cause() != REQUEST_ACCEPTED) {
    //clear pco, ambr
    //TODO:
    //free paa
    paa_t free_paa = {};
    free_paa = sm_context_resp->res.get_paa();
    if (free_paa.is_ip_assigned()){
      switch (sp->pdn_type.pdn_type) {
      case PDN_TYPE_E_IPV4:
      case PDN_TYPE_E_IPV4V6:
        paa_dynamic::get_instance().release_paa (sd->dnn_in_use, free_paa.ipv4_address);
        break;

      case PDN_TYPE_E_IPV6:
      case PDN_TYPE_E_NON_IP:
      default:;
      }
      //sm_context_resp->res.clear_paa(); //TODO:
    }
    //clear the created context??
    //TODO:

    /*
		for (auto it : sm_context_resp->res.bearer_contexts_to_be_created) {
			gtpv2c::bearer_context_created_within_create_session_response bcc = {};
			cause_t bcc_cause = {.cause_value = NO_RESOURCES_AVAILABLE, .pce = 0, .bce = 0, .cs = 0};
			bcc.set(it.eps_bearer_id);
			bcc.set(bcc_cause);
			//sm_context_resp->res.add_bearer_context_created(bcc);
		}
     */

    //Create PDU Session Establishment Reject
    smf_n1_n2 smf_n1_n2_inst;
    std::string n1_sm_msg,n1_sm_msg_hex;
    Logger::smf_app().debug("Create PDU Session Establishment Reject");
    smf_n1_n2_inst.create_n1_sm_container(sm_context_resp_pending->res, PDU_SESSION_ESTABLISHMENT_REJECT, n1_sm_msg, cause_value_5gsm_e::CAUSE_26_INSUFFICIENT_RESOURCES);
    smf_app_inst->convert_string_2_hex(n1_sm_msg, n1_sm_msg_hex);
    sm_context_resp_pending->res.set_n1_sm_message(n1_sm_msg_hex);

    //get supi and put into URL
    std::string supi_str;
    supi_t supi = sm_context_resp_pending->res.get_supi();
    supi_str = sm_context_resp_pending->res.get_supi_prefix() + "-" + smf_supi_to_string (supi);
    std::string url = std::string(inet_ntoa (*((struct in_addr *)&smf_cfg.amf_addr.ipv4_addr)))  + ":" + std::to_string(smf_cfg.amf_addr.port) + "/namf-comm/v2/ue-contexts/" + supi_str.c_str() +"/n1-n2-messages";
    sm_context_resp_pending->res.set_amf_url(url);

    //Fill the json part
    sm_context_resp_pending->res.n1n2_message_transfer_data["n1MessageContainer"]["n1MessageClass"] = "SM";
    sm_context_resp_pending->res.n1n2_message_transfer_data["n1MessageContainer"]["n1MessageContent"]["contentId"] = "n1SmMsg";
    //sm_context_resp_pending->res.n1n2_message_transfer_data["ppi"] = 1; //Don't need this info for the moment
    sm_context_resp_pending->res.n1n2_message_transfer_data["pduSessionId"] = sm_context_resp_pending->res.get_pdu_session_id();
    //sm_context_resp_pending->res.n1n2_message_transfer_data["arp"]["priorityLevel"] = 1;
    //sm_context_resp_pending->res.n1n2_message_transfer_data["arp"]["preemptCap"] = "NOT_PREEMPT";
    //sm_context_resp_pending->res.n1n2_message_transfer_data["arp"]["preemptVuln"] = "NOT_PREEMPTABLE";
    //sm_context_resp_pending->res.n1n2_message_transfer_data["5qi"] = ;

    //send ITTI message to N11 interface to trigger N1N2MessageTransfer towards AMFs
    Logger::smf_app().info( "Sending ITTI message %s to task TASK_SMF_N11", sm_context_resp_pending->get_msg_name());
    int ret = itti_inst->send_msg(sm_context_resp_pending);
    if (RETURNok != ret) {
      Logger::smf_app().error( "Could not send ITTI message %s to task TASK_SMF_N11",  sm_context_resp_pending->get_msg_name());
    }
  }

}

//-------------------------------------------------------------------------------------
void smf_context::handle_pdu_session_update_sm_context_request (std::shared_ptr<itti_n11_update_sm_context_request> smreq)
{

  Logger::smf_app().info("Handle a PDU Session Update SM Context Request message from AMF");
  pdu_session_update_sm_context_request sm_context_req_msg = smreq->req;
  smf_n1_n2 smf_n1_n2_inst;
  oai::smf_server::model::SmContextUpdateError smContextUpdateError;
  oai::smf_server::model::ProblemDetails problem_details;
  bool update_upf = false;
  session_management_procedures_type_e procedure_type (session_management_procedures_type_e::PDU_SESSION_ESTABLISHMENT_UE_REQUESTED);

  //Step 1. get DNN, SMF PDU session context. At this stage, dnn_context and pdu_session must be existed
  std::shared_ptr<dnn_context> sd;
  std::shared_ptr<smf_pdu_session> sp;
  bool find_dnn = find_dnn_context (sm_context_req_msg.get_snssai(), sm_context_req_msg.get_dnn(), sd);
  bool find_pdn = false;
  if (find_dnn){
    find_pdn = sd.get()->find_pdu_session(sm_context_req_msg.get_pdu_session_id(), sp);
  }
  if (!find_dnn or !find_pdn){
    //error, send reply to AMF with error code "Context Not Found"
    Logger::smf_app().warn("DNN or PDU session context does not exist!");
    problem_details.setCause(pdu_session_application_error_e2str[PDU_SESSION_APPLICATION_ERROR_CONTEXT_NOT_FOUND]);
    smContextUpdateError.setError(problem_details);
    smf_n11_inst->send_pdu_session_update_sm_context_response(smreq->http_response, smContextUpdateError, Pistache::Http::Code::Not_Found);
    return;
  }

  //we need to store HttpResponse and session-related information to be used when receiving the response from UPF
  itti_n11_update_sm_context_response *n1_sm_context_resp = new itti_n11_update_sm_context_response(TASK_SMF_APP, TASK_SMF_N11, smreq->http_response);
  std::shared_ptr<itti_n11_update_sm_context_response> sm_context_resp_pending = std::shared_ptr<itti_n11_update_sm_context_response>(n1_sm_context_resp);

  n1_sm_context_resp->res.set_supi(sm_context_req_msg.get_supi());
  n1_sm_context_resp->res.set_supi_prefix(sm_context_req_msg.get_supi_prefix());
  n1_sm_context_resp->res.set_cause(REQUEST_ACCEPTED);
  n1_sm_context_resp->res.set_pdu_session_id(sm_context_req_msg.get_pdu_session_id());
  n1_sm_context_resp->res.set_snssai(sm_context_req_msg.get_snssai());
  n1_sm_context_resp->res.set_dnn(sm_context_req_msg.get_dnn());


  //Step 2.1. Decode N1 (if content is available)
  if (sm_context_req_msg.n1_sm_msg_is_set()){
    std::string n1_sm_msg; //N1 SM container
    std::string n1_sm_msg_hex; //N1 SM container
    nas_message_t decoded_nas_msg;

    //Decode NAS and get the necessary information
    n1_sm_msg = sm_context_req_msg.get_n1_sm_message();
    memset (&decoded_nas_msg, 0, sizeof (nas_message_t));

    int decoder_rc = smf_n1_n2_inst.decode_n1_sm_container(decoded_nas_msg, n1_sm_msg);
    if (decoder_rc != RETURNok) {
      //error, should send reply to AMF with error code!!
      Logger::smf_app().warn("N1 SM container cannot be decoded correctly!");
      problem_details.setCause(pdu_session_application_error_e2str[PDU_SESSION_APPLICATION_ERROR_N1_SM_ERROR]);
      smContextUpdateError.setError(problem_details);
      //PDU Session Establishment Reject
      //24.501: response with a 5GSM STATUS message including cause "#95 Semantically incorrect message"
      smf_n1_n2_inst.create_n1_sm_container(sm_context_req_msg, PDU_SESSION_ESTABLISHMENT_REJECT, n1_sm_msg, cause_value_5gsm_e::CAUSE_95_SEMANTICALLY_INCORRECT_MESSAGE); //TODO: should define 5GSM cause in 24.501
      //Send response to AMF
      smf_n11_inst->send_pdu_session_update_sm_context_response(smreq->http_response, smContextUpdateError, Pistache::Http::Code::Forbidden, n1_sm_msg);
    }

    Logger::smf_app().debug("NAS header information, extended_protocol_discriminator %d, security_header_type:%d",
        decoded_nas_msg.header.extended_protocol_discriminator,
        decoded_nas_msg.header.security_header_type);

    Logger::smf_app().debug("NAS header information, Message Type %d", decoded_nas_msg.plain.sm.header.message_type);


    //FOR TESTing  PDU_SESSION_MODIFICATION_REQUEST, should be REMOVED!!!
    uint8_t message_type = PDU_SESSION_MODIFICATION_REQUEST;
    //end
    switch (message_type){
    // switch (decoded_nas_msg.plain.sm.header.message_type){

    //PDU_SESSION_MODIFICATION_REQUEST - UE initiated PDU session modification request
    case PDU_SESSION_MODIFICATION_REQUEST:{
      Logger::smf_app().debug("PDU_SESSION_MODIFICATION_REQUEST");
      //PDU Session Modification procedure (UE-initiated, step 1.a, Section 4.3.3.2@3GPP TS 23.502)
      procedure_type = session_management_procedures_type_e::PDU_SESSION_MODIFICATION_UE_INITIATED;
      sm_context_resp_pending->session_procedure_type = session_management_procedures_type_e::PDU_SESSION_MODIFICATION_UE_INITIATED;

      //step 1. assign the necessary information from pdu_session_modification_request to sm_context_req_msg to be used to create N1 SM, N2 SM information
      //decoded_nas_msg.plain.sm.pdu_session_modification_request;
      //needs the following IEs
      // PTI,
      /* ExtendedProtocolDiscriminator extendedprotocoldiscriminator;
      PDUSessionIdentity pdusessionidentity;
      ProcedureTransactionIdentity proceduretransactionidentity;
      MessageType messagetype;

      uint16_t presence;
      _5GSMCapability _5gsmcapability;
      _5GSMCause _5gsmcause;
      MaximumNumberOfSupportedPacketFilters maximumnumberofsupportedpacketfilters;
      AlwaysonPDUSessionRequested alwaysonpdusessionrequested;
      IntergrityProtectionMaximumDataRate intergrityprotectionmaximumdatarate;
      QOSRules qosrules;
      QOSFlowDescriptions qosflowdescriptions;
      MappedEPSBearerContexts mappedepsbearercontexts;
      ExtendedProtocolConfigurationOptions extendedprotocolconfigurationoptions;
       */

      //See section 6.4.2 - UE-requested PDU Session modification procedure@ 3GPP TS 24.501
      //PTI
      Logger::smf_app().info("PTI %d", decoded_nas_msg.plain.sm.header.procedure_transaction_identity);
      procedure_transaction_id_t pti = {.procedure_transaction_id = decoded_nas_msg.plain.sm.header.procedure_transaction_identity};
      n1_sm_context_resp->res.set_pti(pti);

      //TODO: _5GSMCapability _5gsmcapability = decoded_nas_msg.plain.sm.pdu_session_modification_request._5gsmcapability;
      //
      //TODO: Cause
      //TODO: uint8_t maximum_number_of_supported_packet_filters = decoded_nas_msg.plain.sm.pdu_session_modification_request.maximumnumberofsupportedpacketfilters;
      //sp.get()->set_number_of_supported_packet_filters(maximum_number_of_supported_packet_filters);

      //TODO: AlwaysonPDUSessionRequested
      //TODO: IntergrityProtectionMaximumDataRate intergrityprotectionmaximumdatarate;

      //TODO: process QoS rules and Qos Flow descriptions
      uint8_t number_of_rules = decoded_nas_msg.plain.sm.pdu_session_modification_request.qosrules.lengthofqosrulesie;
      QOSRulesIE * qos_rules_ie = (QOSRulesIE *) calloc (1, sizeof(QOSRulesIE));
      qos_rules_ie = decoded_nas_msg.plain.sm.pdu_session_modification_request.qosrules.qosrulesie;
      for (int i = 0; i < number_of_rules; i++){
          //qos_rules_ie[0].qosruleidentifer
        if ((qos_rules_ie[i].ruleoperationcode == CREATE_NEW_QOS_RULE) and (qos_rules_ie[i].segregation == SEGREGATION_REQUESTED)){
          //Request to bind specific SDF to a dedicated QoS flow
          if (qos_rules_ie[i].qosruleidentifer == 0) {
            //new QoS rule
          } else{
            //existing QoS rule
          }
        }
          //qos_rules_ie[0].ruleoperationcode
          //qos_rules_ie[0].dqrbit
          //qos_rules_ie[0].numberofpacketfilters
          //1st rule
          // qos_rules_ie[0].packetfilterlist.create_modifyandadd_modifyandreplace->packetfilterdirection
          // qos_rules_ie[0].packetfilterlist.create_modifyandadd_modifyandreplace->packetfilteridentifier
          // qos_rules_ie[0].packetfilterlist.create_modifyandadd_modifyandreplace->packetfiltercontents.component_type
          // qos_rules_ie[0].qosruleprecedence ;
          // qos_rules_ie[0].segregation ;
          // qos_rules_ie[0].qosflowidentifer ;
      }

      /*
       typedef struct{
  uint8_t uint;
  uint16_t value;
}GFBROrMFBR_UpLinkOrDownLink;

typedef struct{
  uint8_t uplinkinmilliseconds;
  uint8_t downlinkinmilliseconds;
}AveragingWindow;

typedef struct{
  uint8_t parameteridentifier;
  //uint8_t lengthofparametercontents;
  union {
    uint8_t _5qi;
    GFBROrMFBR_UpLinkOrDownLink gfbrormfbr_uplinkordownlink;
    AveragingWindow averagingwindow;
    uint8_t epsbeareridentity:4;
  }parametercontents;
}ParametersList;

typedef struct{
  uint8_t qfi:6;
  uint8_t operationcode:3;
  uint8_t e:1;
  uint8_t numberofparameters:6;
  ParametersList *parameterslist;
}QOSFlowDescriptionsContents;

typedef struct{
  uint16_t qosflowdescriptionsnumber;   //Custom variables are protocol independent
  QOSFlowDescriptionsContents *qosflowdescriptionscontents;
}QOSFlowDescriptions;


       */

      //verify the PDU session ID
      if (smreq->req.get_pdu_session_id() != decoded_nas_msg.plain.sm.pdu_session_modification_request.pdusessionidentity){
        //TODO: error
      }

      //section 6.3.2. Network-requested PDU Session modification procedure @ 3GPP TS 24.501
      //requested QoS rules (including packet filters) and/or requested QoS flow descriptions
      //session-AMBR, session TMBR
      // PTI
      //or UE capability


      //Create a N1 SM (PDU Session Modification Command) and N2 SM (PDU Session Resource Modify Request Transfer IE)
      std::string n1_sm_msg_to_be_created, n1_sm_msg_hex_to_be_created;
      std::string n2_sm_info_to_be_created, n2_sm_info_hex_to_be_created;
      //N1 SM (PDU Session Modification Command)
      smf_n1_n2_inst.create_n1_sm_container(n1_sm_context_resp->res, PDU_SESSION_MODIFICATION_COMMAND, n1_sm_msg_to_be_created, cause_value_5gsm_e::CAUSE_0_UNKNOWN); //TODO: need cause?
      //N2 SM (PDU Session Resource Modify Request Transfer IE)
      smf_n1_n2_inst.create_n2_sm_information(n1_sm_context_resp->res, 1, n2_sm_info_type_e::PDU_RES_MOD_REQ, n2_sm_info_to_be_created);
      smf_app_inst->convert_string_2_hex(n1_sm_msg_to_be_created, n1_sm_msg_hex_to_be_created);
      smf_app_inst->convert_string_2_hex(n2_sm_info_to_be_created, n2_sm_info_hex_to_be_created);

      n1_sm_context_resp->res.set_n1_sm_message(n1_sm_msg_hex_to_be_created);
      n1_sm_context_resp->res.set_n1_sm_msg_type("PDU_SESSION_MODIFICATION_COMMAND");
      n1_sm_context_resp->res.set_n2_sm_information(n2_sm_info_hex_to_be_created);
      n1_sm_context_resp->res.set_n2_sm_info_type("PDU_RES_MOD_REQ");

      //Fill the json part
      //N1SM
      n1_sm_context_resp->res.sm_context_updated_data["n1SmMsg"]["n1MessageClass"] = "SM";
      n1_sm_context_resp->res.sm_context_updated_data["n1SmMsg"]["n1MessageContent"]["contentId"] = "n1SmMsg"; //part 2
      n1_sm_context_resp->res.sm_context_updated_data["n2SmInfo"]["n2InformationClass"] = "SM";
      n1_sm_context_resp->res.sm_context_updated_data["n2SmInfo"]["n2InfoContent"]["ngapIeType"] = "PDU_RES_MOD_REQ"; //NGAP message
      n1_sm_context_resp->res.sm_context_updated_data["n2SmInfo"]["n2InfoContent"]["ngapData"]["contentId"] = "n2SmMsg"; //part 3

      //Store pdu_session_modification_request in itti_n11_update_sm_context_response
      Logger::smf_app().info( "Sending ITTI message %s to task TASK_SMF_N11", sm_context_resp_pending->get_msg_name());

      //Update PDU Session status
      sp.get()->set_pdu_session_status(pdu_session_status_e::PDU_SESSION_MODIFICATION_PENDING);
      //start timer T3591
      //get smf_pdu_session and set the corresponding timer
      sp.get()->timer_T3591 = itti_inst->timer_setup(T3591_TIMER_VALUE_SEC, 0, TASK_SMF_APP, TASK_SMF_APP_TRIGGER_T3591, sm_context_req_msg.get_pdu_session_id());

      int ret = itti_inst->send_msg(sm_context_resp_pending);
      if (RETURNok != ret) {
        Logger::smf_app().error( "Could not send ITTI message %s to task TASK_SMF_N11",  sm_context_resp_pending->get_msg_name());
      }
      //don't need to create a procedure to update UPF
      break;
    }

    //PDU_SESSION_MODIFICATION_COMPLETE - PDU Session Modification procedure

    case PDU_SESSION_MODIFICATION_COMPLETE:{
      //PDU Session Modification procedure (Section 4.3.3.2@3GPP TS 23.502)
      //TODO: should be verified since mentioned PDU_SESSION_MODIFICATION_COMMAND ACK in spec (see Step 11, section 4.3.3.2@3GPP TS 23.502)
      //send response

      /* see section 6.3.2.3@3GPP TS 24.501 V16.1.0
       Upon receipt of a PDU SESSION MODIFICATION COMPLETE message, the SMF shall stop timer T3591 and shall
       consider the PDU session as modified. If the selected SSC mode of the PDU session is "SSC mode 3" and the PDU
       SESSION MODIFICATION COMMAND message included 5GSM cause #39 "reactivation requested", the SMF shall
       start timer T3593. If the PDU Session Address Lifetime value is sent to the UE in the PDU SESSION
       MODIFICATION COMMAND message then timer T3593 shall be started with the same value, otherwise it shall use a
       default value.
       */
      //Update PDU Session status -> ACTIVE
      sp.get()->set_pdu_session_status(pdu_session_status_e::PDU_SESSION_ACTIVE);
      //stop T3591
      itti_inst->timer_remove(sp.get()->timer_T3591);


      break;
    }

    case PDU_SESSION_RELEASE_REQUEST:{
      //PDU Session Release procedure (Section 4.3.4@3GPP TS 23.502)
      //TODO:


      break;
    }

    case PDU_SESSION_RELEASE_COMMAND:{
      //PDU Session Release procedure (Section 4.3.4@3GPP TS 23.502)
      //TODO:

      break;
    }



    default: {

      //Message Type Unknown
    }
    }


  }


  //Step 2.2. Decode N2 (if content is available)
  if (sm_context_req_msg.n2_sm_info_is_set()){

    //get necessary information (N2 SM information)
    std::string n2_sm_info_type_str = smreq->req.get_n2_sm_info_type();
    std::string n2_sm_information = smreq->req.get_n2_sm_information();
    n2_sm_info_type_e n2_sm_info_type = smf_app_inst->n2_sm_info_type_str2e(n2_sm_info_type_str);

    unsigned int data_len = n2_sm_information.length();
    unsigned char *data = (unsigned char *)malloc(data_len + 1);
    memset(data, 0, data_len + 1);
    memcpy ((void *)data, (void *)n2_sm_information.c_str(), data_len);

    //decode N2 SM Info
    switch (n2_sm_info_type){

    //UE-Requested PDU Session Establishment procedure (Section 4.3.2.2.1@3GPP TS 23.502)
    //or UE Triggered Service Request Procedure (step 2)
    case n2_sm_info_type_e::PDU_RES_SETUP_RSP:{
      Logger::smf_app().info("PDU Session Establishment Request, processing N2 SM Information");
      //Ngap_PDUSessionResourceSetupResponseTransfer_t
      //  Ngap_QosFlowPerTNLInformation_t  qosFlowPerTNLInformation;
      //  struct Ngap_QosFlowPerTNLInformation  *additionalQosFlowPerTNLInformation;  /* OPTIONAL */
      //  struct Ngap_SecurityResult  *securityResult;  /* OPTIONAL */
      //  struct Ngap_QosFlowList *qosFlowFailedToSetupList;  /* OPTIONAL */
      //  struct Ngap_ProtocolExtensionContainer  *iE_Extensions; /* OPTIONAL */

      //TEST - enable to create a N2 SM information and send to AMF
      /* std::string n2_sm_info, n2_sm_info_hex ;
      smf_n1_n2 smf_n1_n2_inst;
      //N1 SM (PDU Session Modification Command)
      smf_n1_n2_inst.create_n2_sm_information(sm_context_req_msg, 1, n2_sm_info_type_e::PDU_RES_SETUP_RSP, n2_sm_info);
       */

      //PDU_SESSION_ESTABLISHMENT_UE_REQUESTED & SERVICE_REQUEST_UE_TRIGGERED
      procedure_type = session_management_procedures_type_e::SERVICE_REQUEST_UE_TRIGGERED;

      //Ngap_PDUSessionResourceSetupResponseTransfer
      std::shared_ptr<Ngap_PDUSessionResourceSetupResponseTransfer_t>  decoded_msg = std::make_shared<Ngap_PDUSessionResourceSetupResponseTransfer_t>();
      asn_dec_rval_t rc  = asn_decode(nullptr,ATS_ALIGNED_CANONICAL_PER, &asn_DEF_Ngap_PDUSessionResourceSetupResponseTransfer, (void **)&decoded_msg, (void *)data, data_len);
      if(rc.code != RC_OK)
      {
        Logger::smf_api_server().warn("asn_decode failed with code %d",rc.code );
        //TODO: send error to AMF??
      }

      //TODO: store AN Tunnel Info + list of accepted QFIs
      fteid_t dl_teid;
      //TODO: to be verified which one is teid_gre_key, ipv4_address
      memcpy (&dl_teid.teid_gre_key, decoded_msg->qosFlowPerTNLInformation.uPTransportLayerInformation.choice.gTPTunnel->gTP_TEID.buf, sizeof (struct in_addr));
      memcpy (&dl_teid.ipv4_address, decoded_msg->qosFlowPerTNLInformation.uPTransportLayerInformation.choice.gTPTunnel->transportLayerAddress.buf, 4);
      printf("\ngTP_TEID:");
      printf("%02x ", decoded_msg->qosFlowPerTNLInformation.uPTransportLayerInformation.choice.gTPTunnel->gTP_TEID.buf[0]);
      printf("%02x ", decoded_msg->qosFlowPerTNLInformation.uPTransportLayerInformation.choice.gTPTunnel->gTP_TEID.buf[1]);
      printf("%02x ", decoded_msg->qosFlowPerTNLInformation.uPTransportLayerInformation.choice.gTPTunnel->gTP_TEID.buf[2]);
      printf("%02x ", decoded_msg->qosFlowPerTNLInformation.uPTransportLayerInformation.choice.gTPTunnel->gTP_TEID.buf[3]);
      Logger::smf_app().debug("gTP_TEID " "0x%" PRIx32 " ", htonl(dl_teid.teid_gre_key));
      Logger::smf_app().debug("uPTransportLayerInformation IP Addr %s", conv::toString(dl_teid.ipv4_address).c_str());

      sm_context_req_msg.set_dl_fteid(dl_teid);

      for (int i =0; i< decoded_msg->qosFlowPerTNLInformation.associatedQosFlowList.list.count; i++ ){
        pfcp::qfi_t qfi((uint8_t)(decoded_msg->qosFlowPerTNLInformation.associatedQosFlowList.list.array[i])->qosFlowIdentifier);
        sm_context_req_msg.add_qfi(qfi);
        Logger::smf_app().debug("associatedQosFlowList %d",(decoded_msg->qosFlowPerTNLInformation.associatedQosFlowList.list.array[i])->qosFlowIdentifier );
      }
      //need to update UPF accordingly
      update_upf = true;

      break;
    }

    //PDU Session Modification procedure (UE-initiated, Section 4.3.3.2@3GPP TS 23.502)
    case n2_sm_info_type_e::PDU_RES_MOD_RSP:{
      procedure_type = session_management_procedures_type_e::PDU_SESSION_MODIFICATION_UE_INITIATED;
      //PDU Session Resource Modify Request Transfer

      //Ngap_PDUSessionResourceModifyResponseTransfer
      std::shared_ptr<Ngap_PDUSessionResourceModifyResponseTransfer_t>  decoded_msg = std::make_shared<Ngap_PDUSessionResourceModifyResponseTransfer_t>();
      asn_dec_rval_t rc  = asn_decode(nullptr,ATS_ALIGNED_CANONICAL_PER, &asn_DEF_Ngap_PDUSessionResourceModifyResponseTransfer, (void **)&decoded_msg, (void *)data, data_len);
      if(rc.code != RC_OK)
      {
        Logger::smf_api_server().warn("asn_decode failed %d...",rc.code );
        //TODO: send error to AMF??
      }

      //Ngap_PDUSessionResourceModifyResponseTransfer_t
      // struct Ngap_UPTransportLayerInformation *dL_NGU_UP_TNLInformation;  /* OPTIONAL */
      // struct Ngap_UPTransportLayerInformation *uL_NGU_UP_TNLInformation;  /* OPTIONAL */
      // struct Ngap_QosFlowAddOrModifyResponseList  *qosFlowAddOrModifyResponseList;  /* OPTIONAL */
      // struct Ngap_QosFlowPerTNLInformation  *additionalQosFlowPerTNLInformation;  /* OPTIONAL */
      // struct Ngap_QosFlowList *qosFlowFailedToAddOrModifyList;  /* OPTIONAL */
      //struct Ngap_ProtocolExtensionContainer  *iE_Extensions; /* OPTIONAL */

      //if dL_NGU_UP_TNLInformation is included, it shall be considered as the new DL transfort layer addr for the PDU session (should be verified)
      fteid_t dl_teid;
      memcpy (&dl_teid.ipv4_address, decoded_msg->dL_NGU_UP_TNLInformation->choice.gTPTunnel->gTP_TEID.buf, sizeof (struct in_addr));
      memcpy (&dl_teid.teid_gre_key, decoded_msg->dL_NGU_UP_TNLInformation->choice.gTPTunnel->transportLayerAddress.buf, 4);
      sm_context_req_msg.set_dl_fteid(dl_teid);
      //list of Qos Flows which have been successfully setup or modified
      for (int i =0; i< decoded_msg->qosFlowAddOrModifyResponseList->list.count; i++ ){
        sm_context_req_msg.add_qfi((decoded_msg->qosFlowAddOrModifyResponseList->list.array[i])->qosFlowIdentifier);
      }
      //TODO:
      //list of QoS Flows which have failed to be modified
      //qosFlowFailedToAddOrModifyList

      //need to update UPF accordingly
      update_upf = true;

      break;
    }

    //PDU Session Modification procedure
    case n2_sm_info_type_e::PDU_RES_MOD_FAIL:{

    }
    break;
    default: {

    }

    }
    //free memory
    free(data);
    data = nullptr;
  }

  //Step 3. For Service Request
  if (!sm_context_req_msg.n1_sm_msg_is_set() and !sm_context_req_msg.n2_sm_info_is_set() and  sm_context_req_msg.upCnx_state_is_set()){
    procedure_type = session_management_procedures_type_e::SERVICE_REQUEST_UE_TRIGGERED;
    //if request accepted-> set unCnxState to ACTIVATING
    //Update upCnxState
    sp.get()->set_upCnx_state(upCnx_state_e::UPCNX_STATE_ACTIVATING);
    //need update UPF
    update_upf = true;

    //get QFIs associated with PDU session ID
    std::vector<smf_qos_flow> qos_flows = {};
    sp.get()->get_qos_flows(qos_flows);
    for (auto i: qos_flows){
      sm_context_req_msg.add_qfi(i.qfi.qfi);
    }
    //TODO: to be completed

  }

  //Step 4. Create a procedure for update sm context and let the procedure handle the request if necessary
  if (update_upf){
    //TODO:
    session_update_sm_context_procedure* proc = new session_update_sm_context_procedure(sp);
    std::shared_ptr<smf_procedure> sproc = std::shared_ptr<smf_procedure>(proc);
    proc->session_procedure_type = procedure_type;

    smreq->req = sm_context_req_msg;
    insert_procedure(sproc);
    if (proc->run(smreq, sm_context_resp_pending, shared_from_this())) {
      // error !
      Logger::smf_app().info( "PDU SESSION CREATE SM CONTEXT REQUEST procedure failed");
      remove_procedure(proc);
    }
  }

  //TODO, Step 5.
  /*  If the PDU Session establishment is not successful, the SMF informs the AMF by invoking Nsmf_PDUSession_SMContextStatusNotify (Release). The SMF also releases any N4
  session(s) created, any PDU Session address if allocated (e.g. IP address) and releases the association with PCF,
  if any. In this case, step 19 is skipped.
  see step 18, section 4.3.2.2.1@3GPP TS 23.502)
   */

}

//------------------------------------------------------------------------------
void smf_context::insert_dnn_subscription(const snssai_t& snssai, std::shared_ptr<session_management_subscription>& ss)
{
  Logger::smf_app().info( "Insert dnn subscription, key: %d", (uint8_t)snssai.sST);
  //std::unique_lock<std::recursive_mutex> lock(m_context);
  //dnn_subscriptions.insert (std::make_pair <const uint8_t, std::shared_ptr<session_management_subscription> >((uint8_t)snssai.sST, ss));
  dnn_subscriptions[(uint8_t)snssai.sST] = ss;

}

//------------------------------------------------------------------------------
bool smf_context::find_dnn_subscription(const snssai_t& snssai, std::shared_ptr<session_management_subscription>& ss)
{
  Logger::smf_app().info( "find_dnn_subscription: %d, map size %d", (uint8_t)snssai.sST, dnn_subscriptions.size());
  //std::unique_lock<std::recursive_mutex> lock(m_context);
  if (dnn_subscriptions.count((uint8_t)snssai.sST) > 0 ){
    ss = dnn_subscriptions.at((uint8_t)snssai.sST);
    return true;
  }

  Logger::smf_app().info( "find_dnn_subscription: cannot find DNN subscription for SNSSAI %d", (uint8_t)snssai.sST);
  return false;
}


//------------------------------------------------------------------------------
bool smf_context::find_dnn_context(const snssai_t& nssai, const std::string& dnn, std::shared_ptr<dnn_context>& dnn_context)
{
  std::unique_lock<std::recursive_mutex> lock(m_context);
  for (auto it : dnns) {
    if ((0 == dnn.compare(it->dnn_in_use)) and ((uint8_t)nssai.sST) == (uint8_t) (it->nssai.sST)) {
      dnn_context = it;
      return true;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
void smf_context::insert_dnn(std::shared_ptr<dnn_context>& sd)
{
  std::unique_lock<std::recursive_mutex> lock(m_context);
  dnns.push_back(sd);
}

//------------------------------------------------------------------------------
bool smf_context::verify_sm_context_request(std::shared_ptr<itti_n11_create_sm_context_request> smreq)
{
  //check the validity of the UE request according to the user subscription or local policies
  //TODO:
  return true;
}

//-----------------------------------------------------------------------------
supi_t smf_context::get_supi() const
{
  return supi;
}

//-----------------------------------------------------------------------------
void smf_context::set_supi(supi_t const& s)
{
  supi = s;
}

//-----------------------------------------------------------------------------
std::size_t smf_context::get_number_dnn_contexts()
{
  return dnns.size();
}

//-----------------------------------------------------------------------------
void smf_context::set_scid(scid_t const& id)
{
  scid = id;
}

//-----------------------------------------------------------------------------
scid_t smf_context::get_scid() const
{
  return scid;
}

//------------------------------------------------------------------------------
bool dnn_context::find_pdu_session(const uint32_t pdu_session_id , std::shared_ptr<smf_pdu_session>& pdn)
{
  pdn = {};

  std::unique_lock<std::recursive_mutex> lock(m_context);
  for (auto it : pdu_sessions) {
    if (pdu_session_id == it->pdu_session_id) {
      pdn = it;
      return true;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
void dnn_context::insert_pdu_session(std::shared_ptr<smf_pdu_session>& sp)
{
  std::unique_lock<std::recursive_mutex> lock(m_context);
  pdu_sessions.push_back(sp);
}

//------------------------------------------------------------------------------
std::string dnn_context::toString() const
{
  std::string s = {};
  s.append("DNN CONTEXT:\n");
  s.append("\tIn use:\t\t\t\t").append(std::to_string(in_use)).append("\n");
  s.append("\tDNN:\t\t\t\t").append(dnn_in_use).append("\n");
  //s.append("\tAPN AMBR Bitrate Uplink:\t").append(std::to_string(apn_ambr.br_ul)).append("\n");
  //s.append("\tAPN AMBR Bitrate Downlink:\t").append(std::to_string(apn_ambr.br_dl)).append("\n");
  for (auto it : pdu_sessions) {
    s.append(it->toString());
  }
  return s;
}

//------------------------------------------------------------------------------
void session_management_subscription::insert_dnn_configuration(std::string dnn, std::shared_ptr<dnn_configuration_t>& dnn_configuration){
  dnn_configurations.insert(std::pair<std::string, std::shared_ptr<dnn_configuration_t>>(dnn,dnn_configuration));
}

//------------------------------------------------------------------------------
void session_management_subscription::find_dnn_configuration(std::string dnn, std::shared_ptr<dnn_configuration_t>& dnn_configuration){
  Logger::smf_app().info( "find_dnn_configuration with dnn %s", dnn.c_str());
  if (dnn_configurations.count(dnn) > 0){
    dnn_configuration = dnn_configurations.at(dnn);
  }
}


//------------------------------------------------------------------------------
void smf_qos_flow::release_qos_flow()
{
  released = true;
}

//------------------------------------------------------------------------------
std::string smf_qos_flow::toString() const
{
  std::string s = {};
  s.append("QoS Flow:\n");
  s.append("\tFQI:\t\t\t\t").append(std::to_string((uint8_t)qfi.qfi)).append("\n");
  s.append("\tUL FTEID:\t\t").append(ul_fteid.toString()).append("\n");
  s.append("\tPDR ID UL:\t\t\t").append(std::to_string(pdr_id_ul.rule_id)).append("\n");
  s.append("\tPDR ID DL:\t\t\t").append(std::to_string(pdr_id_dl.rule_id)).append("\n");
  s.append("\tPRECEDENCE:\t\t\t").append(std::to_string(precedence.precedence)).append("\n");
  if (far_id_ul.first) {
    s.append("\tFAR ID UL:\t\t\t").append(std::to_string(far_id_ul.second.far_id)).append("\n");
  }
  if (far_id_dl.first) {
    s.append("\tFAR ID DL:\t\t\t").append(std::to_string(far_id_dl.second.far_id)).append("\n");
  }
  return s;
}
//------------------------------------------------------------------------------
void smf_qos_flow::deallocate_ressources()
{
  Logger::smf_app().info( "smf_qos_flow::deallocate_ressources(%d)", (uint8_t)qfi.qfi);
  clear();
}


