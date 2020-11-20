/**
* Nsmf_EventExposure
* Session Management Event Exposure Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
*
* The version of the OpenAPI document: 1.1.0.alpha-1
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/


#include "EventNotification.h"

namespace oai {
namespace smf_server {
namespace model {

EventNotification::EventNotification()
{
    m_TimeStamp = "";
    m_Supi = "";
    m_SupiIsSet = false;
    m_Gpsi = "";
    m_GpsiIsSet = false;
    m_SourceDnai = "";
    m_SourceDnaiIsSet = false;
    m_TargetDnai = "";
    m_TargetDnaiIsSet = false;
    m_DnaiChgTypeIsSet = false;
    m_SourceUeIpv4Addr = "";
    m_SourceUeIpv4AddrIsSet = false;
    m_SourceUeIpv6PrefixIsSet = false;
    m_TargetUeIpv4Addr = "";
    m_TargetUeIpv4AddrIsSet = false;
    m_TargetUeIpv6PrefixIsSet = false;
    m_SourceTraRoutingIsSet = false;
    m_TargetTraRoutingIsSet = false;
    m_UeMac = "";
    m_UeMacIsSet = false;
    m_AdIpv4Addr = "";
    m_AdIpv4AddrIsSet = false;
    m_AdIpv6PrefixIsSet = false;
    m_ReIpv4Addr = "";
    m_ReIpv4AddrIsSet = false;
    m_ReIpv6PrefixIsSet = false;
    m_PlmnIdIsSet = false;
    m_AccTypeIsSet = false;
    m_PduSeId = 0;
    m_PduSeIdIsSet = false;
    m_DddStatusIsSet = false;
    m_MaxWaitTime = "";
    m_MaxWaitTimeIsSet = false;
    
}

EventNotification::~EventNotification()
{
}

void EventNotification::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const EventNotification& o)
{
    j = nlohmann::json();
    j["event"] = o.m_Event;
    j["timeStamp"] = o.m_TimeStamp;
    if(o.supiIsSet())
        j["supi"] = o.m_Supi;
    if(o.gpsiIsSet())
        j["gpsi"] = o.m_Gpsi;
    if(o.sourceDnaiIsSet())
        j["sourceDnai"] = o.m_SourceDnai;
    if(o.targetDnaiIsSet())
        j["targetDnai"] = o.m_TargetDnai;
    if(o.dnaiChgTypeIsSet())
        j["dnaiChgType"] = o.m_DnaiChgType;
    if(o.sourceUeIpv4AddrIsSet())
        j["sourceUeIpv4Addr"] = o.m_SourceUeIpv4Addr;
    if(o.sourceUeIpv6PrefixIsSet())
        j["sourceUeIpv6Prefix"] = o.m_SourceUeIpv6Prefix;
    if(o.targetUeIpv4AddrIsSet())
        j["targetUeIpv4Addr"] = o.m_TargetUeIpv4Addr;
    if(o.targetUeIpv6PrefixIsSet())
        j["targetUeIpv6Prefix"] = o.m_TargetUeIpv6Prefix;
    if(o.sourceTraRoutingIsSet())
        j["sourceTraRouting"] = o.m_SourceTraRouting;
    if(o.targetTraRoutingIsSet())
        j["targetTraRouting"] = o.m_TargetTraRouting;
    if(o.ueMacIsSet())
        j["ueMac"] = o.m_UeMac;
    if(o.adIpv4AddrIsSet())
        j["adIpv4Addr"] = o.m_AdIpv4Addr;
    if(o.adIpv6PrefixIsSet())
        j["adIpv6Prefix"] = o.m_AdIpv6Prefix;
    if(o.reIpv4AddrIsSet())
        j["reIpv4Addr"] = o.m_ReIpv4Addr;
    if(o.reIpv6PrefixIsSet())
        j["reIpv6Prefix"] = o.m_ReIpv6Prefix;
    if(o.plmnIdIsSet())
        j["plmnId"] = o.m_PlmnId;
    if(o.accTypeIsSet())
        j["accType"] = o.m_AccType;
    if(o.pduSeIdIsSet())
        j["pduSeId"] = o.m_PduSeId;
    if(o.dddStatusIsSet())
        j["dddStatus"] = o.m_DddStatus;
    if(o.maxWaitTimeIsSet())
        j["maxWaitTime"] = o.m_MaxWaitTime;
}

void from_json(const nlohmann::json& j, EventNotification& o)
{
    j.at("event").get_to(o.m_Event);
    j.at("timeStamp").get_to(o.m_TimeStamp);
    if(j.find("supi") != j.end())
    {
        j.at("supi").get_to(o.m_Supi);
        o.m_SupiIsSet = true;
    } 
    if(j.find("gpsi") != j.end())
    {
        j.at("gpsi").get_to(o.m_Gpsi);
        o.m_GpsiIsSet = true;
    } 
    if(j.find("sourceDnai") != j.end())
    {
        j.at("sourceDnai").get_to(o.m_SourceDnai);
        o.m_SourceDnaiIsSet = true;
    } 
    if(j.find("targetDnai") != j.end())
    {
        j.at("targetDnai").get_to(o.m_TargetDnai);
        o.m_TargetDnaiIsSet = true;
    } 
    if(j.find("dnaiChgType") != j.end())
    {
        j.at("dnaiChgType").get_to(o.m_DnaiChgType);
        o.m_DnaiChgTypeIsSet = true;
    } 
    if(j.find("sourceUeIpv4Addr") != j.end())
    {
        j.at("sourceUeIpv4Addr").get_to(o.m_SourceUeIpv4Addr);
        o.m_SourceUeIpv4AddrIsSet = true;
    } 
    if(j.find("sourceUeIpv6Prefix") != j.end())
    {
        j.at("sourceUeIpv6Prefix").get_to(o.m_SourceUeIpv6Prefix);
        o.m_SourceUeIpv6PrefixIsSet = true;
    } 
    if(j.find("targetUeIpv4Addr") != j.end())
    {
        j.at("targetUeIpv4Addr").get_to(o.m_TargetUeIpv4Addr);
        o.m_TargetUeIpv4AddrIsSet = true;
    } 
    if(j.find("targetUeIpv6Prefix") != j.end())
    {
        j.at("targetUeIpv6Prefix").get_to(o.m_TargetUeIpv6Prefix);
        o.m_TargetUeIpv6PrefixIsSet = true;
    } 
    if(j.find("sourceTraRouting") != j.end())
    {
        j.at("sourceTraRouting").get_to(o.m_SourceTraRouting);
        o.m_SourceTraRoutingIsSet = true;
    } 
    if(j.find("targetTraRouting") != j.end())
    {
        j.at("targetTraRouting").get_to(o.m_TargetTraRouting);
        o.m_TargetTraRoutingIsSet = true;
    } 
    if(j.find("ueMac") != j.end())
    {
        j.at("ueMac").get_to(o.m_UeMac);
        o.m_UeMacIsSet = true;
    } 
    if(j.find("adIpv4Addr") != j.end())
    {
        j.at("adIpv4Addr").get_to(o.m_AdIpv4Addr);
        o.m_AdIpv4AddrIsSet = true;
    } 
    if(j.find("adIpv6Prefix") != j.end())
    {
        j.at("adIpv6Prefix").get_to(o.m_AdIpv6Prefix);
        o.m_AdIpv6PrefixIsSet = true;
    } 
    if(j.find("reIpv4Addr") != j.end())
    {
        j.at("reIpv4Addr").get_to(o.m_ReIpv4Addr);
        o.m_ReIpv4AddrIsSet = true;
    } 
    if(j.find("reIpv6Prefix") != j.end())
    {
        j.at("reIpv6Prefix").get_to(o.m_ReIpv6Prefix);
        o.m_ReIpv6PrefixIsSet = true;
    } 
    if(j.find("plmnId") != j.end())
    {
        j.at("plmnId").get_to(o.m_PlmnId);
        o.m_PlmnIdIsSet = true;
    } 
    if(j.find("accType") != j.end())
    {
        j.at("accType").get_to(o.m_AccType);
        o.m_AccTypeIsSet = true;
    } 
    if(j.find("pduSeId") != j.end())
    {
        j.at("pduSeId").get_to(o.m_PduSeId);
        o.m_PduSeIdIsSet = true;
    } 
    if(j.find("dddStatus") != j.end())
    {
        j.at("dddStatus").get_to(o.m_DddStatus);
        o.m_DddStatusIsSet = true;
    } 
    if(j.find("maxWaitTime") != j.end())
    {
        j.at("maxWaitTime").get_to(o.m_MaxWaitTime);
        o.m_MaxWaitTimeIsSet = true;
    } 
}

SmfEvent EventNotification::getEvent() const
{
    return m_Event;
}
void EventNotification::setEvent(SmfEvent const& value)
{
    m_Event = value;
}
std::string EventNotification::getTimeStamp() const
{
    return m_TimeStamp;
}
void EventNotification::setTimeStamp(std::string const& value)
{
    m_TimeStamp = value;
}
std::string EventNotification::getSupi() const
{
    return m_Supi;
}
void EventNotification::setSupi(std::string const& value)
{
    m_Supi = value;
    m_SupiIsSet = true;
}
bool EventNotification::supiIsSet() const
{
    return m_SupiIsSet;
}
void EventNotification::unsetSupi()
{
    m_SupiIsSet = false;
}
std::string EventNotification::getGpsi() const
{
    return m_Gpsi;
}
void EventNotification::setGpsi(std::string const& value)
{
    m_Gpsi = value;
    m_GpsiIsSet = true;
}
bool EventNotification::gpsiIsSet() const
{
    return m_GpsiIsSet;
}
void EventNotification::unsetGpsi()
{
    m_GpsiIsSet = false;
}
std::string EventNotification::getSourceDnai() const
{
    return m_SourceDnai;
}
void EventNotification::setSourceDnai(std::string const& value)
{
    m_SourceDnai = value;
    m_SourceDnaiIsSet = true;
}
bool EventNotification::sourceDnaiIsSet() const
{
    return m_SourceDnaiIsSet;
}
void EventNotification::unsetSourceDnai()
{
    m_SourceDnaiIsSet = false;
}
std::string EventNotification::getTargetDnai() const
{
    return m_TargetDnai;
}
void EventNotification::setTargetDnai(std::string const& value)
{
    m_TargetDnai = value;
    m_TargetDnaiIsSet = true;
}
bool EventNotification::targetDnaiIsSet() const
{
    return m_TargetDnaiIsSet;
}
void EventNotification::unsetTargetDnai()
{
    m_TargetDnaiIsSet = false;
}
DnaiChangeType EventNotification::getDnaiChgType() const
{
    return m_DnaiChgType;
}
void EventNotification::setDnaiChgType(DnaiChangeType const& value)
{
    m_DnaiChgType = value;
    m_DnaiChgTypeIsSet = true;
}
bool EventNotification::dnaiChgTypeIsSet() const
{
    return m_DnaiChgTypeIsSet;
}
void EventNotification::unsetDnaiChgType()
{
    m_DnaiChgTypeIsSet = false;
}
std::string EventNotification::getSourceUeIpv4Addr() const
{
    return m_SourceUeIpv4Addr;
}
void EventNotification::setSourceUeIpv4Addr(std::string const& value)
{
    m_SourceUeIpv4Addr = value;
    m_SourceUeIpv4AddrIsSet = true;
}
bool EventNotification::sourceUeIpv4AddrIsSet() const
{
    return m_SourceUeIpv4AddrIsSet;
}
void EventNotification::unsetSourceUeIpv4Addr()
{
    m_SourceUeIpv4AddrIsSet = false;
}
Ipv6Prefix EventNotification::getSourceUeIpv6Prefix() const
{
    return m_SourceUeIpv6Prefix;
}
void EventNotification::setSourceUeIpv6Prefix(Ipv6Prefix const& value)
{
    m_SourceUeIpv6Prefix = value;
    m_SourceUeIpv6PrefixIsSet = true;
}
bool EventNotification::sourceUeIpv6PrefixIsSet() const
{
    return m_SourceUeIpv6PrefixIsSet;
}
void EventNotification::unsetSourceUeIpv6Prefix()
{
    m_SourceUeIpv6PrefixIsSet = false;
}
std::string EventNotification::getTargetUeIpv4Addr() const
{
    return m_TargetUeIpv4Addr;
}
void EventNotification::setTargetUeIpv4Addr(std::string const& value)
{
    m_TargetUeIpv4Addr = value;
    m_TargetUeIpv4AddrIsSet = true;
}
bool EventNotification::targetUeIpv4AddrIsSet() const
{
    return m_TargetUeIpv4AddrIsSet;
}
void EventNotification::unsetTargetUeIpv4Addr()
{
    m_TargetUeIpv4AddrIsSet = false;
}
Ipv6Prefix EventNotification::getTargetUeIpv6Prefix() const
{
    return m_TargetUeIpv6Prefix;
}
void EventNotification::setTargetUeIpv6Prefix(Ipv6Prefix const& value)
{
    m_TargetUeIpv6Prefix = value;
    m_TargetUeIpv6PrefixIsSet = true;
}
bool EventNotification::targetUeIpv6PrefixIsSet() const
{
    return m_TargetUeIpv6PrefixIsSet;
}
void EventNotification::unsetTargetUeIpv6Prefix()
{
    m_TargetUeIpv6PrefixIsSet = false;
}
RouteToLocation EventNotification::getSourceTraRouting() const
{
    return m_SourceTraRouting;
}
void EventNotification::setSourceTraRouting(RouteToLocation const& value)
{
    m_SourceTraRouting = value;
    m_SourceTraRoutingIsSet = true;
}
bool EventNotification::sourceTraRoutingIsSet() const
{
    return m_SourceTraRoutingIsSet;
}
void EventNotification::unsetSourceTraRouting()
{
    m_SourceTraRoutingIsSet = false;
}
RouteToLocation EventNotification::getTargetTraRouting() const
{
    return m_TargetTraRouting;
}
void EventNotification::setTargetTraRouting(RouteToLocation const& value)
{
    m_TargetTraRouting = value;
    m_TargetTraRoutingIsSet = true;
}
bool EventNotification::targetTraRoutingIsSet() const
{
    return m_TargetTraRoutingIsSet;
}
void EventNotification::unsetTargetTraRouting()
{
    m_TargetTraRoutingIsSet = false;
}
std::string EventNotification::getUeMac() const
{
    return m_UeMac;
}
void EventNotification::setUeMac(std::string const& value)
{
    m_UeMac = value;
    m_UeMacIsSet = true;
}
bool EventNotification::ueMacIsSet() const
{
    return m_UeMacIsSet;
}
void EventNotification::unsetUeMac()
{
    m_UeMacIsSet = false;
}
std::string EventNotification::getAdIpv4Addr() const
{
    return m_AdIpv4Addr;
}
void EventNotification::setAdIpv4Addr(std::string const& value)
{
    m_AdIpv4Addr = value;
    m_AdIpv4AddrIsSet = true;
}
bool EventNotification::adIpv4AddrIsSet() const
{
    return m_AdIpv4AddrIsSet;
}
void EventNotification::unsetAdIpv4Addr()
{
    m_AdIpv4AddrIsSet = false;
}
Ipv6Prefix EventNotification::getAdIpv6Prefix() const
{
    return m_AdIpv6Prefix;
}
void EventNotification::setAdIpv6Prefix(Ipv6Prefix const& value)
{
    m_AdIpv6Prefix = value;
    m_AdIpv6PrefixIsSet = true;
}
bool EventNotification::adIpv6PrefixIsSet() const
{
    return m_AdIpv6PrefixIsSet;
}
void EventNotification::unsetAdIpv6Prefix()
{
    m_AdIpv6PrefixIsSet = false;
}
std::string EventNotification::getReIpv4Addr() const
{
    return m_ReIpv4Addr;
}
void EventNotification::setReIpv4Addr(std::string const& value)
{
    m_ReIpv4Addr = value;
    m_ReIpv4AddrIsSet = true;
}
bool EventNotification::reIpv4AddrIsSet() const
{
    return m_ReIpv4AddrIsSet;
}
void EventNotification::unsetReIpv4Addr()
{
    m_ReIpv4AddrIsSet = false;
}
Ipv6Prefix EventNotification::getReIpv6Prefix() const
{
    return m_ReIpv6Prefix;
}
void EventNotification::setReIpv6Prefix(Ipv6Prefix const& value)
{
    m_ReIpv6Prefix = value;
    m_ReIpv6PrefixIsSet = true;
}
bool EventNotification::reIpv6PrefixIsSet() const
{
    return m_ReIpv6PrefixIsSet;
}
void EventNotification::unsetReIpv6Prefix()
{
    m_ReIpv6PrefixIsSet = false;
}
PlmnId EventNotification::getPlmnId() const
{
    return m_PlmnId;
}
void EventNotification::setPlmnId(PlmnId const& value)
{
    m_PlmnId = value;
    m_PlmnIdIsSet = true;
}
bool EventNotification::plmnIdIsSet() const
{
    return m_PlmnIdIsSet;
}
void EventNotification::unsetPlmnId()
{
    m_PlmnIdIsSet = false;
}
AccessType EventNotification::getAccType() const
{
    return m_AccType;
}
void EventNotification::setAccType(AccessType const& value)
{
    m_AccType = value;
    m_AccTypeIsSet = true;
}
bool EventNotification::accTypeIsSet() const
{
    return m_AccTypeIsSet;
}
void EventNotification::unsetAccType()
{
    m_AccTypeIsSet = false;
}
int32_t EventNotification::getPduSeId() const
{
    return m_PduSeId;
}
void EventNotification::setPduSeId(int32_t const value)
{
    m_PduSeId = value;
    m_PduSeIdIsSet = true;
}
bool EventNotification::pduSeIdIsSet() const
{
    return m_PduSeIdIsSet;
}
void EventNotification::unsetPduSeId()
{
    m_PduSeIdIsSet = false;
}
DddStatus EventNotification::getDddStatus() const
{
    return m_DddStatus;
}
void EventNotification::setDddStatus(DddStatus const& value)
{
    m_DddStatus = value;
    m_DddStatusIsSet = true;
}
bool EventNotification::dddStatusIsSet() const
{
    return m_DddStatusIsSet;
}
void EventNotification::unsetDddStatus()
{
    m_DddStatusIsSet = false;
}
std::string EventNotification::getMaxWaitTime() const
{
    return m_MaxWaitTime;
}
void EventNotification::setMaxWaitTime(std::string const& value)
{
    m_MaxWaitTime = value;
    m_MaxWaitTimeIsSet = true;
}
bool EventNotification::maxWaitTimeIsSet() const
{
    return m_MaxWaitTimeIsSet;
}
void EventNotification::unsetMaxWaitTime()
{
    m_MaxWaitTimeIsSet = false;
}

}
}
}

