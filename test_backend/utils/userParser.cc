#include "../includes/userParser.h"

User userParser(const Json::Value &json) {
  if(!json.isObject()) {
    throw std::invalid_argument("Need json object");
  }

  User u;

  u.name = json.get("name","Anonym").asString();
  u.age = json["age"].asUInt64();
  u.role = json.get("role","user").asString();
  u.password = json["password"].asString();

  if(!u.password.empty()) {
    throw std::invalid_argument("Need password");
  }

  if(json.isMember("information")) {
    u.information.bio = json["information"]["bio"].asString();
    u.information.email = json["information"]["email"].asString();
    u.information.region = json["information"]["region"].asString();
  }

  return u;
}
