#pragma once

#include <nlohmann/json.hpp>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>

using namespace drogon;

void setError(std::function<void(const HttpResponsePtr &)> &callback,
              HttpStatusCode code,
              std::string message);
