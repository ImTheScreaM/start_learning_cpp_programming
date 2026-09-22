#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>
#include <algorithm>
#include <nlohmann/json.hpp>

#include "GET.h"

#include "../helpers/JsonHelper.h"
#include "../includes/data_type.h" 

using namespace drogon;

namespace {
	void setError(const std::function<void(const HttpResponsePtr &)> &cb,
					HttpStatusCode code,
					std::string message)
	{
		nlohmann::json body {
			{"ok",false},
			{"status",message}
		};

		auto response = HttpResponse::newHttpResponse();
		response->setStatusCode(code);
		response->setContentTypeCode(CT_APPLICATION_JSON);
		response->setBody(body.dump());
		cb(response);
	}
}

void GetController::GetHandler(const HttpRequestPtr &request,
								 std::function<void(const HttpResponsePtr &)> &&callback)
{
	auto name = request->getParameter("name");
	std::cout << "[ NAME ] " << name << std::endl;
	std::vector<User> users;

	try {
		JsonHelper helper("./json/db.json",users);
		helper.load_from_json();
	} catch(const std::exception &e) {
		setError(callback,k500InternalServerError,std::string("Load error" ) + e.what());
		return;
	}

	auto find = std::find_if(users.begin(),users.end(),
		[&name](const User& u){return u.name == name;}); 

	if(find == users.end()) {
		setError(callback,k400BadRequest,"No user found:" + name);
		return;
	}

	nlohmann::json findUser = *find;
	auto response = HttpResponse::newHttpResponse(); 
	response->setStatusCode(drogon::k200OK);
	response->setContentTypeCode(CT_APPLICATION_JSON);
	response->setBody(findUser.dump());
	callback(response);
}
