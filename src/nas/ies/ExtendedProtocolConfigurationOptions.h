#ifndef _EXTENDEDPROTOCOLCONFIGURATIONOPTIONS_H_
#define _EXTENDEDPROTOCOLCONFIGURATIONOPTIONS_H_

#include <stdint.h>
#include "bstrlib.h"

#define EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_MINIMUM_LENGTH 4
#define EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_MAXIMUM_LENGTH 65538

#define EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_MINIMUM_LENGTH_TLVE 4
#define EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_MAXIMUM_LENGTH_TLVE 65538

typedef bstring ExtendedProtocolConfigurationOptions;

int encode_extended_protocol_configuration_options ( ExtendedProtocolConfigurationOptions extendedprotocolconfigurationoptions, uint8_t iei, uint8_t * buffer, uint32_t len  ) ;
int decode_extended_protocol_configuration_options ( ExtendedProtocolConfigurationOptions * extendedprotocolconfigurationoptions, uint8_t iei, uint8_t * buffer, uint32_t len  ) ;

#endif
