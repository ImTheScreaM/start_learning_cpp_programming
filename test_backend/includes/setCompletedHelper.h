#pragma once

#include <nlohmann/json.hpp>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>
#include <nlohmann/json.hpp>

using namespace drogon;

void setCompleted(std::function<void(const HttpResponsePtr &)> &callback,
                  HttpStatusCode code,
                  nlohmann::json data);
