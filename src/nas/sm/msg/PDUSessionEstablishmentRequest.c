#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "TLVEncoder.h"
#include "TLVDecoder.h"
#include "PDUSessionEstablishmentRequest.h"

int decode_pdu_session_establishment_request( pdu_session_establishment_request_msg *pdu_session_establishment_request, uint8_t* buffer, uint32_t len)
{
    uint32_t decoded = 0;
    int decoded_result = 0;

    // Check if we got a NULL pointer and if buffer length is >= minimum length expected for the message.
    CHECK_PDU_POINTER_AND_LENGTH_DECODER (buffer, PDU_SESSION_ESTABLISHMENT_REQUEST_MINIMUM_LENGTH, len);

    if((decoded_result = decode_extended_protocol_discriminator (&pdu_session_establishment_request->extendedprotocoldiscriminator, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_pdu_session_identity (&pdu_session_establishment_request->pdusessionidentity, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_procedure_transaction_identity (&pdu_session_establishment_request->proceduretransactionidentity, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_message_type (&pdu_session_establishment_request->messagetype, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_intergrity_protection_maximum_data_rate (&pdu_session_establishment_request->intergrityprotectionmaximumdatarate, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode__pdu_session_type (&pdu_session_establishment_request->_pdusessiontype, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_ssc_mode (&pdu_session_establishment_request->sscmode, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode__5gsm_capability (&pdu_session_establishment_request->_5gsmcapability, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_maximum_number_of_supported_packet_filters (&pdu_session_establishment_request->maximumnumberofsupportedpacketfilters, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_alwayson_pdu_session_requested (&pdu_session_establishment_request->alwaysonpdusessionrequested, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_smpdudn_request_container (&pdu_session_establishment_request->smpdudnrequestcontainer, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_extended_protocol_configuration_options (&pdu_session_establishment_request->extendedprotocolconfigurationoptions, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;


    return decoded;
}


int encode_pdu_session_establishment_request( pdu_session_establishment_request_msg *pdu_session_establishment_request, uint8_t* buffer, uint32_t len)
{
    uint32_t encoded = 0;
    int encoded_result = 0;
    
    // Check if we got a NULL pointer and if buffer length is >= minimum length expected for the message.
    CHECK_PDU_POINTER_AND_LENGTH_ENCODER (buffer, PDU_SESSION_ESTABLISHMENT_REQUEST_MINIMUM_LENGTH, len);

    if((encoded_result = encode_extended_protocol_discriminator (pdu_session_establishment_request->extendedprotocoldiscriminator, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_pdu_session_identity (pdu_session_establishment_request->pdusessionidentity, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_procedure_transaction_identity (pdu_session_establishment_request->proceduretransactionidentity, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_message_type (pdu_session_establishment_request->messagetype, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_intergrity_protection_maximum_data_rate (pdu_session_establishment_request->intergrityprotectionmaximumdatarate, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode__pdu_session_type (pdu_session_establishment_request->_pdusessiontype, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_ssc_mode (pdu_session_establishment_request->sscmode, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode__5gsm_capability (pdu_session_establishment_request->_5gsmcapability, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_maximum_number_of_supported_packet_filters (pdu_session_establishment_request->maximumnumberofsupportedpacketfilters, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_alwayson_pdu_session_requested (pdu_session_establishment_request->alwaysonpdusessionrequested, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_smpdudn_request_container (pdu_session_establishment_request->smpdudnrequestcontainer, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_extended_protocol_configuration_options (pdu_session_establishment_request->extendedprotocolconfigurationoptions, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;


    return encoded;
}
