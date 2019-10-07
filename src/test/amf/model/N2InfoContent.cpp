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


#include "N2InfoContent.h"

namespace oai {
namespace amf {
namespace model {

N2InfoContent::N2InfoContent()
{
    m_NgapMessageType = 0;
    m_NgapMessageTypeIsSet = false;
    m_NgapIeTypeIsSet = false;
    
}

N2InfoContent::~N2InfoContent()
{
}

void N2InfoContent::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const N2InfoContent& o)
{
    j = nlohmann::json();
    if(o.ngapMessageTypeIsSet())
        j["ngapMessageType"] = o.m_NgapMessageType;
    if(o.ngapIeTypeIsSet())
        j["ngapIeType"] = o.m_NgapIeType;
    j["ngapData"] = o.m_NgapData;
}

void from_json(const nlohmann::json& j, N2InfoContent& o)
{
    if(j.find("ngapMessageType") != j.end())
    {
        j.at("ngapMessageType").get_to(o.m_NgapMessageType);
        o.m_NgapMessageTypeIsSet = true;
    } 
    if(j.find("ngapIeType") != j.end())
    {
        j.at("ngapIeType").get_to(o.m_NgapIeType);
        o.m_NgapIeTypeIsSet = true;
    } 
    j.at("ngapData").get_to(o.m_NgapData);
}

int32_t N2InfoContent::getNgapMessageType() const
{
    return m_NgapMessageType;
}
void N2InfoContent::setNgapMessageType(int32_t const value)
{
    m_NgapMessageType = value;
    m_NgapMessageTypeIsSet = true;
}
bool N2InfoContent::ngapMessageTypeIsSet() const
{
    return m_NgapMessageTypeIsSet;
}
void N2InfoContent::unsetNgapMessageType()
{
    m_NgapMessageTypeIsSet = false;
}
NgapIeType N2InfoContent::getNgapIeType() const
{
    return m_NgapIeType;
}
void N2InfoContent::setNgapIeType(NgapIeType const& value)
{
    m_NgapIeType = value;
    m_NgapIeTypeIsSet = true;
}
bool N2InfoContent::ngapIeTypeIsSet() const
{
    return m_NgapIeTypeIsSet;
}
void N2InfoContent::unsetNgapIeType()
{
    m_NgapIeTypeIsSet = false;
}
RefToBinaryData N2InfoContent::getNgapData() const
{
    return m_NgapData;
}
void N2InfoContent::setNgapData(RefToBinaryData const& value)
{
    m_NgapData = value;
    
}

}
}
}

