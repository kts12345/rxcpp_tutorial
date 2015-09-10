//01_04.cpp

#include <array>
#include <functional>
#include "rxcpp/rx.hpp"
#include "node_util/node_util.hpp"

using namespace node_util; // console, "string"s +, 1000ms, set_timeout,
namespace rx = rxcpp;
using evt_t = int;

void test_01_05() {
  //-----------------------------------------------------------------------------
  auto on_subscribe = [](auto& observer) {
    std::array<std::function<void()>, 3> events = {
        [=] { observer.on_next(evt_t(51)); }
      , [=] { observer.on_completed();     }
      , [=] { observer.on_next(evt_t(52)); }
    };

    std::array<int, 3> ids = {
        set_timeout(events[0], 1000ms)
      , set_timeout(events[1], 3000ms)
      , set_timeout(events[2], 5000ms)
    };

    auto on_dispose = [=] { 
      console::log("on_dispose"); 
      for (auto id : ids)
        clear_timeout(id);
    };
    observer.add(on_dispose);
  };

  auto handler_next      = [](evt_t i) { console::log  ("on_next: "s  + i); };
  auto handler_error     = [](auto  e) { console::error("on_error: "s + e); };
  auto handler_completed = []          { console::log  ("on_completed");    };

  //--------------
  auto observable1  = rx::observable<>::create<evt_t>(on_subscribe);
  auto observable2  = observable1.map([](evt_t i) { return i + 1000; });
  auto subscription = observable2.subscribe(handler_next,
                                            handler_error,
                                            handler_completed);

  set_timeout(
      [subscription] { subscription.unsubscribe(); }
    , 2000ms);
  //-----------------------------------------------------------------------------
}

/* 실행 결과

[14:44:51] [LOG]   ----- test start -----
[14:44:52] [LOG]   on_next: 31
[14:44:53] [LOG]   on_dispose
[14:44:53] [LOG]   ----- test end    -----

*/