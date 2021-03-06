//01_02.cpp

#include <array>
#include <functional>
#include "rxcpp/rx.hpp"
#include "node_util/node_util.hpp"

using namespace node_util; // console, "string"s +, 1000ms, set_timeout,
namespace rx = rxcpp;
using evt_t  = int;

void test_01_02() {
//-----------------------------------------------------------------------------
  auto on_subscribe = [](auto& observer) {
    std::array<std::function<void()>, 3> events = { 
        [=] { observer.on_next(evt_t(21)); } 
      , [=] { observer.on_completed();     } 
      , [=] { observer.on_next(evt_t(22)); }
    };

    set_timeout(events[0], 1000ms);
    set_timeout(events[1], 3000ms);
    set_timeout(events[2], 5000ms);

    auto on_dispose = [] { console::log ("on_dispose"); };
    observer.add(on_dispose);
  };

  auto handler_next      = [](evt_t i) { console::log  ("on_next: "s  + i); };
  auto handler_error     = [](auto  e) { console::error("on_error: "s + e); };
  auto handler_completed = []          { console::log  ("on_completed");    };

  //--------------
  auto observable   = rx::observable<>::create<evt_t>(on_subscribe);
  auto subscription = observable.subscribe(handler_next,
                                           handler_error,
                                           handler_completed);
//-----------------------------------------------------------------------------
}

/* 실행 결과

[14:44:03] [LOG]   ----- test start -----
[14:44:04] [LOG]   on_next: 21
[14:44:06] [LOG]   on_completed
[14:44:06] [LOG]   on_dispose
[14:44:08] [LOG]   ----- test end    -----

*/