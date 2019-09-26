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


#include "SmContextRetrieveData.h"

namespace oai {
namespace smf {
namespace model {

SmContextRetrieveData::SmContextRetrieveData()
{
    m_TargetMmeCapIsSet = false;
    m_SmContextTypeIsSet = false;
    
}

SmContextRetrieveData::~SmContextRetrieveData()
{
}

void SmContextRetrieveData::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const SmContextRetrieveData& o)
{
    j = nlohmann::json();
    if(o.targetMmeCapIsSet())
        j["targetMmeCap"] = o.m_TargetMmeCap;
    if(o.smContextTypeIsSet())
        j["smContextType"] = o.m_SmContextType;
}

void from_json(const nlohmann::json& j, SmContextRetrieveData& o)
{
    if(j.find("targetMmeCap") != j.end())
    {
        j.at("targetMmeCap").get_to(o.m_TargetMmeCap);
        o.m_TargetMmeCapIsSet = true;
    } 
    if(j.find("smContextType") != j.end())
    {
        j.at("smContextType").get_to(o.m_SmContextType);
        o.m_SmContextTypeIsSet = true;
    } 
}

MmeCapabilities SmContextRetrieveData::getTargetMmeCap() const
{
    return m_TargetMmeCap;
}
void SmContextRetrieveData::setTargetMmeCap(MmeCapabilities const& value)
{
    m_TargetMmeCap = value;
    m_TargetMmeCapIsSet = true;
}
bool SmContextRetrieveData::targetMmeCapIsSet() const
{
    return m_TargetMmeCapIsSet;
}
void SmContextRetrieveData::unsetTargetMmeCap()
{
    m_TargetMmeCapIsSet = false;
}
SmContextType SmContextRetrieveData::getSmContextType() const
{
    return m_SmContextType;
}
void SmContextRetrieveData::setSmContextType(SmContextType const& value)
{
    m_SmContextType = value;
    m_SmContextTypeIsSet = true;
}
bool SmContextRetrieveData::smContextTypeIsSet() const
{
    return m_SmContextTypeIsSet;
}
void SmContextRetrieveData::unsetSmContextType()
{
    m_SmContextTypeIsSet = false;
}

}
}
}
