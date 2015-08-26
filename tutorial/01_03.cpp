//01_01.cpp

#include "rxcpp/rx.hpp"
#include "node_util/node_util.hpp"

using namespace node_util; // console, "string"s + 
namespace rx = rxcpp;
using evt_t  = int;

void test_01_03() {
//-----------------------------------------------------------------------------
  auto when_subscribe = [](auto& observer) {
    //observer.on_next(evt_t(31));
    //observer.on_next(evt_t(32));
    observer.on_completed();
    auto when_dispose = [] {
      console::info("when dispose");
    };

    return when_dispose;
  };

  auto handler_next      = [](evt_t i) { throw "aaa"; console::log  ("on_next: "s  + i); };
  auto handler_error     = [](auto  e) { console::error("on_error: "s + e); };
  auto handler_completed = []          { console::info ("on_completed");    };

  auto observable   = rx::observable<>::create<evt_t>(when_subscribe);
  auto subscription = observable.subscribe(handler_next,
                                           handler_error,
                                           handler_completed);
  subscription.cancell();
//-----------------------------------------------------------------------------
}