#include "../includes/PUT.h"


void PutController::changeDatasUser(const drogon::HttpRequestPtr &request,
                                    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
  auto data = request->getJsonObject();

  if (!data) {
    setError(callback,k400BadRequest,"Invalid JSON");
    return;
  }

  try {
    std::vector<User> user;
    JsonHelper helper("./json/db.json",user);
    helper.load_from_json();
    std::cout << data;

  } catch(const std::exception &e) {
    setError(callback,k500InternalServerError,std::string("PUT error:") + e.what());
  }
}
