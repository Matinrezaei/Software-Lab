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
 * QosFlowItem.h
 *
 * 
 */

#ifndef OAI_SMF_MODEL_QosFlowItem_H_
#define OAI_SMF_MODEL_QosFlowItem_H_


#include "../ModelBase.h"

#include "Cause.h"

namespace oai {
namespace smf {
namespace model {


/// <summary>
/// 
/// </summary>
class  QosFlowItem
    : public ModelBase
{
public:
    QosFlowItem();
    virtual ~QosFlowItem();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// QosFlowItem members

    /// <summary>
    /// 
    /// </summary>
    int32_t getQfi() const;
    
    void setQfi(int32_t value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<Cause> getCause() const;
    bool causeIsSet() const;
    void unsetCause();

    void setCause(const std::shared_ptr<Cause>& value);


protected:
    int32_t m_Qfi;
        std::shared_ptr<Cause> m_Cause;
    bool m_CauseIsSet;
};


}
}
}

#endif /* OAI_SMF_MODEL_QosFlowItem_H_ */
