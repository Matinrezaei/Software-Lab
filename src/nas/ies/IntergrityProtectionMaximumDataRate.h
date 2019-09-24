#include <stdint.h>
#include "bstrlib.h"

#define INTERGRITY_PROTECTION_MAXIMUM_DATA_RATE_MINIMUM_LENGTH 3
#define INTERGRITY_PROTECTION_MAXIMUM_DATA_RATE_MAXIMUM_LENGTH 3

typedef bstring IntergrityProtectionMaximumDataRate;

int encode_intergrity_protection_maximum_data_rate ( IntergrityProtectionMaximumDataRate intergrityprotectionmaximumdatarate, uint8_t iei, uint8_t * buffer, uint32_t len  ) ;
int decode_intergrity_protection_maximum_data_rate ( IntergrityProtectionMaximumDataRate * intergrityprotectionmaximumdatarate, uint8_t iei, uint8_t * buffer, uint32_t len  ) ;

