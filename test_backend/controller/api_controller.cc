#include "../includes/api_controller.h"
#include <exception>
// GET

void ApiController::get_user_by_name(const HttpRequestPtr &request,
                        std::function<void(const HttpResponsePtr &)> &&callback)
{
    getController_.getUserByName(request, std::move(callback));
}

void ApiController::get_user_by_email(const HttpRequestPtr &request,
                        std::function<void(const HttpResponsePtr &)> &&callback)
{
    getController_.getUserByEmail(request, std::move(callback));
}

// POST

void ApiController::create_user(const HttpRequestPtr &request,
                                std::function<void(const HttpResponsePtr &)> &&callback)
{
		postController_.createUser(request, std::move(callback));
}


// PUT

void ApiController::change_datas_user(const HttpRequestPtr &request,
                                      std::function<void(const HttpResponsePtr &)> &&callback)
{
    putController_.changeDatasUser(request,std::move(callback));
}

// DELETE


void ApiController::delete_user(const HttpRequestPtr& request,
                                std::function<void (const HttpResponsePtr &)> &&callback)
{
    deleteController_.deleteUser(request,std::move(callback));
}

