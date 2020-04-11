/**
 * Nsmf_PDUSession
 * SMF PDU Session Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "PDUSessionsCollectionApiImpl.h"

namespace oai {
namespace smf_server {
namespace api {

using namespace oai::smf_server::model;

PDUSessionsCollectionApiImpl::PDUSessionsCollectionApiImpl(std::shared_ptr<Pistache::Rest::Router> rtr, smf::smf_app *smf_app_inst, std::string address)
    :
    PDUSessionsCollectionApi(rtr),
    m_smf_app(smf_app_inst),
    m_address(address) {
}

void PDUSessionsCollectionApiImpl::post_pdu_sessions(const PduSessionCreateData &pduSessionCreateData, Pistache::Http::ResponseWriter &response) {
  Logger::smf_api_server().info("post_pdu_sessions...");
  response.send(Pistache::Http::Code::Ok, "Post_pdu_sessions API has not been implemented yet!\n");

}

}
}
}

