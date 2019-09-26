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
 * SubscriptionDeletionForSharedDataApi.h
 *
 * 
 */

#ifndef SubscriptionDeletionForSharedDataApi_H_
#define SubscriptionDeletionForSharedDataApi_H_


#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>


#include "ProblemDetails.h"
#include <string>

namespace oai {
namespace udm {
namespace api {

using namespace oai::udm::model;

class  SubscriptionDeletionForSharedDataApi {
public:
    SubscriptionDeletionForSharedDataApi(std::shared_ptr<Pistache::Rest::Router>);
    virtual ~SubscriptionDeletionForSharedDataApi() {}
    void init();

    const std::string base = "/nudm-sdm/v2";

private:
    void setupRoutes();

    void unsubscribe_for_shared_data_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void subscription_deletion_for_shared_data_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

    std::shared_ptr<Pistache::Rest::Router> router;

    /// <summary>
    /// unsubscribe from notifications for shared data
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="subscriptionId">Id of the Shared data Subscription</param>
    virtual void unsubscribe_for_shared_data(const std::string &subscriptionId, Pistache::Http::ResponseWriter &response) = 0;

};

}
}
}

#endif /* SubscriptionDeletionForSharedDataApi_H_ */
