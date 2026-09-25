#pragma once

#include <drogon/HttpFilter.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>

using namespace drogon; 
 

class CorsFilter : public HttpFilter<CorsFilter,false> { 
	public:
		CorsFilter() = default;

		void doFilter(const HttpRequestPtr &req,
									FilterCallback &&fcb,
									FilterChainCallback &&fccb) override;
};
