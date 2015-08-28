//01_01.cpp

#include "rxcpp/rx.hpp"
#include "node_util/node_util.hpp"

using namespace node_util; // console, "string"s + 
namespace rx = rxcpp;
using evt_t  = int;

void test_01_01() {
//-----------------------------------------------------------------------------
  auto on_subscribe = [](auto& observer) {
    observer.on_next(evt_t(11));
    observer.on_completed();
    observer.on_next(evt_t(12));

    auto on_dispose = [] { console::log("on_dispose"); };
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

[14:38:28] [LOG]   ----- test start -----
[14:38:28] [LOG]   on_next: 11
[14:38:28] [LOG]   on_completed
[14:38:28] [LOG]   on_dispose
[14:38:28] [LOG]   ----- test end    -----

*/
