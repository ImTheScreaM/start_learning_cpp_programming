#pragma once

#include <drogon/drogon.h>
#include <nlohmann/json.hpp>

#include "../includes/data_type.h"
#include "../includes/setErrorHelper.h"
#include "../includes/JsonHelper.h"
#include "../includes/setCompletedHelper.h"


void FindAndResponse(std::function<void(const HttpResponsePtr &)> &&callback,
                     std::function<bool(const User &)> pred,
                     const std::string notFoundMsg);
