/**
* Nsmf_PDUSession
* SMF PDU Session Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
*
* The version of the OpenAPI document: 1.1.0.alpha-1
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/
/*
 * PduSessionCreateData.h
 *
 * 
 */

#ifndef PduSessionCreateData_H_
#define PduSessionCreateData_H_


#include "RatType.h"
#include "RefToBinaryData.h"
#include <string>
#include "PlmnId.h"
#include "Snssai.h"
#include <vector>
#include "AccessType.h"
#include "DnnSelectionMode.h"
#include "EpsInterworkingIndication.h"
#include "UserLocation.h"
#include "RoamingChargingProfile.h"
#include "RequestType.h"
#include "TunnelInfo.h"
#include "Guami.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
/// 
/// </summary>
class  PduSessionCreateData
{
public:
    PduSessionCreateData();
    virtual ~PduSessionCreateData();

    void validate();

    /////////////////////////////////////////////
    /// PduSessionCreateData members

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
    bool isUnauthenticatedSupi() const;
    void setUnauthenticatedSupi(bool const value);
    bool unauthenticatedSupiIsSet() const;
    void unsetUnauthenticatedSupi();
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
    int32_t getPduSessionId() const;
    void setPduSessionId(int32_t const value);
    bool pduSessionIdIsSet() const;
    void unsetPduSessionId();
    /// <summary>
    /// 
    /// </summary>
    std::string getDnn() const;
    void setDnn(std::string const& value);
        /// <summary>
    /// 
    /// </summary>
    Snssai getSNssai() const;
    void setSNssai(Snssai const& value);
    bool sNssaiIsSet() const;
    void unsetSNssai();
    /// <summary>
    /// 
    /// </summary>
    std::string getVsmfId() const;
    void setVsmfId(std::string const& value);
        /// <summary>
    /// 
    /// </summary>
    PlmnId getServingNetwork() const;
    void setServingNetwork(PlmnId const& value);
        /// <summary>
    /// 
    /// </summary>
    RequestType getRequestType() const;
    void setRequestType(RequestType const& value);
    bool requestTypeIsSet() const;
    void unsetRequestType();
    /// <summary>
    /// 
    /// </summary>
    std::vector<int32_t>& getEpsBearerId();
    bool epsBearerIdIsSet() const;
    void unsetEpsBearerId();
    /// <summary>
    /// 
    /// </summary>
    std::string getPgwS8cFteid() const;
    void setPgwS8cFteid(std::string const& value);
    bool pgwS8cFteidIsSet() const;
    void unsetPgwS8cFteid();
    /// <summary>
    /// 
    /// </summary>
    std::string getVsmfPduSessionUri() const;
    void setVsmfPduSessionUri(std::string const& value);
        /// <summary>
    /// 
    /// </summary>
    TunnelInfo getVcnTunnelInfo() const;
    void setVcnTunnelInfo(TunnelInfo const& value);
    bool vcnTunnelInfoIsSet() const;
    void unsetVcnTunnelInfo();
    /// <summary>
    /// 
    /// </summary>
    AccessType getAnType() const;
    void setAnType(AccessType const& value);
        /// <summary>
    /// 
    /// </summary>
    AccessType getSecondAnType() const;
    void setSecondAnType(AccessType const& value);
    bool secondAnTypeIsSet() const;
    void unsetSecondAnType();
    /// <summary>
    /// 
    /// </summary>
    RatType getRatType() const;
    void setRatType(RatType const& value);
    bool ratTypeIsSet() const;
    void unsetRatType();
    /// <summary>
    /// 
    /// </summary>
    UserLocation getUeLocation() const;
    void setUeLocation(UserLocation const& value);
    bool ueLocationIsSet() const;
    void unsetUeLocation();
    /// <summary>
    /// 
    /// </summary>
    std::string getUeTimeZone() const;
    void setUeTimeZone(std::string const& value);
    bool ueTimeZoneIsSet() const;
    void unsetUeTimeZone();
    /// <summary>
    /// 
    /// </summary>
    UserLocation getAddUeLocation() const;
    void setAddUeLocation(UserLocation const& value);
    bool addUeLocationIsSet() const;
    void unsetAddUeLocation();
    /// <summary>
    /// 
    /// </summary>
    std::string getGpsi() const;
    void setGpsi(std::string const& value);
    bool gpsiIsSet() const;
    void unsetGpsi();
    /// <summary>
    /// 
    /// </summary>
    RefToBinaryData getN1SmInfoFromUe() const;
    void setN1SmInfoFromUe(RefToBinaryData const& value);
    bool n1SmInfoFromUeIsSet() const;
    void unsetN1SmInfoFromUe();
    /// <summary>
    /// 
    /// </summary>
    RefToBinaryData getUnknownN1SmInfo() const;
    void setUnknownN1SmInfo(RefToBinaryData const& value);
    bool unknownN1SmInfoIsSet() const;
    void unsetUnknownN1SmInfo();
    /// <summary>
    /// 
    /// </summary>
    std::string getSupportedFeatures() const;
    void setSupportedFeatures(std::string const& value);
    bool supportedFeaturesIsSet() const;
    void unsetSupportedFeatures();
    /// <summary>
    /// 
    /// </summary>
    std::string getHPcfId() const;
    void setHPcfId(std::string const& value);
    bool hPcfIdIsSet() const;
    void unsetHPcfId();
    /// <summary>
    /// 
    /// </summary>
    bool isHoPreparationIndication() const;
    void setHoPreparationIndication(bool const value);
    bool hoPreparationIndicationIsSet() const;
    void unsetHoPreparationIndication();
    /// <summary>
    /// 
    /// </summary>
    DnnSelectionMode getSelMode() const;
    void setSelMode(DnnSelectionMode const& value);
    bool selModeIsSet() const;
    void unsetSelMode();
    /// <summary>
    /// 
    /// </summary>
    bool isAlwaysOnRequested() const;
    void setAlwaysOnRequested(bool const value);
    bool alwaysOnRequestedIsSet() const;
    void unsetAlwaysOnRequested();
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
    std::string getRoutingIndicator() const;
    void setRoutingIndicator(std::string const& value);
    bool routingIndicatorIsSet() const;
    void unsetRoutingIndicator();
    /// <summary>
    /// 
    /// </summary>
    EpsInterworkingIndication getEpsInterworkingInd() const;
    void setEpsInterworkingInd(EpsInterworkingIndication const& value);
    bool epsInterworkingIndIsSet() const;
    void unsetEpsInterworkingInd();
    /// <summary>
    /// 
    /// </summary>
    std::string getVSmfServiceInstanceId() const;
    void setVSmfServiceInstanceId(std::string const& value);
    bool vSmfServiceInstanceIdIsSet() const;
    void unsetVSmfServiceInstanceId();
    /// <summary>
    /// 
    /// </summary>
    std::string getRecoveryTime() const;
    void setRecoveryTime(std::string const& value);
    bool recoveryTimeIsSet() const;
    void unsetRecoveryTime();
    /// <summary>
    /// 
    /// </summary>
    RoamingChargingProfile getRoamingChargingProfile() const;
    void setRoamingChargingProfile(RoamingChargingProfile const& value);
    bool roamingChargingProfileIsSet() const;
    void unsetRoamingChargingProfile();
    /// <summary>
    /// 
    /// </summary>
    std::string getChargingId() const;
    void setChargingId(std::string const& value);
    bool chargingIdIsSet() const;
    void unsetChargingId();
    /// <summary>
    /// 
    /// </summary>
    int32_t getOldPduSessionId() const;
    void setOldPduSessionId(int32_t const value);
    bool oldPduSessionIdIsSet() const;
    void unsetOldPduSessionId();
    /// <summary>
    /// 
    /// </summary>
    std::string getEpsBearerCtxStatus() const;
    void setEpsBearerCtxStatus(std::string const& value);
    bool epsBearerCtxStatusIsSet() const;
    void unsetEpsBearerCtxStatus();
    /// <summary>
    /// 
    /// </summary>
    std::string getAmfNfId() const;
    void setAmfNfId(std::string const& value);
    bool amfNfIdIsSet() const;
    void unsetAmfNfId();
    /// <summary>
    /// 
    /// </summary>
    Guami getGuami() const;
    void setGuami(Guami const& value);
    bool guamiIsSet() const;
    void unsetGuami();
    /// <summary>
    /// 
    /// </summary>
    bool isCpCiotEnabled() const;
    void setCpCiotEnabled(bool const value);
    bool cpCiotEnabledIsSet() const;
    void unsetCpCiotEnabled();
    /// <summary>
    /// 
    /// </summary>
    bool isInvokeNef() const;
    void setInvokeNef(bool const value);
    bool invokeNefIsSet() const;
    void unsetInvokeNef();
    /// <summary>
    /// 
    /// </summary>
    bool isMaPduIndication() const;
    void setMaPduIndication(bool const value);
    bool maPduIndicationIsSet() const;
    void unsetMaPduIndication();

    friend void to_json(nlohmann::json& j, const PduSessionCreateData& o);
    friend void from_json(const nlohmann::json& j, PduSessionCreateData& o);
protected:
    std::string m_Supi;
    bool m_SupiIsSet;
    bool m_UnauthenticatedSupi;
    bool m_UnauthenticatedSupiIsSet;
    std::string m_Pei;
    bool m_PeiIsSet;
    int32_t m_PduSessionId;
    bool m_PduSessionIdIsSet;
    std::string m_Dnn;

    Snssai m_SNssai;
    bool m_SNssaiIsSet;
    std::string m_VsmfId;

    PlmnId m_ServingNetwork;

    RequestType m_RequestType;
    bool m_RequestTypeIsSet;
    std::vector<int32_t> m_EpsBearerId;
    bool m_EpsBearerIdIsSet;
    std::string m_PgwS8cFteid;
    bool m_PgwS8cFteidIsSet;
    std::string m_VsmfPduSessionUri;

    TunnelInfo m_VcnTunnelInfo;
    bool m_VcnTunnelInfoIsSet;
    AccessType m_AnType;

    AccessType m_SecondAnType;
    bool m_SecondAnTypeIsSet;
    RatType m_RatType;
    bool m_RatTypeIsSet;
    UserLocation m_UeLocation;
    bool m_UeLocationIsSet;
    std::string m_UeTimeZone;
    bool m_UeTimeZoneIsSet;
    UserLocation m_AddUeLocation;
    bool m_AddUeLocationIsSet;
    std::string m_Gpsi;
    bool m_GpsiIsSet;
    RefToBinaryData m_N1SmInfoFromUe;
    bool m_N1SmInfoFromUeIsSet;
    RefToBinaryData m_UnknownN1SmInfo;
    bool m_UnknownN1SmInfoIsSet;
    std::string m_SupportedFeatures;
    bool m_SupportedFeaturesIsSet;
    std::string m_HPcfId;
    bool m_HPcfIdIsSet;
    bool m_HoPreparationIndication;
    bool m_HoPreparationIndicationIsSet;
    DnnSelectionMode m_SelMode;
    bool m_SelModeIsSet;
    bool m_AlwaysOnRequested;
    bool m_AlwaysOnRequestedIsSet;
    std::string m_UdmGroupId;
    bool m_UdmGroupIdIsSet;
    std::string m_RoutingIndicator;
    bool m_RoutingIndicatorIsSet;
    EpsInterworkingIndication m_EpsInterworkingInd;
    bool m_EpsInterworkingIndIsSet;
    std::string m_VSmfServiceInstanceId;
    bool m_VSmfServiceInstanceIdIsSet;
    std::string m_RecoveryTime;
    bool m_RecoveryTimeIsSet;
    RoamingChargingProfile m_RoamingChargingProfile;
    bool m_RoamingChargingProfileIsSet;
    std::string m_ChargingId;
    bool m_ChargingIdIsSet;
    int32_t m_OldPduSessionId;
    bool m_OldPduSessionIdIsSet;
    std::string m_EpsBearerCtxStatus;
    bool m_EpsBearerCtxStatusIsSet;
    std::string m_AmfNfId;
    bool m_AmfNfIdIsSet;
    Guami m_Guami;
    bool m_GuamiIsSet;
    bool m_CpCiotEnabled;
    bool m_CpCiotEnabledIsSet;
    bool m_InvokeNef;
    bool m_InvokeNefIsSet;
    bool m_MaPduIndication;
    bool m_MaPduIndicationIsSet;
};

}
}
}

#endif /* PduSessionCreateData_H_ */
