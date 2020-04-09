#include  "3gpp_23.003.h"
#include  "Ngap_TAI.h"
#include  "Ngap_NR-CGI.h"

//#include  "asn1_conversions.h"
//#include  "conversions.h"


#include  "ng_pdu_path_switch_request_failure.h"
#include  "Ngap_HandoverFailure.h"
#include  "Ngap_CauseRadioNetwork.h"


#include  "Ngap_PathSwitchRequestFailure.h"
#include  "Ngap_PDUSessionResourceReleasedListPSFail.h"
#include  "Ngap_PDUSessionResourceReleasedItemPSFail.h"


#include  "Ngap_UnsuccessfulOutcome.h"
#include  "Ngap_NGAP-PDU.h"
#include  "Ngap_ProtocolIE-Field.h"
#include  "Ngap_ProcedureCode.h"
#include  "Ngap_Criticality.h"
#include  "Ngap_Cause.h"


#include  "Ngap_CriticalityDiagnostics.h"
#include  "Ngap_CriticalityDiagnostics-IE-List.h"
#include  "Ngap_CriticalityDiagnostics-IE-Item.h"

#include  "Ngap_TimeStamp.h"

#include  "common_defs.h"
#include  "common_types.h"
#include  "../common/ngap/ngap_common.h"
#include  "INTEGER.h"
#include  "asn_SEQUENCE_OF.h"
#include  "OCTET_STRING.h"


#define BUF_LEN   1024

Ngap_PathSwitchRequestFailureIEs_t  * make_path_sw_req_failure_CriticalityDiagnostics()
{
	Ngap_PathSwitchRequestFailureIEs_t *ie;
	ie = calloc(1, sizeof(Ngap_PathSwitchRequestFailureIEs_t));
	
	ie->id            = Ngap_ProtocolIE_ID_id_CriticalityDiagnostics;
	ie->criticality   = Ngap_Criticality_ignore;
	ie->value.present = Ngap_PathSwitchRequestFailureIEs__value_PR_CriticalityDiagnostics;
	
    return ie;
}

Ngap_PathSwitchRequestFailureIEs_t  *make_path_sw_req_failure_AMF_UE_NGAP_ID(uint64_t amf_UE_NGAP_ID)
{
    Ngap_PathSwitchRequestFailureIEs_t *ie = NULL;
	ie = calloc(1, sizeof(Ngap_PathSwitchRequestFailureIEs_t));
	
	ie->id            = Ngap_ProtocolIE_ID_id_AMF_UE_NGAP_ID;
	ie->criticality   = Ngap_Criticality_ignore;
	ie->value.present = Ngap_PathSwitchRequestFailureIEs__value_PR_AMF_UE_NGAP_ID;

	asn_ulong2INTEGER(&ie->value.choice.AMF_UE_NGAP_ID, amf_UE_NGAP_ID & AMF_UE_NGAP_ID_MASK_);
	
	printf("AMF_UE_NGAP_ID:0x%x\n",amf_UE_NGAP_ID);
	return ie;
}
Ngap_PathSwitchRequestFailureIEs_t  *make_path_sw_req_failure_RAN_UE_NGAP_ID(uint32_t rAN_UE_NGAP_ID)
{
	Ngap_PathSwitchRequestFailureIEs_t *ie;
	ie = calloc(1, sizeof(Ngap_PathSwitchRequestFailureIEs_t));

	ie->id            = Ngap_ProtocolIE_ID_id_RAN_UE_NGAP_ID;
	ie->criticality   = Ngap_Criticality_ignore;
	ie->value.present = Ngap_PathSwitchRequestFailureIEs__value_PR_RAN_UE_NGAP_ID;
	ie->value.choice.RAN_UE_NGAP_ID = rAN_UE_NGAP_ID ;

	printf("RAN_UE_NGAP_ID:0x%x",ie->value.choice.RAN_UE_NGAP_ID);
	return ie;
}


Ngap_PDUSessionResourceReleasedItemPSFail_t *make_path_sw_req_failure_PDUSessionResourceReleasedItemPSFail(
	const long  pDUSessionID, const char	 *pDUSessionResourceSetup)
{
    Ngap_PDUSessionResourceReleasedItemPSFail_t  *item = NULL;
    item =  calloc(1, sizeof(Ngap_PDUSessionResourceReleasedItemPSFail_t));
	
    item->pDUSessionID = pDUSessionID;
	OCTET_STRING_fromBuf(&item->pathSwitchRequestUnsuccessfulTransfer,pDUSessionResourceSetup,strlen(pDUSessionResourceSetup));
	printf("ReleaseCommand,pDUSessionID:0x%x, Transfer:%s\n", pDUSessionID, pDUSessionResourceSetup);
    return item;
}

Ngap_PathSwitchRequestFailureIEs_t  * make_path_sw_req_failure_PDUSessionResourceReleasedListPSFail()
{
	Ngap_PathSwitchRequestFailureIEs_t *ie;
	ie = calloc(1, sizeof(Ngap_PathSwitchRequestFailureIEs_t));
	
	ie->id            = Ngap_ProtocolIE_ID_id_PDUSessionResourceReleasedListPSFail;
	ie->criticality   = Ngap_Criticality_reject;
	ie->value.present = Ngap_PathSwitchRequestFailureIEs__value_PR_PDUSessionResourceReleasedListPSFail;
	
    return ie;
}



void add_pdu_path_sw_req_failure_ie(Ngap_PathSwitchRequestFailure_t *ngapPDUPathSwReqFailure, Ngap_PathSwitchRequestFailureIEs_t *ie) {
    int ret;
	ret = ASN_SEQUENCE_ADD(&ngapPDUPathSwReqFailure->protocolIEs.list, ie);
    if ( ret != 0 ) {
        fprintf(stderr, "Failed to add ie\n");
		return ;
    }
	return ;
}
Ngap_NGAP_PDU_t *  ngap_generate_ng_path_sw_req_failure(const char *inputBuf)
{
    Ngap_NGAP_PDU_t * pdu = NULL;
	pdu = calloc(1, sizeof(Ngap_NGAP_PDU_t));
    
	pdu->present = Ngap_NGAP_PDU_PR_unsuccessfulOutcome;
	pdu->choice.unsuccessfulOutcome = calloc(1, sizeof(Ngap_UnsuccessfulOutcome_t));
	pdu->choice.unsuccessfulOutcome->procedureCode = Ngap_ProcedureCode_id_PathSwitchRequest;
	pdu->choice.unsuccessfulOutcome->criticality   = Ngap_Criticality_reject;
	pdu->choice.unsuccessfulOutcome->value.present = Ngap_UnsuccessfulOutcome__value_PR_PathSwitchRequestFailure;

    Ngap_PathSwitchRequestFailure_t	 *ngapPathSwitchRequestFailure = NULL;
	ngapPathSwitchRequestFailure = &pdu->choice.unsuccessfulOutcome->value.choice.PathSwitchRequestFailure;
	
	Ngap_PathSwitchRequestFailureIEs_t  *ie = NULL;

    //Ngap_AMF_UE_NGAP_ID_t
	uint64_t  amf_ue_ngap_id = 0x77;
	ie  = make_path_sw_req_failure_AMF_UE_NGAP_ID(amf_ue_ngap_id);
    add_pdu_path_sw_req_failure_ie(ngapPathSwitchRequestFailure, ie);

    uint64_t  ran_ue_ngap_id = 0x78;
	ie  = make_path_sw_req_failure_RAN_UE_NGAP_ID(ran_ue_ngap_id);
    add_pdu_path_sw_req_failure_ie(ngapPathSwitchRequestFailure, ie);

    //PDUSessionResourceReleasedListPSFail
    Ngap_PDUSessionResourceReleasedItemPSFail_t	 *pReleasedListPSFailItem = NULL;
	ie = make_path_sw_req_failure_PDUSessionResourceReleasedListPSFail();
	pReleasedListPSFailItem = make_path_sw_req_failure_PDUSessionResourceReleasedItemPSFail(0x80, "test_fail_item");
	ASN_SEQUENCE_ADD(&ie->value.choice.PDUSessionResourceReleasedListPSFail.list, pReleasedListPSFailItem);
	add_pdu_path_sw_req_failure_ie(ngapPathSwitchRequestFailure, ie);
	


	//CriticalityDiagnostics
    ie = make_path_sw_req_failure_CriticalityDiagnostics();

	Ngap_ProcedureCode_t  *procedureCode = calloc(1, sizeof(Ngap_ProcedureCode_t));
	*procedureCode = 0x81;
    ie ->value.choice.CriticalityDiagnostics.procedureCode  = procedureCode;

	Ngap_TriggeringMessage_t  *triggeringMessage = calloc(1, sizeof(Ngap_TriggeringMessage_t));
	*triggeringMessage = 0x01;
    ie ->value.choice.CriticalityDiagnostics.triggeringMessage = triggeringMessage;

	Ngap_Criticality_t  *procedureCriticality = calloc(1, sizeof(Ngap_Criticality_t));
	*procedureCriticality = 0x01;
	ie ->value.choice.CriticalityDiagnostics.procedureCriticality = procedureCriticality;

    printf("procedureCode:0x%x,triggeringMessage:0x%x,procedureCriticality:0x%x\n", *procedureCode, *triggeringMessage,*procedureCriticality);	


    Ngap_CriticalityDiagnostics_IE_List_t   *pCriticalityDiagnostics_IE_List  = calloc(1, sizeof(Ngap_CriticalityDiagnostics_IE_List_t));
    Ngap_CriticalityDiagnostics_IE_Item_t   *critiDiagIEsItem = calloc(1, sizeof(Ngap_CriticalityDiagnostics_IE_Item_t));
	critiDiagIEsItem->iECriticality = 0x01;
	critiDiagIEsItem->iE_ID = 0x01;
	critiDiagIEsItem->typeOfError = 0x00;


    printf("iECriticality:0x%x,iE_ID:0x%x,typeOfError:0x%x\n", 
	critiDiagIEsItem->iECriticality,
	critiDiagIEsItem->iE_ID,
	critiDiagIEsItem->typeOfError);


	ie->value.choice.CriticalityDiagnostics.iEsCriticalityDiagnostics = pCriticalityDiagnostics_IE_List;
    
    ASN_SEQUENCE_ADD(&pCriticalityDiagnostics_IE_List->list, critiDiagIEsItem);
	add_pdu_path_sw_req_failure_ie(ngapPathSwitchRequestFailure, ie);
  
	return pdu;
}



int
ngap_amf_handle_ng_pdu_path_sw_req_failure(
    const sctp_assoc_id_t assoc_id,
    const sctp_stream_id_t stream,
	Ngap_NGAP_PDU_t *pdu){

    int rc = RETURNok;

	#if 0
    gnb_description_t   * gnb_association = NULL; 
	//gnb_description_t   * gnb_ref = NULL;
    uint32_t              gnb_id = 0;
    char                 *gnb_name = NULL;
    int				      gnb_name_size = 0;
    int                   ta_ret = 0;
    uint32_t              max_gnb_connected = 0;
    int i = 0;
	
	#endif

	int i  = 0;
    Ngap_PathSwitchRequestFailure_t             *container = NULL;
    Ngap_PathSwitchRequestFailureIEs_t          *ie = NULL;
    Ngap_PathSwitchRequestFailureIEs_t          *ie_gnb_name = NULL;

    unsigned  long    amf_ue_ngap_id    = 0;
	uint32_t          radioNetwork      = 0;
	
	long	  procedureCode         = 0;	
	long	  triggeringMessage     = 0;	
	long	  procedureCriticality  = 0;
	long	  iECriticality         = 0;
	long	  iE_ID                 = 0;
	long 	  typeOfError           = 0;

    DevAssert (pdu != NULL);
    //OAILOG_INFO(LOG_NGAP,"----------------------- DECODED NG SETUP RESPONSE NGAP MSG --------------------------\n");
    //asn_fprint(stdout, &asn_DEF_Ngap_NGAP_PDU, pdu);
    //OAILOG_INFO(LOG_NGAP,"----------------------- DECODED NG SETUP RESPONSE NGAP MSG --------------------------\n");

	container = &pdu->choice.unsuccessfulOutcome->value.choice.PathSwitchRequestFailure;
    
    //AMF_UE_NGAP_ID
    NGAP_FIND_PROTOCOLIE_BY_ID(Ngap_PathSwitchRequestFailureIEs_t, ie, container, Ngap_ProtocolIE_ID_id_AMF_UE_NGAP_ID, false);
    if (ie) 
	{  
	    asn_INTEGER2ulong(&ie->value.choice.AMF_UE_NGAP_ID, &amf_ue_ngap_id);
	    printf("amf_ue_ngap_id, 0x%x\n", amf_ue_ngap_id);
    }

    //PDUSessionResourceReleasedListPSFail
    NGAP_FIND_PROTOCOLIE_BY_ID(Ngap_PathSwitchRequestFailureIEs_t, ie, container, Ngap_ProtocolIE_ID_id_PDUSessionResourceReleasedListPSFail, false);
	if (ie) 
	{ 
	    Ngap_PDUSessionResourceReleasedListPSFail_t	 *fail_container  =  &ie->value.choice.PDUSessionResourceReleasedListPSFail;
        for (i  = 0;i < fail_container->list.count; i++)
	    {
            Ngap_PDUSessionResourceReleasedItemPSFail_t *failItemIes_p = NULL;
            failItemIes_p = fail_container->list.array[i];
			
			if(!failItemIes_p)
			{
				  continue;
        	}

		    long pDUSessionID                              = failItemIes_p->pDUSessionID;
	 	    char *pDUSessionResourceReleaseCommandTransfer = failItemIes_p->pathSwitchRequestUnsuccessfulTransfer.buf;
	        

			printf("ReleaseCommand,pDUSessionID:0x%x, Transfer:%s\n", pDUSessionID, pDUSessionResourceReleaseCommandTransfer);
		}
	}
	//CriticalityDiagnostics
    NGAP_FIND_PROTOCOLIE_BY_ID(Ngap_PathSwitchRequestFailureIEs_t, ie, container, Ngap_ProtocolIE_ID_id_CriticalityDiagnostics, false);
	if (ie) 
	{ 
	   procedureCode         = *ie->value.choice.CriticalityDiagnostics.procedureCode;	
	   triggeringMessage     = *ie->value.choice.CriticalityDiagnostics.triggeringMessage;	
	   procedureCriticality  = *ie->value.choice.CriticalityDiagnostics.procedureCriticality;

	   printf("procedureCode:0x%x,triggeringMessage:0x%x,procedureCriticality:0x%x\n", procedureCode, triggeringMessage,procedureCriticality);  

	   Ngap_CriticalityDiagnostics_IE_List_t   *criticality_container  = ie->value.choice.CriticalityDiagnostics.iEsCriticalityDiagnostics; 
       for (i  = 0;i < criticality_container->list.count; i++)
	   {
           Ngap_CriticalityDiagnostics_IE_Item_t  *criticalityIes_p = criticality_container->list.array[i];
		   if(!criticalityIes_p)
		      continue;
		   
		    iECriticality         = criticalityIes_p->iECriticality;
	        iE_ID                 = criticalityIes_p->iE_ID;
	        typeOfError           = criticalityIes_p->typeOfError;

			printf("iECriticality:0x%x,iE_ID:0x%x,typeOfError:0x%x\n", iECriticality, iE_ID, typeOfError);
	   }  
	}
	
	return rc;
}


int  make_NGAP_PduPathSwitchRequestFailure(const char *inputBuf, const char *OutputBuf)
{

    printf("pdu path sw req failure, start--------------------\n\n");

    int ret = 0;
	int rc  = RETURNok;
	const sctp_assoc_id_t assoc_id  = 0;
    const sctp_stream_id_t stream   = 0;
	Ngap_NGAP_PDU_t  message = {0};

	//wys:  1024 ?
	size_t buffer_size = 1024;  
	void *buffer = calloc(1,buffer_size);
	asn_enc_rval_t er;	
	
	Ngap_NGAP_PDU_t * pdu =  ngap_generate_ng_path_sw_req_failure(inputBuf);
	if(!pdu)
		goto ERROR;

    asn_fprint(stderr, &asn_DEF_Ngap_NGAP_PDU, pdu);

    ret  =  check_NGAP_pdu_constraints(pdu);
    if(ret < 0) 
	{
		printf("ng pdu path sw req failure Constraint validation  failed\n");
		rc = RETURNerror;
		goto ERROR; 
	}

	//encode
	er = aper_encode_to_buffer(&asn_DEF_Ngap_NGAP_PDU, NULL, pdu, buffer, buffer_size);
	if(er.encoded < 0)
	{
		printf("ng pdu path sw req failure encode failed,er.encoded:%d\n",er.encoded);
		rc = RETURNerror;
		goto ERROR; 
	}
  		 
	bstring msgBuf = blk2bstr(buffer, er.encoded);

    //decode
    ngap_amf_decode_pdu(&message, msgBuf);
	ngap_amf_handle_ng_pdu_path_sw_req_failure(0,0, &message);

    //Free pdu
    if(pdu)
       ASN_STRUCT_FREE(asn_DEF_Ngap_NGAP_PDU, pdu);
    
	if(buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	
	printf("pdu path sw req failure, finish--------------------\n\n");
    return rc;

ERROR:
	//Free pdu
	if(pdu)
        ASN_STRUCT_FREE(asn_DEF_Ngap_NGAP_PDU, pdu);
	if(buffer)
	{
		free(buffer);
		buffer = NULL;
	}
 	return rc;  
}



