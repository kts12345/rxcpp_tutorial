#include <string>
#include "rxcpp/rx.hpp"

#include "node_util/node_util.hpp"

using namespace node_util; // console
namespace rx = rxcpp;
using evt_t  = int;

void test_01_01() {

  auto on_subscribe = [](auto& observer) {
    observer.on_next(evt_t(10));
    observer.on_next(evt_t(11));
    observer.on_completed();
  };

  auto handler_next      = [](evt_t e) { console::log("on_next: "s  + e); };
  auto handler_error     = [](auto  e) { console::log("on_error: "s + e); };
  auto handler_completed = []          { console::log("on_completed"); };

  auto observable = rx::observable<>::create<evt_t>(on_subscribe);

  auto subscription = observable.subscribe(handler_next,
                                           handler_error,
                                           handler_completed);
  return;
}

// see https://github.com/kts12345/rxcpp_tutorial/tree/master/tutorial/01_01.md