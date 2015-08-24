//01_02.cpp

#include "rxcpp/rx.hpp"
#include "node_util/node_util.hpp"

using namespace node_util; // console, "string"s +, 5000ms, set_timeout,
namespace rx = rxcpp;
using evt_t  = int;

void test_01_02() {
//-----------------------------------------------------------------------------
  auto when_subscribe = [](auto& observer) {
    auto gen_events = [observer] {
      observer.on_next(evt_t(21));
      observer.on_next(evt_t(22));
      observer.on_completed();
    };
    set_timeout(gen_events, 5000ms);
  };

  auto handler_next      = [](evt_t i) { console::log  ("on_next: "s   + i); };
  auto handler_error     = [](auto  e) { console::error("on_error: "s  + e); };
  auto handler_completed = []          { console::info ("on_completed");     };

  auto observable   = rx::observable<>::create<evt_t>(when_subscribe);
  auto subscription = observable.subscribe(handler_next,
                                           handler_error,
                                           handler_completed);
//-----------------------------------------------------------------------------
}

