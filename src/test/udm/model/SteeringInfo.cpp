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


#include "SteeringInfo.h"

namespace oai {
namespace udm {
namespace model {

SteeringInfo::SteeringInfo()
{
    m_AccessTechListIsSet = false;
    
}

SteeringInfo::~SteeringInfo()
{
}

void SteeringInfo::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const SteeringInfo& o)
{
    j = nlohmann::json();
    j["plmnId"] = o.m_PlmnId;
    if(o.accessTechListIsSet())
        j["accessTechList"] = o.m_AccessTechList;
}

void from_json(const nlohmann::json& j, SteeringInfo& o)
{
    j.at("plmnId").get_to(o.m_PlmnId);
    if(j.find("accessTechList") != j.end())
    {
        j.at("accessTechList").get_to(o.m_AccessTechList);
        o.m_AccessTechListIsSet = true;
    } 
}

PlmnId SteeringInfo::getPlmnId() const
{
    return m_PlmnId;
}
void SteeringInfo::setPlmnId(PlmnId const& value)
{
    m_PlmnId = value;
    
}
std::vector<AccessTech>& SteeringInfo::getAccessTechList()
{
    return m_AccessTechList;
}
bool SteeringInfo::accessTechListIsSet() const
{
    return m_AccessTechListIsSet;
}
void SteeringInfo::unsetAccessTechList()
{
    m_AccessTechListIsSet = false;
}

}
}
}
