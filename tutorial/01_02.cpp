#include <string>
#include <chrono>
#include "rxcpp/rx.hpp"
#include "node_util/node_util.hpp"

using namespace std::literals::chrono_literals;
using namespace node_util;
namespace rx = rxcpp;

void test_01_02()
{

  auto source = rx::observable<>::create<int>([&](auto& observer) {
    set_timeout([=]{
        observer.on_next(42);
        observer.on_completed();
      }, 6s);
  });

  auto handler_next       = [](auto i) { console::log("on_next: "s  + i); };
  auto handler_error      = [](auto e) { console::log("on_error: "  + e); };
  auto handler_completed  = []         { console::log("on_completed");    };

  auto sub = source.subscribe(handler_next,
                              handler_error,
                              handler_completed);
}

