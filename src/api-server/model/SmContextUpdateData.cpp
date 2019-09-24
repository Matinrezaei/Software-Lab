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


#include "SmContextUpdateData.h"

namespace oai {
namespace smf {
namespace model {

SmContextUpdateData::SmContextUpdateData()
{
    m_Pei = "";
    m_PeiIsSet = false;
    m_ServingNfId = "";
    m_ServingNfIdIsSet = false;
    m_GuamiIsSet = false;
    m_ServingNetworkIsSet = false;
    m_BackupAmfInfoIsSet = false;
    m_AnTypeIsSet = false;
    m_SecondAnTypeIsSet = false;
    m_RatTypeIsSet = false;
    m_PresenceInLadnIsSet = false;
    m_UeLocationIsSet = false;
    m_UeTimeZone = "";
    m_UeTimeZoneIsSet = false;
    m_AddUeLocationIsSet = false;
    m_UpCnxStateIsSet = false;
    m_HoStateIsSet = false;
    m_ToBeSwitched = false;
    m_ToBeSwitchedIsSet = false;
    m_FailedToBeSwitched = false;
    m_FailedToBeSwitchedIsSet = false;
    m_N1SmMsgIsSet = false;
    m_N2SmInfoIsSet = false;
    m_N2SmInfoTypeIsSet = false;
    m_TargetIdIsSet = false;
    m_TargetServingNfId = "";
    m_TargetServingNfIdIsSet = false;
    m_SmContextStatusUri = "";
    m_SmContextStatusUriIsSet = false;
    m_DataForwarding = false;
    m_DataForwardingIsSet = false;
    m_EpsBearerSetupIsSet = false;
    m_RevokeEbiListIsSet = false;
    m_Release = false;
    m_ReleaseIsSet = false;
    m_CauseIsSet = false;
    m_NgApCauseIsSet = false;
    m__5gMmCauseValue = 0;
    m__5gMmCauseValueIsSet = false;
    m_SNssaiIsSet = false;
    m_TraceDataIsSet = false;
    m_EpsInterworkingIndIsSet = false;
    m_AnTypeCanBeChanged = false;
    m_AnTypeCanBeChangedIsSet = false;
    m_N2SmInfoExt1IsSet = false;
    m_N2SmInfoTypeExt1IsSet = false;
    m_MaReleaseIndIsSet = false;
    m_ExemptionIndIsSet = false;
    
}

SmContextUpdateData::~SmContextUpdateData()
{
}

void SmContextUpdateData::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const SmContextUpdateData& o)
{
    j = nlohmann::json();
    if(o.peiIsSet())
        j["pei"] = o.m_Pei;
    if(o.servingNfIdIsSet())
        j["servingNfId"] = o.m_ServingNfId;
    if(o.guamiIsSet())
        j["guami"] = o.m_Guami;
    if(o.servingNetworkIsSet())
        j["servingNetwork"] = o.m_ServingNetwork;
    if(o.backupAmfInfoIsSet())
        j["backupAmfInfo"] = o.m_BackupAmfInfo;
    if(o.anTypeIsSet())
        j["anType"] = o.m_AnType;
    if(o.secondAnTypeIsSet())
        j["secondAnType"] = o.m_SecondAnType;
    if(o.ratTypeIsSet())
        j["ratType"] = o.m_RatType;
    if(o.presenceInLadnIsSet())
        j["presenceInLadn"] = o.m_PresenceInLadn;
    if(o.ueLocationIsSet())
        j["ueLocation"] = o.m_UeLocation;
    if(o.ueTimeZoneIsSet())
        j["ueTimeZone"] = o.m_UeTimeZone;
    if(o.addUeLocationIsSet())
        j["addUeLocation"] = o.m_AddUeLocation;
    if(o.upCnxStateIsSet())
        j["upCnxState"] = o.m_UpCnxState;
    if(o.hoStateIsSet())
        j["hoState"] = o.m_HoState;
    if(o.toBeSwitchedIsSet())
        j["toBeSwitched"] = o.m_ToBeSwitched;
    if(o.failedToBeSwitchedIsSet())
        j["failedToBeSwitched"] = o.m_FailedToBeSwitched;
    if(o.n1SmMsgIsSet())
        j["n1SmMsg"] = o.m_N1SmMsg;
    if(o.n2SmInfoIsSet())
        j["n2SmInfo"] = o.m_N2SmInfo;
    if(o.n2SmInfoTypeIsSet())
        j["n2SmInfoType"] = o.m_N2SmInfoType;
    if(o.targetIdIsSet())
        j["targetId"] = o.m_TargetId;
    if(o.targetServingNfIdIsSet())
        j["targetServingNfId"] = o.m_TargetServingNfId;
    if(o.smContextStatusUriIsSet())
        j["smContextStatusUri"] = o.m_SmContextStatusUri;
    if(o.dataForwardingIsSet())
        j["dataForwarding"] = o.m_DataForwarding;
    if(o.epsBearerSetupIsSet())
        j["epsBearerSetup"] = o.m_EpsBearerSetup;
    if(o.revokeEbiListIsSet())
        j["revokeEbiList"] = o.m_RevokeEbiList;
    if(o.releaseIsSet())
        j["release"] = o.m_Release;
    if(o.causeIsSet())
        j["cause"] = o.m_Cause;
    if(o.ngApCauseIsSet())
        j["ngApCause"] = o.m_NgApCause;
    if(o._5gMmCauseValueIsSet())
        j["5gMmCauseValue"] = o.m__5gMmCauseValue;
    if(o.sNssaiIsSet())
        j["sNssai"] = o.m_SNssai;
    if(o.traceDataIsSet())
        j["traceData"] = o.m_TraceData;
    if(o.epsInterworkingIndIsSet())
        j["epsInterworkingInd"] = o.m_EpsInterworkingInd;
    if(o.anTypeCanBeChangedIsSet())
        j["anTypeCanBeChanged"] = o.m_AnTypeCanBeChanged;
    if(o.n2SmInfoExt1IsSet())
        j["n2SmInfoExt1"] = o.m_N2SmInfoExt1;
    if(o.n2SmInfoTypeExt1IsSet())
        j["n2SmInfoTypeExt1"] = o.m_N2SmInfoTypeExt1;
    if(o.maReleaseIndIsSet())
        j["maReleaseInd"] = o.m_MaReleaseInd;
    if(o.exemptionIndIsSet())
        j["exemptionInd"] = o.m_ExemptionInd;
}

void from_json(const nlohmann::json& j, SmContextUpdateData& o)
{
    if(j.find("pei") != j.end())
    {
        j.at("pei").get_to(o.m_Pei);
        o.m_PeiIsSet = true;
    } 
    if(j.find("servingNfId") != j.end())
    {
        j.at("servingNfId").get_to(o.m_ServingNfId);
        o.m_ServingNfIdIsSet = true;
    } 
    if(j.find("guami") != j.end())
    {
        j.at("guami").get_to(o.m_Guami);
        o.m_GuamiIsSet = true;
    } 
    if(j.find("servingNetwork") != j.end())
    {
        j.at("servingNetwork").get_to(o.m_ServingNetwork);
        o.m_ServingNetworkIsSet = true;
    } 
    if(j.find("backupAmfInfo") != j.end())
    {
        j.at("backupAmfInfo").get_to(o.m_BackupAmfInfo);
        o.m_BackupAmfInfoIsSet = true;
    } 
    if(j.find("anType") != j.end())
    {
        j.at("anType").get_to(o.m_AnType);
        o.m_AnTypeIsSet = true;
    } 
    if(j.find("secondAnType") != j.end())
    {
        j.at("secondAnType").get_to(o.m_SecondAnType);
        o.m_SecondAnTypeIsSet = true;
    } 
    if(j.find("ratType") != j.end())
    {
        j.at("ratType").get_to(o.m_RatType);
        o.m_RatTypeIsSet = true;
    } 
    if(j.find("presenceInLadn") != j.end())
    {
        j.at("presenceInLadn").get_to(o.m_PresenceInLadn);
        o.m_PresenceInLadnIsSet = true;
    } 
    if(j.find("ueLocation") != j.end())
    {
        j.at("ueLocation").get_to(o.m_UeLocation);
        o.m_UeLocationIsSet = true;
    } 
    if(j.find("ueTimeZone") != j.end())
    {
        j.at("ueTimeZone").get_to(o.m_UeTimeZone);
        o.m_UeTimeZoneIsSet = true;
    } 
    if(j.find("addUeLocation") != j.end())
    {
        j.at("addUeLocation").get_to(o.m_AddUeLocation);
        o.m_AddUeLocationIsSet = true;
    } 
    if(j.find("upCnxState") != j.end())
    {
        j.at("upCnxState").get_to(o.m_UpCnxState);
        o.m_UpCnxStateIsSet = true;
    } 
    if(j.find("hoState") != j.end())
    {
        j.at("hoState").get_to(o.m_HoState);
        o.m_HoStateIsSet = true;
    } 
    if(j.find("toBeSwitched") != j.end())
    {
        j.at("toBeSwitched").get_to(o.m_ToBeSwitched);
        o.m_ToBeSwitchedIsSet = true;
    } 
    if(j.find("failedToBeSwitched") != j.end())
    {
        j.at("failedToBeSwitched").get_to(o.m_FailedToBeSwitched);
        o.m_FailedToBeSwitchedIsSet = true;
    } 
    if(j.find("n1SmMsg") != j.end())
    {
        j.at("n1SmMsg").get_to(o.m_N1SmMsg);
        o.m_N1SmMsgIsSet = true;
    } 
    if(j.find("n2SmInfo") != j.end())
    {
        j.at("n2SmInfo").get_to(o.m_N2SmInfo);
        o.m_N2SmInfoIsSet = true;
    } 
    if(j.find("n2SmInfoType") != j.end())
    {
        j.at("n2SmInfoType").get_to(o.m_N2SmInfoType);
        o.m_N2SmInfoTypeIsSet = true;
    } 
    if(j.find("targetId") != j.end())
    {
        j.at("targetId").get_to(o.m_TargetId);
        o.m_TargetIdIsSet = true;
    } 
    if(j.find("targetServingNfId") != j.end())
    {
        j.at("targetServingNfId").get_to(o.m_TargetServingNfId);
        o.m_TargetServingNfIdIsSet = true;
    } 
    if(j.find("smContextStatusUri") != j.end())
    {
        j.at("smContextStatusUri").get_to(o.m_SmContextStatusUri);
        o.m_SmContextStatusUriIsSet = true;
    } 
    if(j.find("dataForwarding") != j.end())
    {
        j.at("dataForwarding").get_to(o.m_DataForwarding);
        o.m_DataForwardingIsSet = true;
    } 
    if(j.find("epsBearerSetup") != j.end())
    {
        j.at("epsBearerSetup").get_to(o.m_EpsBearerSetup);
        o.m_EpsBearerSetupIsSet = true;
    } 
    if(j.find("revokeEbiList") != j.end())
    {
        j.at("revokeEbiList").get_to(o.m_RevokeEbiList);
        o.m_RevokeEbiListIsSet = true;
    } 
    if(j.find("release") != j.end())
    {
        j.at("release").get_to(o.m_Release);
        o.m_ReleaseIsSet = true;
    } 
    if(j.find("cause") != j.end())
    {
        j.at("cause").get_to(o.m_Cause);
        o.m_CauseIsSet = true;
    } 
    if(j.find("ngApCause") != j.end())
    {
        j.at("ngApCause").get_to(o.m_NgApCause);
        o.m_NgApCauseIsSet = true;
    } 
    if(j.find("5gMmCauseValue") != j.end())
    {
        j.at("5gMmCauseValue").get_to(o.m__5gMmCauseValue);
        o.m__5gMmCauseValueIsSet = true;
    } 
    if(j.find("sNssai") != j.end())
    {
        j.at("sNssai").get_to(o.m_SNssai);
        o.m_SNssaiIsSet = true;
    } 
    if(j.find("traceData") != j.end())
    {
        j.at("traceData").get_to(o.m_TraceData);
        o.m_TraceDataIsSet = true;
    } 
    if(j.find("epsInterworkingInd") != j.end())
    {
        j.at("epsInterworkingInd").get_to(o.m_EpsInterworkingInd);
        o.m_EpsInterworkingIndIsSet = true;
    } 
    if(j.find("anTypeCanBeChanged") != j.end())
    {
        j.at("anTypeCanBeChanged").get_to(o.m_AnTypeCanBeChanged);
        o.m_AnTypeCanBeChangedIsSet = true;
    } 
    if(j.find("n2SmInfoExt1") != j.end())
    {
        j.at("n2SmInfoExt1").get_to(o.m_N2SmInfoExt1);
        o.m_N2SmInfoExt1IsSet = true;
    } 
    if(j.find("n2SmInfoTypeExt1") != j.end())
    {
        j.at("n2SmInfoTypeExt1").get_to(o.m_N2SmInfoTypeExt1);
        o.m_N2SmInfoTypeExt1IsSet = true;
    } 
    if(j.find("maReleaseInd") != j.end())
    {
        j.at("maReleaseInd").get_to(o.m_MaReleaseInd);
        o.m_MaReleaseIndIsSet = true;
    } 
    if(j.find("exemptionInd") != j.end())
    {
        j.at("exemptionInd").get_to(o.m_ExemptionInd);
        o.m_ExemptionIndIsSet = true;
    } 
}

std::string SmContextUpdateData::getPei() const
{
    return m_Pei;
}
void SmContextUpdateData::setPei(std::string const& value)
{
    m_Pei = value;
    m_PeiIsSet = true;
}
bool SmContextUpdateData::peiIsSet() const
{
    return m_PeiIsSet;
}
void SmContextUpdateData::unsetPei()
{
    m_PeiIsSet = false;
}
std::string SmContextUpdateData::getServingNfId() const
{
    return m_ServingNfId;
}
void SmContextUpdateData::setServingNfId(std::string const& value)
{
    m_ServingNfId = value;
    m_ServingNfIdIsSet = true;
}
bool SmContextUpdateData::servingNfIdIsSet() const
{
    return m_ServingNfIdIsSet;
}
void SmContextUpdateData::unsetServingNfId()
{
    m_ServingNfIdIsSet = false;
}
Guami SmContextUpdateData::getGuami() const
{
    return m_Guami;
}
void SmContextUpdateData::setGuami(Guami const& value)
{
    m_Guami = value;
    m_GuamiIsSet = true;
}
bool SmContextUpdateData::guamiIsSet() const
{
    return m_GuamiIsSet;
}
void SmContextUpdateData::unsetGuami()
{
    m_GuamiIsSet = false;
}
PlmnId SmContextUpdateData::getServingNetwork() const
{
    return m_ServingNetwork;
}
void SmContextUpdateData::setServingNetwork(PlmnId const& value)
{
    m_ServingNetwork = value;
    m_ServingNetworkIsSet = true;
}
bool SmContextUpdateData::servingNetworkIsSet() const
{
    return m_ServingNetworkIsSet;
}
void SmContextUpdateData::unsetServingNetwork()
{
    m_ServingNetworkIsSet = false;
}
std::vector<BackupAmfInfo>& SmContextUpdateData::getBackupAmfInfo()
{
    return m_BackupAmfInfo;
}
bool SmContextUpdateData::backupAmfInfoIsSet() const
{
    return m_BackupAmfInfoIsSet;
}
void SmContextUpdateData::unsetBackupAmfInfo()
{
    m_BackupAmfInfoIsSet = false;
}
AccessType SmContextUpdateData::getAnType() const
{
    return m_AnType;
}
void SmContextUpdateData::setAnType(AccessType const& value)
{
    m_AnType = value;
    m_AnTypeIsSet = true;
}
bool SmContextUpdateData::anTypeIsSet() const
{
    return m_AnTypeIsSet;
}
void SmContextUpdateData::unsetAnType()
{
    m_AnTypeIsSet = false;
}
AccessType SmContextUpdateData::getSecondAnType() const
{
    return m_SecondAnType;
}
void SmContextUpdateData::setSecondAnType(AccessType const& value)
{
    m_SecondAnType = value;
    m_SecondAnTypeIsSet = true;
}
bool SmContextUpdateData::secondAnTypeIsSet() const
{
    return m_SecondAnTypeIsSet;
}
void SmContextUpdateData::unsetSecondAnType()
{
    m_SecondAnTypeIsSet = false;
}
RatType SmContextUpdateData::getRatType() const
{
    return m_RatType;
}
void SmContextUpdateData::setRatType(RatType const& value)
{
    m_RatType = value;
    m_RatTypeIsSet = true;
}
bool SmContextUpdateData::ratTypeIsSet() const
{
    return m_RatTypeIsSet;
}
void SmContextUpdateData::unsetRatType()
{
    m_RatTypeIsSet = false;
}
PresenceState SmContextUpdateData::getPresenceInLadn() const
{
    return m_PresenceInLadn;
}
void SmContextUpdateData::setPresenceInLadn(PresenceState const& value)
{
    m_PresenceInLadn = value;
    m_PresenceInLadnIsSet = true;
}
bool SmContextUpdateData::presenceInLadnIsSet() const
{
    return m_PresenceInLadnIsSet;
}
void SmContextUpdateData::unsetPresenceInLadn()
{
    m_PresenceInLadnIsSet = false;
}
UserLocation SmContextUpdateData::getUeLocation() const
{
    return m_UeLocation;
}
void SmContextUpdateData::setUeLocation(UserLocation const& value)
{
    m_UeLocation = value;
    m_UeLocationIsSet = true;
}
bool SmContextUpdateData::ueLocationIsSet() const
{
    return m_UeLocationIsSet;
}
void SmContextUpdateData::unsetUeLocation()
{
    m_UeLocationIsSet = false;
}
std::string SmContextUpdateData::getUeTimeZone() const
{
    return m_UeTimeZone;
}
void SmContextUpdateData::setUeTimeZone(std::string const& value)
{
    m_UeTimeZone = value;
    m_UeTimeZoneIsSet = true;
}
bool SmContextUpdateData::ueTimeZoneIsSet() const
{
    return m_UeTimeZoneIsSet;
}
void SmContextUpdateData::unsetUeTimeZone()
{
    m_UeTimeZoneIsSet = false;
}
UserLocation SmContextUpdateData::getAddUeLocation() const
{
    return m_AddUeLocation;
}
void SmContextUpdateData::setAddUeLocation(UserLocation const& value)
{
    m_AddUeLocation = value;
    m_AddUeLocationIsSet = true;
}
bool SmContextUpdateData::addUeLocationIsSet() const
{
    return m_AddUeLocationIsSet;
}
void SmContextUpdateData::unsetAddUeLocation()
{
    m_AddUeLocationIsSet = false;
}
UpCnxState SmContextUpdateData::getUpCnxState() const
{
    return m_UpCnxState;
}
void SmContextUpdateData::setUpCnxState(UpCnxState const& value)
{
    m_UpCnxState = value;
    m_UpCnxStateIsSet = true;
}
bool SmContextUpdateData::upCnxStateIsSet() const
{
    return m_UpCnxStateIsSet;
}
void SmContextUpdateData::unsetUpCnxState()
{
    m_UpCnxStateIsSet = false;
}
HoState SmContextUpdateData::getHoState() const
{
    return m_HoState;
}
void SmContextUpdateData::setHoState(HoState const& value)
{
    m_HoState = value;
    m_HoStateIsSet = true;
}
bool SmContextUpdateData::hoStateIsSet() const
{
    return m_HoStateIsSet;
}
void SmContextUpdateData::unsetHoState()
{
    m_HoStateIsSet = false;
}
bool SmContextUpdateData::isToBeSwitched() const
{
    return m_ToBeSwitched;
}
void SmContextUpdateData::setToBeSwitched(bool const value)
{
    m_ToBeSwitched = value;
    m_ToBeSwitchedIsSet = true;
}
bool SmContextUpdateData::toBeSwitchedIsSet() const
{
    return m_ToBeSwitchedIsSet;
}
void SmContextUpdateData::unsetToBeSwitched()
{
    m_ToBeSwitchedIsSet = false;
}
bool SmContextUpdateData::isFailedToBeSwitched() const
{
    return m_FailedToBeSwitched;
}
void SmContextUpdateData::setFailedToBeSwitched(bool const value)
{
    m_FailedToBeSwitched = value;
    m_FailedToBeSwitchedIsSet = true;
}
bool SmContextUpdateData::failedToBeSwitchedIsSet() const
{
    return m_FailedToBeSwitchedIsSet;
}
void SmContextUpdateData::unsetFailedToBeSwitched()
{
    m_FailedToBeSwitchedIsSet = false;
}
RefToBinaryData SmContextUpdateData::getN1SmMsg() const
{
    return m_N1SmMsg;
}
void SmContextUpdateData::setN1SmMsg(RefToBinaryData const& value)
{
    m_N1SmMsg = value;
    m_N1SmMsgIsSet = true;
}
bool SmContextUpdateData::n1SmMsgIsSet() const
{
    return m_N1SmMsgIsSet;
}
void SmContextUpdateData::unsetN1SmMsg()
{
    m_N1SmMsgIsSet = false;
}
RefToBinaryData SmContextUpdateData::getN2SmInfo() const
{
    return m_N2SmInfo;
}
void SmContextUpdateData::setN2SmInfo(RefToBinaryData const& value)
{
    m_N2SmInfo = value;
    m_N2SmInfoIsSet = true;
}
bool SmContextUpdateData::n2SmInfoIsSet() const
{
    return m_N2SmInfoIsSet;
}
void SmContextUpdateData::unsetN2SmInfo()
{
    m_N2SmInfoIsSet = false;
}
N2SmInfoType SmContextUpdateData::getN2SmInfoType() const
{
    return m_N2SmInfoType;
}
void SmContextUpdateData::setN2SmInfoType(N2SmInfoType const& value)
{
    m_N2SmInfoType = value;
    m_N2SmInfoTypeIsSet = true;
}
bool SmContextUpdateData::n2SmInfoTypeIsSet() const
{
    return m_N2SmInfoTypeIsSet;
}
void SmContextUpdateData::unsetN2SmInfoType()
{
    m_N2SmInfoTypeIsSet = false;
}
NgRanTargetId SmContextUpdateData::getTargetId() const
{
    return m_TargetId;
}
void SmContextUpdateData::setTargetId(NgRanTargetId const& value)
{
    m_TargetId = value;
    m_TargetIdIsSet = true;
}
bool SmContextUpdateData::targetIdIsSet() const
{
    return m_TargetIdIsSet;
}
void SmContextUpdateData::unsetTargetId()
{
    m_TargetIdIsSet = false;
}
std::string SmContextUpdateData::getTargetServingNfId() const
{
    return m_TargetServingNfId;
}
void SmContextUpdateData::setTargetServingNfId(std::string const& value)
{
    m_TargetServingNfId = value;
    m_TargetServingNfIdIsSet = true;
}
bool SmContextUpdateData::targetServingNfIdIsSet() const
{
    return m_TargetServingNfIdIsSet;
}
void SmContextUpdateData::unsetTargetServingNfId()
{
    m_TargetServingNfIdIsSet = false;
}
std::string SmContextUpdateData::getSmContextStatusUri() const
{
    return m_SmContextStatusUri;
}
void SmContextUpdateData::setSmContextStatusUri(std::string const& value)
{
    m_SmContextStatusUri = value;
    m_SmContextStatusUriIsSet = true;
}
bool SmContextUpdateData::smContextStatusUriIsSet() const
{
    return m_SmContextStatusUriIsSet;
}
void SmContextUpdateData::unsetSmContextStatusUri()
{
    m_SmContextStatusUriIsSet = false;
}
bool SmContextUpdateData::isDataForwarding() const
{
    return m_DataForwarding;
}
void SmContextUpdateData::setDataForwarding(bool const value)
{
    m_DataForwarding = value;
    m_DataForwardingIsSet = true;
}
bool SmContextUpdateData::dataForwardingIsSet() const
{
    return m_DataForwardingIsSet;
}
void SmContextUpdateData::unsetDataForwarding()
{
    m_DataForwardingIsSet = false;
}
std::vector<std::string>& SmContextUpdateData::getEpsBearerSetup()
{
    return m_EpsBearerSetup;
}
bool SmContextUpdateData::epsBearerSetupIsSet() const
{
    return m_EpsBearerSetupIsSet;
}
void SmContextUpdateData::unsetEpsBearerSetup()
{
    m_EpsBearerSetupIsSet = false;
}
std::vector<int32_t>& SmContextUpdateData::getRevokeEbiList()
{
    return m_RevokeEbiList;
}
bool SmContextUpdateData::revokeEbiListIsSet() const
{
    return m_RevokeEbiListIsSet;
}
void SmContextUpdateData::unsetRevokeEbiList()
{
    m_RevokeEbiListIsSet = false;
}
bool SmContextUpdateData::isRelease() const
{
    return m_Release;
}
void SmContextUpdateData::setRelease(bool const value)
{
    m_Release = value;
    m_ReleaseIsSet = true;
}
bool SmContextUpdateData::releaseIsSet() const
{
    return m_ReleaseIsSet;
}
void SmContextUpdateData::unsetRelease()
{
    m_ReleaseIsSet = false;
}
Cause SmContextUpdateData::getCause() const
{
    return m_Cause;
}
void SmContextUpdateData::setCause(Cause const& value)
{
    m_Cause = value;
    m_CauseIsSet = true;
}
bool SmContextUpdateData::causeIsSet() const
{
    return m_CauseIsSet;
}
void SmContextUpdateData::unsetCause()
{
    m_CauseIsSet = false;
}
NgApCause SmContextUpdateData::getNgApCause() const
{
    return m_NgApCause;
}
void SmContextUpdateData::setNgApCause(NgApCause const& value)
{
    m_NgApCause = value;
    m_NgApCauseIsSet = true;
}
bool SmContextUpdateData::ngApCauseIsSet() const
{
    return m_NgApCauseIsSet;
}
void SmContextUpdateData::unsetNgApCause()
{
    m_NgApCauseIsSet = false;
}
int32_t SmContextUpdateData::get5gMmCauseValue() const
{
    return m__5gMmCauseValue;
}
void SmContextUpdateData::set5gMmCauseValue(int32_t const value)
{
    m__5gMmCauseValue = value;
    m__5gMmCauseValueIsSet = true;
}
bool SmContextUpdateData::_5gMmCauseValueIsSet() const
{
    return m__5gMmCauseValueIsSet;
}
void SmContextUpdateData::unset_5gMmCauseValue()
{
    m__5gMmCauseValueIsSet = false;
}
Snssai SmContextUpdateData::getSNssai() const
{
    return m_SNssai;
}
void SmContextUpdateData::setSNssai(Snssai const& value)
{
    m_SNssai = value;
    m_SNssaiIsSet = true;
}
bool SmContextUpdateData::sNssaiIsSet() const
{
    return m_SNssaiIsSet;
}
void SmContextUpdateData::unsetSNssai()
{
    m_SNssaiIsSet = false;
}
TraceData SmContextUpdateData::getTraceData() const
{
    return m_TraceData;
}
void SmContextUpdateData::setTraceData(TraceData const& value)
{
    m_TraceData = value;
    m_TraceDataIsSet = true;
}
bool SmContextUpdateData::traceDataIsSet() const
{
    return m_TraceDataIsSet;
}
void SmContextUpdateData::unsetTraceData()
{
    m_TraceDataIsSet = false;
}
EpsInterworkingIndication SmContextUpdateData::getEpsInterworkingInd() const
{
    return m_EpsInterworkingInd;
}
void SmContextUpdateData::setEpsInterworkingInd(EpsInterworkingIndication const& value)
{
    m_EpsInterworkingInd = value;
    m_EpsInterworkingIndIsSet = true;
}
bool SmContextUpdateData::epsInterworkingIndIsSet() const
{
    return m_EpsInterworkingIndIsSet;
}
void SmContextUpdateData::unsetEpsInterworkingInd()
{
    m_EpsInterworkingIndIsSet = false;
}
bool SmContextUpdateData::isAnTypeCanBeChanged() const
{
    return m_AnTypeCanBeChanged;
}
void SmContextUpdateData::setAnTypeCanBeChanged(bool const value)
{
    m_AnTypeCanBeChanged = value;
    m_AnTypeCanBeChangedIsSet = true;
}
bool SmContextUpdateData::anTypeCanBeChangedIsSet() const
{
    return m_AnTypeCanBeChangedIsSet;
}
void SmContextUpdateData::unsetAnTypeCanBeChanged()
{
    m_AnTypeCanBeChangedIsSet = false;
}
RefToBinaryData SmContextUpdateData::getN2SmInfoExt1() const
{
    return m_N2SmInfoExt1;
}
void SmContextUpdateData::setN2SmInfoExt1(RefToBinaryData const& value)
{
    m_N2SmInfoExt1 = value;
    m_N2SmInfoExt1IsSet = true;
}
bool SmContextUpdateData::n2SmInfoExt1IsSet() const
{
    return m_N2SmInfoExt1IsSet;
}
void SmContextUpdateData::unsetN2SmInfoExt1()
{
    m_N2SmInfoExt1IsSet = false;
}
N2SmInfoType SmContextUpdateData::getN2SmInfoTypeExt1() const
{
    return m_N2SmInfoTypeExt1;
}
void SmContextUpdateData::setN2SmInfoTypeExt1(N2SmInfoType const& value)
{
    m_N2SmInfoTypeExt1 = value;
    m_N2SmInfoTypeExt1IsSet = true;
}
bool SmContextUpdateData::n2SmInfoTypeExt1IsSet() const
{
    return m_N2SmInfoTypeExt1IsSet;
}
void SmContextUpdateData::unsetN2SmInfoTypeExt1()
{
    m_N2SmInfoTypeExt1IsSet = false;
}
MaReleaseIndication SmContextUpdateData::getMaReleaseInd() const
{
    return m_MaReleaseInd;
}
void SmContextUpdateData::setMaReleaseInd(MaReleaseIndication const& value)
{
    m_MaReleaseInd = value;
    m_MaReleaseIndIsSet = true;
}
bool SmContextUpdateData::maReleaseIndIsSet() const
{
    return m_MaReleaseIndIsSet;
}
void SmContextUpdateData::unsetMaReleaseInd()
{
    m_MaReleaseIndIsSet = false;
}
ExemptionInd SmContextUpdateData::getExemptionInd() const
{
    return m_ExemptionInd;
}
void SmContextUpdateData::setExemptionInd(ExemptionInd const& value)
{
    m_ExemptionInd = value;
    m_ExemptionIndIsSet = true;
}
bool SmContextUpdateData::exemptionIndIsSet() const
{
    return m_ExemptionIndIsSet;
}
void SmContextUpdateData::unsetExemptionInd()
{
    m_ExemptionIndIsSet = false;
}

}
}
}

