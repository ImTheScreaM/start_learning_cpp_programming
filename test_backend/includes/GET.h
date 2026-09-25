 #pragma once
 
#include <nlohmann/json.hpp>
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <functional>
#include <algorithm>

#include "../includes/data_type.h"
#include "../includes/setErrorHelper.h"
#include "../includes/FindAndResponse.h"

class GetController {
	public:
		void getUserByName(const drogon::HttpRequestPtr &request,
		std::function<void(const drogon::HttpResponsePtr &)> &&callback);

		void getUserByEmail(const drogon::HttpRequestPtr &request,
		std::function<void(const drogon::HttpResponsePtr &)> &&callback);
};
