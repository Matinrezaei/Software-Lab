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

/*! \file smf_msg.hpp
  \brief
  \author
  \company Eurecom
  \email:
 */
#ifndef FILE_SMF_MSG_HPP_SEEN
#define FILE_SMF_MSG_HPP_SEEN

#include "smf.h"
#include "pistache/http.h"
#include "3gpp_29.274.h"
#include "3gpp_24.007.h"
#include "3gpp_24.501.h"

namespace smf {

class pdu_session_create_sm_context_request {

public:
	//pdu_session_create_sm_context_request(): nas_msg(), m_Supi(), m_UnauthenticatedSupi(true), m_PduSessionId(), m_Dnn(), m_SNssai() {}
	pdu_session_create_sm_context_request(): m_supi(), m_unauthenticated_supi(true), m_pdu_session_id(), m_dnn(), m_snssai() {}
	supi_t get_supi() const;
	void set_supi(supi_t const& value);

	pdu_session_id_t get_pdu_session_id() const;
	void set_pdu_session_id(pdu_session_id_t const value);

	std::string get_dnn() const;
	void set_dnn(std::string const& value);

	snssai_t get_snssai() const;
	void set_snssai(snssai_t const& value);

	std::string get_serving_nf_id() const;
	void set_serving_nf_id(std::string const& value);

	request_type_t get_request_type() const;
	void set_request_type(request_type_t const& value);

	//	pdu_session_establishment_request_msg get_nas_msg() const;
	//	void set_nas_msg(pdu_session_establishment_request_msg const& value);

	void set_dnn_selection_mode(std::string const& value);
	std::string get_dnn_selection_mode() const;

	extended_protocol_discriminator_t get_epd() const;
	void set_epd(extended_protocol_discriminator_t const& epd);

	procedure_transaction_id_t get_pti() const;
	void set_pti(procedure_transaction_id_t const& pti);

	uint8_t get_message_type() const;
	void set_message_type(uint8_t const& message_type);

	uint8_t get_pdu_session_type() const;
	void set_pdu_session_type(uint8_t const& pdu_session_type);

	ipmdr_t get_ipmdr() const;
	void set_ipmdr(ipmdr_t const& ipmdr);

private:
	//pdu_session_establishment_request_msg nas_msg;
	supi_t m_supi;
	bool m_unauthenticated_supi;
	//std::string m_Pei;
	//std::string m_Gpsi;
	pdu_session_id_t m_pdu_session_id;
	std::string m_dnn;
	snssai_t m_snssai;
	//Snssai m_HplmnSnssai;
	std::string m_serving_nf_id; //AMF Id
	//Guami m_Guami;
	//std::string m_ServiceName;
	//PlmnId m_ServingNetwork;
	request_type_t m_request_type;
	//RefToBinaryData m_N1SmMsg;
	std::string m_an_type;
	//std::string m_SecondAnType;
	std::string m_rat_type;
	std::string m_presence_in_ladn;
	//UserLocation m_UeLocation;
	//std::string m_UeTimeZone;
	//UserLocation m_AddUeLocation;
	//std::string m_SmContextStatusUri;

	//std::string m_HSmfUri;
	// std::vector<std::string> m_AdditionalHsmfUri;
	// int32_t m_OldPduSessionId;
	// std::vector<int32_t> m_PduSessionsActivateList;
	//std::string m_UeEpsPdnConnection;
	//std::string m_HoState;
	//std::string m_PcfId;
	//std::string m_NrfUri;
	//std::string m_SupportedFeatures;
	std::string m_dnn_selection_mode;//SelMode
	//std::vector<BackupAmfInfo> m_BackupAmfInfo;
	//TraceData m_TraceData;
	//std::string m_UdmGroupId;
	//std::string m_RoutingIndicator;
	//EpsInterworkingIndication m_EpsInterworkingInd;
	//bool m_IndirectForwardingFlag;
	//NgRanTargetId m_TargetId;
	//std::string m_EpsBearerCtxStatus;
	//bool m_CpCiotEnabled;
	//bool m_InvokeNef;
	// bool m_MaPduIndication;
	//RefToBinaryData m_N2SmInfo;
	//std::string m_SmContextRef;

	//NAS
	//Extended protocol discriminator (Mandatory)
	extended_protocol_discriminator_t m_epd;
	//PDU session ID (Mandatory)
	//TODO: need to check with PDU_session_id from outside of NAS??
	//PTI (Mandatory)
	procedure_transaction_id_t m_pti;
	//Message type (Mandatory) (PDU SESSION ESTABLISHMENT REQUEST message identity)
	uint8_t m_message_type;
	//Integrity protection maximum data rate (Mandatory)
	ipmdr_t m_ipmdr;
	//PDU session type (Optional)
	uint8_t m_pdu_session_type;
	//SSC mode (Optional)
	//5GSM capability (Optional)
	//Maximum number of supported (Optional)
	//Maximum number of supported packet filters (Optional)
	//Always-on PDU session requested (Optional)
	//SM PDU DN request container (Optional)
	//Extended protocol configuration options (Optional) e.g, FOR DHCP


};


class pdu_session_create_sm_context_response {

public:
	pdu_session_create_sm_context_response(){ }

	supi_t get_supi() const;
	void set_supi(supi_t const& value);
	pdu_session_id_t get_pdu_session_id() const;
	void set_pdu_session_id(pdu_session_id_t const value);
	void set_cause(uint8_t cause);
	uint8_t get_cause();
	void set_paa(paa_t paa);
	paa_t get_paa();
	void set_http_code(Pistache::Http::Code code);
	Pistache::Http::Code get_http_code();

private:
	supi_t m_supi;
	pdu_session_id_t m_pdu_session_id;
	uint8_t m_cause;
	paa_t m_paa;
	Pistache::Http::Code m_code;
};

}

#endif