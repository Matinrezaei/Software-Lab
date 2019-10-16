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
 * VsmfUpdateError.h
 *
 * 
 */

#ifndef VsmfUpdateError_H_
#define VsmfUpdateError_H_


#include "NgApCause.h"
#include "ProblemDetails.h"
#include "RefToBinaryData.h"
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
/// 
/// </summary>
class  VsmfUpdateError
{
public:
    VsmfUpdateError();
    virtual ~VsmfUpdateError();

    void validate();

    /////////////////////////////////////////////
    /// VsmfUpdateError members

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
    RefToBinaryData getN1SmInfoFromUe() const;
    void setN1SmInfoFromUe(RefToBinaryData const& value);
    bool n1SmInfoFromUeIsSet() const;
    void unsetN1SmInfoFromUe();
    /// <summary>
    /// 
    /// </summary>
    RefToBinaryData getUnknownN1SmInfo() const;
    void setUnknownN1SmInfo(RefToBinaryData const& value);
    bool unknownN1SmInfoIsSet() const;
    void unsetUnknownN1SmInfo();
    /// <summary>
    /// 
    /// </summary>
    std::vector<int32_t>& getFailedToAssignEbiList();
    bool failedToAssignEbiListIsSet() const;
    void unsetFailedToAssignEbiList();
    /// <summary>
    /// 
    /// </summary>
    NgApCause getNgApCause() const;
    void setNgApCause(NgApCause const& value);
    bool ngApCauseIsSet() const;
    void unsetNgApCause();
    /// <summary>
    /// 
    /// </summary>
    int32_t get5gMmCauseValue() const;
    void set5gMmCauseValue(int32_t const value);
    bool _5gMmCauseValueIsSet() const;
    void unset_5gMmCauseValue();
    /// <summary>
    /// 
    /// </summary>
    std::string getRecoveryTime() const;
    void setRecoveryTime(std::string const& value);
    bool recoveryTimeIsSet() const;
    void unsetRecoveryTime();

    friend void to_json(nlohmann::json& j, const VsmfUpdateError& o);
    friend void from_json(const nlohmann::json& j, VsmfUpdateError& o);
protected:
    ProblemDetails m_Error;

    int32_t m_Pti;
    bool m_PtiIsSet;
    std::string m_N1smCause;
    bool m_N1smCauseIsSet;
    RefToBinaryData m_N1SmInfoFromUe;
    bool m_N1SmInfoFromUeIsSet;
    RefToBinaryData m_UnknownN1SmInfo;
    bool m_UnknownN1SmInfoIsSet;
    std::vector<int32_t> m_FailedToAssignEbiList;
    bool m_FailedToAssignEbiListIsSet;
    NgApCause m_NgApCause;
    bool m_NgApCauseIsSet;
    int32_t m__5gMmCauseValue;
    bool m__5gMmCauseValueIsSet;
    std::string m_RecoveryTime;
    bool m_RecoveryTimeIsSet;
};

}
}
}

#endif /* VsmfUpdateError_H_ */
