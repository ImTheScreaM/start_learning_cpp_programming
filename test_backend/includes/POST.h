#pragma once

#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/HttpRequest.h>
#include <exception>
#include <functional>
#include <vector>


#include "../includes/setErrorHelper.h"
#include "../includes/JsonHelper.h"
#include "../includes/data_type.h"

class PostController
{
	public: 
		void createUser(const drogon::HttpRequestPtr& request,
		std::function<void(const drogon::HttpResponsePtr &)> && callback);
  
};
