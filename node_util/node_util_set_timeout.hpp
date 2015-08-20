#include "boost/asio/system_timer.hpp"

namespace node_util {

auto set_timeout = [](auto& callback, auto& time, auto& io_service)
{
  using timer_t = boost::asio::system_timer;

  auto timer = std::make_shared<timer_t>(io_service, time);

  timer->async_wait([timer, callback](auto& ec) {
    callback();
  });
};

}// end of namespace node_util