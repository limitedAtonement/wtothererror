#ifndef web_container_hpp_test
#define web_container_hpp_test
#include <Wt/WContainerWidget.h>
#include <Wt/WSignal.h>

struct web_container : public Wt::WContainerWidget
{
    web_container ();
    Wt::Signal<> & done() { return done_; }

    private:
    Wt::Signal<> done_;
};
#endif
