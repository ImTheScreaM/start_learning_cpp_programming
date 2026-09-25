#include "../includes/GET.h"

void GetController::getUserByName(const HttpRequestPtr &request,
								 std::function<void(const HttpResponsePtr &)> &&callback)
{
	auto name = request->getParameter("name");

	if(name.empty()) {
		setError(callback,k400BadRequest,"No has name in param");
		return;
	}

	FindAndResponse(std::move(callback),
									[&name](const User &u){return u.name == name;},
									"No has user with that name");
}


void GetController::getUserByEmail(const HttpRequestPtr &request,
					std::function<void(const HttpResponsePtr &)> &&callback)
{
	auto email = request->getParameter("email");

	if(email.empty()) {
		setError(callback,k400BadRequest,"No has email in param");
		return;
	}

	FindAndResponse(std::move(callback),
									[&email](const User &u) {return u.information.email == email;},
									"No has user with that email");


}
