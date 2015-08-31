#ifndef  __NODE_UTIL_SET_TIMEOUT_HPP__
#define  __NODE_UTIL_SET_TIMEOUT_HPP__

#include <boost/asio/system_timer.hpp>
#include <boost/optional.hpp>

namespace node_util {

using namespace boost::asio;

inline 
io_service* default_io_service(io_service* service = nullptr) {

    static io_service* service_ = nullptr;

    if (service)
      service_ = service;

    return service_;
}

inline 
std::map<int, std::shared_ptr<system_timer>> &
g_timers() {
  static std::map<int, std::shared_ptr<system_timer>> _timers;
  return _timers;
}

template<typename callback_t, typename time_t>
static int set_timeout(callback_t& callback, 
                        time_t&     time, 
                        io_service* io = nullptr) {

  static int _id = 0;
  auto id = _id++;

  auto& io_service = *default_io_service(io);

  auto timer = std::make_shared<system_timer>(io_service, time);
  g_timers()[id] = timer;

  timer->async_wait([callback, id](auto& ec) {
    g_timers()[id].reset();
    if (!ec)
      callback();
  });

  return id;
};

inline void clear_timeout(int id)
{
  using namespace std::literals::chrono_literals;

  if (g_timers()[id])
  {
    g_timers()[id]->expires_from_now(0ms);
  }
}

}// end of namespace node_util

#endif //__NODE_UTIL_SET_TIMEOUT_HPP__