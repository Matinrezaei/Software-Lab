/**
* Namf_Communication
* AMF Communication Service © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
*
* The version of the OpenAPI document: 1.1.0.alpha-1
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/

#include "NonUEN2MessagesSubscriptionsCollectionDocumentApiImpl.h"

namespace oai {
namespace amf {
namespace api {

using namespace oai::amf::model;

NonUEN2MessagesSubscriptionsCollectionDocumentApiImpl::NonUEN2MessagesSubscriptionsCollectionDocumentApiImpl(std::shared_ptr<Pistache::Rest::Router> rtr)
    : NonUEN2MessagesSubscriptionsCollectionDocumentApi(rtr)
    { }

void NonUEN2MessagesSubscriptionsCollectionDocumentApiImpl::non_ue_n2_info_subscribe(const NonUeN2InfoSubscriptionCreateData &nonUeN2InfoSubscriptionCreateData, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}

}
}
}

