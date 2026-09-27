#include "../includes/POST.h"
#include "../includes/userParser.h"

void PostController::createUser(const HttpRequestPtr& request,
			std::function<void(const HttpResponsePtr &)> && callback)
{
	auto jsonPtr = request->getJsonObject();
	if(!jsonPtr) {
		setError(callback,k400BadRequest,"Invalid json");
		return;
	}

	try {
		User newUser = userParser(*jsonPtr);

		std::vector<User> users;
		JsonHelper helper("./json/db.json",users);
		helper.load_from_json();

		const std::string &checkEmail = newUser.information.email;

		auto findEmail = std::find_if(users.begin(),users.end(),
			[&checkEmail](const User &u){
				return u.information.email == checkEmail;});

		if(findEmail != users.end()) {
		  setError(callback,k409Conflict,"User with that email already has");
			return;
		}

		users.push_back(newUser);
		helper.save_to_json();

		nlohmann::json body {
			{"status","OK"},
			{"message","created"}
		};

		setCompleted(callback,k200OK,body);

	} catch(const std::exception &e) {
		setError(callback,k500InternalServerError,std::string("POST error:") + e.what());
	}
}
