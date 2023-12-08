/**
 * Nsmf_EventExposure
 * Session Management Event Exposure Service. © 2019, 3GPP Organizational
 * Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "IndividualSubscriptionDocumentApi.h"
#include "Helpers.h"
#include "smf_config.hpp"

extern smf::smf_config smf_cfg;

namespace oai {
namespace smf_server {
namespace api {

using namespace oai::smf_server::helpers;
using namespace oai::smf_server::model;

IndividualSubscriptionDocumentApi::IndividualSubscriptionDocumentApi(
    std::shared_ptr<Pistache::Rest::Router> rtr) {
  router = rtr;
}

void IndividualSubscriptionDocumentApi::init() {
  setupRoutes();
}

void IndividualSubscriptionDocumentApi::setupRoutes() {
  using namespace Pistache::Rest;

  Routes::Delete(
      *router, base + smf_cfg.sbi_api_version + "/subscriptions/:subId",
      Routes::bind(
          &IndividualSubscriptionDocumentApi::
              delete_individual_subcription_handler,
          this));
  Routes::Get(
      *router, base + smf_cfg.sbi_api_version + "/subscriptions/:subId",
      Routes::bind(
          &IndividualSubscriptionDocumentApi::
              get_individual_subcription_handler,
          this));
  Routes::Put(
      *router, base + smf_cfg.sbi_api_version + "/subscriptions/:subId",
      Routes::bind(
          &IndividualSubscriptionDocumentApi::
              replace_individual_subcription_handler,
          this));

  // Default handler, called when a route is not found
  router->addCustomHandler(Routes::bind(
      &IndividualSubscriptionDocumentApi::
          individual_subscription_document_api_default_handler,
      this));
}

void IndividualSubscriptionDocumentApi::delete_individual_subcription_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  // Getting the path params
  auto subId = request.param(":subId").as<std::string>();

  try {
    this->delete_individual_subcription(subId, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}
void IndividualSubscriptionDocumentApi::get_individual_subcription_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  // Getting the path params
  auto subId = request.param(":subId").as<std::string>();

  try {
    this->get_individual_subcription(subId, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}
void IndividualSubscriptionDocumentApi::replace_individual_subcription_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  // Getting the path params
  auto subId = request.param(":subId").as<std::string>();

  // Getting the body param

  NsmfEventExposure nsmfEventExposure;

  try {
    nlohmann::json::parse(request.body()).get_to(nsmfEventExposure);
    this->replace_individual_subcription(subId, nsmfEventExposure, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}

void IndividualSubscriptionDocumentApi::
    individual_subscription_document_api_default_handler(
        const Pistache::Rest::Request&,
        Pistache::Http::ResponseWriter response) {
  response.send(
      Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

}  // namespace api
}  // namespace smf_server
}  // namespace oai
