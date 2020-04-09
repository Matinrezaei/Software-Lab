#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "TLVEncoder.h"
#include "TLVDecoder.h"
#include "PDUSessionReleaseComplete.h"

int decode_pdu_session_release_complete( pdu_session_release_complete_msg *pdu_session_release_complete, uint8_t *buffer, uint32_t len)
{
  uint32_t decoded = 0;
  int decoded_result = 0;

  // Check if we got a NULL pointer and if buffer length is >= minimum length expected for the message.
  CHECK_PDU_POINTER_AND_LENGTH_DECODER (buffer, PDU_SESSION_RELEASE_COMPLETE_MINIMUM_LENGTH, len);

  while (len - decoded > 0) {
    uint8_t ieiDecoded = *(buffer + decoded);

    if (ieiDecoded == 0)
      break;

    switch (ieiDecoded) {
    case PDU_SESSION_RELEASE_COMPLETE__5GSM_CAUSE_IEI:
      if ((decoded_result = decode__5gsm_cause (&pdu_session_release_complete->_5gsmcause, PDU_SESSION_RELEASE_COMPLETE__5GSM_CAUSE_IEI, buffer + decoded, len - decoded)) < 0)
        return decoded_result;
      else {
        decoded += decoded_result;
        pdu_session_release_complete->presence |= PDU_SESSION_RELEASE_COMPLETE__5GSM_CAUSE_PRESENCE;
      }
      break;
    case PDU_SESSION_RELEASE_COMPLETE_E_P_C_O_IEI:
      if ((decoded_result = decode_extended_protocol_configuration_options (&pdu_session_release_complete->extendedprotocolconfigurationoptions, PDU_SESSION_RELEASE_COMPLETE_E_P_C_O_IEI, buffer + decoded, len - decoded)) < 0)
        return decoded_result;
      else {
        decoded += decoded_result;
        pdu_session_release_complete->presence |= PDU_SESSION_RELEASE_COMPLETE_E_P_C_O_PRESENCE;
      }
      break;
    }
  }

  return decoded;
}


int encode_pdu_session_release_complete( pdu_session_release_complete_msg *pdu_session_release_complete, uint8_t *buffer, uint32_t len)
{
  uint32_t encoded = 0;
  int encoded_result = 0;

  // Check if we got a NULL pointer and if buffer length is >= minimum length expected for the message.
  CHECK_PDU_POINTER_AND_LENGTH_ENCODER (buffer, PDU_SESSION_RELEASE_COMPLETE_MINIMUM_LENGTH, len);

if ((pdu_session_release_complete->presence & PDU_SESSION_RELEASE_COMPLETE__5GSM_CAUSE_PRESENCE) == PDU_SESSION_RELEASE_COMPLETE__5GSM_CAUSE_PRESENCE) {
  if ((encoded_result = encode__5gsm_cause (pdu_session_release_complete->_5gsmcause, PDU_SESSION_RELEASE_COMPLETE__5GSM_CAUSE_IEI, buffer + encoded, len - encoded)) < 0)
    return encoded_result;
  else
    encoded += encoded_result;
}

if ((pdu_session_release_complete->presence & PDU_SESSION_RELEASE_COMPLETE_E_P_C_O_PRESENCE) == PDU_SESSION_RELEASE_COMPLETE_E_P_C_O_PRESENCE) {
  if ((encoded_result = encode_extended_protocol_configuration_options (pdu_session_release_complete->extendedprotocolconfigurationoptions, PDU_SESSION_RELEASE_COMPLETE_E_P_C_O_IEI, buffer + encoded, len - encoded)) < 0)
    return encoded_result;
  else
    encoded += encoded_result;
}

return encoded;
}
