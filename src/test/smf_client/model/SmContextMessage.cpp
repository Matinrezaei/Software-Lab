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



#include "SmContextMessage.h"

namespace oai {
namespace smf {
namespace model {




SmContextMessage::SmContextMessage()
{
    m_JsonDataIsSet = false;
    m_BinaryDataN1SmMessageIsSet = false;
    m_BinaryDataN2SmInformationIsSet = false;
}

SmContextMessage::~SmContextMessage()
{
}

void SmContextMessage::validate()
{
    // TODO: implement validation
}

web::json::value SmContextMessage::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_JsonDataIsSet)
    {
        val[utility::conversions::to_string_t("jsonData")] = ModelBase::toJson(m_JsonData);
    }
    if(m_BinaryDataN1SmMessageIsSet)
    {
       // val[utility::conversions::to_string_t("binaryDataN1SmMessage")] = ModelBase::toJson(m_BinaryDataN1SmMessage);
    }
    if(m_BinaryDataN2SmInformationIsSet)
    {
        //val[utility::conversions::to_string_t("binaryDataN2SmInformation")] = ModelBase::toJson(m_BinaryDataN2SmInformation);
    }

    return val;
}

void SmContextMessage::fromJson(const web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("jsonData")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("jsonData"));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<SmContextCreateData> newItem(new SmContextCreateData());
            newItem->fromJson(fieldValue);
            setJsonData( newItem );
        }
    }
    if(val.has_field(utility::conversions::to_string_t("binaryDataN1SmMessage")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("binaryDataN1SmMessage"));
        if(!fieldValue.is_null())
        {
            //HttpContent newItem();
            //newItem->fromJson(fieldValue);
            //setBinaryDataN1SmMessage( newItem );
        }
    }
    if(val.has_field(utility::conversions::to_string_t("binaryDataN2SmInformation")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("binaryDataN2SmInformation"));
        if(!fieldValue.is_null())
        {
            //HttpContent newItem(utility::conversions::to_string_t(""));
            //newItem->fromJson(fieldValue);
            //setBinaryDataN2SmInformation( newItem );
        }
    }
}

void SmContextMessage::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_JsonDataIsSet)
    {
        if (m_JsonData.get())
        {
            m_JsonData->toMultipart(multipart, utility::conversions::to_string_t("jsonData."));
        }
    }
    if(m_BinaryDataN1SmMessageIsSet)
    {
       /* if (m_BinaryDataN1SmMessage.get())
        {
            m_BinaryDataN1SmMessage->toMultipart(multipart, utility::conversions::to_string_t("binaryDataN1SmMessage."));
        }
      */
    }
    if(m_BinaryDataN2SmInformationIsSet)
    {
      /*  if (m_BinaryDataN2SmInformation.get())
        {
            m_BinaryDataN2SmInformation->toMultipart(multipart, utility::conversions::to_string_t("binaryDataN2SmInformation."));
        }
      */
    }
}

void SmContextMessage::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("jsonData")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("jsonData")))
        {
            std::shared_ptr<SmContextCreateData> newItem(new SmContextCreateData());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("jsonData."));
            setJsonData( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("binaryDataN1SmMessage")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("binaryDataN1SmMessage")))
        {
            //HttpContent newItem(utility::conversions::to_string_t(""));
            //newItem->fromMultiPart(multipart, utility::conversions::to_string_t("binaryDataN1SmMessage."));
            //setBinaryDataN1SmMessage( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("binaryDataN2SmInformation")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("binaryDataN2SmInformation")))
        {
            //HttpContent newItem(utility::conversions::to_string_t(""));
           // newItem->fromMultiPart(multipart, utility::conversions::to_string_t("binaryDataN2SmInformation."));
           // setBinaryDataN2SmInformation( newItem );
        }
    }
}

std::shared_ptr<SmContextCreateData> SmContextMessage::getJsonData() const
{
    return m_JsonData;
}

void SmContextMessage::setJsonData(const std::shared_ptr<SmContextCreateData>& value)
{
    m_JsonData = value;
    m_JsonDataIsSet = true;
}

bool SmContextMessage::jsonDataIsSet() const
{
    return m_JsonDataIsSet;
}

void SmContextMessage::unsetJsonData()
{
    m_JsonDataIsSet = false;
}

HttpContent SmContextMessage::getBinaryDataN1SmMessage() const
{
    return m_BinaryDataN1SmMessage;
}

void SmContextMessage::setBinaryDataN1SmMessage(const HttpContent& value)
{
    m_BinaryDataN1SmMessage = value;
    m_BinaryDataN1SmMessageIsSet = true;
}

bool SmContextMessage::binaryDataN1SmMessageIsSet() const
{
    return m_BinaryDataN1SmMessageIsSet;
}

void SmContextMessage::unsetBinaryDataN1SmMessage()
{
    m_BinaryDataN1SmMessageIsSet = false;
}

HttpContent SmContextMessage::getBinaryDataN2SmInformation() const
{
    return m_BinaryDataN2SmInformation;
}

void SmContextMessage::setBinaryDataN2SmInformation(const HttpContent& value)
{
    m_BinaryDataN2SmInformation = value;
    m_BinaryDataN2SmInformationIsSet = true;
}

bool SmContextMessage::binaryDataN2SmInformationIsSet() const
{
    return m_BinaryDataN2SmInformationIsSet;
}

void SmContextMessage::unsetBinaryDataN2SmInformation()
{
    m_BinaryDataN2SmInformationIsSet = false;
}

}
}
}

