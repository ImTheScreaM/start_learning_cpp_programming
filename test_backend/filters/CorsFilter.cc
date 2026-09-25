#include "../includes/CorsFilter.h"

void CorsFilter::doFilter(const HttpRequestPtr &req,
									FilterCallback &&fcb,
									FilterChainCallback &&fccb) 
{
	if(req->method() == Options) { 
		auto response = HttpResponse::newHttpResponse();
		response->setStatusCode(k204NoContent);
		response->addHeader("Access-Control-Allow-Origin",  "*");
    response->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    response->addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
    response->addHeader("Access-Control-Max-Age","3600");
    fcb(response);
    return;
	} 
	auto response = HttpResponse::newHttpResponse();
	response->setStatusCode(k204NoContent);
	response->addHeader("Access-Control-Allow-Origin",  "*");
  response->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  response->addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");

  fccb();
}
