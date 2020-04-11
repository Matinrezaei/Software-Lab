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

#include "IndividualPDUSessionHSMFApi.h"
#include "Helpers.h"

namespace oai {
namespace smf_server {
namespace api {

using namespace oai::smf_server::helpers;
using namespace oai::smf_server::model;

IndividualPDUSessionHSMFApi::IndividualPDUSessionHSMFApi(std::shared_ptr<Pistache::Rest::Router> rtr) { 
  router = rtr;
}

void IndividualPDUSessionHSMFApi::init() {
  setupRoutes();
}

void IndividualPDUSessionHSMFApi::setupRoutes() {
  using namespace Pistache::Rest;

  Routes::Post(*router, base + "/pdu-sessions/:pduSessionRef/release", Routes::bind(&IndividualPDUSessionHSMFApi::release_pdu_session_handler, this));
  Routes::Post(*router, base + "/pdu-sessions/:pduSessionRef/modify", Routes::bind(&IndividualPDUSessionHSMFApi::update_pdu_session_handler, this));

  // Default handler, called when a route is not found
  router->addCustomHandler(Routes::bind(&IndividualPDUSessionHSMFApi::individual_pdu_session_hsmf_api_default_handler, this));
}

void IndividualPDUSessionHSMFApi::release_pdu_session_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
  // Getting the path params
  auto pduSessionRef = request.param(":pduSessionRef").as<std::string>();

  // Getting the body param

  ReleaseData releaseData = {};

  try {
    nlohmann::json::parse(request.body()).get_to(releaseData);
    this->release_pdu_session(pduSessionRef, releaseData, response);
  } catch (nlohmann::detail::exception &e) {
    //send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (std::exception &e) {
    //send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }

}
void IndividualPDUSessionHSMFApi::update_pdu_session_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
  // Getting the path params
  auto pduSessionRef = request.param(":pduSessionRef").as<std::string>();

  // Getting the body param

  HsmfUpdateData hsmfUpdateData = {};

  try {
    nlohmann::json::parse(request.body()).get_to(hsmfUpdateData);
    this->update_pdu_session(pduSessionRef, hsmfUpdateData, response);
  } catch (nlohmann::detail::exception &e) {
    //send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (std::exception &e) {
    //send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }

}

void IndividualPDUSessionHSMFApi::individual_pdu_session_hsmf_api_default_handler(const Pistache::Rest::Request &, Pistache::Http::ResponseWriter response) {
  response.send(Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

}
}
}

