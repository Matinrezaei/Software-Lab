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
 * SmContextReleaseData.h
 *
 *
 */

#ifndef SmContextReleaseData_H_
#define SmContextReleaseData_H_

#include "NgApCause.h"
#include "Cause.h"
#include "RefToBinaryData.h"
#include <string>
#include "UserLocation.h"
#include "N2SmInfoType.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
///
/// </summary>
class SmContextReleaseData {
 public:
  SmContextReleaseData();
  virtual ~SmContextReleaseData();

  void validate();

  /////////////////////////////////////////////
  /// SmContextReleaseData members

  /// <summary>
  ///
  /// </summary>
  Cause getCause() const;
  void setCause(Cause const& value);
  bool causeIsSet() const;
  void unsetCause();
  /// <summary>
  ///
  /// </summary>
  NgApCause getNgApCause() const;
  void setNgApCause(NgApCause const& value);
  bool ngApCauseIsSet() const;
  void unsetNgApCause();
  /// <summary>
  ///
  /// </summary>
  int32_t get5gMmCauseValue() const;
  void set5gMmCauseValue(int32_t const value);
  bool _5gMmCauseValueIsSet() const;
  void unset_5gMmCauseValue();
  /// <summary>
  ///
  /// </summary>
  UserLocation getUeLocation() const;
  void setUeLocation(UserLocation const& value);
  bool ueLocationIsSet() const;
  void unsetUeLocation();
  /// <summary>
  ///
  /// </summary>
  std::string getUeTimeZone() const;
  void setUeTimeZone(std::string const& value);
  bool ueTimeZoneIsSet() const;
  void unsetUeTimeZone();
  /// <summary>
  ///
  /// </summary>
  UserLocation getAddUeLocation() const;
  void setAddUeLocation(UserLocation const& value);
  bool addUeLocationIsSet() const;
  void unsetAddUeLocation();
  /// <summary>
  ///
  /// </summary>
  bool isVsmfReleaseOnly() const;
  void setVsmfReleaseOnly(bool const value);
  bool vsmfReleaseOnlyIsSet() const;
  void unsetVsmfReleaseOnly();
  /// <summary>
  ///
  /// </summary>
  RefToBinaryData getN2SmInfo() const;
  void setN2SmInfo(RefToBinaryData const& value);
  bool n2SmInfoIsSet() const;
  void unsetN2SmInfo();
  /// <summary>
  ///
  /// </summary>
  std::string getN2SmInfoType() const;
  void setN2SmInfoType(std::string const& value);
  bool n2SmInfoTypeIsSet() const;
  void unsetN2SmInfoType();
  /// <summary>
  ///
  /// </summary>
  bool isIsmfReleaseOnly() const;
  void setIsmfReleaseOnly(bool const value);
  bool ismfReleaseOnlyIsSet() const;
  void unsetIsmfReleaseOnly();

  friend void to_json(nlohmann::json& j, const SmContextReleaseData& o);
  friend void from_json(const nlohmann::json& j, SmContextReleaseData& o);

 protected:
  Cause m_Cause;
  bool m_CauseIsSet;
  NgApCause m_NgApCause;
  bool m_NgApCauseIsSet;
  int32_t m__5gMmCauseValue;
  bool m__5gMmCauseValueIsSet;
  UserLocation m_UeLocation;
  bool m_UeLocationIsSet;
  std::string m_UeTimeZone;
  bool m_UeTimeZoneIsSet;
  UserLocation m_AddUeLocation;
  bool m_AddUeLocationIsSet;
  bool m_VsmfReleaseOnly;
  bool m_VsmfReleaseOnlyIsSet;
  RefToBinaryData m_N2SmInfo;
  bool m_N2SmInfoIsSet;
  std::string m_N2SmInfoType;
  bool m_N2SmInfoTypeIsSet;
  bool m_IsmfReleaseOnly;
  bool m_IsmfReleaseOnlyIsSet;
};

}  // namespace model
}  // namespace smf_server
}  // namespace oai

#endif /* SmContextReleaseData_H_ */
