/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 *file except in compliance with the License. You may obtain a copy of the
 *License at
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

/*! \file smf_profile.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include "logger.hpp"
#include "smf_profile.hpp"
#include "string.hpp"

using namespace std;
using namespace smf;

//------------------------------------------------------------------------------
void smf_profile::set_nf_instance_id(const std::string &instance_id) {
  nf_instance_id = instance_id;
}

//------------------------------------------------------------------------------
void smf_profile::get_nf_instance_id(std::string &instance_id) const {
  instance_id = nf_instance_id;
}

//------------------------------------------------------------------------------
std::string smf_profile::get_nf_instance_id() const { return nf_instance_id; }

//------------------------------------------------------------------------------
void smf_profile::set_nf_instance_name(const std::string &instance_name) {
  nf_instance_name = instance_name;
}

//------------------------------------------------------------------------------
void smf_profile::get_nf_instance_name(std::string &instance_name) const {
  instance_name = nf_instance_name;
}

//------------------------------------------------------------------------------
std::string smf_profile::get_nf_instance_name() const {
  return nf_instance_name;
}

//------------------------------------------------------------------------------
void smf_profile::set_nf_type(const std::string &type) { nf_type = type; }

//------------------------------------------------------------------------------
std::string smf_profile::get_nf_type() const { return nf_type; }
//------------------------------------------------------------------------------
void smf_profile::set_nf_status(const std::string &status) {
  nf_status = status;
}

//------------------------------------------------------------------------------
void smf_profile::get_nf_status(std::string &status) const {
  status = nf_status;
}

//------------------------------------------------------------------------------
std::string smf_profile::get_nf_status() const { return nf_status; }

//------------------------------------------------------------------------------
void smf_profile::set_nf_heartBeat_timer(const int32_t &timer) {
  heartBeat_timer = timer;
}

//------------------------------------------------------------------------------
void smf_profile::get_nf_heartBeat_timer(int32_t &timer) const {
  timer = heartBeat_timer;
}

//------------------------------------------------------------------------------
int32_t smf_profile::get_nf_heartBeat_timer() const { return heartBeat_timer; }

//------------------------------------------------------------------------------
void smf_profile::set_nf_priority(const uint16_t &p) { priority = p; }

//------------------------------------------------------------------------------
void smf_profile::get_nf_priority(uint16_t &p) const { p = priority; }

//------------------------------------------------------------------------------
uint16_t smf_profile::get_nf_priority() const { return priority; }

//------------------------------------------------------------------------------
void smf_profile::set_nf_capacity(const uint16_t &c) { capacity = c; }

//------------------------------------------------------------------------------
void smf_profile::get_nf_capacity(uint16_t &c) const { c = capacity; }

//------------------------------------------------------------------------------
uint16_t smf_profile::get_nf_capacity() const { return capacity; }

//------------------------------------------------------------------------------
void smf_profile::set_nf_snssais(const std::vector<snssai_t> &s) {
  snssais = s;
}

//------------------------------------------------------------------------------
void smf_profile::get_nf_snssais(std::vector<snssai_t> &s) const {
  s = snssais;
}

//------------------------------------------------------------------------------
void smf_profile::add_snssai(const snssai_t &s) { snssais.push_back(s); }
//------------------------------------------------------------------------------
void smf_profile::set_nf_ipv4_addresses(const std::vector<struct in_addr> &a) {
  ipv4_addresses = a;
}

//------------------------------------------------------------------------------
void smf_profile::add_nf_ipv4_addresses(const struct in_addr &a) {
  ipv4_addresses.push_back(a);
}
//------------------------------------------------------------------------------
void smf_profile::get_nf_ipv4_addresses(std::vector<struct in_addr> &a) const {
  a = ipv4_addresses;
}

//------------------------------------------------------------------------------
void smf_profile::set_custom_info(const nlohmann::json &c) { custom_info = c; }

//------------------------------------------------------------------------------
void smf_profile::get_custom_info(nlohmann::json &c) const { c = custom_info; }

//------------------------------------------------------------------------------
void smf_profile::set_smf_info(const smf_info_t &s) { smf_info = s; }

//------------------------------------------------------------------------------
void smf_profile::add_smf_info_item(const snssai_smf_info_item_t &s) {
  smf_info.snssai_smf_info_list.push_back(s);
}

//------------------------------------------------------------------------------
void smf_profile::get_smf_info(smf_info_t &s) const { s = smf_info; }

//------------------------------------------------------------------------------
void smf_profile::display() {
  Logger::smf_app().debug("NF instance info");

  Logger::smf_app().debug("\tInstance ID: %s", nf_instance_id.c_str());

  Logger::smf_app().debug("\tInstance name: %s", nf_instance_name.c_str());
  Logger::smf_app().debug("\tInstance type: %s", nf_type.c_str());
  Logger::smf_app().debug("\tStatus: %s", nf_status.c_str());
  Logger::smf_app().debug("\tHeartBeat timer: %d", heartBeat_timer);
  Logger::smf_app().debug("\tPriority: %d", priority);
  Logger::smf_app().debug("\tCapacity: %d", capacity);
  // SNSSAIs
  if (snssais.size() > 0) {
    Logger::smf_app().debug("\tSNSSAI:");
  }
  for (auto s : snssais) {
    Logger::smf_app().debug("\t\t SST, SD: %d, %s", s.sST, s.sD.c_str());
  }

  // IPv4 Addresses
  if (ipv4_addresses.size() > 0) {
    Logger::smf_app().debug("\tIPv4 Addr:");
  }
  for (auto address : ipv4_addresses) {
    Logger::smf_app().debug("\t\t %s", inet_ntoa(address));
  }

  if (!custom_info.empty()) {
    Logger::smf_app().debug("\tCustom info: %s", custom_info.dump().c_str());
  }

  // SMF info
  if (smf_info.snssai_smf_info_list.size() > 0) {
    Logger::smf_app().debug("\tSMF Info:");
  }
  for (auto s : smf_info.snssai_smf_info_list) {
    Logger::smf_app().debug("\t\tParameters supported by the SMF:");
    Logger::smf_app().debug("\t\t\tSNSSAI (SST %d, SD %s)", s.snssai.sST,
                            s.snssai.sD.c_str());
    for (auto d : s.dnn_smf_info_list) {
      Logger::smf_app().debug("\t\t\tDNN %s", d.dnn.c_str());
    }
  }
}

//------------------------------------------------------------------------------
void smf_profile::to_json(nlohmann::json &data) const {
  data["nfInstanceId"] = nf_instance_id;
  data["nfInstanceName"] = nf_instance_name;
  data["nfType"] = nf_type;
  data["nfStatus"] = nf_status;
  data["heartBeatTimer"] = heartBeat_timer;
  // SNSSAIs
  data["sNssais"] = nlohmann::json::array();
  for (auto s : snssais) {
    nlohmann::json tmp = {};
    tmp["sst"] = s.sST;
    tmp["sd"] = s.sD;
    ;
    data["sNssais"].push_back(tmp);
  }
  // ipv4_addresses
  data["ipv4Addresses"] = nlohmann::json::array();
  for (auto address : ipv4_addresses) {
    nlohmann::json tmp = inet_ntoa(address);
    data["ipv4Addresses"].push_back(tmp);
  }

  data["priority"] = priority;
  data["capacity"] = capacity;
  data["custom_info"] = custom_info;

  // SMF info
  data["smfInfo"] = {};
  data["smfInfo"]["sNssaiSmfInfoList"] = nlohmann::json::array();
  for (auto s : smf_info.snssai_smf_info_list) {
    nlohmann::json tmp = {};
    tmp["sNssai"]["sst"] = s.snssai.sST;
    tmp["sNssai"]["sd"] = s.snssai.sD;
    tmp["dnnSmfInfoList"] = nlohmann::json::array();
    for (auto d : s.dnn_smf_info_list) {
      nlohmann::json dnn_json = {};
      dnn_json["dnn"] = d.dnn;
      tmp["dnnSmfInfoList"].push_back(dnn_json);
    }
    data["smfInfo"]["sNssaiSmfInfoList"].push_back(tmp);
  }

  Logger::smf_app().debug("SMF profile to json:\n %s", data.dump().c_str());
}

//------------------------------------------------------------------------------
void smf_profile::from_json(const nlohmann::json &data) {
  if (data.find("nfInstanceId") != data.end()) {
    nf_instance_id = data["nfInstanceId"].get<std::string>();
  }

  if (data.find("nfInstanceName") != data.end()) {
    nf_instance_name = data["nfInstanceName"].get<std::string>();
  }

  if (data.find("nfType") != data.end()) {
    nf_type = data["nfType"].get<std::string>();
  }

  if (data.find("nfStatus") != data.end()) {
    nf_status = data["nfStatus"].get<std::string>();
  }

  if (data.find("heartBeatTimer") != data.end()) {
    heartBeat_timer = data["heartBeatTimer"].get<int>();
  }
  // sNssais
  if (data.find("sNssais") != data.end()) {
    for (auto it : data["sNssais"]) {
      snssai_t s = {};
      s.sST = it["sst"].get<int>();
      s.sD = it["sd"].get<std::string>();
      snssais.push_back(s);
      // Logger::smf_app().debug("Added SNSSAI (SST %d, SD %s)", s.sST,
      // s.sD.c_str());
    }
  }

  if (data.find("ipv4Addresses") != data.end()) {
    nlohmann::json addresses = data["ipv4Addresses"];

    for (auto it : addresses) {
      struct in_addr addr4 = {};
      std::string address = it.get<std::string>();
      unsigned char buf_in_addr[sizeof(struct in_addr)];
      if (inet_pton(AF_INET, util::trim(address).c_str(), buf_in_addr) == 1) {
        memcpy(&addr4, buf_in_addr, sizeof(struct in_addr));
      } else {
        Logger::smf_app().warn("Address conversion: Bad value %s",
                               util::trim(address).c_str());
      }
      // Logger::smf_app().debug("\tIPv4 Addr: %s", address.c_str());
      add_nf_ipv4_addresses(addr4);
    }
  }

  if (data.find("priority") != data.end()) {
    priority = data["priority"].get<int>();
  }

  if (data.find("capacity") != data.end()) {
    capacity = data["capacity"].get<int>();
  }

  // TODO: custom_info;

  // SMF info
  if (data.find("smfInfo") != data.end()) {
    nlohmann::json info = data["smfInfo"];

    dnn_smf_info_item_t dnn_item = {};

    if (info.find("sNssaiSmfInfoList") != info.end()) {
      nlohmann::json snssai_smf_info_list =
          data["smfInfo"]["sNssaiSmfInfoList"];

      for (auto it : snssai_smf_info_list) {
        snssai_smf_info_item_t smf_info_item = {};
        if (it.find("sNssai") != it.end()) {
          if (it["sNssai"].find("sst") != it["sNssai"].end())
            smf_info_item.snssai.sST = it["sNssai"]["sst"].get<int>();
          if (it["sNssai"].find("sd") != it["sNssai"].end())
            smf_info_item.snssai.sD = it["sNssai"]["sd"].get<std::string>();
        }
        if (it.find("dnnSmfInfoList") != it.end()) {
          for (auto d : it["dnnSmfInfoList"]) {
            if (d.find("dnn") != d.end()) {
              dnn_item.dnn = d["dnn"].get<std::string>();
              smf_info_item.dnn_smf_info_list.push_back(dnn_item);
            }
          }
        }
        smf_info.snssai_smf_info_list.push_back(smf_info_item);
      }
    }
  }

  display();
}

//------------------------------------------------------------------------------
void smf_profile::handle_heartbeart_timeout(uint64_t ms) {
  Logger::smf_app().info("Handle heartbeart timeout profile %s, time %d",
                         nf_instance_id.c_str(), ms);
  set_nf_status("SUSPENDED");
}
