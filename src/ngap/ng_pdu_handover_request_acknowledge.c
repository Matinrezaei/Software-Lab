#include  "3gpp_23.003.h"
#include  "Ngap_TAI.h"
#include  "Ngap_NR-CGI.h"

//#include  "asn1_conversions.h"
//#include  "conversions.h"


#include  "ng_pdu_handover_request_acknowledge.h"
#include  "Ngap_HandoverRequestAcknowledge.h"


#include  "Ngap_SuccessfulOutcome.h"
#include  "Ngap_NGAP-PDU.h"
#include  "Ngap_ProtocolIE-Field.h"
#include  "Ngap_ProcedureCode.h"
#include  "Ngap_Criticality.h"


#include  "Ngap_PDUSessionResourceAdmittedList.h"
#include  "Ngap_PDUSessionResourceAdmittedItem.h"

#include  "Ngap_PDUSessionResourceFailedToSetupListHOAck.h"
#include  "Ngap_PDUSessionResourceFailedToSetupItemHOAck.h"



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

Ngap_HandoverRequestAcknowledgeIEs_t  * make_handover_req_ack_CriticalityDiagnostics()
{
	Ngap_HandoverRequestAcknowledgeIEs_t *ie;
	ie = calloc(1, sizeof(Ngap_HandoverRequestAcknowledgeIEs_t));
	
	ie->id            = Ngap_ProtocolIE_ID_id_CriticalityDiagnostics;
	ie->criticality   = Ngap_Criticality_ignore;
	ie->value.present = Ngap_HandoverRequestAcknowledgeIEs__value_PR_CriticalityDiagnostics;
	
    return ie;
}

Ngap_HandoverRequestAcknowledgeIEs_t  *make_handover_req_ack_RAN_UE_NGAP_ID(uint32_t rAN_UE_NGAP_ID)
{
	Ngap_HandoverRequestAcknowledgeIEs_t *ie;
	ie = calloc(1, sizeof(Ngap_HandoverRequestAcknowledgeIEs_t));

	ie->id            = Ngap_ProtocolIE_ID_id_RAN_UE_NGAP_ID;
	ie->criticality   = Ngap_Criticality_ignore;
	ie->value.present = Ngap_HandoverRequestAcknowledgeIEs__value_PR_RAN_UE_NGAP_ID;
	ie->value.choice.RAN_UE_NGAP_ID = rAN_UE_NGAP_ID ;

	printf("RAN_UE_NGAP_ID:0x%x\n",ie->value.choice.RAN_UE_NGAP_ID);
	return ie;
}

Ngap_HandoverRequestAcknowledgeIEs_t  *make_handover_req_ack_AMF_UE_NGAP_ID(uint64_t amf_UE_NGAP_ID)
{
    Ngap_HandoverRequestAcknowledgeIEs_t *ie = NULL;
	ie = calloc(1, sizeof(Ngap_HandoverRequestAcknowledgeIEs_t));
	
	ie->id            = Ngap_ProtocolIE_ID_id_AMF_UE_NGAP_ID;
	ie->criticality   = Ngap_Criticality_ignore;
	ie->value.present = Ngap_HandoverRequestAcknowledgeIEs__value_PR_AMF_UE_NGAP_ID;

	asn_ulong2INTEGER(&ie->value.choice.AMF_UE_NGAP_ID, amf_UE_NGAP_ID & AMF_UE_NGAP_ID_MASK_);
	
	printf("AMF_UE_NGAP_ID:0x%x\n",amf_UE_NGAP_ID);
	return ie;
}

Ngap_PDUSessionResourceAdmittedItem_t *make_req_ack_PDUSessionResourceAdmittedItem(
const long  pDUSessionID,  
const char *pDUTransfer)
{
    Ngap_PDUSessionResourceAdmittedItem_t  *item = NULL;
    item =  calloc(1, sizeof(Ngap_PDUSessionResourceAdmittedItem_t));
	
    item->pDUSessionID = pDUSessionID;
	OCTET_STRING_fromBuf(&item->handoverRequestAcknowledgeTransfer, pDUTransfer,strlen(pDUTransfer));
		
	printf("AdmittedItem,pDUSessionID:0x%x,Transfer:%s\n", item->pDUSessionID,item->handoverRequestAcknowledgeTransfer.buf);
	
    return item;
}

Ngap_HandoverRequestAcknowledgeIEs_t  *make_req_ack_PDUSessionResourceAdmittedList()
{
    Ngap_HandoverRequestAcknowledgeIEs_t *ie = NULL;
	ie = calloc(1, sizeof(Ngap_HandoverRequestAcknowledgeIEs_t));
	
	ie->id            = Ngap_ProtocolIE_ID_id_PDUSessionResourceAdmittedList;
	ie->criticality   = Ngap_Criticality_ignore;
	ie->value.present = Ngap_HandoverRequestAcknowledgeIEs__value_PR_PDUSessionResourceAdmittedList;
	
	return ie;
}


Ngap_PDUSessionResourceFailedToSetupItemHOAck_t *make_req_ack_PDUSessionResourceFailedToSetupItemHOAck(
const long  pDUSessionID,  
const char *pDUTransfer)
{
    Ngap_PDUSessionResourceFailedToSetupItemHOAck_t  *item = NULL;
    item =  calloc(1, sizeof(Ngap_PDUSessionResourceFailedToSetupItemHOAck_t));
	
    item->pDUSessionID = pDUSessionID;
	OCTET_STRING_fromBuf(&item->handoverResourceAllocationUnsuccessfulTransfer, pDUTransfer,strlen(pDUTransfer));
		
	printf("FailedItem,pDUSessionID:0x%x,Transfer:%s\n", item->pDUSessionID,item->handoverResourceAllocationUnsuccessfulTransfer.buf);
	
    return item;
}


Ngap_HandoverRequestAcknowledgeIEs_t  *make_req_ack_PDUSessionResourceFailedToSetupListHOAck()
{
    Ngap_HandoverRequestAcknowledgeIEs_t *ie = NULL;
	ie = calloc(1, sizeof(Ngap_HandoverRequestAcknowledgeIEs_t));
	
	ie->id            = Ngap_ProtocolIE_ID_id_PDUSessionResourceFailedToSetupListHOAck;
	ie->criticality   = Ngap_Criticality_ignore;
	ie->value.present = Ngap_HandoverRequestAcknowledgeIEs__value_PR_PDUSessionResourceFailedToSetupListHOAck;
	
	return ie;
}

Ngap_HandoverRequestAcknowledgeIEs_t  *make_TargetToSource_TransparentContainer(const char *transparent)
{
    Ngap_HandoverRequestAcknowledgeIEs_t *ie = NULL;
	ie                = calloc(1, sizeof(Ngap_HandoverRequestAcknowledgeIEs_t));
	
	ie->id            = Ngap_ProtocolIE_ID_id_TargetToSource_TransparentContainer;
	ie->criticality   = Ngap_Criticality_reject;
	ie->value.present = Ngap_HandoverRequestAcknowledgeIEs__value_PR_TargetToSource_TransparentContainer;
	OCTET_STRING_fromBuf (&ie->value.choice.TargetToSource_TransparentContainer, transparent, strlen(transparent));

    printf("transparent:%s,\n",  transparent);

	return ie;
}


void add_pdu_handover_req_ack_ie(Ngap_HandoverRequestAcknowledge_t *ngapPDUHandoverReqAck, Ngap_HandoverRequestAcknowledgeIEs_t *ie) {
    int ret;
	ret = ASN_SEQUENCE_ADD(&ngapPDUHandoverReqAck->protocolIEs.list, ie);
    if ( ret != 0 ) {
        fprintf(stderr, "Failed to add ie\n");
		return ;
    }
	return ;
}
Ngap_NGAP_PDU_t *  ngap_generate_ng_handover_req_ack(const char *inputBuf)
{
    Ngap_NGAP_PDU_t * pdu = NULL;
	pdu = calloc(1, sizeof(Ngap_NGAP_PDU_t));
    
	pdu->present = Ngap_NGAP_PDU_PR_successfulOutcome;
	pdu->choice.successfulOutcome = calloc(1, sizeof(Ngap_SuccessfulOutcome_t));
	pdu->choice.successfulOutcome->procedureCode = Ngap_ProcedureCode_id_HandoverResourceAllocation;
	pdu->choice.successfulOutcome->criticality   = Ngap_Criticality_reject;
	pdu->choice.successfulOutcome->value.present = Ngap_SuccessfulOutcome__value_PR_HandoverRequestAcknowledge;

    Ngap_HandoverRequestAcknowledge_t *ngapPDUHandoverRequestAcknowledge = NULL;
	ngapPDUHandoverRequestAcknowledge = &pdu->choice.successfulOutcome->value.choice.HandoverRequestAcknowledge;
	
	Ngap_HandoverRequestAcknowledgeIEs_t  *ie = NULL;

    //Ngap_AMF_UE_NGAP_ID_t
	uint64_t  amf_ue_ngap_id = 0x77;
	ie  = make_handover_req_ack_AMF_UE_NGAP_ID(amf_ue_ngap_id);
    add_pdu_handover_req_ack_ie(ngapPDUHandoverRequestAcknowledge, ie);

	//Ngap_AMF_UE_NGAP_ID_t
    uint32_t  ran_ue_ngap_id = 0x78;
	ie  = make_handover_req_ack_RAN_UE_NGAP_ID(ran_ue_ngap_id);
	add_pdu_handover_req_ack_ie(ngapPDUHandoverRequestAcknowledge, ie);

  
    //PDUSessionResourceAdmittedList
    Ngap_PDUSessionResourceAdmittedItem_t	 *pAdmittedItem  = NULL;
	ie             = make_req_ack_PDUSessionResourceAdmittedList();
	pAdmittedItem  = make_req_ack_PDUSessionResourceAdmittedItem(0x80,"test_ack_admit");
    ASN_SEQUENCE_ADD(&ie->value.choice.PDUSessionResourceAdmittedList.list, pAdmittedItem);
	add_pdu_handover_req_ack_ie(ngapPDUHandoverRequestAcknowledge, ie);

	//PDUSessionResourceFailedToSetupListHOAck
	Ngap_PDUSessionResourceFailedToSetupItemHOAck_t	 *pFailedItem = NULL;
	ie          = make_req_ack_PDUSessionResourceFailedToSetupListHOAck();
	pFailedItem = make_req_ack_PDUSessionResourceFailedToSetupItemHOAck(0x80,"test_ack_failed");
	ASN_SEQUENCE_ADD(&ie->value.choice.PDUSessionResourceFailedToSetupListHOAck.list, pFailedItem);
	add_pdu_handover_req_ack_ie(ngapPDUHandoverRequestAcknowledge, ie);


    //TargetToSource_TransparentContainer
    //Ngap_TargetToSource_TransparentContainer_t	 TargetToSource_TransparentContainer;
    
	ie = make_TargetToSource_TransparentContainer("test_trans_container");
	add_pdu_handover_req_ack_ie(ngapPDUHandoverRequestAcknowledge, ie);
	
	//CriticalityDiagnostics
    ie = make_handover_req_ack_CriticalityDiagnostics();

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
	add_pdu_handover_req_ack_ie(ngapPDUHandoverRequestAcknowledge, ie);
  
	return pdu;
}



int
ngap_amf_handle_ng_pdu_handover_req_ack(
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
    Ngap_HandoverRequestAcknowledge_t             *container = NULL;
    Ngap_HandoverRequestAcknowledgeIEs_t          *ie = NULL;
    Ngap_HandoverRequestAcknowledgeIEs_t          *ie_gnb_name = NULL;

    unsigned  long    amf_ue_ngap_id        = 0;
	uint32_t          ran_ue_ngap_id        = 0;
	uint32_t          handoverType          = 0;

    long	  pDUSessionID = 0;
	char 	  *handoverCommandTransfer = NULL;
	int       pDUFailedSessionResourceModifyResponseTransfer_size  =  0;

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

	container = &pdu->choice.successfulOutcome->value.choice.HandoverRequestAcknowledge;
    
    //AMF_UE_NGAP_ID
    NGAP_FIND_PROTOCOLIE_BY_ID(Ngap_HandoverRequestAcknowledgeIEs_t, ie, container, Ngap_ProtocolIE_ID_id_AMF_UE_NGAP_ID, false);
    if (ie) 
	{  
	    asn_INTEGER2ulong(&ie->value.choice.AMF_UE_NGAP_ID, &amf_ue_ngap_id);
	    printf("amf_ue_ngap_id, 0x%x\n", amf_ue_ngap_id);
    }

    //Ngap_AMF_UE_NGAP_ID_t
    NGAP_FIND_PROTOCOLIE_BY_ID(Ngap_HandoverRequestAcknowledgeIEs_t, ie, container, Ngap_ProtocolIE_ID_id_RAN_UE_NGAP_ID, false);
    if (ie) 
	{  
	    ran_ue_ngap_id = ie->value.choice.RAN_UE_NGAP_ID;
	    printf("ran_ue_ngap_id, 0x%x\n", ran_ue_ngap_id);
    }


   
    //PDUSessionResourceAdmittedList
    NGAP_FIND_PROTOCOLIE_BY_ID(Ngap_HandoverRequestAcknowledgeIEs_t, ie, container, Ngap_ProtocolIE_ID_id_PDUSessionResourceAdmittedList, false);
    if (ie) 
	{ 
	    Ngap_PDUSessionResourceAdmittedList_t	 *AdmittedList_container  =  &ie->value.choice.PDUSessionResourceAdmittedList;
        for (i  = 0;i < AdmittedList_container->list.count; i++)
	    {
            Ngap_PDUSessionResourceAdmittedItem_t *pAdmitItemIes_p = NULL;
            pAdmitItemIes_p = AdmittedList_container->list.array[i];
			
			if(!pAdmitItemIes_p)
			{
				  continue;
        	}
        	
		    pDUSessionID              = pAdmitItemIes_p->pDUSessionID;
	 	    handoverCommandTransfer   = pAdmitItemIes_p->handoverRequestAcknowledgeTransfer.buf;
	        
			printf("PDUSessionResourceAdmittedList, pDUSessionID:0x%x,transfer:%s\n", pDUSessionID, handoverCommandTransfer);

		}
    }

	//PDUSessionResourceFailedToSetupListHOAck
    NGAP_FIND_PROTOCOLIE_BY_ID(Ngap_HandoverRequestAcknowledgeIEs_t, ie, container, Ngap_ProtocolIE_ID_id_PDUSessionResourceFailedToSetupListHOAck, false);
    if (ie) 
	{ 
	    Ngap_PDUSessionResourceFailedToSetupListHOAck_t	 *failedList_container  =  &ie->value.choice.PDUSessionResourceFailedToSetupListHOAck;
        for (i  = 0;i < failedList_container->list.count; i++)
	    {
            Ngap_PDUSessionResourceFailedToSetupItemHOAck_t *pfailedItemIes_p = NULL;
            pfailedItemIes_p = failedList_container->list.array[i];
			
			if(!pfailedItemIes_p)
			{
				  continue;
        	}
        	
		    pDUSessionID              = pfailedItemIes_p->pDUSessionID;
	 	    handoverCommandTransfer   = pfailedItemIes_p->handoverResourceAllocationUnsuccessfulTransfer.buf;
	        
			printf("PDUSessionResourceFailedList, pDUSessionID:0x%x,transfer:%s\n", pDUSessionID, handoverCommandTransfer);

		}
    }
	
    
    //TargetToSource_TransparentContainer
    NGAP_FIND_PROTOCOLIE_BY_ID(Ngap_HandoverRequestAcknowledgeIEs_t, ie, container, Ngap_ProtocolIE_ID_id_TargetToSource_TransparentContainer, false);
	if (ie) 
	{  
		printf("TargetToSource_TransparentContainer:%s\n", ie->value.choice.TargetToSource_TransparentContainer.buf);
	}
	
	
	//CriticalityDiagnostics
    NGAP_FIND_PROTOCOLIE_BY_ID(Ngap_HandoverRequestAcknowledgeIEs_t, ie, container, Ngap_ProtocolIE_ID_id_CriticalityDiagnostics, false);
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


int  make_NGAP_PduHandOver_Req_Ack(const char *inputBuf, const char *OutputBuf)
{

    printf("pdu handover req ack, start--------------------\n\n");

    int ret = 0;
	int rc  = RETURNok;
	const sctp_assoc_id_t assoc_id  = 0;
    const sctp_stream_id_t stream   = 0;
	Ngap_NGAP_PDU_t  message = {0};

	//wys:  1024 ?
	size_t buffer_size = 1024;  
	void *buffer = calloc(1,buffer_size);
	asn_enc_rval_t er;	
	
	Ngap_NGAP_PDU_t * pdu =  ngap_generate_ng_handover_req_ack(inputBuf);
	if(!pdu)
		goto ERROR;

    asn_fprint(stderr, &asn_DEF_Ngap_NGAP_PDU, pdu);

    ret  =  check_NGAP_pdu_constraints(pdu);
    if(ret < 0) 
	{
		printf("ng pdu handover req ack Constraint validation  failed\n");
		rc = RETURNerror;
		goto ERROR; 
	}

	//encode
	er = aper_encode_to_buffer(&asn_DEF_Ngap_NGAP_PDU, NULL, pdu, buffer, buffer_size);
	if(er.encoded < 0)
	{
		printf("ng pdu handover req ack encode failed,er.encoded:%d\n",er.encoded);
		rc = RETURNerror;
		goto ERROR; 
	}
  		 
	bstring msgBuf = blk2bstr(buffer, er.encoded);

    //decode
    ngap_amf_decode_pdu(&message, msgBuf);
	ngap_amf_handle_ng_pdu_handover_req_ack(0,0, &message);

    //Free pdu
    if(pdu)
       ASN_STRUCT_FREE(asn_DEF_Ngap_NGAP_PDU, pdu);
    
	if(buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	
	printf("pdu handover req ack, finish--------------------\n\n");
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



