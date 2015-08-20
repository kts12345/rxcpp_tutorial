#include <string>
#include <chrono>
#include "boost/asio/system_timer.hpp"
#include "boost/asio.hpp"
#include "rxcpp/rx.hpp"
#include "node_util/node_util.hpp"

using namespace std::literals::chrono_literals;
using namespace node_util;


void test_01_01(boost::asio::io_service& io_service)
{
  namespace rx = rxcpp;

  auto source = rxcpp::observable<>::create<int>([&](auto& observer)
  {
    set_timeout( [=]() {
        observer.on_next(42);
        observer.on_completed();
      }, 
      6000ms,
      io_service);
  });

  auto on_next      = [&](auto i) { console::log("on_next: " + std::to_string(i));};
  auto on_error     = [&](auto e) { console::log("error");};
  auto on_completed = [&]()       { console::log("on_completed");};

  auto sub = source.subscribe(on_next, on_error, on_completed);

  return;
}

