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


#include "SorInfo.h"

namespace oai {
namespace udm {
namespace model {

SorInfo::SorInfo()
{
    m_SteeringContainerIsSet = false;
    m_AckInd = false;
    m_SorMacIausf = "";
    m_SorMacIausfIsSet = false;
    m_Countersor = "";
    m_CountersorIsSet = false;
    m_ProvisioningTime = "";
    
}

SorInfo::~SorInfo()
{
}

void SorInfo::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const SorInfo& o)
{
    j = nlohmann::json();
    if(o.steeringContainerIsSet())
        j["steeringContainer"] = o.m_SteeringContainer;
    j["ackInd"] = o.m_AckInd;
    if(o.sorMacIausfIsSet())
        j["sorMacIausf"] = o.m_SorMacIausf;
    if(o.countersorIsSet())
        j["countersor"] = o.m_Countersor;
    j["provisioningTime"] = o.m_ProvisioningTime;
}

void from_json(const nlohmann::json& j, SorInfo& o)
{
    if(j.find("steeringContainer") != j.end())
    {
        j.at("steeringContainer").get_to(o.m_SteeringContainer);
        o.m_SteeringContainerIsSet = true;
    } 
    j.at("ackInd").get_to(o.m_AckInd);
    if(j.find("sorMacIausf") != j.end())
    {
        j.at("sorMacIausf").get_to(o.m_SorMacIausf);
        o.m_SorMacIausfIsSet = true;
    } 
    if(j.find("countersor") != j.end())
    {
        j.at("countersor").get_to(o.m_Countersor);
        o.m_CountersorIsSet = true;
    } 
    j.at("provisioningTime").get_to(o.m_ProvisioningTime);
}

SteeringContainer SorInfo::getSteeringContainer() const
{
    return m_SteeringContainer;
}
void SorInfo::setSteeringContainer(SteeringContainer const& value)
{
    m_SteeringContainer = value;
    m_SteeringContainerIsSet = true;
}
bool SorInfo::steeringContainerIsSet() const
{
    return m_SteeringContainerIsSet;
}
void SorInfo::unsetSteeringContainer()
{
    m_SteeringContainerIsSet = false;
}
bool SorInfo::isAckInd() const
{
    return m_AckInd;
}
void SorInfo::setAckInd(bool const value)
{
    m_AckInd = value;
    
}
std::string SorInfo::getSorMacIausf() const
{
    return m_SorMacIausf;
}
void SorInfo::setSorMacIausf(std::string const& value)
{
    m_SorMacIausf = value;
    m_SorMacIausfIsSet = true;
}
bool SorInfo::sorMacIausfIsSet() const
{
    return m_SorMacIausfIsSet;
}
void SorInfo::unsetSorMacIausf()
{
    m_SorMacIausfIsSet = false;
}
std::string SorInfo::getCountersor() const
{
    return m_Countersor;
}
void SorInfo::setCountersor(std::string const& value)
{
    m_Countersor = value;
    m_CountersorIsSet = true;
}
bool SorInfo::countersorIsSet() const
{
    return m_CountersorIsSet;
}
void SorInfo::unsetCountersor()
{
    m_CountersorIsSet = false;
}
std::string SorInfo::getProvisioningTime() const
{
    return m_ProvisioningTime;
}
void SorInfo::setProvisioningTime(std::string const& value)
{
    m_ProvisioningTime = value;
    
}

}
}
}

