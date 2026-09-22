#pragma once

#include <drogon/HttpResponse.h>
#include <functional>

class PostController
{
	public: 
		void PostHandler(const drogon::HttpRequestPtr& request,
		std::function<void(const drogon::HttpResponsePtr &)> && callback);
  
};