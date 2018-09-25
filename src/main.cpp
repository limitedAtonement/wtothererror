#define BOOST_SIGNALS_NO_DEPRECATION_WARNING
#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <string>
#include "web.hpp"

std::unique_ptr<Wt::WApplication> create_application(Wt::WEnvironment const & env)
{
    return std::make_unique<myweb_app_test>(env);
}

int main(int argc, char** argv)
{
    return Wt::WRun(argc, argv, &create_application);
}
