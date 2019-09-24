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
 * ModificationNotification.h
 *
 * 
 */

#ifndef ModificationNotification_H_
#define ModificationNotification_H_


#include "NotifyItem.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace udm {
namespace model {

/// <summary>
/// 
/// </summary>
class  ModificationNotification
{
public:
    ModificationNotification();
    virtual ~ModificationNotification();

    void validate();

    /////////////////////////////////////////////
    /// ModificationNotification members

    /// <summary>
    /// 
    /// </summary>
    std::vector<NotifyItem>& getNotifyItems();
    
    friend void to_json(nlohmann::json& j, const ModificationNotification& o);
    friend void from_json(const nlohmann::json& j, ModificationNotification& o);
protected:
    std::vector<NotifyItem> m_NotifyItems;

};

}
}
}

#endif /* ModificationNotification_H_ */
