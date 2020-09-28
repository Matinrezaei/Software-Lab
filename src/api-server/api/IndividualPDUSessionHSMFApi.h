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
/*
 * IndividualPDUSessionHSMFApi.h
 *
 * 
 */

#ifndef IndividualPDUSessionHSMFApi_H_
#define IndividualPDUSessionHSMFApi_H_

#include <string>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>

#include "HsmfUpdateData.h"
#include "HsmfUpdateError.h"
#include "HsmfUpdatedData.h"
#include "ProblemDetails.h"
#include "ReleaseData.h"

namespace oai {
namespace smf_server {
namespace api {

using namespace oai::smf_server::model;

class IndividualPDUSessionHSMFApi {
 public:
  IndividualPDUSessionHSMFApi(std::shared_ptr<Pistache::Rest::Router>);
  virtual ~IndividualPDUSessionHSMFApi() {
  }
  void init();

  const std::string base = "/nsmf-pdusession/";

 private:
  void setupRoutes();

  void release_pdu_session_handler(const Pistache::Rest::Request &request,
                                   Pistache::Http::ResponseWriter response);
  void update_pdu_session_handler(const Pistache::Rest::Request &request,
                                  Pistache::Http::ResponseWriter response);
  void individual_pdu_session_hsmf_api_default_handler(
      const Pistache::Rest::Request &request,
      Pistache::Http::ResponseWriter response);

  std::shared_ptr<Pistache::Rest::Router> router;

  /// <summary>
  /// Release
  /// </summary>
  /// <remarks>
  ///
  /// </remarks>
  /// <param name="pduSessionRef">PDU session reference</param>
  /// <param name="releaseData">representation of the data to be sent to H-SMF when releasing the PDU session (optional)</param>
  virtual void release_pdu_session(
      const std::string &pduSessionRef, const ReleaseData &releaseData,
      Pistache::Http::ResponseWriter &response) = 0;

  /// <summary>
  /// Update (initiated by V-SMF)
  /// </summary>
  /// <remarks>
  ///
  /// </remarks>
  /// <param name="pduSessionRef">PDU session reference</param>
  /// <param name="hsmfUpdateData">representation of the updates to apply to the PDU session</param>
  virtual void update_pdu_session(const std::string &pduSessionRef,
                                  const HsmfUpdateData &hsmfUpdateData,
                                  Pistache::Http::ResponseWriter &response) = 0;

};

}
}
}

#endif /* IndividualPDUSessionHSMFApi_H_ */

