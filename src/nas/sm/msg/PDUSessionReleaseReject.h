#ifndef _PDUSESSIONRELEASEREJECT_H_
#define _PDUSESSIONRELEASEREJECT_H_

#include <stdint.h>

#include "ExtendedProtocolDiscriminator.h"
#include "PDUSessionIdentity.h"
#include "ProcedureTransactionIdentity.h"
#include "MessageType.h"
#include "_5GSMCause.h"
#include "ExtendedProtocolConfigurationOptions.h"


#if 0
/* Minimum length macro. Formed by minimum length of each mandatory field */
#define PDU_SESSION_RELEASE_REJECT_MINIMUM_LENGTH ( \
		EXTENDED_PROTOCOL_DISCRIMINATOR_MINIMUM_LENGTH + \
		PDU_SESSION_IDENTITY_MINIMUM_LENGTH + \
		PROCEDURE_TRANSACTION_IDENTITY_MINIMUM_LENGTH + \
		MESSAGE_TYPE_MINIMUM_LENGTH + \
		_5GSM_CAUSE_MINIMUM_LENGTH + \
		EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_MINIMUM_LENGTH + \
0)
#endif
/* Minimum length macro. Formed by minimum length of each mandatory field */
#define PDU_SESSION_RELEASE_REJECT_MINIMUM_LENGTH ( \
		_5GSM_CAUSE_MINIMUM_LENGTH_V + \
0)


/* Maximum length macro. Formed by maximum length of each field */
#define PDU_SESSION_RELEASE_REJECT_MAXIMUM_LENGTH ( \
		EXTENDED_PROTOCOL_DISCRIMINATOR_MAXIMUM_LENGTH + \
		PDU_SESSION_IDENTITY_MAXIMUM_LENGTH + \
		PROCEDURE_TRANSACTION_IDENTITY_MAXIMUM_LENGTH + \
		MESSAGE_TYPE_MAXIMUM_LENGTH + \
		_5GSM_CAUSE_MAXIMUM_LENGTH_V + \
		EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_MAXIMUM_LENGTH_TLVE + \
0)


#define PDU_SESSION_RELEASE_REJECT_E_P_C_O_IEI	0x7B
#define PDU_SESSION_RELEASE_REJECT_E_P_C_O_PRESENCE	(1<<0)

typedef struct pdu_session_release_reject_msg_tag{
	ExtendedProtocolDiscriminator extendedprotocoldiscriminator;
	PDUSessionIdentity pdusessionidentity;
	ProcedureTransactionIdentity proceduretransactionidentity;
	MessageType messagetype;
	_5GSMCause _5gsmcause;
	uint8_t presence;
	ExtendedProtocolConfigurationOptions extendedprotocolconfigurationoptions;
}pdu_session_release_reject_msg;


int decode_pdu_session_release_reject(pdu_session_release_reject_msg *pdusessionreleasereject, uint8_t *buffer, uint32_t len);
int encode_pdu_session_release_reject(pdu_session_release_reject_msg *pdusessionreleasereject, uint8_t *buffer, uint32_t len);

#endif
