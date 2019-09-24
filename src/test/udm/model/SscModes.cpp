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


#include "SscModes.h"

namespace oai {
namespace udm {
namespace model {

SscModes::SscModes()
{
    m_AllowedSscModesIsSet = false;
    
}

SscModes::~SscModes()
{
}

void SscModes::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const SscModes& o)
{
    j = nlohmann::json();
    j["defaultSscMode"] = o.m_DefaultSscMode;
    if(o.allowedSscModesIsSet())
        j["allowedSscModes"] = o.m_AllowedSscModes;
}

void from_json(const nlohmann::json& j, SscModes& o)
{
    j.at("defaultSscMode").get_to(o.m_DefaultSscMode);
    if(j.find("allowedSscModes") != j.end())
    {
        j.at("allowedSscModes").get_to(o.m_AllowedSscModes);
        o.m_AllowedSscModesIsSet = true;
    } 
}

SscMode SscModes::getDefaultSscMode() const
{
    return m_DefaultSscMode;
}
void SscModes::setDefaultSscMode(SscMode const& value)
{
    m_DefaultSscMode = value;
    
}
std::vector<SscMode>& SscModes::getAllowedSscModes()
{
    return m_AllowedSscModes;
}
bool SscModes::allowedSscModesIsSet() const
{
    return m_AllowedSscModesIsSet;
}
void SscModes::unsetAllowedSscModes()
{
    m_AllowedSscModesIsSet = false;
}

}
}
}

