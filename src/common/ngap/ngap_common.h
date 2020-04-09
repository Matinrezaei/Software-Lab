/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

#ifndef FILE_NGAP_COMMON_SEEN
#define FILE_NGAP_COMMON_SEEN

#include  "common_defs.h"
#include  "common_types.h"
#include  "conversions.h"
#include  "bstrlib.h"

#include  "Ngap_NGAP-PDU.h"
#include  "Ngap_ProcedureCode.h"
#include  "Ngap_TriggeringMessage.h"
#include  "Ngap_Criticality.h"
#include  "Ngap_CriticalityDiagnostics-IE-Item.h"




#if  0
#include "Ngap_AdditionalQosFlowInformation.h"
#include "Ngap_AllocationAndRetentionPriority.h"
#include "Ngap_AllowedNSSAI.h"
#include "Ngap_AllowedNSSAI-Item.h"
#include "Ngap_AllowedTACs.h"
#include "Ngap_AMFName.h"
#include "Ngap_AMFPagingTarget.h"
#include "Ngap_Cause.h"
#include "Ngap_ResetType.h"
#include "Ngap_RoutingID.h"
#include "Ngap_NRPPa-PDU.h"
#include "Ngap_AMF-UE-NGAP-ID.h"
#include "Ngap_RAN-UE-NGAP-ID.h"
#include "Ngap_TimeToWait.h"
#include "Ngap_CriticalityDiagnostics.h"
#include "Ngap_ServedGUAMIList.h"
#include "Ngap_RelativeAMFCapacity.h"
#include "Ngap_PLMNSupportList.h"
#include "Ngap_AMF-TNLAssociationToAddList.h"
#include "Ngap_AMF-TNLAssociationToRemoveList.h"
#include "Ngap_AMF-TNLAssociationToUpdateList.h"
#include "Ngap_PDUSessionResourceFailedToSetupListCxtFail.h"
#include "Ngap_CriticalityDiagnostics.h"
#include "Ngap_CriticalityDiagnostics.h"
#include "Ngap_RANPagingPriority.h"
#include "Ngap_SecurityKey.h"
#include "Ngap_IndexToRFSP.h"
#include "Ngap_UEAggregateMaximumBitRate.h"
#include "Ngap_UESecurityCapabilities.h"
#include "Ngap_CoreNetworkAssistanceInformation.h"
#include "Ngap_EmergencyFallbackIndicator.h"
#include "Ngap_RRCInactiveTransitionReportRequest.h"
#include "Ngap_IMSVoiceSupportIndicator.h"
#include "Ngap_UserLocationInformation.h"
#include "Ngap_UEPresenceInAreaOfInterestList.h"
#include "Ngap_LocationReportingRequestType.h"
#include "Ngap_PWSFailedCellIDList.h"
#include "Ngap_UserLocationInformation.h"
#include "Ngap_NAS-PDU.h"
#include "Ngap_PDUSessionResourceToReleaseListRelCmd.h"
#include "Ngap_UERadioCapability.h"
#include "Ngap_UERadioCapabilityForPaging.h"
#include "Ngap_MessageIdentifier.h"
#include "Ngap_SerialNumber.h"
#include "Ngap_BroadcastCancelledAreaList.h"
#include "Ngap_PDUSessionResourceAdmittedList.h"
#include "Ngap_PDUSessionResourceFailedToSetupListHOAck.h"
#include "Ngap_TargetToSource-TransparentContainer.h"
#include "Ngap_BroadcastCompletedAreaList.h"
#include "Ngap_SecurityContext.h"
#include "Ngap_NewSecurityContextInd.h"
#include "Ngap_PDUSessionResourceSwitchedList.h"
#include "Ngap_PDUSessionResourceReleasedListPSAck.h"
#include "Ngap_TraceActivation.h"
#include "Ngap_OverloadResponse.h"
#include "Ngap_TrafficLoadReductionIndication.h"
#include "Ngap_OverloadStartNSSAIList.h"
#include "Ngap_AMF-TNLAssociationSetupList.h"
#include "Ngap_TNLAssociationList.h"
#include "Ngap_PDUSessionResourceModifyListModRes.h"
#include "Ngap_PDUSessionResourceFailedToModifyListModRes.h"
#include "Ngap_MobilityRestrictionList.h"
#include "Ngap_PDUSessionResourceSetupListSURes.h"
#include "Ngap_PDUSessionResourceFailedToSetupListSURes.h"
#include "Ngap_NGRANTraceID.h"
#include "Ngap_PDUSessionResourceModifyListModInd.h"
#include "Ngap_SONConfigurationTransfer.h"
#include "Ngap_UEPagingIdentity.h"
#include "Ngap_TAIListForPaging.h"
#include "Ngap_PagingPriority.h"
#include "Ngap_PagingOrigin.h"
#include "Ngap_AssistanceDataForPaging.h"
#include "Ngap_PDUSessionResourceToBeSwitchedDLList.h"
#include "Ngap_PDUSessionResourceFailedToSetupListPSReq.h"
#include "Ngap_WarningAreaList.h"
#include "Ngap_CancelAllWarningMessages.h"
#include "Ngap_InfoOnRecommendedCellsAndRANNodesForPaging.h"
#include "Ngap_PDUSessionResourceListCxtRelCpl.h"
#include "Ngap_PDUSessionResourceReleasedListPSFail.h"
#include "Ngap_UnavailableGUAMIList.h"
#include "Ngap_PDUSessionResourceListCxtRelReq.h"
#include "Ngap_PDUSessionResourceSetupListSUReq.h"
#include "Ngap_PDUSessionResourceSetupListCxtRes.h"
#include "Ngap_PDUSessionResourceFailedToSetupListCxtRes.h"
#include "Ngap_UE-NGAP-IDs.h"
#include "Ngap_RRCEstablishmentCause.h"
#include "Ngap_UEContextRequest.h"
#include "Ngap_RepetitionPeriod.h"
#include "Ngap_NumberOfBroadcastsRequested.h"
#include "Ngap_WarningType.h"
#include "Ngap_WarningSecurityInfo.h"
#include "Ngap_DataCodingScheme.h"
#include "Ngap_WarningMessageContents.h"
#include "Ngap_ConcurrentWarningMessageInd.h"
#include "Ngap_WarningAreaCoordinates.h"
#include "Ngap_RANStatusTransfer-TransparentContainer.h"
#include "Ngap_HandoverType.h"
#include "Ngap_TargetID.h"
#include "Ngap_DirectForwardingPathAvailability.h"
#include "Ngap_PDUSessionResourceListHORqd.h"
#include "Ngap_SourceToTarget-TransparentContainer.h"
#include "Ngap_PDUSessionResourceSetupListCxtReq.h"
#include "Ngap_MaskedIMEISV.h"
#include "Ngap_PDUSessionResourceModifyListModCfm.h"
#include "Ngap_PDUSessionResourceFailedToModifyListModCfm.h"
#include "Ngap_RRCState.h"
#include "Ngap_DirectForwardingPathAvailability.h"
#include "Ngap_PDUSessionResourceListHORqd.h"
#include "Ngap_SourceToTarget-TransparentContainer.h"
#include "Ngap_NASSecurityParametersFromNGRAN.h"
#include "Ngap_PDUSessionResourceHandoverList.h"
#include "Ngap_PDUSessionResourceToReleaseListHOCmd.h"
#include "Ngap_PDUSessionResourceSetupListCxtReq.h"
#include "Ngap_RANNodeName.h"
#include "Ngap_SupportedTAList.h"
#include "Ngap_SupportedTAItem.h"
#include "Ngap_BroadcastPLMNItem.h"
#include "Ngap_MaskedIMEISV.h"
#include "Ngap_RRCState.h"
#include "Ngap_PDUSessionResourceReleasedListRelRes.h"
#include "Ngap_PDUSessionResourceModifyListModCfm.h"
#include "Ngap_PDUSessionResourceFailedToModifyListModCfm.h"
#include "Ngap_RANNodeName.h"
#include "Ngap_SupportedTAList.h"
#include "Ngap_CellIDListForRestart.h"
#include "Ngap_TAIListForRestart.h"
#include "Ngap_EmergencyAreaIDListForRestart.h"
#include "Ngap_PDUSessionResourceNotifyList.h"
#include "Ngap_PDUSessionResourceReleasedListNot.h"
#include "Ngap_PDUSessionResourceSetupListHOReq.h"
#include "Ngap_PDUSessionResourceModifyListModReq.h"
#include "Ngap_ProcedureCode.h"
#include "Ngap_Criticality.h"
#include "Ngap_DownlinkNonUEAssociatedNRPPaTransport.h"
#include "Ngap_UETNLABindingReleaseRequest.h"
#include "Ngap_NGSetupFailure.h"
#include "Ngap_AMFConfigurationUpdate.h"
#include "Ngap_InitialContextSetupFailure.h"
#include "Ngap_UEContextModificationRequest.h"
#include "Ngap_UplinkNonUEAssociatedNRPPaTransport.h"
#include "Ngap_UERadioCapabilityCheckResponse.h"
#include "Ngap_LocationReport.h"
#include "Ngap_PWSFailureIndication.h"
#include "Ngap_HandoverNotify.h"
#include "Ngap_PDUSessionResourceReleaseCommand.h"
#include "Ngap_UERadioCapabilityInfoIndication.h"
#include "Ngap_PWSCancelResponse.h"
#include "Ngap_DownlinkUEAssociatedNRPPaTransport.h"
#include "Ngap_HandoverRequestAcknowledge.h"
#include "Ngap_UplinkNASTransport.h"
#include "Ngap_WriteReplaceWarningResponse.h"
#include "Ngap_PathSwitchRequestAcknowledge.h"
#include "Ngap_TraceStart.h"
#include "Ngap_RANConfigurationUpdateAcknowledge.h"
#include "Ngap_OverloadStart.h"
#include "Ngap_AMFConfigurationUpdateAcknowledge.h"
#include "Ngap_NGSetupResponse.h"
#include "Ngap_PDUSessionResourceModifyResponse.h"
#include "Ngap_DownlinkNASTransport.h"
#include "Ngap_PDUSessionResourceSetupResponse.h"
#include "Ngap_UplinkUEAssociatedNRPPaTransport.h"
#include "Ngap_CellTrafficTrace.h"
#include "Ngap_PDUSessionResourceModifyIndication.h"
#include "Ngap_UplinkRANConfigurationTransfer.h"
#include "Ngap_Paging.h"
#include "Ngap_PathSwitchRequest.h"
#include "Ngap_PWSCancelRequest.h"
#include "Ngap_DeactivateTrace.h"
#include "Ngap_UEContextReleaseComplete.h"
#include "Ngap_LocationReportingControl.h"
#include "Ngap_PathSwitchRequestFailure.h"
#include "Ngap_HandoverCancelAcknowledge.h"
#include "Ngap_HandoverFailure.h"
#include "Ngap_HandoverCancel.h"
#include "Ngap_AMFStatusIndication.h"
#include "Ngap_LocationReportingFailureIndication.h"
#include "Ngap_AMFConfigurationUpdateFailure.h"
#include "Ngap_UEContextReleaseRequest.h"
#include "Ngap_DownlinkRANConfigurationTransfer.h"
#include "Ngap_PDUSessionResourceSetupRequest.h"
#include "Ngap_InitialContextSetupResponse.h"
#include "Ngap_UERadioCapabilityCheckRequest.h"
#include "Ngap_UEContextReleaseCommand.h"
#include "Ngap_HandoverPreparationFailure.h"
#include "Ngap_InitialUEMessage.h"
#include "Ngap_WriteReplaceWarningRequest.h"
#include "Ngap_UplinkRANStatusTransfer.h"
#include "Ngap_HandoverRequired.h"
#include "Ngap_InitialContextSetupRequest.h"
#include "Ngap_PDUSessionResourceModifyConfirm.h"
#include "Ngap_RANConfigurationUpdateFailure.h"
#include "Ngap_RRCInactiveTransitionReport.h"
#include "Ngap_NASNonDeliveryIndication.h"
#include "Ngap_HandoverCommand.h"
#include "Ngap_NGSetupRequest.h"
#include "Ngap_UEContextModificationResponse.h"
#include "Ngap_PDUSessionResourceReleaseResponse.h"
#include "Ngap_DownlinkRANStatusTransfer.h"
#include "Ngap_TraceFailureIndication.h"
#include "Ngap_RANConfigurationUpdate.h"
#include "Ngap_PWSRestartIndication.h"
#include "Ngap_PDUSessionResourceNotify.h"
#include "Ngap_UEContextModificationFailure.h"
#include "Ngap_RerouteNASRequest.h"
#include "Ngap_HandoverRequest.h"
#include "Ngap_NGResetAcknowledge.h"
#include "Ngap_PDUSessionResourceModifyRequest.h"
#include "Ngap_InitialContextSetupResponse.h"
#include "Ngap_UERadioCapabilityCheckRequest.h"
#include "Ngap_UEContextReleaseCommand.h"
#include "Ngap_HandoverPreparationFailure.h"
#include "Ngap_InitialUEMessage.h"
#include "Ngap_WriteReplaceWarningRequest.h"
#include "Ngap_UplinkRANStatusTransfer.h"
#include "Ngap_HandoverRequired.h"
#include "Ngap_InitialContextSetupRequest.h"
#include "Ngap_PDUSessionResourceModifyConfirm.h"
#include "Ngap_RANConfigurationUpdateFailure.h"
#include "Ngap_RRCInactiveTransitionReport.h"
#include "Ngap_NASNonDeliveryIndication.h"
#include "Ngap_HandoverCommand.h"
#include "Ngap_InitiatingMessage.h"
#include "Ngap_SuccessfulOutcome.h"
#include "Ngap_UnsuccessfulOutcome.h"
#include "Ngap_NGReset.h"
#include "Ngap_DownlinkNonUEAssociatedNRPPaTransport.h"
#include "Ngap_UETNLABindingReleaseRequest.h"
#include "Ngap_NGSetupFailure.h"
#include "Ngap_AMFConfigurationUpdate.h"
#include "Ngap_InitialContextSetupFailure.h"
#include "Ngap_ErrorIndication.h"
#include "Ngap_NGRAN-CGI.h"
#include "Ngap_GUAMI.h"
#include "Ngap_ProtocolIE-Field.h"
#include "Ngap_ProtocolIE-ID.h"
#include "Ngap_PLMNIdentity.h"
#include "Ngap_BroadcastPLMNList.h"
#include "Ngap_TAC.h"
#include "Ngap_ServedGUAMIItem.h"
#include "Ngap_GNB-ID.h"
#include "Ngap_NGAP-PDU.h"
#endif

#include  "assertions.h"

//#include "log.h"

#define true  1
#define false 0

#define NGAP_FIND_PROTOCOLIE_BY_ID(IE_TYPE, ie, container, IE_ID, mandatory) \
  do {\
    IE_TYPE **ptr; \
    ie = NULL; \
    for (ptr = container->protocolIEs.list.array; \
         ptr < &container->protocolIEs.list.array[container->protocolIEs.list.count]; \
         ptr++) { \
      if((*ptr)->id == IE_ID) { \
        ie = *ptr; \
        break; \
      } \
    } \
    if (mandatory) DevAssert(ie != NULL); \
  } while(0)


typedef int (*ngap_message_decoded_callback)(
    const sctp_assoc_id_t             assoc_id,
    const sctp_stream_id_t            stream,
    struct Ngap_NGAP_PDU *message_p
);



int  check_NGAP_pdu_constraints(Ngap_NGAP_PDU_t *pdu);

int  ngap_amf_decode_pdu(Ngap_NGAP_PDU_t *pdu, const_bstring const raw);

#endif
