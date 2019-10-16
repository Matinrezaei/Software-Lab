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
 * VolumeTimedReport.h
 *
 * 
 */

#ifndef VolumeTimedReport_H_
#define VolumeTimedReport_H_


#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
/// 
/// </summary>
class  VolumeTimedReport
{
public:
    VolumeTimedReport();
    virtual ~VolumeTimedReport();

    void validate();

    /////////////////////////////////////////////
    /// VolumeTimedReport members

    /// <summary>
    /// 
    /// </summary>
    std::string getStartTimeStamp() const;
    void setStartTimeStamp(std::string const& value);
        /// <summary>
    /// 
    /// </summary>
    std::string getEndTimeStamp() const;
    void setEndTimeStamp(std::string const& value);
        /// <summary>
    /// 
    /// </summary>
    int64_t getDownlinkVolume() const;
    void setDownlinkVolume(int64_t const value);
        /// <summary>
    /// 
    /// </summary>
    int64_t getUplinkVolume() const;
    void setUplinkVolume(int64_t const value);
    
    friend void to_json(nlohmann::json& j, const VolumeTimedReport& o);
    friend void from_json(const nlohmann::json& j, VolumeTimedReport& o);
protected:
    std::string m_StartTimeStamp;

    std::string m_EndTimeStamp;

    int64_t m_DownlinkVolume;

    int64_t m_UplinkVolume;

};

}
}
}

#endif /* VolumeTimedReport_H_ */
