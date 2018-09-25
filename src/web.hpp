#ifndef web_app_test
#define web_app_test
#include <Wt/WEnvironment.h>
#include <Wt/WApplication.h>

struct myweb_app_test : public Wt::WApplication
{
    myweb_app_test(Wt::WEnvironment const &);
};
#endif
