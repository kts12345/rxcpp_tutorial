#include <string>
#include <chrono>
#include "rxcpp/rx.hpp"

#include "node_util/node_util.hpp"

using namespace std::literals::chrono_literals; // ms
using namespace node_util; // console, +, set_timeoutS
namespace rx = rxcpp;
using evt_t  = int;

void test_01_02() {

  auto on_subscribe = [](auto& observer) {
    auto gen_events = [observer] {
      observer.on_next(evt_t(21));
      observer.on_next(evt_t(22));
      observer.on_completed();
    };
    set_timeout(gen_events, 5000ms);
  };

  auto handler_next      = [](evt_t i) { console::log("on_next: "s   + i); };
  auto handler_error     = [](auto  e) { console::log("on_error: "s  + e); };
  auto handler_completed = []          { console::log("on_completed");    };

  auto observable   = rx::observable<>::create<evt_t>(on_subscribe);

  auto subscription = observable.subscribe(handler_next,
                                           handler_error,
                                           handler_completed);
}

