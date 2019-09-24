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

#include "AccessAndMobilitySubscriptionDataRetrievalApiImpl.h"

namespace oai {
namespace udm {
namespace api {

using namespace oai::udm::model;

AccessAndMobilitySubscriptionDataRetrievalApiImpl::AccessAndMobilitySubscriptionDataRetrievalApiImpl(std::shared_ptr<Pistache::Rest::Router> rtr)
    : AccessAndMobilitySubscriptionDataRetrievalApi(rtr)
    { }

void AccessAndMobilitySubscriptionDataRetrievalApiImpl::get_am_data(const std::string &supi, const Pistache::Optional<std::string> &supportedFeatures, const Pistache::Optional<PlmnId> &plmnId, const Pistache::Optional<Pistache::Http::Header::Raw> &ifNoneMatch, const Pistache::Optional<Pistache::Http::Header::Raw> &ifModifiedSince, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}

}
}
}

