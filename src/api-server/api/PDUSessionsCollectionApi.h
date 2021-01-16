/**
 * Nsmf_PDUSession
 * SMF PDU Session Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

/*
 * PDUSessionsCollectionApi.h
 *
 *
 */

#ifndef PDUSessionsCollectionApi_H_
#define PDUSessionsCollectionApi_H_

#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>

#include "PduSessionCreateData.h"
#include "PduSessionCreateError.h"
#include "PduSessionCreatedData.h"
#include "ProblemDetails.h"

namespace oai {
namespace smf_server {
namespace api {

using namespace oai::smf_server::model;

class PDUSessionsCollectionApi {
 public:
  PDUSessionsCollectionApi(std::shared_ptr<Pistache::Rest::Router>);
  virtual ~PDUSessionsCollectionApi() {}
  void init();

  const std::string base = "/nsmf-pdusession/";

 private:
  void setupRoutes();

  void post_pdu_sessions_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);
  void pdu_sessions_collection_api_default_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);

  std::shared_ptr<Pistache::Rest::Router> router;

  /// <summary>
  /// Create
  /// </summary>
  /// <remarks>
  ///
  /// </remarks>
  /// <param name="pduSessionCreateData">representation of the PDU session to be
  /// created in the H-SMF</param>
  virtual void post_pdu_sessions(
      const PduSessionCreateData& pduSessionCreateData,
      Pistache::Http::ResponseWriter& response) = 0;
};

}  // namespace api
}  // namespace smf_server
}  // namespace oai

#endif /* PDUSessionsCollectionApi_H_ */
