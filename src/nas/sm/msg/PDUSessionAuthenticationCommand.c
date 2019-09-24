#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "TLVEncoder.h"
#include "TLVDecoder.h"
#include "PDUSessionAuthenticationCommand.h"

int decode_pdu_session_authentication_command( pdu_session_authentication_command_msg *pdu_session_authentication_command, uint8_t* buffer, uint32_t len)
{
    uint32_t decoded = 0;
    int decoded_result = 0;

    // Check if we got a NULL pointer and if buffer length is >= minimum length expected for the message.
    CHECK_PDU_POINTER_AND_LENGTH_DECODER (buffer, PDU_SESSION_AUTHENTICATION_COMMAND_MINIMUM_LENGTH, len);

    if((decoded_result = decode_extended_protocol_discriminator (&pdu_session_authentication_command->extendedprotocoldiscriminator, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_pdu_session_identity (&pdu_session_authentication_command->pdusessionidentity, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_procedure_transaction_identity (&pdu_session_authentication_command->proceduretransactionidentity, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_message_type (&pdu_session_authentication_command->messagetype, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_eap_message (&pdu_session_authentication_command->eapmessage, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;

    if((decoded_result = decode_extended_protocol_configuration_options (&pdu_session_authentication_command->extendedprotocolconfigurationoptions, 0, buffer+decoded,len-decoded))<0)
        return decoded_result;
    else
        decoded+=decoded_result;


    return decoded;
}


int encode_pdu_session_authentication_command( pdu_session_authentication_command_msg *pdu_session_authentication_command, uint8_t* buffer, uint32_t len)
{
    uint32_t encoded = 0;
    int encoded_result = 0;
    
    // Check if we got a NULL pointer and if buffer length is >= minimum length expected for the message.
    CHECK_PDU_POINTER_AND_LENGTH_ENCODER (buffer, PDU_SESSION_AUTHENTICATION_COMMAND_MINIMUM_LENGTH, len);

    if((encoded_result = encode_extended_protocol_discriminator (pdu_session_authentication_command->extendedprotocoldiscriminator, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_pdu_session_identity (pdu_session_authentication_command->pdusessionidentity, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_procedure_transaction_identity (pdu_session_authentication_command->proceduretransactionidentity, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_message_type (pdu_session_authentication_command->messagetype, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_eap_message (pdu_session_authentication_command->eapmessage, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;

    if((encoded_result = encode_extended_protocol_configuration_options (pdu_session_authentication_command->extendedprotocolconfigurationoptions, 0, buffer+encoded,len-encoded))<0)
        return encoded_result;
    else
        encoded+=encoded_result;


    return encoded;
}
