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
 * ExemptionInd.h
 *
 * 
 */

#ifndef ExemptionInd_H_
#define ExemptionInd_H_


#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
/// 
/// </summary>
class  ExemptionInd
{
public:
    ExemptionInd();
    virtual ~ExemptionInd();

    void validate();

    /////////////////////////////////////////////
    /// ExemptionInd members

    /// <summary>
    /// 
    /// </summary>
    bool isDnnCongestion() const;
    void setDnnCongestion(bool const value);
    bool dnnCongestionIsSet() const;
    void unsetDnnCongestion();
    /// <summary>
    /// 
    /// </summary>
    bool isSnssaiOnlyCongestion() const;
    void setSnssaiOnlyCongestion(bool const value);
    bool snssaiOnlyCongestionIsSet() const;
    void unsetSnssaiOnlyCongestion();
    /// <summary>
    /// 
    /// </summary>
    bool isSnssaiDnnCongestion() const;
    void setSnssaiDnnCongestion(bool const value);
    bool snssaiDnnCongestionIsSet() const;
    void unsetSnssaiDnnCongestion();

    friend void to_json(nlohmann::json& j, const ExemptionInd& o);
    friend void from_json(const nlohmann::json& j, ExemptionInd& o);
protected:
    bool m_DnnCongestion;
    bool m_DnnCongestionIsSet;
    bool m_SnssaiOnlyCongestion;
    bool m_SnssaiOnlyCongestionIsSet;
    bool m_SnssaiDnnCongestion;
    bool m_SnssaiDnnCongestionIsSet;
};

}
}
}

#endif /* ExemptionInd_H_ */
