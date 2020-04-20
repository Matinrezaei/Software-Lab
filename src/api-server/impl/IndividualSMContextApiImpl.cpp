/**
 * Nsmf_PDUSession
 * SMF PDU Session Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

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

#include "IndividualSMContextApiImpl.h"

namespace oai {
namespace smf_server {
namespace api {

using namespace oai::smf_server::model;

IndividualSMContextApiImpl::IndividualSMContextApiImpl(
    std::shared_ptr<Pistache::Rest::Router> rtr, smf::smf_app *smf_app_inst,
    std::string address)
    :
    IndividualSMContextApi(rtr),
    m_smf_app(smf_app_inst),
    m_address(address) {
}

void IndividualSMContextApiImpl::release_sm_context(
    const std::string &smContextRef,
    const SmContextReleaseMessage &smContextReleaseMessage,
    Pistache::Http::ResponseWriter &response) {

  //TODO: to be updated as update_sm_context_handler
  Logger::smf_api_server().info("release_sm_context...");

  //handle Nsmf_PDUSession_UpdateSMContext Request
  Logger::smf_api_server().info(
      "Received a PDUSession_UpdateSMContext Request: PDU Session Release request from AMF.");
  //Get the SmContextUpdateData from this message and process in smf_app
  smf::pdu_session_update_sm_context_request sm_context_req_msg = { };

  SmContextReleaseData smContextReleaseData = smContextReleaseMessage
      .getJsonData();

  if (smContextReleaseData.n2SmInfoIsSet()) {
    //N2 SM (for Session establishment)
    std::string n2_sm_information = smContextReleaseMessage
        .getBinaryDataN2SmInformation();
    Logger::smf_api_server().debug("smContextMessage, n2 sm information %s",
                                   n2_sm_information.c_str());
    std::string n2_sm_info_type = smContextReleaseData.getN2SmInfoType();
    sm_context_req_msg.set_n2_sm_information(n2_sm_information);
    sm_context_req_msg.set_n2_sm_info_type(n2_sm_info_type);
  }
  //Step 2. TODO: initialize necessary values for sm context req from smContextReleaseData

  //Step 3. Handle the itti_n11_update_sm_context_request message in smf_app
  //std::shared_ptr<itti_n11_update_sm_context_request> itti_msg = std::make_shared<itti_n11_update_sm_context_request>(TASK_SMF_N11, TASK_SMF_APP, response, smContextRef);
  //itti_msg->req = sm_context_req_msg;
  //itti_msg->scid = smContextRef;
  //m_smf_app->handle_pdu_session_update_sm_context_request(itti_msg);

}

void IndividualSMContextApiImpl::retrieve_sm_context(
    const std::string &smContextRef,
    const SmContextRetrieveData &smContextRetrieveData,
    Pistache::Http::ResponseWriter &response) {
  Logger::smf_api_server().info("retrieve_sm_context...");
  response.send(Pistache::Http::Code::Ok,
                "Retrieve_sm_context API has not been implemented yet!\n");
}

void IndividualSMContextApiImpl::update_sm_context(
    const std::string &smContextRef,
    const SmContextUpdateMessage &smContextUpdateMessage,
    Pistache::Http::ResponseWriter &response) {

  //Get the SmContextUpdateData from this message and process in smf_app
  Logger::smf_api_server().info(
      "Received a PDUSession_UpdateSMContext Request from AMF.");

  smf::pdu_session_update_sm_context_request sm_context_req_msg = { };
  SmContextUpdateData smContextUpdateData =
      smContextUpdateMessage.getJsonData();

  if (smContextUpdateData.n2SmInfoIsSet()) {
    //N2 SM (for Session establishment)
    std::string n2_sm_information = smContextUpdateMessage
        .getBinaryDataN2SmInformation();
    Logger::smf_api_server().debug("smContextMessage, n2 sm information %s",
                                   n2_sm_information.c_str());
    std::string n2_sm_info_type = smContextUpdateData.getN2SmInfoType();
    sm_context_req_msg.set_n2_sm_information(n2_sm_information);
    sm_context_req_msg.set_n2_sm_info_type(n2_sm_info_type);

  } else if (smContextUpdateData.n1SmMsgIsSet()) {
    //N1 SM (for session modification)
    std::string n1_sm_message =
        smContextUpdateMessage.getBinaryDataN1SmMessage();
    Logger::smf_api_server().debug("smContextMessage, n1 sm message %s",
                                   n1_sm_message.c_str());
    sm_context_req_msg.set_n1_sm_message(n1_sm_message);
  }
  //Step 2. TODO: initialize necessary values for sm context req from smContextUpdateData

  /* UE-initiated Service Request Operation, section 4.2.3.2@3GPP TS 23.502 */
  //Step 4: PDU Session IDs, Operation Type, UE location Info, Access Type, RAT Type, UE presence in LADN service area, Indication of Access Type can be changed
  //PDU Session IDs
  //UpCnxState, for activation of user plane (see 5.2.2.3.2.2@3GPP TS 29.502)
  if (smContextUpdateData.upCnxStateIsSet())
    sm_context_req_msg.set_upCnx_state(smContextUpdateData.getUpCnxState());
  //Access Type
  if (smContextUpdateData.anTypeIsSet())
    sm_context_req_msg.set_an_type(smContextUpdateData.getAnType());
  //RAT Type
  if (smContextUpdateData.ratTypeIsSet())
    sm_context_req_msg.set_rat_type(smContextUpdateData.getRatType());
  //TODO:
  //UE presence in LADN service area
  //UE location information
  //Indication of Access Type can be changed
  //if (smContextUpdateData.anTypeCanBeChangedIsSet()) sm_context_req_msg.set_access_type_can_be_changed(smContextUpdateData.isAnTypeCanBeChanged());
  //Step 15: N2 SM Info (AN Tunnel Info, List of accepted QoS Flow, List of rejected Qos Flows, PDU Session ID), RAT Type, Access Type

  /* UE-initiated PDU Session Establishment Operation - section 4.3.2.2.1@3GPP TS 23.502 */
  //TODO: Existing PDU session, step 3, SUPI, DNN, S-NSSAIs, SM Context ID, AMF ID, Request Type, N1 SM Container (PDU Session Establishment Request), User location, Access Type, RAT Type, PEI
  //step 15. (SM Context ID -> SCID, N2 SM, Request Type)(Initial Request)
  //TODO: verify why Request Type is not define in smContextUpdateData
  /* PDU Session Modification (SM Context ID -> SCID, N1/N2), section 4.3.3.2@3GPP TS 23.502: */
  //step 1.a,UE-initiated: SM Context ID + N1 (PDU Session Modification Request)
  //step 1.e (AN initiated modification): SM Context ID, N2 SM information (QFI, User location Information and an indication that the QoS Flow is released)
  //step 7a, SM Context ID, N2 SM information, UE location information
  //Step 11, SM Context ID, N1 SM (PDU Session Modification Command ACK), User location
  //Step 3. Handle the itti_n11_update_sm_context_request message in smf_app
  std::shared_ptr<itti_n11_update_sm_context_request> itti_msg =
      std::make_shared<itti_n11_update_sm_context_request>(TASK_SMF_N11,
                                                           TASK_SMF_APP,
                                                           response,
                                                           smContextRef);
  itti_msg->req = sm_context_req_msg;
  itti_msg->scid = smContextRef;
  m_smf_app->handle_pdu_session_update_sm_context_request(itti_msg);

}

}
}
}

