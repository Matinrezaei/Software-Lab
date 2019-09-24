#include <stdint.h>

#include "ExtendedProtocolDiscriminator.h"
#include "PDUSessionIdentity.h"
#include "ProcedureTransactionIdentity.h"
#include "MessageType.h"
#include "_5GSMCause.h"
#include "GPRSTimer3.h"
#include "EAPMessage.h"
#include "ExtendedProtocolConfigurationOptions.h"


/* Minimum length macro. Formed by minimum length of each mandatory field */
#define PDU_SESSION_RELEASE_COMMAND_MINIMUM_LENGTH ( \
		EXTENDED_PROTOCOL_DISCRIMINATOR_MINIMUM_LENGTH + \
		PDU_SESSION_IDENTITY_MINIMUM_LENGTH + \
		PROCEDURE_TRANSACTION_IDENTITY_MINIMUM_LENGTH + \
		MESSAGE_TYPE_MINIMUM_LENGTH + \
		_5GSM_CAUSE_MINIMUM_LENGTH + \
		GPRS_TIMER3_MINIMUM_LENGTH + \
		EAP_MESSAGE_MINIMUM_LENGTH + \
		EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_MINIMUM_LENGTH + \
0)

/* Maximum length macro. Formed by maximum length of each field */
#define PDU_SESSION_RELEASE_COMMAND_MAXIMUM_LENGTH ( \
		EXTENDED_PROTOCOL_DISCRIMINATOR_MAXIMUM_LENGTH + \
		PDU_SESSION_IDENTITY_MAXIMUM_LENGTH + \
		PROCEDURE_TRANSACTION_IDENTITY_MAXIMUM_LENGTH + \
		MESSAGE_TYPE_MAXIMUM_LENGTH + \
		_5GSM_CAUSE_MAXIMUM_LENGTH + \
		GPRS_TIMER3_MAXIMUM_LENGTH + \
		EAP_MESSAGE_MAXIMUM_LENGTH + \
		EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_MAXIMUM_LENGTH + \
0)

typedef struct pdu_session_release_command_msg_tag{
	ExtendedProtocolDiscriminator extendedprotocoldiscriminator;
	PDUSessionIdentity pdusessionidentity;
	ProcedureTransactionIdentity proceduretransactionidentity;
	MessageType messagetype;
	_5GSMCause _5gsmcause;
	GPRSTimer3 gprstimer3;
	EAPMessage eapmessage;
	ExtendedProtocolConfigurationOptions extendedprotocolconfigurationoptions;
}pdu_session_release_command_msg;


int decode_pdu_session_release_command(pdu_session_release_command_msg *pdusessionreleasecommand, uint8_t *buffer, uint32_t len);
int encode_pdu_session_release_command(pdu_session_release_command_msg *pdusessionreleasecommand, uint8_t *buffer, uint32_t len);
