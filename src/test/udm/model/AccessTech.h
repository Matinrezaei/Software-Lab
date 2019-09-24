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
/*
 * AccessTech.h
 *
 * 
 */

#ifndef AccessTech_H_
#define AccessTech_H_


#include <nlohmann/json.hpp>

namespace oai {
namespace udm {
namespace model {

/// <summary>
/// 
/// </summary>
class  AccessTech
{
public:
    AccessTech();
    virtual ~AccessTech();

    void validate();

    /////////////////////////////////////////////
    /// AccessTech members


    friend void to_json(nlohmann::json& j, const AccessTech& o);
    friend void from_json(const nlohmann::json& j, AccessTech& o);
protected:
};

}
}
}

#endif /* AccessTech_H_ */
