#include <cstdlib>
#include <memory>
#include <drogon/drogon.h>

#include "../controller/api_controller.h"

using namespace drogon;

int main()
{


    app()
        .loadConfigFile("./json/config.json")
        .registerController(
            std::make_shared<ApiController>()
        )
        .registerPreRoutingAdvice(
            [](const HttpRequestPtr &req,
               AdviceCallback &&callback,
               AdviceChainCallback &&chainCallback)
            {
                if (req->method() == Options)
                {
                    auto response = HttpResponse::newHttpResponse();

                    response->setStatusCode(k204NoContent);

                    response->addHeader(
                        "Access-Control-Allow-Origin",
                        "http://localhost:5173"
                    );

                    response->addHeader(
                        "Access-Control-Allow-Methods",
                        "GET, POST, OPTIONS"
                    );

                    response->addHeader(
                        "Access-Control-Allow-Headers",
                        "Content-Type, Authorization"
                    );

                    response->addHeader(
                        "Access-Control-Max-Age",
                        "3600"
                    );

                    callback(response);
                    return;
                }

                chainCallback();
            })
        .run();

    return EXIT_SUCCESS;
}
