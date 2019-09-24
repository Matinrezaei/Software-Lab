/**
* Nudm_SDM
* Nudm Subscriber Data Management Service. � 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
*
* The version of the OpenAPI document: 2.1.0.alpha-1
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/


#include "GroupIdentifiers.h"

namespace oai {
namespace udm {
namespace model {

GroupIdentifiers::GroupIdentifiers()
{
    m_ExtGroupId = "";
    m_ExtGroupIdIsSet = false;
    m_IntGroupId = "";
    m_IntGroupIdIsSet = false;
    
}

GroupIdentifiers::~GroupIdentifiers()
{
}

void GroupIdentifiers::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const GroupIdentifiers& o)
{
    j = nlohmann::json();
    if(o.extGroupIdIsSet())
        j["extGroupId"] = o.m_ExtGroupId;
    if(o.intGroupIdIsSet())
        j["intGroupId"] = o.m_IntGroupId;
}

void from_json(const nlohmann::json& j, GroupIdentifiers& o)
{
    if(j.find("extGroupId") != j.end())
    {
        j.at("extGroupId").get_to(o.m_ExtGroupId);
        o.m_ExtGroupIdIsSet = true;
    } 
    if(j.find("intGroupId") != j.end())
    {
        j.at("intGroupId").get_to(o.m_IntGroupId);
        o.m_IntGroupIdIsSet = true;
    } 
}

std::string GroupIdentifiers::getExtGroupId() const
{
    return m_ExtGroupId;
}
void GroupIdentifiers::setExtGroupId(std::string const& value)
{
    m_ExtGroupId = value;
    m_ExtGroupIdIsSet = true;
}
bool GroupIdentifiers::extGroupIdIsSet() const
{
    return m_ExtGroupIdIsSet;
}
void GroupIdentifiers::unsetExtGroupId()
{
    m_ExtGroupIdIsSet = false;
}
std::string GroupIdentifiers::getIntGroupId() const
{
    return m_IntGroupId;
}
void GroupIdentifiers::setIntGroupId(std::string const& value)
{
    m_IntGroupId = value;
    m_IntGroupIdIsSet = true;
}
bool GroupIdentifiers::intGroupIdIsSet() const
{
    return m_IntGroupIdIsSet;
}
void GroupIdentifiers::unsetIntGroupId()
{
    m_IntGroupIdIsSet = false;
}

}
}
}

