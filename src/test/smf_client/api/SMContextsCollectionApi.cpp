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


#include "SMContextsCollectionApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>



#include <boost/algorithm/string/replace.hpp>

namespace oai {
namespace smf {
namespace api {

using namespace oai::smf::model;

SMContextsCollectionApi::SMContextsCollectionApi( std::shared_ptr<ApiClient> apiClient )
    : m_ApiClient(apiClient)
{
}

SMContextsCollectionApi::~SMContextsCollectionApi()
{
}

pplx::task<std::shared_ptr<SmContextCreatedData>> SMContextsCollectionApi::postSmContexts(std::shared_ptr<SmContextMessage> smContextMessage)
{

    // verify the required parameter 'smContextMessage' is set
    if (smContextMessage == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'smContextMessage' when calling SMContextsCollectionApi->postSmContexts"));
    }


    std::shared_ptr<ApiConfiguration> localVarApiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t localVarPath = utility::conversions::to_string_t("/sm-contexts");
    
    std::map<utility::string_t, utility::string_t> localVarQueryParams;
    std::map<utility::string_t, utility::string_t> localVarHeaderParams( localVarApiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> localVarFormParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> localVarFileParams;

    std::unordered_set<utility::string_t> localVarResponseHttpContentTypes;
    localVarResponseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );
    //localVarResponseHttpContentTypes.insert( utility::conversions::to_string_t("multipart/related") );
    //localVarResponseHttpContentTypes.insert( utility::conversions::to_string_t("application/problem+json") );

    utility::string_t localVarResponseHttpContentType;

    // use JSON if possible
    if ( localVarResponseHttpContentTypes.size() == 0 )
    {
        localVarResponseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( localVarResponseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != localVarResponseHttpContentTypes.end() )
    {
        localVarResponseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( localVarResponseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != localVarResponseHttpContentTypes.end() )
    {
        localVarResponseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(400, utility::conversions::to_string_t("SMContextsCollectionApi->postSmContexts does not produce any supported media type"));
    }

    localVarHeaderParams[utility::conversions::to_string_t("Accept")] = localVarResponseHttpContentType;

    std::unordered_set<utility::string_t> localVarConsumeHttpContentTypes;
    //localVarConsumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );
    localVarConsumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );


    std::shared_ptr<IHttpBody> localVarHttpBody;
    utility::string_t localVarRequestHttpContentType;

    // use JSON if possible
    if ( localVarConsumeHttpContentTypes.size() == 0 || localVarConsumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != localVarConsumeHttpContentTypes.end() )
    {
    	localVarRequestHttpContentType = utility::conversions::to_string_t("application/json");
        web::json::value localVarJson;

        localVarJson = ModelBase::toJson(smContextMessage);
        auto supi = localVarJson[U("jsonData")][U("supi")];
        std::cout << supi <<std::endl;
        localVarHttpBody = std::shared_ptr<IHttpBody>( new JsonBody( localVarJson ) );
    }
    // multipart formdata
    else if( localVarConsumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != localVarConsumeHttpContentTypes.end() )
    {
        localVarRequestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
        std::shared_ptr<MultipartFormData> localVarMultipart(new MultipartFormData);

        if(smContextMessage.get())
        {
        	smContextMessage->toMultipart(localVarMultipart, utility::conversions::to_string_t("smContextMessage"));
        }

        localVarHttpBody = localVarMultipart;
        localVarRequestHttpContentType += utility::conversions::to_string_t("; boundary=") + localVarMultipart->getBoundary();
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("SMContextsCollectionApi->postSmContexts does not consume any supported media type"));
    }

    // authentication (oAuth2ClientCredentials) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(localVarPath, utility::conversions::to_string_t("POST"), localVarQueryParams, localVarHttpBody, localVarHeaderParams, localVarFormParams, localVarFileParams, localVarRequestHttpContentType)
    .then([=](web::http::http_response localVarResponse)
    {
        if (m_ApiClient->getResponseHandler())
        {
            m_ApiClient->getResponseHandler()(localVarResponse.status_code(), localVarResponse.headers());
        }

        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (localVarResponse.status_code() >= 400)
        {
            throw ApiException(localVarResponse.status_code()
                , utility::conversions::to_string_t("error calling postSmContexts: ") + localVarResponse.reason_phrase()
                , std::make_shared<std::stringstream>(localVarResponse.extract_utf8string(true).get()));
        }

        // check response content type
        if(localVarResponse.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t localVarContentType = localVarResponse.headers()[utility::conversions::to_string_t("Content-Type")];
            if( localVarContentType.find(localVarResponseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postSmContexts: unexpected response type: ") + localVarContentType
                    , std::make_shared<std::stringstream>(localVarResponse.extract_utf8string(true).get()));
            }
        }

        return localVarResponse.extract_string();
    })
    .then([=](utility::string_t localVarResponse)
    {
        std::shared_ptr<SmContextCreatedData> localVarResult(new SmContextCreatedData());

        if(localVarResponseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value localVarJson = web::json::value::parse(localVarResponse);

            localVarResult->fromJson(localVarJson);
        }
        // else if(localVarResponseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postSmContexts: unsupported response type"));
        }

        return localVarResult;
    });
}

}
}
}

