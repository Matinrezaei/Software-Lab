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
#ifndef FILE_SMF_PROCEDURE_HPP_SEEN
#define FILE_SMF_PROCEDURE_HPP_SEEN

/*! \file smf_procedure.hpp
  \brief
  \author Lionel Gauthier
  \company Eurecom
  \email: lionel.gauthier@eurecom.fr
*/

#include "3gpp_29.244.hpp"
#include "3gpp_29.274.hpp"
#include "itti_msg_n11.hpp"
#include "itti_msg_n4.hpp"
#include "itti_msg_n4_restore.hpp"
#include "msg_pfcp.hpp"
#include "msg_gtpv2c.hpp"
#include "uint_generator.hpp"
#include "smf_msg.hpp"

#include <memory>
#include <mutex>
#include <set>

namespace pgwc {

class apn_context;
class pgw_context;
class pgw_pdn_connection;

//------------------------------------------------------------------------------
class smf_procedure {
private:
  static uint64_t              trxn_id_generator;

  static uint64_t generate_trxn_id() {
    return util::uint_uid_generator<uint64_t>::get_instance().get_uid();
  }

public:
  uint64_t              trxn_id;
  smf_procedure(){trxn_id = generate_trxn_id();}
  explicit smf_procedure(uint64_t tx){trxn_id = tx;}
  virtual ~smf_procedure(){}
  virtual itti_msg_type_t get_procedure_type(){return ITTI_MSG_TYPE_NONE;}
  virtual void handle_itti_msg (itti_n4_session_establishment_response& resp) {}
  virtual void handle_itti_msg (itti_n4_session_modification_response& resp) {}
  virtual void handle_itti_msg (itti_n4_session_deletion_response& resp) {}
  //tual void handle_itti_msg (itti_s5s8_downlink_data_notification_acknowledge& resp) {}
};


class sgw_eps_bearer_context;
class sgw_pdn_connection;

//------------------------------------------------------------------------------
class sx_session_restore_procedure : public smf_procedure {
public:
  explicit sx_session_restore_procedure(std::set<pfcp::fseid_t>& sessions2restore) : smf_procedure(), pending_sessions(sessions2restore),
  restored_sessions()
  {
    sessions2restore.clear();
  }

  int run();
  //void handle_itti_msg (itti_n4_session_establishment_response& resp);

  //~sx_session_restore_procedure() {}

  std::set<pfcp::fseid_t> pending_sessions;
  std::set<pfcp::fseid_t> restored_sessions;
};

//------------------------------------------------------------------------------
class session_create_sm_context_procedure : public smf_procedure {
public:
  explicit session_create_sm_context_procedure(std::shared_ptr<pgw_pdn_connection>& sppc) : smf_procedure(), ppc(sppc),
      sx_triggered(), n11_triggered_pending(), n11_trigger() {}

  int run(std::shared_ptr<itti_n11_create_sm_context_request> req,
          std::shared_ptr<itti_n11_create_sm_context_response>resp,
          std::shared_ptr<pgwc::pgw_context> pc);

  void handle_itti_msg (itti_n4_session_establishment_response& resp);

  std::shared_ptr<itti_n4_session_establishment_request> sx_triggered;
  std::shared_ptr<pgw_pdn_connection>                      ppc;
  std::shared_ptr<pgwc::pgw_context>                       pc;

  std::shared_ptr<itti_n11_create_sm_context_request> n11_trigger;
  std::shared_ptr<itti_n11_create_sm_context_response> n11_triggered_pending;
};

}
#include "../pgwc/pgw_context.hpp"

#endif