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
 * SmContextCreateError.h
 *
 * 
 */

#ifndef SmContextCreateError_H_
#define SmContextCreateError_H_


#include "ProblemDetails.h"
#include "RefToBinaryData.h"
#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace smf {
namespace model {

/// <summary>
/// 
/// </summary>
class  SmContextCreateError
{
public:
    SmContextCreateError();
    virtual ~SmContextCreateError();

    void validate();

    /////////////////////////////////////////////
    /// SmContextCreateError members

    /// <summary>
    /// 
    /// </summary>
    ProblemDetails getError() const;
    void setError(ProblemDetails const& value);
        /// <summary>
    /// 
    /// </summary>
    RefToBinaryData getN1SmMsg() const;
    void setN1SmMsg(RefToBinaryData const& value);
    bool n1SmMsgIsSet() const;
    void unsetN1SmMsg();
    /// <summary>
    /// 
    /// </summary>
    std::string getRecoveryTime() const;
    void setRecoveryTime(std::string const& value);
    bool recoveryTimeIsSet() const;
    void unsetRecoveryTime();

    friend void to_json(nlohmann::json& j, const SmContextCreateError& o);
    friend void from_json(const nlohmann::json& j, SmContextCreateError& o);
protected:
    ProblemDetails m_Error;

    RefToBinaryData m_N1SmMsg;
    bool m_N1SmMsgIsSet;
    std::string m_RecoveryTime;
    bool m_RecoveryTimeIsSet;
};

}
}
}

#endif /* SmContextCreateError_H_ */
