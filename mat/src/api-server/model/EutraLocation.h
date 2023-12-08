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
 * EutraLocation.h
 *
 *
 */

#ifndef EutraLocation_H_
#define EutraLocation_H_

#include "Ecgi.h"
#include "Tai.h"
#include <string>
#include "GlobalRanNodeId.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
///
/// </summary>
class EutraLocation {
 public:
  EutraLocation();
  virtual ~EutraLocation();

  void validate();

  bool operator==(const EutraLocation& rhs) const;
  bool operator!=(const EutraLocation& rhs) const;

  /////////////////////////////////////////////
  /// EutraLocation members

  /// <summary>
  ///
  /// </summary>
  Tai getTai() const;
  void setTai(Tai const& value);
  /// <summary>
  ///
  /// </summary>
  Ecgi getEcgi() const;
  void setEcgi(Ecgi const& value);
  /// <summary>
  ///
  /// </summary>
  int32_t getAgeOfLocationInformation() const;
  void setAgeOfLocationInformation(int32_t const value);
  bool ageOfLocationInformationIsSet() const;
  void unsetAgeOfLocationInformation();
  /// <summary>
  ///
  /// </summary>
  std::string getUeLocationTimestamp() const;
  void setUeLocationTimestamp(std::string const& value);
  bool ueLocationTimestampIsSet() const;
  void unsetUeLocationTimestamp();
  /// <summary>
  ///
  /// </summary>
  std::string getGeographicalInformation() const;
  void setGeographicalInformation(std::string const& value);
  bool geographicalInformationIsSet() const;
  void unsetGeographicalInformation();
  /// <summary>
  ///
  /// </summary>
  std::string getGeodeticInformation() const;
  void setGeodeticInformation(std::string const& value);
  bool geodeticInformationIsSet() const;
  void unsetGeodeticInformation();
  /// <summary>
  ///
  /// </summary>
  GlobalRanNodeId getGlobalNgenbId() const;
  void setGlobalNgenbId(GlobalRanNodeId const& value);
  bool globalNgenbIdIsSet() const;
  void unsetGlobalNgenbId();

  friend void to_json(nlohmann::json& j, const EutraLocation& o);
  friend void from_json(const nlohmann::json& j, EutraLocation& o);

 protected:
  Tai m_Tai;

  Ecgi m_Ecgi;

  int32_t m_AgeOfLocationInformation;
  bool m_AgeOfLocationInformationIsSet;
  std::string m_UeLocationTimestamp;
  bool m_UeLocationTimestampIsSet;
  std::string m_GeographicalInformation;
  bool m_GeographicalInformationIsSet;
  std::string m_GeodeticInformation;
  bool m_GeodeticInformationIsSet;
  GlobalRanNodeId m_GlobalNgenbId;
  bool m_GlobalNgenbIdIsSet;
};

}  // namespace model
}  // namespace smf_server
}  // namespace oai

#endif /* EutraLocation_H_ */
