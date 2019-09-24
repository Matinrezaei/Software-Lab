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


#include "NgRanTargetId.h"

namespace oai {
namespace smf {
namespace model {

NgRanTargetId::NgRanTargetId()
{
    
}

NgRanTargetId::~NgRanTargetId()
{
}

void NgRanTargetId::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const NgRanTargetId& o)
{
    j = nlohmann::json();
    j["ranNodeId"] = o.m_RanNodeId;
    j["tai"] = o.m_Tai;
}

void from_json(const nlohmann::json& j, NgRanTargetId& o)
{
    j.at("ranNodeId").get_to(o.m_RanNodeId);
    j.at("tai").get_to(o.m_Tai);
}

GlobalRanNodeId NgRanTargetId::getRanNodeId() const
{
    return m_RanNodeId;
}
void NgRanTargetId::setRanNodeId(GlobalRanNodeId const& value)
{
    m_RanNodeId = value;
    
}
Tai NgRanTargetId::getTai() const
{
    return m_Tai;
}
void NgRanTargetId::setTai(Tai const& value)
{
    m_Tai = value;
    
}

}
}
}

