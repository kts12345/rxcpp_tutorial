#include <string>
#include "rxcpp/rx.hpp"
#include "node_util/node_util.hpp"

using namespace node_util;
namespace rx = rxcpp;

void test_01_01()
{
  auto source = rx::observable<>::create<int>(
  [&](auto& observer) {
    observer.on_next(42);
    observer.on_completed();
  });

  auto handler_next      = [](auto i) { console::log("on_next: "s  + i); };
  auto handler_error     = [](auto e) { console::log("on_error: "  + e); };
  auto handler_completed = []         { console::log("on_completed"); };

  auto sub = source.subscribe(handler_next,
                              handler_error,
                              handler_completed);
  return;
}