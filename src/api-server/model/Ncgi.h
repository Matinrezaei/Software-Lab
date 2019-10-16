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
 * Ncgi.h
 *
 * 
 */

#ifndef Ncgi_H_
#define Ncgi_H_


#include <string>
#include "PlmnId.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
/// 
/// </summary>
class  Ncgi
{
public:
    Ncgi();
    virtual ~Ncgi();

    void validate();

    /////////////////////////////////////////////
    /// Ncgi members

    /// <summary>
    /// 
    /// </summary>
    PlmnId getPlmnId() const;
    void setPlmnId(PlmnId const& value);
        /// <summary>
    /// 
    /// </summary>
    std::string getNrCellId() const;
    void setNrCellId(std::string const& value);
    
    friend void to_json(nlohmann::json& j, const Ncgi& o);
    friend void from_json(const nlohmann::json& j, Ncgi& o);
protected:
    PlmnId m_PlmnId;

    std::string m_NrCellId;

};

}
}
}

#endif /* Ncgi_H_ */
