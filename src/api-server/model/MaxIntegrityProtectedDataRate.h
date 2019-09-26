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
 * MaxIntegrityProtectedDataRate.h
 *
 * Possible values are   - 64_KBPS   - MAX_UE_RATE 
 */

#ifndef MaxIntegrityProtectedDataRate_H_
#define MaxIntegrityProtectedDataRate_H_


#include <nlohmann/json.hpp>

namespace oai {
namespace smf {
namespace model {

/// <summary>
/// Possible values are   - 64_KBPS   - MAX_UE_RATE 
/// </summary>
class  MaxIntegrityProtectedDataRate
{
public:
    MaxIntegrityProtectedDataRate();
    virtual ~MaxIntegrityProtectedDataRate();

    void validate();

    /////////////////////////////////////////////
    /// MaxIntegrityProtectedDataRate members


    friend void to_json(nlohmann::json& j, const MaxIntegrityProtectedDataRate& o);
    friend void from_json(const nlohmann::json& j, MaxIntegrityProtectedDataRate& o);
protected:
};

}
}
}

#endif /* MaxIntegrityProtectedDataRate_H_ */