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


#include "UpSecurity.h"

namespace oai {
namespace smf_server {
namespace model {

UpSecurity::UpSecurity()
{
    
}

UpSecurity::~UpSecurity()
{
}

void UpSecurity::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const UpSecurity& o)
{
    j = nlohmann::json();
    j["upIntegr"] = o.m_UpIntegr;
    j["upConfid"] = o.m_UpConfid;
}

void from_json(const nlohmann::json& j, UpSecurity& o)
{
    j.at("upIntegr").get_to(o.m_UpIntegr);
    j.at("upConfid").get_to(o.m_UpConfid);
}

UpIntegrity UpSecurity::getUpIntegr() const
{
    return m_UpIntegr;
}
void UpSecurity::setUpIntegr(UpIntegrity const& value)
{
    m_UpIntegr = value;
    
}
UpConfidentiality UpSecurity::getUpConfid() const
{
    return m_UpConfid;
}
void UpSecurity::setUpConfid(UpConfidentiality const& value)
{
    m_UpConfid = value;
    
}

}
}
}

