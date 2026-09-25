#include "../includes/setCompletedHelper.h"

void setCompleted(std::function<void(const HttpResponsePtr &)> &callback,
                  HttpStatusCode code,
                  nlohmann::json data)
{

    auto response = HttpResponse::newHttpResponse();
    response->setStatusCode(code);
    response->setContentTypeCode(CT_APPLICATION_JSON);
    response->setBody(data.dump());
    callback(response);
}
