#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>
#include <exception>
#include <vector>

#include "POST.h"
#include "../includes/data_type.h"
#include "../helpers/JsonHelper.h"

using namespace drogon;


void PostController::PostHandler(const HttpRequestPtr& request,
			std::function<void(const HttpResponsePtr &)> && callback)
{
	auto jsonPtr = request->getJsonObject();
	std::vector<User> users;

	if(!jsonPtr) {
		auto response = HttpResponse::newHttpResponse();
		response->setStatusCode(k400BadRequest);
		response->setBody("Invalid json");
		callback(response);
		return;
	}


	try {
		User newUser;

		newUser.name = (*jsonPtr)["name"].asString();
		newUser.age = (*jsonPtr)["age"].asUInt64();
		newUser.role = (*jsonPtr)["role"].asString();

		newUser.information.bio = (*jsonPtr)["information"]["bio"].asString();
		newUser.information.email = (*jsonPtr)["information"]["email"].asString();
		newUser.information.region = (*jsonPtr)["information"]["region"].asString();

		auto findEmail = std::find_if(users.begin(),users.end(),
			[&newUser](const User &u){
				return u.information.email == newUser.information.email;
		});

		if(findEmail != users.end()) {
			throw "Already has user";
		}

		std::vector<User> users;
		JsonHelper helper("./json/db.json",users);
		
		helper.load_from_json();
		users.push_back(newUser);
		helper.save_to_json();

		auto response = HttpResponse::newHttpResponse();
		response->setStatusCode(k200OK);
		response->setBody("creater!");
		callback(response);

	} catch(const std::exception &e) {
		auto response = HttpResponse::newHttpResponse();
		response->setStatusCode(k500InternalServerError);
		response->setBody(e.what());
		callback(response);
	}
}
