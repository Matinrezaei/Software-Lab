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
/*
 * UpSecurity.h
 *
 * 
 */

#ifndef UpSecurity_H_
#define UpSecurity_H_


#include "UpConfidentiality.h"
#include "UpIntegrity.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
/// 
/// </summary>
class  UpSecurity
{
public:
    UpSecurity();
    virtual ~UpSecurity();

    void validate();

    /////////////////////////////////////////////
    /// UpSecurity members

    /// <summary>
    /// 
    /// </summary>
    UpIntegrity getUpIntegr() const;
    void setUpIntegr(UpIntegrity const& value);
        /// <summary>
    /// 
    /// </summary>
    UpConfidentiality getUpConfid() const;
    void setUpConfid(UpConfidentiality const& value);
    
    friend void to_json(nlohmann::json& j, const UpSecurity& o);
    friend void from_json(const nlohmann::json& j, UpSecurity& o);
protected:
    UpIntegrity m_UpIntegr;

    UpConfidentiality m_UpConfid;

};

}
}
}

#endif /* UpSecurity_H_ */
