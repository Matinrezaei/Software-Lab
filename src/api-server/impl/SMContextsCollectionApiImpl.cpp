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

#include "SMContextsCollectionApiImpl.h"
#include "logger.hpp"
#include "smf_msg.hpp"
#include "itti_msg_n11.hpp"

extern "C" {
#include <ctype.h>
#include "nas_message.h"
#include "mmData.h"
//#include "NasMain.h"
}

namespace oai {
namespace smf {
namespace api {

using namespace oai::smf::model;

SMContextsCollectionApiImpl::SMContextsCollectionApiImpl(std::shared_ptr<Pistache::Rest::Router> rtr, pgwc::pgw_app *smf_app_inst)
: SMContextsCollectionApi(rtr), m_smf_app(smf_app_inst)

{ }

void SMContextsCollectionApiImpl::post_sm_contexts(const SmContextMessage &smContextMessage, Pistache::Http::ResponseWriter &response) {

	Logger::smf_api_server().info("post_sm_contexts...");

	//decode NAS message and assign the necessary informations to pgwc::pdu_session_create_sm_context_request
	//and pass this message to SMF to handle this message

	//step 1. Decode NAS  message (for instance, ... only served as an example)
	nas_message_decode_status_t   decode_status = {0};
	nas_message_t	decoded_nas_msg;
	memset (&decoded_nas_msg, 0, sizeof (nas_message_t));
	int decoder_rc = RETURNok;
	//unsigned char data[100] = {'\0'}; //hardcoded for the moment

	SmContextCreateData smContextCreateData = smContextMessage.getJsonData();
	std::string n1SmMessage = smContextMessage.getBinaryDataN1SmMessage();

	unsigned int n1SmMsgLen = strlen(n1SmMessage.c_str());
	unsigned char *data = (unsigned char *)malloc(n1SmMsgLen + 1);//hardcoded for the moment
	unsigned char datavalue[512]  = {'\0'}; // = (unsigned char *)malloc(n1SmMsgLen/2 + 1);
	memset(data,0,n1SmMsgLen + 1);

	//Decode and process nas message
	//bsafe (disable temporarily warning for strncpy)
	//std::strncpy((char *)data, n1SmMessage.c_str(), sizeof(data));

	memcpy ((void *)data, (void *)n1SmMessage.c_str(),n1SmMsgLen);
	//establishment_request(data);
	printf("data = %s\n",data);
	printf("datavalue = ");
	for(int i=0;i<n1SmMsgLen;i++)
	{
		char datatmp[3] = {0};
		memcpy(datatmp,&data[i],2);
		// Ensure both characters are hexadecimal
        bool bBothDigits = true;

        for(int j = 0; j < 2; ++j)
        {
            if(!isxdigit(datatmp[j]))
                bBothDigits = false;
        }
		if(!bBothDigits)
        	break;
		// Convert two hexadecimal characters into one character
        unsigned int nAsciiCharacter;
        sscanf(datatmp, "%x", &nAsciiCharacter);
		printf("%x ",nAsciiCharacter);
		// Concatenate this character onto the output
       	datavalue[i/2] = (unsigned char)nAsciiCharacter;

        // Skip the next character
        i++;
	}
	printf("\n");
	free(data);
	data = NULL;

	//use a temporary security mechanism
	fivegmm_security_context_t * security = ( fivegmm_security_context_t *) std::calloc(1,sizeof(fivegmm_security_context_t));
	security->selected_algorithms.encryption = NAS_SECURITY_ALGORITHMS_NEA1;
	security->dl_count.overflow = 0xffff;
	security->dl_count.seq_num =  0x23;
	security->knas_enc[0] = 0x14;
	security->selected_algorithms.integrity = NAS_SECURITY_ALGORITHMS_NIA1;
	security->knas_int[0] = 0x41;

	//decode the NAS message (using NAS lib)
	// comment to fix a unknown bug
	decoder_rc = nas_message_decode (datavalue, &decoded_nas_msg, sizeof(datavalue), security, &decode_status);

	Logger::smf_api_server().debug("nas header  decode extended_protocol_discriminator %d, security_header_type:%d,sequence_number:%d,message_authentication_code:%d\n",
			decoded_nas_msg.header.extended_protocol_discriminator,
			decoded_nas_msg.header.security_header_type,
			decoded_nas_msg.header.sequence_number,
			decoded_nas_msg.header.message_authentication_code);

//nas_message_decode test
	switch(decoded_nas_msg.plain.sm.header.message_type)
	{
		case PDU_SESSION_ESTABLISHMENT_REQUEST:
			printf("PDU_SESSION_ESTABLISHMENT_REQUEST------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("intergrity buffer:0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.intergrityprotectionmaximumdatarate)->data[0]),(unsigned char )((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.intergrityprotectionmaximumdatarate)->data[1]));
			printf("_pdusessiontype bits_3:0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request._pdusessiontype.pdu_session_type_value);
			printf("sscmode bits_3:0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.sscmode.ssc_mode_value);
			printf("_5gsmcapability bits_5 --- MPTCP:0x%x ATS-LL:0x%x EPT-S1:0x%x MH6-PDU:0x%x RqoS:0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request._5gsmcapability.is_MPTCP_supported,decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request._5gsmcapability.is_ATSLL_supported,decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request._5gsmcapability.is_EPTS1_supported,decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request._5gsmcapability.is_MH6PDU_supported,decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request._5gsmcapability.is_Rqos_supported);
			printf("maximum bits_11:0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.maximumnumberofsupportedpacketfilters);
			printf("Always-on bits_1 --- APSR:0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.alwaysonpdusessionrequested.apsr_requested);
			printf("sm_pdu_dn buffer:0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.smpdudnrequestcontainer)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.smpdudnrequestcontainer)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.smpdudnrequestcontainer)->data[2]));
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_request.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_ESTABLISHMENT_REQUEST------------ end\n");
		break;
		case PDU_SESSION_ESTABLISHMENT_ACCPET:
			printf("PDU_SESSION_ESTABLISHMENT_ACCPET------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("PDU_SESSION_ESTABLISHMENT_ACCPET------------ end\n");
		break;
		case PDU_SESSION_ESTABLISHMENT_REJECT:
			printf("PDU_SESSION_ESTABLISHMENT_REJECT------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("_5gsmcause: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject._5gsmcause);
			printf("gprstimer3 --- unit_bits_H3: 0x%x,timeValue_bits_L5: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.gprstimer3.unit,decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.gprstimer3.timeValue);
			printf("allowedsscmode --- is_ssc1_allowed: 0x%x, is_ssc2_allowed: 0x%x, is_ssc3_allowed: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.allowedsscmode.is_ssc1_allowed,decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.allowedsscmode.is_ssc2_allowed,decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.allowedsscmode.is_ssc3_allowed);
			printf("eapmessage buffer:0x%x 0x%x\n",(unsigned char)(decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.eapmessage->data[0]),(unsigned char )(decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.eapmessage->data[1]));
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject.extendedprotocolconfigurationoptions)->data[3]));
			printf("_5gsmcongestionreattemptindicator bits_1 --- abo:0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_establishment_reject._5gsmcongestionreattemptindicator.abo);
		    printf("PDU_SESSION_ESTABLISHMENT_REJECT------------ end\n");
		break;
		case PDU_SESSION_AUTHENTICATION_COMMAND:
			printf("PDU_SESSION_AUTHENTICATION_COMMAND------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("eapmessage buffer:0x%x 0x%x\n",(unsigned char)(decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_command.eapmessage->data[0]),(unsigned char )(decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_command.eapmessage->data[1]));
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_command.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_command.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_command.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_command.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_AUTHENTICATION_COMMAND------------ end\n");
		break;
		case PDU_SESSION_AUTHENTICATION_COMPLETE:
			printf("PDU_SESSION_AUTHENTICATION_COMPLETE------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("eapmessage buffer:0x%x 0x%x\n",(unsigned char)(decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_complete.eapmessage->data[0]),(unsigned char )(decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_complete.eapmessage->data[1]));
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_complete.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_complete.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_complete.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_complete.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_AUTHENTICATION_COMPLETE------------ end\n");
		break;
		case PDU_SESSION_AUTHENTICATION_RESULT:
			printf("PDU_SESSION_AUTHENTICATION_RESULT------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("eapmessage buffer:0x%x 0x%x\n",(unsigned char)(decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_result.eapmessage->data[0]),(unsigned char )(decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_result.eapmessage->data[1]));
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_result.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_result.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_result.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_authentication_result.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_AUTHENTICATION_RESULT------------ end\n");
		break;
		case PDU_SESSION_MODIFICATION_REQUEST:
			printf("PDU_SESSION_MODIFICATION_REQUEST------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);

			printf("PDU_SESSION_MODIFICATION_REQUEST------------ end\n");
		break;
		case PDU_SESSION_MODIFICATION_REJECT:
			printf("PDU_SESSION_MODIFICATION_REJECT------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("_5gsmcause: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_reject._5gsmcause);
			printf("gprstimer3 --- unit_bits_H3: 0x%x,timeValue_bits_L5: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_reject.gprstimer3.unit,decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_reject.gprstimer3.timeValue);
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_reject.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_reject.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_reject.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_reject.extendedprotocolconfigurationoptions)->data[3]));
			printf("_5gsmcongestionreattemptindicator bits_1 --- abo:0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_reject._5gsmcongestionreattemptindicator.abo);
			printf("PDU_SESSION_MODIFICATION_REJECT------------ end\n");
		break;
		case PDU_SESSION_MODIFICATION_COMMAND:
			printf("PDU_SESSION_MODIFICATION_COMMAND------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);

			printf("PDU_SESSION_MODIFICATION_COMMAND------------ end\n");
		break;
		case PDU_SESSION_MODIFICATION_COMPLETE:
			printf("PDU_SESSION_MODIFICATION_COMPLETE------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_complete.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_complete.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_complete.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_complete.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_MODIFICATION_COMPLETE------------ end\n");
		break;
		case PDU_SESSION_MODIFICATION_COMMANDREJECT:
			printf("PDU_SESSION_MODIFICATION_COMMANDREJECT------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("_5gsmcause: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_command_reject._5gsmcause);
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_command_reject.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_command_reject.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_command_reject.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_modification_command_reject.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_MODIFICATION_COMMANDREJECT------------ end\n");
		break;
		case PDU_SESSION_RELEASE_REQUEST:
			printf("PDU_SESSION_RELEASE_REQUEST------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("_5gsmcause: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_request._5gsmcause);
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_request.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_request.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_request.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_request.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_RELEASE_REQUEST------------ end\n");
		break;
		case PDU_SESSION_RELEASE_REJECT:
			printf("PDU_SESSION_RELEASE_REJECT------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("_5gsmcause: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_reject._5gsmcause);
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_reject.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_reject.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_reject.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_reject.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_RELEASE_REJECT------------ end\n");
		break;
		case PDU_SESSION_RELEASE_COMMAND:
			printf("PDU_SESSION_RELEASE_COMMAND------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("_5gsmcause: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command._5gsmcause);
			printf("gprstimer3 --- unit_bits_H3: 0x%x,timeValue_bits_L5: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command.gprstimer3.unit,decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command.gprstimer3.timeValue);
			printf("eapmessage buffer:0x%x 0x%x\n",(unsigned char)(decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command.eapmessage->data[0]),(unsigned char )(decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command.eapmessage->data[1]));
			printf("_5gsmcongestionreattemptindicator bits_1 --- abo:0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command._5gsmcongestionreattemptindicator.abo);
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_command.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_RELEASE_COMMAND------------ end\n");
		break;
		case PDU_SESSION_RELEASE_COMPLETE:
			printf("PDU_SESSION_RELEASE_COMPLETE------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("_5gsmcause: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_complete._5gsmcause);
			printf("extend_options buffer:0x%x 0x%x 0x%x 0x%x\n",(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_complete.extendedprotocolconfigurationoptions)->data[0]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_complete.extendedprotocolconfigurationoptions)->data[1]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_complete.extendedprotocolconfigurationoptions)->data[2]),(unsigned char)((decoded_nas_msg.plain.sm.specific_msg.pdu_session_release_complete.extendedprotocolconfigurationoptions)->data[3]));
			printf("PDU_SESSION_RELEASE_COMPLETE------------ end\n");
		break;
		case _5GSM_STAUS:
			printf("_5GSM_STAUS------------ start\n");
			printf("sm header,extended_protocol_discriminator:0x%x,pdu_session_identity:0x%x,proeduer_transaction_identity:0x%x, message type:0x%x\n", decoded_nas_msg.plain.sm.header.extended_protocol_discriminator,decoded_nas_msg.plain.sm.header.pdu_session_identity,decoded_nas_msg.plain.sm.header.proeduer_transaction_identity,decoded_nas_msg.plain.sm.header.message_type);
			printf("_5gsmcause: 0x%x\n",decoded_nas_msg.plain.sm.specific_msg._5gsm_status._5gsmcause);
			printf("_5GSM_STAUS------------ end\n");
		break;

	}




	//Step 2. Create a pdu_session_create_sm_context_request message and store the necessary information
	pgwc::pdu_session_create_sm_context_request sm_context_req_msg = {};

	//supi
	supi_t supi =  {.length = 0};
	smf_string_to_supi(&supi, smContextCreateData.getSupi().c_str());
	sm_context_req_msg.set_supi(supi);
	//dnn
	sm_context_req_msg.set_dnn(smContextCreateData.getDnn());
	//S-Nssai
	snssai_t snssai(smContextCreateData.getSNssai().getSst(), smContextCreateData.getSNssai().getSd());
	sm_context_req_msg.set_snssai(snssai);
	//PDU session ID
	sm_context_req_msg.set_pdu_session_id(smContextCreateData.getPduSessionId());
	//AMF ID
	sm_context_req_msg.set_serving_nf_id(smContextCreateData.getServingNfId()); //TODO: should be verified that AMF ID is stored in GUAMI or ServingNfId
	//Request Type
	sm_context_req_msg.set_request_type(smContextCreateData.getRequestType());
	//PCF ID
	// Priority Access
	//User Location Information
	//Access Type
	// PEI
	// GPSI
	// UE presence in LADN service area
	// DNN Selection Mode
	sm_context_req_msg.set_dnn_selection_mode(smContextCreateData.getSelMode());
	//Subscription for PDU Session Status Notification
	// Trace requirement

	//From N1 Container (NAS)
	//Extended protocol discriminator (Mandatory)
	sm_context_req_msg.set_epd(decoded_nas_msg.header.extended_protocol_discriminator);
	//PDU session ID (Mandatory)
	//TODO:
	//PTI (Mandatory)

	//TODO:
	//Message type (Mandatory) (PDU SESSION ESTABLISHMENT REQUEST message identity)
	//sm_context_req_msg->set_message_type(decoded_nas_msg.plain.sm.pdu_session_establishment_request.messagetype);
	//Logger::smf_api_server().debug("nas decode messaget type %d\n",
	//		decoded_nas_msg.plain.sm.pdu_session_establishment_request.messagetype);
	sm_context_req_msg.set_message_type (PDU_SESSION_ESTABLISHMENT_REQUEST); //Temporary - should be removed (get from NAS)
	//Integrity protection maximum data rate (Mandatory)
	//PDU session type (Optional)
	sm_context_req_msg.set_pdu_session_type(PDN_TYPE_E_IPV4);//TODO: should get from NAS msg
	//SSC mode (Optional)
	//5GSM capability (Optional)
	//Maximum number of supported (Optional)
	//Maximum number of supported packet filters (Optional)
	//Always-on PDU session requested (Optional)
	//SM PDU DN request container (Optional)
	//Extended protocol configuration options (Optional) e.g, FOR DHCP

	//Step 3. Handle the pdu_session_create_sm_context_request message in pwg_app
	//m_smf_app->handle_amf_msg(sm_context_req_msg, response);

    itti_n11_create_sm_context_request *itti_msg = new itti_n11_create_sm_context_request(TASK_SMF_N11, TASK_PGWC_APP, response);
    itti_msg->req = sm_context_req_msg;

    std::shared_ptr<itti_n11_create_sm_context_request> i = std::shared_ptr<itti_n11_create_sm_context_request>(itti_msg);

    m_smf_app->handle_amf_msg(i);



}

}
}
}
