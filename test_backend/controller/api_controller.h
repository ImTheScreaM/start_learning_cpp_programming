#pragma once

#include <drogon/HttpController.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon.h> 
 
#include "../HTTP_methods/GET.h"
#include "../HTTP_methods/POST.h"
 
using namespace drogon;

class ApiController : public HttpController<ApiController,false> 
{
	public:
		METHOD_LIST_BEGIN
			METHOD_ADD(ApiController::get, "/get_user", Get);
			METHOD_ADD(ApiController::post,"/create_user",Post);
		METHOD_LIST_END

		void get(const HttpRequestPtr &request,
							std::function<void(const HttpResponsePtr &)> &&callback);
		void post(const HttpRequestPtr &request,
							std::function<void(const HttpResponsePtr &)> &&callback);
	private:
		GetController getController_;
		PostController postController_;
};
