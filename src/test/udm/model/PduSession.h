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
 * PduSession.h
 *
 * 
 */

#ifndef PduSession_H_
#define PduSession_H_


#include <string>
#include "PlmnId.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace udm {
namespace model {

/// <summary>
/// 
/// </summary>
class  PduSession
{
public:
    PduSession();
    virtual ~PduSession();

    void validate();

    /////////////////////////////////////////////
    /// PduSession members

    /// <summary>
    /// 
    /// </summary>
    std::string getDnn() const;
    void setDnn(std::string const& value);
        /// <summary>
    /// 
    /// </summary>
    std::string getSmfInstanceId() const;
    void setSmfInstanceId(std::string const& value);
        /// <summary>
    /// 
    /// </summary>
    PlmnId getPlmnId() const;
    void setPlmnId(PlmnId const& value);
    
    friend void to_json(nlohmann::json& j, const PduSession& o);
    friend void from_json(const nlohmann::json& j, PduSession& o);
protected:
    std::string m_Dnn;

    std::string m_SmfInstanceId;

    PlmnId m_PlmnId;

};

}
}
}

#endif /* PduSession_H_ */