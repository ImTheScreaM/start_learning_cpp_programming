#pragma once
 
#include "GET.h"
#include "POST.h"


class ApiController : public HttpController<ApiController,false> 
{
	public:
		METHOD_LIST_BEGIN
			METHOD_ADD(ApiController::get_user_by_name, "/get_user_by_name", Get);
			METHOD_ADD(ApiController::get_user_by_email, "/get_user_by_email", Get);
			METHOD_ADD(ApiController::create_user,"/create_user",Post);
		METHOD_LIST_END

		void get_user_by_name(const HttpRequestPtr &request,
				 std::function<void(const HttpResponsePtr &)> &&callback);

		void get_user_by_email(const HttpRequestPtr &request,
													std::function<void(const HttpResponsePtr &)> &&callback);

		void create_user(const HttpRequestPtr &request,
				  std::function<void(const HttpResponsePtr &)> &&callback);
	private:
		GetController getController_;
		PostController postController_;
};
