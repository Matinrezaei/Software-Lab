#ifndef __5GSMCAUSE_H_
#define __5GSMCAUSE_H_

#include <stdint.h>
#include "bstrlib.h"

#define _5GSM_CAUSE_MINIMUM_LENGTH 2
#define _5GSM_CAUSE_MAXIMUM_LENGTH 2

#define _5GSM_CAUSE_MINIMUM_LENGTH_TV 2
#define _5GSM_CAUSE_MAXIMUM_LENGTH_TV 2
#define _5GSM_CAUSE_MINIMUM_LENGTH_V 1
#define _5GSM_CAUSE_MAXIMUM_LENGTH_V 1


typedef uint8_t _5GSMCause;

int encode__5gsm_cause ( _5GSMCause _5gsmcause, uint8_t iei, uint8_t * buffer, uint32_t len  ) ;
int decode__5gsm_cause ( _5GSMCause * _5gsmcause, uint8_t iei, uint8_t * buffer, uint32_t len  ) ;

#endif
