#pragma once
 
#include "GET.h"
#include "POST.h"
#include "PUT.h"
#include "DELETE.h"

class ApiController : public HttpController<ApiController,false> 
{
	public:
		METHOD_LIST_BEGIN
			METHOD_ADD(ApiController::get_user_by_name, "/get_user_by_name", Get);
			METHOD_ADD(ApiController::get_user_by_email, "/get_user_by_email", Get);
			METHOD_ADD(ApiController::create_user,"/create_user",Post);
			METHOD_ADD(ApiController::change_datas_user,"/change_datas_user",Put);
			METHOD_ADD(ApiController::delete_user,"/delete_user",Delete);
		METHOD_LIST_END

		void get_user_by_name(const HttpRequestPtr &request,
													std::function<void(const HttpResponsePtr &)> &&callback);

		void get_user_by_email(const HttpRequestPtr &request,
										 			 std::function<void(const HttpResponsePtr &)> &&callback);

		void create_user(const HttpRequestPtr &request,
										 std::function<void(const HttpResponsePtr &)> &&callback);

		void change_datas_user(const HttpRequestPtr &request,
													 std::function<void(const HttpResponsePtr&)> &&callback);

		void delete_user(const HttpRequestPtr &request,
										 std::function<void(const HttpResponsePtr&)> &&callback);

	private:
		GetController getController_;
		PostController postController_;
		PutController  putController_;
		DeleteController deleteController_;
};
