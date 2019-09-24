#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#include "TLVEncoder.h"
#include "TLVDecoder.h"
#include "AuthenticationParameterRAND.h"

int encode_authentication_parameter_rand ( AuthenticationParameterRAND  authenticationparameterrand, uint8_t iei, uint8_t * buffer, uint32_t len  ) 
{
  uint32_t                                encode_result;
  uint32_t                                encoded = 0;

  /*
   * Checking IEI and pointer
   */
  CHECK_PDU_POINTER_AND_LENGTH_ENCODER (buffer, AUTHENTICATION_PARAMETER_RAND_MINIMUM_LENGTH, len);

  if (iei > 0) {
    *buffer = iei;
    printf("encoded rand iei(%x)\n",iei);
    encoded++;
  }

//  *buffer = iei;
//  encoded++;

  if ((encode_result = encode_bstring (authenticationparameterrand, buffer + encoded, len - encoded)) < 0) {
       return encode_result;
  } else {
    encoded += encode_result;
  }

  return encoded;
}

int decode_authentication_parameter_rand ( AuthenticationParameterRAND * authenticationparameterrand, uint8_t iei, uint8_t * buffer, uint32_t len  ) 
{
  int                                     decoded = 0;
  uint8_t                                 ielen = 1;
  int                                     decode_result;

  if (iei > 0) {
    CHECK_IEI_DECODER (iei, *buffer);
    decoded++;
  }
  
  if ((decode_result = decode_bstring (authenticationparameterrand, ielen, buffer + decoded, len - decoded)) < 0)
    return decode_result;
  else
    decoded += decode_result; 

  return decoded;
}

