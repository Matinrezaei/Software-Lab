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
* SubscriptionCreationForSharedDataApiImpl.h
*
* 
*/

#ifndef SUBSCRIPTION_CREATION_FOR_SHARED_DATA_API_IMPL_H_
#define SUBSCRIPTION_CREATION_FOR_SHARED_DATA_API_IMPL_H_


#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>

#include <SubscriptionCreationForSharedDataApi.h>

#include <pistache/optional.h>

#include "ProblemDetails.h"
#include "SdmSubscription.h"

namespace oai {
namespace udm {
namespace api {

using namespace oai::udm::model;

class SubscriptionCreationForSharedDataApiImpl : public oai::udm::api::SubscriptionCreationForSharedDataApi {
public:
    SubscriptionCreationForSharedDataApiImpl(std::shared_ptr<Pistache::Rest::Router>);
    ~SubscriptionCreationForSharedDataApiImpl() {}

    void subscribe_to_shared_data(const SdmSubscription &sdmSubscription, Pistache::Http::ResponseWriter &response);

};

}
}
}



#endif