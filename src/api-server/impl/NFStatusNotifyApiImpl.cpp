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

/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the
 * License at
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

#include "NFStatusNotifyApiImpl.h"

#include "logger.hpp"
#include "smf_msg.hpp"
#include "itti_msg_sbi.hpp"
#include "smf_config.hpp"

extern smf::smf_config smf_cfg;

namespace oai {
namespace smf_server {
namespace api {

using namespace oai::smf_server::model;

NFStatusNotifyApiImpl::NFStatusNotifyApiImpl(
    std::shared_ptr<Pistache::Rest::Router> rtr, smf::smf_app* smf_app_inst,
    std::string address)
    : NFStatusNotifyApi(rtr), m_smf_app(smf_app_inst), m_address(address) {}

void NFStatusNotifyApiImpl::receive_nf_status_notification(
    const NotificationData& notificationData,
    Pistache::Http::ResponseWriter& response) {
  Logger::smf_api_server().info(
      "NFStatusNotifyApiImpl, received a NF status notification...");

  smf::data_notification_msg notification_msg = {};
  notification_msg.set_notification_event_type(notificationData.getEvent());
  notification_msg.set_nf_instance_uri(notificationData.getNfInstanceUri());

  std::shared_ptr<smf::nf_profile> p = {};

  // Only support UPF for now
  if (notificationData.getNfProfile().getNfType() == "UPF")
    p = std::make_shared<smf::upf_profile>();

  nlohmann::json pj = {};
  to_json(pj, notificationData.getNfProfile());
  p.get()->from_json(pj);
  notification_msg.set_profile(p);

  // Step 2. Handle the message in smf_app
  std::shared_ptr<itti_sbi_notification_data> itti_msg =
      std::make_shared<itti_sbi_notification_data>(TASK_SMF_N11, TASK_SMF_APP);
  itti_msg->notification_msg = notification_msg;
  itti_msg->http_version     = 1;

  ProblemDetails problem_details = {};
  uint8_t http_code              = 0;

  if (m_smf_app->handle_nf_status_notification(
          itti_msg, problem_details, http_code)) {
    response.send(Pistache::Http::Code(204));
  } else {
    nlohmann::json json_data = {};
    to_json(json_data, problem_details);
    // content type
    response.headers().add<Pistache::Http::Header::ContentType>(
        Pistache::Http::Mime::MediaType("application/problem+json"));
    response.send(Pistache::Http::Code(http_code), json_data.dump().c_str());
  }
}

}  // namespace api
}  // namespace smf_server
}  // namespace oai
