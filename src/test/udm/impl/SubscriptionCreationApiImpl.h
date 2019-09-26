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
* SubscriptionCreationApiImpl.h
*
* 
*/

#ifndef SUBSCRIPTION_CREATION_API_IMPL_H_
#define SUBSCRIPTION_CREATION_API_IMPL_H_


#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>

#include <SubscriptionCreationApi.h>

#include <pistache/optional.h>

#include "ProblemDetails.h"
#include "SdmSubscription.h"
#include <string>

namespace oai {
namespace udm {
namespace api {

using namespace oai::udm::model;

class SubscriptionCreationApiImpl : public oai::udm::api::SubscriptionCreationApi {
public:
    SubscriptionCreationApiImpl(std::shared_ptr<Pistache::Rest::Router>);
    ~SubscriptionCreationApiImpl() {}

    void subscribe(const std::string &supi, const SdmSubscription &sdmSubscription, Pistache::Http::ResponseWriter &response);

};

}
}
}



#endif