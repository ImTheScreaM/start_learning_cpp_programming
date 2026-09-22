#pragma once

#include <cstdint>
#include <string>
#include <nlohmann/json.hpp>

struct UserInformation {
	std::string region;
	std::string bio;
	std::string email;
}; 

struct User { 
	std::string name; 
	uint64_t age;
	std::string role;
	UserInformation information;
};


NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(User,name,age,role,information) 
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(UserInformation,region,bio,email)
