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
 * PresenceState.h
 *
 * 
 */

#ifndef PresenceState_H_
#define PresenceState_H_


#include <nlohmann/json.hpp>

namespace oai {
namespace amf {
namespace model {

/// <summary>
/// 
/// </summary>
class  PresenceState
{
public:
    PresenceState();
    virtual ~PresenceState();

    void validate();

    /////////////////////////////////////////////
    /// PresenceState members


    friend void to_json(nlohmann::json& j, const PresenceState& o);
    friend void from_json(const nlohmann::json& j, PresenceState& o);
protected:
};

}
}
}

#endif /* PresenceState_H_ */