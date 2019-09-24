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
 * HoState.h
 *
 * Possible values are - NONE - PREPARING - PREPARED - COMPLETED - CANCELLED 
 */

#ifndef HoState_H_
#define HoState_H_


#include <nlohmann/json.hpp>

namespace oai {
namespace smf {
namespace model {

/// <summary>
/// Possible values are - NONE - PREPARING - PREPARED - COMPLETED - CANCELLED 
/// </summary>
class  HoState
{
public:
    HoState();
    virtual ~HoState();

    void validate();

    /////////////////////////////////////////////
    /// HoState members


    friend void to_json(nlohmann::json& j, const HoState& o);
    friend void from_json(const nlohmann::json& j, HoState& o);
protected:
};

}
}
}

#endif /* HoState_H_ */
