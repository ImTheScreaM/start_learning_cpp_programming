 #pragma once
 
 #include <drogon/HttpTypes.h>
 #include <drogon/HttpResponse.h>
 #include <functional>
  
 class GetController {
 public: 
     void GetHandler(const drogon::HttpRequestPtr &request, 
     std::function<void(const drogon::HttpResponsePtr &)> &&callback); 
 };