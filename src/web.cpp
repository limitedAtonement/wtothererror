#include "web.hpp"
#include "webcontainer.hpp"

myweb_app_test::myweb_app_test(Wt::WEnvironment const & env)
    : Wt::WApplication(env)
{
    auto container{root()->addNew<web_container>()};
    container->setId("the-container");
    /* NOT "/js/myjs.js" in case we are serving from a subdirectory. */
    require("js/myjs.js");
}

