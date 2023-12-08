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
 * SmContext.h
 *
 *
 */

#ifndef SmContext_H_
#define SmContext_H_

#include "Ambr.h"
#include "MaxIntegrityProtectedDataRate.h"
#include "RatType.h"
#include <string>
#include "UpSecurity.h"
#include "QosFlowSetupItem.h"
#include "PlmnId.h"
#include "Snssai.h"
#include "TraceData.h"
#include <vector>
#include "AccessType.h"
#include "DnnSelectionMode.h"
#include "EpsPdnCnxInfo.h"
#include "EpsBearerInfo.h"
#include "EpsInterworkingIndication.h"
#include "ServiceName.h"
#include "PduSessionType.h"
#include "Guami.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
///
/// </summary>
class SmContext {
 public:
  SmContext();
  virtual ~SmContext();

  void validate();

  /////////////////////////////////////////////
  /// SmContext members

  /// <summary>
  ///
  /// </summary>
  std::string getSupi() const;
  void setSupi(std::string const& value);
  bool supiIsSet() const;
  void unsetSupi();
  /// <summary>
  ///
  /// </summary>
  bool isUnauthenticatedSupi() const;
  void setUnauthenticatedSupi(bool const value);
  bool unauthenticatedSupiIsSet() const;
  void unsetUnauthenticatedSupi();
  /// <summary>
  ///
  /// </summary>
  std::string getPei() const;
  void setPei(std::string const& value);
  bool peiIsSet() const;
  void unsetPei();
  /// <summary>
  ///
  /// </summary>
  std::string getGpsi() const;
  void setGpsi(std::string const& value);
  bool gpsiIsSet() const;
  void unsetGpsi();
  /// <summary>
  ///
  /// </summary>
  int32_t getPduSessionId() const;
  void setPduSessionId(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  std::string getDnn() const;
  void setDnn(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  Snssai getSNssai() const;
  void setSNssai(Snssai const& value);
  /// <summary>
  ///
  /// </summary>
  Snssai getHplmnSnssai() const;
  void setHplmnSnssai(Snssai const& value);
  bool hplmnSnssaiIsSet() const;
  void unsetHplmnSnssai();
  /// <summary>
  ///
  /// </summary>
  std::string getServingNfId() const;
  void setServingNfId(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  Guami getGuami() const;
  void setGuami(Guami const& value);
  bool guamiIsSet() const;
  void unsetGuami();
  /// <summary>
  ///
  /// </summary>
  ServiceName getServiceName() const;
  void setServiceName(ServiceName const& value);
  bool serviceNameIsSet() const;
  void unsetServiceName();
  /// <summary>
  ///
  /// </summary>
  PlmnId getServingNetwork() const;
  void setServingNetwork(PlmnId const& value);
  /// <summary>
  ///
  /// </summary>
  AccessType getAnType() const;
  void setAnType(AccessType const& value);
  /// <summary>
  ///
  /// </summary>
  RatType getRatType() const;
  void setRatType(RatType const& value);
  bool ratTypeIsSet() const;
  void unsetRatType();
  /// <summary>
  ///
  /// </summary>
  std::string getSmContextStatusUri() const;
  void setSmContextStatusUri(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getHSmfUri() const;
  void setHSmfUri(std::string const& value);
  bool hSmfUriIsSet() const;
  void unsetHSmfUri();
  /// <summary>
  ///
  /// </summary>
  std::string getPcfId() const;
  void setPcfId(std::string const& value);
  bool pcfIdIsSet() const;
  void unsetPcfId();
  /// <summary>
  ///
  /// </summary>
  DnnSelectionMode getSelMode() const;
  void setSelMode(DnnSelectionMode const& value);
  bool selModeIsSet() const;
  void unsetSelMode();
  /// <summary>
  ///
  /// </summary>
  TraceData getTraceData() const;
  void setTraceData(TraceData const& value);
  bool traceDataIsSet() const;
  void unsetTraceData();
  /// <summary>
  ///
  /// </summary>
  std::string getUdmGroupId() const;
  void setUdmGroupId(std::string const& value);
  bool udmGroupIdIsSet() const;
  void unsetUdmGroupId();
  /// <summary>
  ///
  /// </summary>
  std::string getRoutingIndicator() const;
  void setRoutingIndicator(std::string const& value);
  bool routingIndicatorIsSet() const;
  void unsetRoutingIndicator();
  /// <summary>
  ///
  /// </summary>
  EpsInterworkingIndication getEpsInterworkingInd() const;
  void setEpsInterworkingInd(EpsInterworkingIndication const& value);
  bool epsInterworkingIndIsSet() const;
  void unsetEpsInterworkingInd();
  /// <summary>
  ///
  /// </summary>
  PduSessionType getPduSessionType() const;
  void setPduSessionType(PduSessionType const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getSscMode() const;
  void setSscMode(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  Ambr getSessionAmbr() const;
  void setSessionAmbr(Ambr const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<QosFlowSetupItem>& getQosFlowsSetupList();
  /// <summary>
  ///
  /// </summary>
  std::string getHSmfInstanceId() const;
  void setHSmfInstanceId(std::string const& value);
  bool hSmfInstanceIdIsSet() const;
  void unsetHSmfInstanceId();
  /// <summary>
  ///
  /// </summary>
  bool isEnablePauseCharging() const;
  void setEnablePauseCharging(bool const value);
  bool enablePauseChargingIsSet() const;
  void unsetEnablePauseCharging();
  /// <summary>
  ///
  /// </summary>
  std::string getUeIpv4Address() const;
  void setUeIpv4Address(std::string const& value);
  bool ueIpv4AddressIsSet() const;
  void unsetUeIpv4Address();
  /// <summary>
  ///
  /// </summary>
  std::string getUeIpv6Prefix() const;
  void setUeIpv6Prefix(std::string const& value);
  bool ueIpv6PrefixIsSet() const;
  void unsetUeIpv6Prefix();
  /// <summary>
  ///
  /// </summary>
  EpsPdnCnxInfo getEpsPdnCnxInfo() const;
  void setEpsPdnCnxInfo(EpsPdnCnxInfo const& value);
  bool epsPdnCnxInfoIsSet() const;
  void unsetEpsPdnCnxInfo();
  /// <summary>
  ///
  /// </summary>
  std::vector<EpsBearerInfo>& getEpsBearerInfo();
  bool epsBearerInfoIsSet() const;
  void unsetEpsBearerInfo();
  /// <summary>
  ///
  /// </summary>
  MaxIntegrityProtectedDataRate getMaxIntegrityProtectedDataRate() const;
  void setMaxIntegrityProtectedDataRate(
      MaxIntegrityProtectedDataRate const& value);
  bool maxIntegrityProtectedDataRateIsSet() const;
  void unsetMaxIntegrityProtectedDataRate();
  /// <summary>
  ///
  /// </summary>
  bool isAlwaysOnGranted() const;
  void setAlwaysOnGranted(bool const value);
  bool alwaysOnGrantedIsSet() const;
  void unsetAlwaysOnGranted();
  /// <summary>
  ///
  /// </summary>
  UpSecurity getUpSecurity() const;
  void setUpSecurity(UpSecurity const& value);
  bool upSecurityIsSet() const;
  void unsetUpSecurity();
  /// <summary>
  ///
  /// </summary>
  std::string getHSmfServiceInstanceId() const;
  void setHSmfServiceInstanceId(std::string const& value);
  bool hSmfServiceInstanceIdIsSet() const;
  void unsetHSmfServiceInstanceId();
  /// <summary>
  ///
  /// </summary>
  std::string getRecoveryTime() const;
  void setRecoveryTime(std::string const& value);
  bool recoveryTimeIsSet() const;
  void unsetRecoveryTime();

  friend void to_json(nlohmann::json& j, const SmContext& o);
  friend void from_json(const nlohmann::json& j, SmContext& o);

 protected:
  std::string m_Supi;
  bool m_SupiIsSet;
  bool m_UnauthenticatedSupi;
  bool m_UnauthenticatedSupiIsSet;
  std::string m_Pei;
  bool m_PeiIsSet;
  std::string m_Gpsi;
  bool m_GpsiIsSet;
  int32_t m_PduSessionId;

  std::string m_Dnn;

  Snssai m_SNssai;

  Snssai m_HplmnSnssai;
  bool m_HplmnSnssaiIsSet;
  std::string m_ServingNfId;

  Guami m_Guami;
  bool m_GuamiIsSet;
  ServiceName m_ServiceName;
  bool m_ServiceNameIsSet;
  PlmnId m_ServingNetwork;

  AccessType m_AnType;

  RatType m_RatType;
  bool m_RatTypeIsSet;
  std::string m_SmContextStatusUri;

  std::string m_HSmfUri;
  bool m_HSmfUriIsSet;
  std::string m_PcfId;
  bool m_PcfIdIsSet;
  DnnSelectionMode m_SelMode;
  bool m_SelModeIsSet;
  TraceData m_TraceData;
  bool m_TraceDataIsSet;
  std::string m_UdmGroupId;
  bool m_UdmGroupIdIsSet;
  std::string m_RoutingIndicator;
  bool m_RoutingIndicatorIsSet;
  EpsInterworkingIndication m_EpsInterworkingInd;
  bool m_EpsInterworkingIndIsSet;
  PduSessionType m_PduSessionType;

  std::string m_SscMode;

  Ambr m_SessionAmbr;

  std::vector<QosFlowSetupItem> m_QosFlowsSetupList;

  std::string m_HSmfInstanceId;
  bool m_HSmfInstanceIdIsSet;
  bool m_EnablePauseCharging;
  bool m_EnablePauseChargingIsSet;
  std::string m_UeIpv4Address;
  bool m_UeIpv4AddressIsSet;
  std::string m_UeIpv6Prefix;
  bool m_UeIpv6PrefixIsSet;
  EpsPdnCnxInfo m_EpsPdnCnxInfo;
  bool m_EpsPdnCnxInfoIsSet;
  std::vector<EpsBearerInfo> m_EpsBearerInfo;
  bool m_EpsBearerInfoIsSet;
  MaxIntegrityProtectedDataRate m_MaxIntegrityProtectedDataRate;
  bool m_MaxIntegrityProtectedDataRateIsSet;
  bool m_AlwaysOnGranted;
  bool m_AlwaysOnGrantedIsSet;
  UpSecurity m_UpSecurity;
  bool m_UpSecurityIsSet;
  std::string m_HSmfServiceInstanceId;
  bool m_HSmfServiceInstanceIdIsSet;
  std::string m_RecoveryTime;
  bool m_RecoveryTimeIsSet;
};

}  // namespace model
}  // namespace smf_server
}  // namespace oai

#endif /* SmContext_H_ */
