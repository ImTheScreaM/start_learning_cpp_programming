#pragma once

#include <nlohmann/json.hpp>
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <algorithm>

#include "../includes/data_type.h"
#include "../includes/setErrorHelper.h"
#include "../includes/setCompletedHelper.h"
#include "../includes/JsonHelper.h"

class DeleteController {
  public:
    void deleteUser(const drogon::HttpRequestPtr &request,
                    std::function<void(const drogon::HttpResponsePtr &)> &&callback);
};

