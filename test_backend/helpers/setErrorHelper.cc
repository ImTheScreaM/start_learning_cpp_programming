#include "../includes/setErrorHelper.h"

void setError(std::function<void(const HttpResponsePtr &)> &callback,
              HttpStatusCode code,
              std::string message)
{
  nlohmann::json body {
    {"ok",false},
    {"status",message}
  };

  auto response = HttpResponse::newHttpResponse();
  response->setStatusCode(code);
  response->setContentTypeCode(CT_APPLICATION_JSON);
  response->setBody(body.dump());
  callback(response);
}
