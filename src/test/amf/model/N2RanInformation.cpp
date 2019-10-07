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


#include "N2RanInformation.h"

namespace oai {
namespace amf {
namespace model {

N2RanInformation::N2RanInformation()
{
    
}

N2RanInformation::~N2RanInformation()
{
}

void N2RanInformation::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const N2RanInformation& o)
{
    j = nlohmann::json();
    j["n2InfoContent"] = o.m_N2InfoContent;
}

void from_json(const nlohmann::json& j, N2RanInformation& o)
{
    j.at("n2InfoContent").get_to(o.m_N2InfoContent);
}

N2InfoContent N2RanInformation::getN2InfoContent() const
{
    return m_N2InfoContent;
}
void N2RanInformation::setN2InfoContent(N2InfoContent const& value)
{
    m_N2InfoContent = value;
    
}

}
}
}

