#include "../includes/FindAndResponse.h"

void FindAndResponse(std::function<void(const HttpResponsePtr &)> &&callback,
                     std::function<bool(const User &)> pred,
                     const std::string notFoundMsg)
{
  std::vector<User> users;

  try {
    JsonHelper helper("./json/db.json",users);
    helper.load_from_json();
  } catch(const std::exception &e) {
    setError(callback,k500InternalServerError,std::string("Load error")  + e.what());
    return;
  }

  auto find = std::find_if(users.begin(),users.end(),pred);

  if(find == users.end()) {
    setError(callback,k404NotFound,"No user found:" + notFoundMsg);
    return;
  }
  setCompleted(callback,k200OK,nlohmann::json(*find));
}
