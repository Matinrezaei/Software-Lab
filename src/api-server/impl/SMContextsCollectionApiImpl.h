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
 * SMContextsCollectionApiImpl.h
 *
 *
 */
/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

#ifndef SM_CONTEXTS_COLLECTION_API_IMPL_H_
#define SM_CONTEXTS_COLLECTION_API_IMPL_H_

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>

#include <SMContextsCollectionApi.h>

#include <pistache/optional.h>

#include "SmContextMessage.h"
#include "ProblemDetails.h"
#include "SmContextCreateError.h"
#include "SmContextCreatedData.h"
#include "smf_app.hpp"

namespace oai {
namespace smf_server {
namespace api {

using namespace oai::smf_server::model;

class SMContextsCollectionApiImpl : public oai::smf_server::api::SMContextsCollectionApi {
 public:
  SMContextsCollectionApiImpl(std::shared_ptr<Pistache::Rest::Router>, smf::smf_app *smf_app_inst, std::string address);
  ~SMContextsCollectionApiImpl() {
  }

  void post_sm_contexts(const SmContextMessage &smContextMessage, Pistache::Http::ResponseWriter &response);
 private:
  smf::smf_app *m_smf_app;
  std::string m_address;
};

}
}
}

#endif
