/**
 * Nsmf_PDUSession
 * SMF PDU Session Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 4.1.1-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * N3gaLocation.h
 *
 * 
 */

#ifndef OAI_SMF_MODEL_N3gaLocation_H_
#define OAI_SMF_MODEL_N3gaLocation_H_


#include "../ModelBase.h"

#include "Tai.h"
#include <cpprest/details/basic_types.h>

namespace oai {
namespace smf {
namespace model {


/// <summary>
/// 
/// </summary>
class  N3gaLocation
    : public ModelBase
{
public:
    N3gaLocation();
    virtual ~N3gaLocation();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// N3gaLocation members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<Tai> getN3gppTai() const;
    bool n3gppTaiIsSet() const;
    void unsetN3gppTai();

    void setN3gppTai(const std::shared_ptr<Tai>& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getN3IwfId() const;
    bool n3IwfIdIsSet() const;
    void unsetN3IwfId();

    void setN3IwfId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getUeIpv4Addr() const;
    bool ueIpv4AddrIsSet() const;
    void unsetUeIpv4Addr();

    void setUeIpv4Addr(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getUeIpv6Addr() const;
    bool ueIpv6AddrIsSet() const;
    void unsetUeIpv6Addr();

    void setUeIpv6Addr(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    int32_t getPortNumber() const;
    bool portNumberIsSet() const;
    void unsetPortNumber();

    void setPortNumber(int32_t value);


protected:
    std::shared_ptr<Tai> m_N3gppTai;
    bool m_N3gppTaiIsSet;
    utility::string_t m_N3IwfId;
    bool m_N3IwfIdIsSet;
    utility::string_t m_UeIpv4Addr;
    bool m_UeIpv4AddrIsSet;
    utility::string_t m_UeIpv6Addr;
    bool m_UeIpv6AddrIsSet;
    int32_t m_PortNumber;
    bool m_PortNumberIsSet;
};


}
}
}

#endif /* OAI_SMF_MODEL_N3gaLocation_H_ */