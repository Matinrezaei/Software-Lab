/**
* Namf_Communication
* AMF Communication Service © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
*
* The version of the OpenAPI document: 1.1.0.alpha-1
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/
/*
 * UeContext.h
 *
 * 
 */

#ifndef UeContext_H_
#define UeContext_H_


#include "Ambr.h"
#include "CoreNetworkType.h"
#include "Area.h"
#include "RatType.h"
#include <string>
#include "TraceData.h"
#include <vector>
#include "SeafData.h"
#include "PolicyReqTrigger.h"
#include "SmsSupport.h"
#include "PduSessionContext.h"
#include "ServiceAreaRestriction.h"
#include "AmfEventSubscription.h"
#include "MmContext.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace amf {
namespace model {

/// <summary>
/// 
/// </summary>
class  UeContext
{
public:
    UeContext();
    virtual ~UeContext();

    void validate();

    /////////////////////////////////////////////
    /// UeContext members

    /// <summary>
    /// 
    /// </summary>
    std::string getSupi() const;
    void setSupi(std::string const& value);
    bool supiIsSet() const;
    void unsetSupi();
    /// <summary>
    /// 
    /// </summary>
    bool isSupiUnauthInd() const;
    void setSupiUnauthInd(bool const value);
    bool supiUnauthIndIsSet() const;
    void unsetSupiUnauthInd();
    /// <summary>
    /// 
    /// </summary>
    std::vector<std::string>& getGpsiList();
    bool gpsiListIsSet() const;
    void unsetGpsiList();
    /// <summary>
    /// 
    /// </summary>
    std::string getPei() const;
    void setPei(std::string const& value);
    bool peiIsSet() const;
    void unsetPei();
    /// <summary>
    /// 
    /// </summary>
    std::string getUdmGroupId() const;
    void setUdmGroupId(std::string const& value);
    bool udmGroupIdIsSet() const;
    void unsetUdmGroupId();
    /// <summary>
    /// 
    /// </summary>
    std::string getAusfGroupId() const;
    void setAusfGroupId(std::string const& value);
    bool ausfGroupIdIsSet() const;
    void unsetAusfGroupId();
    /// <summary>
    /// 
    /// </summary>
    std::string getRoutingIndicator() const;
    void setRoutingIndicator(std::string const& value);
    bool routingIndicatorIsSet() const;
    void unsetRoutingIndicator();
    /// <summary>
    /// 
    /// </summary>
    std::vector<std::string>& getGroupList();
    bool groupListIsSet() const;
    void unsetGroupList();
    /// <summary>
    /// 
    /// </summary>
    std::string getDrxParameter() const;
    void setDrxParameter(std::string const& value);
    bool drxParameterIsSet() const;
    void unsetDrxParameter();
    /// <summary>
    /// 
    /// </summary>
    int32_t getSubRfsp() const;
    void setSubRfsp(int32_t const value);
    bool subRfspIsSet() const;
    void unsetSubRfsp();
    /// <summary>
    /// 
    /// </summary>
    int32_t getUsedRfsp() const;
    void setUsedRfsp(int32_t const value);
    bool usedRfspIsSet() const;
    void unsetUsedRfsp();
    /// <summary>
    /// 
    /// </summary>
    Ambr getSubUeAmbr() const;
    void setSubUeAmbr(Ambr const& value);
    bool subUeAmbrIsSet() const;
    void unsetSubUeAmbr();
    /// <summary>
    /// 
    /// </summary>
    SmsSupport getSmsSupport() const;
    void setSmsSupport(SmsSupport const& value);
    bool smsSupportIsSet() const;
    void unsetSmsSupport();
    /// <summary>
    /// 
    /// </summary>
    std::string getSmsfId() const;
    void setSmsfId(std::string const& value);
    bool smsfIdIsSet() const;
    void unsetSmsfId();
    /// <summary>
    /// 
    /// </summary>
    SeafData getSeafData() const;
    void setSeafData(SeafData const& value);
    bool seafDataIsSet() const;
    void unsetSeafData();
    /// <summary>
    /// 
    /// </summary>
    std::string get5gMmCapability() const;
    void set5gMmCapability(std::string const& value);
    bool _5gMmCapabilityIsSet() const;
    void unset_5gMmCapability();
    /// <summary>
    /// 
    /// </summary>
    std::string getPcfId() const;
    void setPcfId(std::string const& value);
    bool pcfIdIsSet() const;
    void unsetPcfId();
    /// <summary>
    /// 
    /// </summary>
    std::string getPcfAmPolicyUri() const;
    void setPcfAmPolicyUri(std::string const& value);
    bool pcfAmPolicyUriIsSet() const;
    void unsetPcfAmPolicyUri();
    /// <summary>
    /// 
    /// </summary>
    std::vector<PolicyReqTrigger>& getAmPolicyReqTriggerList();
    bool amPolicyReqTriggerListIsSet() const;
    void unsetAmPolicyReqTriggerList();
    /// <summary>
    /// 
    /// </summary>
    std::string getPcfUePolicyUri() const;
    void setPcfUePolicyUri(std::string const& value);
    bool pcfUePolicyUriIsSet() const;
    void unsetPcfUePolicyUri();
    /// <summary>
    /// 
    /// </summary>
    std::vector<PolicyReqTrigger>& getUePolicyReqTriggerList();
    bool uePolicyReqTriggerListIsSet() const;
    void unsetUePolicyReqTriggerList();
    /// <summary>
    /// 
    /// </summary>
    std::string getHpcfId() const;
    void setHpcfId(std::string const& value);
    bool hpcfIdIsSet() const;
    void unsetHpcfId();
    /// <summary>
    /// 
    /// </summary>
    std::vector<RatType>& getRestrictedRatList();
    bool restrictedRatListIsSet() const;
    void unsetRestrictedRatList();
    /// <summary>
    /// 
    /// </summary>
    std::vector<Area>& getForbiddenAreaList();
    bool forbiddenAreaListIsSet() const;
    void unsetForbiddenAreaList();
    /// <summary>
    /// 
    /// </summary>
    ServiceAreaRestriction getServiceAreaRestriction() const;
    void setServiceAreaRestriction(ServiceAreaRestriction const& value);
    bool serviceAreaRestrictionIsSet() const;
    void unsetServiceAreaRestriction();
    /// <summary>
    /// 
    /// </summary>
    std::vector<CoreNetworkType>& getRestrictedCoreNwTypeList();
    bool restrictedCoreNwTypeListIsSet() const;
    void unsetRestrictedCoreNwTypeList();
    /// <summary>
    /// 
    /// </summary>
    std::vector<AmfEventSubscription>& getEventSubscriptionList();
    bool eventSubscriptionListIsSet() const;
    void unsetEventSubscriptionList();
    /// <summary>
    /// 
    /// </summary>
    std::vector<MmContext>& getMmContextList();
    bool mmContextListIsSet() const;
    void unsetMmContextList();
    /// <summary>
    /// 
    /// </summary>
    std::vector<PduSessionContext>& getSessionContextList();
    bool sessionContextListIsSet() const;
    void unsetSessionContextList();
    /// <summary>
    /// 
    /// </summary>
    TraceData getTraceData() const;
    void setTraceData(TraceData const& value);
    bool traceDataIsSet() const;
    void unsetTraceData();
    /// <summary>
    /// 
    /// </summary>
    int32_t getRemainingServiceGapTimer() const;
    void setRemainingServiceGapTimer(int32_t const value);
    bool remainingServiceGapTimerIsSet() const;
    void unsetRemainingServiceGapTimer();

    friend void to_json(nlohmann::json& j, const UeContext& o);
    friend void from_json(const nlohmann::json& j, UeContext& o);
protected:
    std::string m_Supi;
    bool m_SupiIsSet;
    bool m_SupiUnauthInd;
    bool m_SupiUnauthIndIsSet;
    std::vector<std::string> m_GpsiList;
    bool m_GpsiListIsSet;
    std::string m_Pei;
    bool m_PeiIsSet;
    std::string m_UdmGroupId;
    bool m_UdmGroupIdIsSet;
    std::string m_AusfGroupId;
    bool m_AusfGroupIdIsSet;
    std::string m_RoutingIndicator;
    bool m_RoutingIndicatorIsSet;
    std::vector<std::string> m_GroupList;
    bool m_GroupListIsSet;
    std::string m_DrxParameter;
    bool m_DrxParameterIsSet;
    int32_t m_SubRfsp;
    bool m_SubRfspIsSet;
    int32_t m_UsedRfsp;
    bool m_UsedRfspIsSet;
    Ambr m_SubUeAmbr;
    bool m_SubUeAmbrIsSet;
    SmsSupport m_SmsSupport;
    bool m_SmsSupportIsSet;
    std::string m_SmsfId;
    bool m_SmsfIdIsSet;
    SeafData m_SeafData;
    bool m_SeafDataIsSet;
    std::string m__5gMmCapability;
    bool m__5gMmCapabilityIsSet;
    std::string m_PcfId;
    bool m_PcfIdIsSet;
    std::string m_PcfAmPolicyUri;
    bool m_PcfAmPolicyUriIsSet;
    std::vector<PolicyReqTrigger> m_AmPolicyReqTriggerList;
    bool m_AmPolicyReqTriggerListIsSet;
    std::string m_PcfUePolicyUri;
    bool m_PcfUePolicyUriIsSet;
    std::vector<PolicyReqTrigger> m_UePolicyReqTriggerList;
    bool m_UePolicyReqTriggerListIsSet;
    std::string m_HpcfId;
    bool m_HpcfIdIsSet;
    std::vector<RatType> m_RestrictedRatList;
    bool m_RestrictedRatListIsSet;
    std::vector<Area> m_ForbiddenAreaList;
    bool m_ForbiddenAreaListIsSet;
    ServiceAreaRestriction m_ServiceAreaRestriction;
    bool m_ServiceAreaRestrictionIsSet;
    std::vector<CoreNetworkType> m_RestrictedCoreNwTypeList;
    bool m_RestrictedCoreNwTypeListIsSet;
    std::vector<AmfEventSubscription> m_EventSubscriptionList;
    bool m_EventSubscriptionListIsSet;
    std::vector<MmContext> m_MmContextList;
    bool m_MmContextListIsSet;
    std::vector<PduSessionContext> m_SessionContextList;
    bool m_SessionContextListIsSet;
    TraceData m_TraceData;
    bool m_TraceDataIsSet;
    int32_t m_RemainingServiceGapTimer;
    bool m_RemainingServiceGapTimerIsSet;
};

}
}
}

#endif /* UeContext_H_ */
