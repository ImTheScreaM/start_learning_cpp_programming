#include "api_controller.h"
#include <exception>

void ApiController::get(const HttpRequestPtr &request,
                        std::function<void(const HttpResponsePtr &)> &&callback) 
{
    getController_.GetHandler(request, std::move(callback));
} 

void ApiController::post(const HttpRequestPtr &request,
                         std::function<void(const HttpResponsePtr &)> &&callback)
{
		try {
			postController_.PostHandler(request, std::move(callback));
		} catch(const std::exception &e) {
			std::cout<< "[ ERROR ]" << e.what() << std::endl;
		}
    
}