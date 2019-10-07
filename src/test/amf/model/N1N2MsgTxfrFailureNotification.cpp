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


#include "N1N2MsgTxfrFailureNotification.h"

namespace oai {
namespace amf {
namespace model {

N1N2MsgTxfrFailureNotification::N1N2MsgTxfrFailureNotification()
{
    m_N1n2MsgDataUri = "";
    
}

N1N2MsgTxfrFailureNotification::~N1N2MsgTxfrFailureNotification()
{
}

void N1N2MsgTxfrFailureNotification::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const N1N2MsgTxfrFailureNotification& o)
{
    j = nlohmann::json();
    j["cause"] = o.m_Cause;
    j["n1n2MsgDataUri"] = o.m_N1n2MsgDataUri;
}

void from_json(const nlohmann::json& j, N1N2MsgTxfrFailureNotification& o)
{
    j.at("cause").get_to(o.m_Cause);
    j.at("n1n2MsgDataUri").get_to(o.m_N1n2MsgDataUri);
}

N1N2MessageTransferCause N1N2MsgTxfrFailureNotification::getCause() const
{
    return m_Cause;
}
void N1N2MsgTxfrFailureNotification::setCause(N1N2MessageTransferCause const& value)
{
    m_Cause = value;
    
}
std::string N1N2MsgTxfrFailureNotification::getN1n2MsgDataUri() const
{
    return m_N1n2MsgDataUri;
}
void N1N2MsgTxfrFailureNotification::setN1n2MsgDataUri(std::string const& value)
{
    m_N1n2MsgDataUri = value;
    
}

}
}
}
