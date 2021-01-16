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

#include "RouteToLocation.h"

namespace oai {
namespace smf_server {
namespace model {

RouteToLocation::RouteToLocation() {
  m_Dnai             = "";
  m_RouteInfoIsSet   = false;
  m_RouteProfId      = "";
  m_RouteProfIdIsSet = false;
}

RouteToLocation::~RouteToLocation() {}

void RouteToLocation::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const RouteToLocation& o) {
  j         = nlohmann::json();
  j["dnai"] = o.m_Dnai;
  if (o.routeInfoIsSet()) j["routeInfo"] = o.m_RouteInfo;
  if (o.routeProfIdIsSet()) j["routeProfId"] = o.m_RouteProfId;
}

void from_json(const nlohmann::json& j, RouteToLocation& o) {
  j.at("dnai").get_to(o.m_Dnai);
  if (j.find("routeInfo") != j.end()) {
    j.at("routeInfo").get_to(o.m_RouteInfo);
    o.m_RouteInfoIsSet = true;
  }
  if (j.find("routeProfId") != j.end()) {
    j.at("routeProfId").get_to(o.m_RouteProfId);
    o.m_RouteProfIdIsSet = true;
  }
}

std::string RouteToLocation::getDnai() const {
  return m_Dnai;
}
void RouteToLocation::setDnai(std::string const& value) {
  m_Dnai = value;
}
RouteInformation RouteToLocation::getRouteInfo() const {
  return m_RouteInfo;
}
void RouteToLocation::setRouteInfo(RouteInformation const& value) {
  m_RouteInfo      = value;
  m_RouteInfoIsSet = true;
}
bool RouteToLocation::routeInfoIsSet() const {
  return m_RouteInfoIsSet;
}
void RouteToLocation::unsetRouteInfo() {
  m_RouteInfoIsSet = false;
}
std::string RouteToLocation::getRouteProfId() const {
  return m_RouteProfId;
}
void RouteToLocation::setRouteProfId(std::string const& value) {
  m_RouteProfId      = value;
  m_RouteProfIdIsSet = true;
}
bool RouteToLocation::routeProfIdIsSet() const {
  return m_RouteProfIdIsSet;
}
void RouteToLocation::unsetRouteProfId() {
  m_RouteProfIdIsSet = false;
}

}  // namespace model
}  // namespace smf_server
}  // namespace oai
