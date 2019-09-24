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
 * Guami.h
 *
 * 
 */

#ifndef Guami_H_
#define Guami_H_


#include <string>
#include "PlmnId.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace smf {
namespace model {

/// <summary>
/// 
/// </summary>
class  Guami
{
public:
    Guami();
    virtual ~Guami();

    void validate();

    /////////////////////////////////////////////
    /// Guami members

    /// <summary>
    /// 
    /// </summary>
    PlmnId getPlmnId() const;
    void setPlmnId(PlmnId const& value);
        /// <summary>
    /// 
    /// </summary>
    std::string getAmfId() const;
    void setAmfId(std::string const& value);
    
    friend void to_json(nlohmann::json& j, const Guami& o);
    friend void from_json(const nlohmann::json& j, Guami& o);
protected:
    PlmnId m_PlmnId;

    std::string m_AmfId;

};

}
}
}

#endif /* Guami_H_ */
