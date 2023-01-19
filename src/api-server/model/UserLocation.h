/**
 * Npcf_SMPolicyControl API
 * Session Management Policy Control Service © 2020, 3GPP Organizational
 * Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.1.alpha-5
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * UserLocation.h
 *
 *
 */

#ifndef UserLocation_H_
#define UserLocation_H_

#include "EutraLocation.h"
#include "NrLocation.h"
#include "N3gaLocation.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace smf_server {
namespace model {

/// <summary>
///
/// </summary>
class UserLocation {
 public:
  UserLocation();
  virtual ~UserLocation() = default;

  /// <summary>
  /// Validate the current data in the model. Throws a ValidationException on
  /// failure.
  /// </summary>
  void validate() const;

  /// <summary>
  /// Validate the current data in the model. Returns false on error and writes
  /// an error message into the given stringstream.
  /// </summary>
  bool validate(std::stringstream& msg) const;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(std::stringstream& msg, const std::string& pathPrefix) const;

  bool operator==(const UserLocation& rhs) const;
  bool operator!=(const UserLocation& rhs) const;

  /////////////////////////////////////////////
  /// UserLocation members

  /// <summary>
  ///
  /// </summary>
  EutraLocation getEutraLocation() const;
  void setEutraLocation(EutraLocation const& value);
  bool eutraLocationIsSet() const;
  void unsetEutraLocation();
  /// <summary>
  ///
  /// </summary>
  NrLocation getNrLocation() const;
  void setNrLocation(NrLocation const& value);
  bool nrLocationIsSet() const;
  void unsetNrLocation();
  /// <summary>
  ///
  /// </summary>
  N3gaLocation getN3gaLocation() const;
  void setN3gaLocation(N3gaLocation const& value);
  bool n3gaLocationIsSet() const;
  void unsetN3gaLocation();

  friend void to_json(nlohmann::json& j, const UserLocation& o);
  friend void from_json(const nlohmann::json& j, UserLocation& o);

 protected:
  EutraLocation m_EutraLocation;
  bool m_EutraLocationIsSet;
  NrLocation m_NrLocation;
  bool m_NrLocationIsSet;
  N3gaLocation m_N3gaLocation;
  bool m_N3gaLocationIsSet;
};

}  // namespace model
}  // namespace smf_server
}  // namespace oai
#endif /* UserLocation_H_ */
