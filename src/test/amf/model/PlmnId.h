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
/*
 * PlmnId.h
 *
 * 
 */

#ifndef PlmnId_H_
#define PlmnId_H_


#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace amf {
namespace model {

/// <summary>
/// 
/// </summary>
class  PlmnId
{
public:
    PlmnId();
    virtual ~PlmnId();

    void validate();

    /////////////////////////////////////////////
    /// PlmnId members

    /// <summary>
    /// 
    /// </summary>
    std::string getMcc() const;
    void setMcc(std::string const& value);
        /// <summary>
    /// 
    /// </summary>
    std::string getMnc() const;
    void setMnc(std::string const& value);
    
    friend void to_json(nlohmann::json& j, const PlmnId& o);
    friend void from_json(const nlohmann::json& j, PlmnId& o);
protected:
    std::string m_Mcc;

    std::string m_Mnc;

};

}
}
}

#endif /* PlmnId_H_ */
