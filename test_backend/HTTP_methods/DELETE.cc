#include "../includes/DELETE.h"

void DeleteController::deleteUser(const drogon::HttpRequestPtr &request,
                                  std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
  auto getEmail = request->getParameter("email");
  auto getUser = request->getParameter("name");

  if(getEmail.empty() || getUser.empty()) {
    setError(callback,k400BadRequest,"Requier parametr don't has [email or name]");
    return;
  }

  try {
    std::vector<User> users;
    JsonHelper helper("./json/db.json",users);
    helper.load_from_json();

    auto find = std::find_if(users.begin(),users.end(),
               [&getEmail,&getUser](const User &u){return u.information.email == getEmail && u.name == getUser;});

    if(find == users.end()) {
      setError(callback,k404NotFound,"No user found");
      return;
    }

    users.erase(find);
    helper.save_to_json();

    nlohmann::json body {
      {"status","ok"},
      {"message","User deleted"}
    };

    setCompleted(callback,k200OK,body);
  } catch(const std::exception &e) {
    setError(callback,k500InternalServerError,std::string("Deleted users failed: ") + e.what());
  }
}
