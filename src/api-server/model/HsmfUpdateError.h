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
 * HsmfUpdateError.h
 *
 * 
 */

#ifndef HsmfUpdateError_H_
#define HsmfUpdateError_H_


#include "ProblemDetails.h"
#include "RefToBinaryData.h"
#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
/// 
/// </summary>
class  HsmfUpdateError
{
public:
    HsmfUpdateError();
    virtual ~HsmfUpdateError();

    void validate();

    /////////////////////////////////////////////
    /// HsmfUpdateError members

    /// <summary>
    /// 
    /// </summary>
    ProblemDetails getError() const;
    void setError(ProblemDetails const& value);
        /// <summary>
    /// 
    /// </summary>
    int32_t getPti() const;
    void setPti(int32_t const value);
    bool ptiIsSet() const;
    void unsetPti();
    /// <summary>
    /// 
    /// </summary>
    std::string getN1smCause() const;
    void setN1smCause(std::string const& value);
    bool n1smCauseIsSet() const;
    void unsetN1smCause();
    /// <summary>
    /// 
    /// </summary>
    RefToBinaryData getN1SmInfoToUe() const;
    void setN1SmInfoToUe(RefToBinaryData const& value);
    bool n1SmInfoToUeIsSet() const;
    void unsetN1SmInfoToUe();
    /// <summary>
    /// 
    /// </summary>
    int32_t getBackOffTimer() const;
    void setBackOffTimer(int32_t const value);
    bool backOffTimerIsSet() const;
    void unsetBackOffTimer();
    /// <summary>
    /// 
    /// </summary>
    std::string getRecoveryTime() const;
    void setRecoveryTime(std::string const& value);
    bool recoveryTimeIsSet() const;
    void unsetRecoveryTime();

    friend void to_json(nlohmann::json& j, const HsmfUpdateError& o);
    friend void from_json(const nlohmann::json& j, HsmfUpdateError& o);
protected:
    ProblemDetails m_Error;

    int32_t m_Pti;
    bool m_PtiIsSet;
    std::string m_N1smCause;
    bool m_N1smCauseIsSet;
    RefToBinaryData m_N1SmInfoToUe;
    bool m_N1SmInfoToUeIsSet;
    int32_t m_BackOffTimer;
    bool m_BackOffTimerIsSet;
    std::string m_RecoveryTime;
    bool m_RecoveryTimeIsSet;
};

}
}
}

#endif /* HsmfUpdateError_H_ */
