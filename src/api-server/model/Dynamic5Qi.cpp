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


#include "Dynamic5Qi.h"

namespace oai {
namespace smf_server {
namespace model {

Dynamic5Qi::Dynamic5Qi()
{
    m_PriorityLevel = 0;
    m_PacketDelayBudget = 0;
    m_PacketErrRate = "";
    m_AverWindow = 0;
    m_AverWindowIsSet = false;
    m_MaxDataBurstVol = 0;
    m_MaxDataBurstVolIsSet = false;
    
}

Dynamic5Qi::~Dynamic5Qi()
{
}

void Dynamic5Qi::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const Dynamic5Qi& o)
{
    j = nlohmann::json();
    j["resourceType"] = o.m_ResourceType;
    j["priorityLevel"] = o.m_PriorityLevel;
    j["packetDelayBudget"] = o.m_PacketDelayBudget;
    j["packetErrRate"] = o.m_PacketErrRate;
    if(o.averWindowIsSet())
        j["averWindow"] = o.m_AverWindow;
    if(o.maxDataBurstVolIsSet())
        j["maxDataBurstVol"] = o.m_MaxDataBurstVol;
}

void from_json(const nlohmann::json& j, Dynamic5Qi& o)
{
    j.at("resourceType").get_to(o.m_ResourceType);
    j.at("priorityLevel").get_to(o.m_PriorityLevel);
    j.at("packetDelayBudget").get_to(o.m_PacketDelayBudget);
    j.at("packetErrRate").get_to(o.m_PacketErrRate);
    if(j.find("averWindow") != j.end())
    {
        j.at("averWindow").get_to(o.m_AverWindow);
        o.m_AverWindowIsSet = true;
    } 
    if(j.find("maxDataBurstVol") != j.end())
    {
        j.at("maxDataBurstVol").get_to(o.m_MaxDataBurstVol);
        o.m_MaxDataBurstVolIsSet = true;
    } 
}

QosResourceType Dynamic5Qi::getResourceType() const
{
    return m_ResourceType;
}
void Dynamic5Qi::setResourceType(QosResourceType const& value)
{
    m_ResourceType = value;
    
}
int32_t Dynamic5Qi::getPriorityLevel() const
{
    return m_PriorityLevel;
}
void Dynamic5Qi::setPriorityLevel(int32_t const value)
{
    m_PriorityLevel = value;
    
}
int32_t Dynamic5Qi::getPacketDelayBudget() const
{
    return m_PacketDelayBudget;
}
void Dynamic5Qi::setPacketDelayBudget(int32_t const value)
{
    m_PacketDelayBudget = value;
    
}
std::string Dynamic5Qi::getPacketErrRate() const
{
    return m_PacketErrRate;
}
void Dynamic5Qi::setPacketErrRate(std::string const& value)
{
    m_PacketErrRate = value;
    
}
int32_t Dynamic5Qi::getAverWindow() const
{
    return m_AverWindow;
}
void Dynamic5Qi::setAverWindow(int32_t const value)
{
    m_AverWindow = value;
    m_AverWindowIsSet = true;
}
bool Dynamic5Qi::averWindowIsSet() const
{
    return m_AverWindowIsSet;
}
void Dynamic5Qi::unsetAverWindow()
{
    m_AverWindowIsSet = false;
}
int32_t Dynamic5Qi::getMaxDataBurstVol() const
{
    return m_MaxDataBurstVol;
}
void Dynamic5Qi::setMaxDataBurstVol(int32_t const value)
{
    m_MaxDataBurstVol = value;
    m_MaxDataBurstVolIsSet = true;
}
bool Dynamic5Qi::maxDataBurstVolIsSet() const
{
    return m_MaxDataBurstVolIsSet;
}
void Dynamic5Qi::unsetMaxDataBurstVol()
{
    m_MaxDataBurstVolIsSet = false;
}

}
}
}

