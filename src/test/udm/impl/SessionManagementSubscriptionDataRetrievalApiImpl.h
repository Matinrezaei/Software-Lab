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
* SessionManagementSubscriptionDataRetrievalApiImpl.h
*
* 
*/

#ifndef SESSION_MANAGEMENT_SUBSCRIPTION_DATA_RETRIEVAL_API_IMPL_H_
#define SESSION_MANAGEMENT_SUBSCRIPTION_DATA_RETRIEVAL_API_IMPL_H_


#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>

#include <SessionManagementSubscriptionDataRetrievalApi.h>

#include <pistache/optional.h>

#include "PlmnId.h"
#include "ProblemDetails.h"
#include "SessionManagementSubscriptionData.h"
#include "Snssai.h"
#include <string>

namespace oai {
namespace udm {
namespace api {

using namespace oai::udm::model;

class SessionManagementSubscriptionDataRetrievalApiImpl : public oai::udm::api::SessionManagementSubscriptionDataRetrievalApi {
public:
    SessionManagementSubscriptionDataRetrievalApiImpl(std::shared_ptr<Pistache::Rest::Router>);
    ~SessionManagementSubscriptionDataRetrievalApiImpl() {}

    //void get_sm_data(const std::string &supi, const Pistache::Optional<std::string> &supportedFeatures, const Pistache::Optional<Snssai> &singleNssai, const Pistache::Optional<std::string> &dnn, const Pistache::Optional<PlmnId> &plmnId, const Pistache::Optional<Pistache::Http::Header::Raw> &ifNoneMatch, const Pistache::Optional<Pistache::Http::Header::Raw> &ifModifiedSince, Pistache::Http::ResponseWriter &response);
    void get_sm_data(const std::string &supi, const Pistache::Optional<Snssai> &singleNssai, const Pistache::Optional<std::string> &dnn, Pistache::Http::ResponseWriter &response);

};

}
}
}



#endif
