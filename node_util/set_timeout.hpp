#ifndef  __NODE_UTIL_SET_TIMEOUT_HPP__
#define  __NODE_UTIL_SET_TIMEOUT_HPP__

#include <atomic>
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

struct timer_id
{
  static inline timer_id make_next_id() {
    static std::atomic<unsigned int> _id(0);
    return timer_id{ ++_id };
  }
  unsigned int id;
};

template<typename callback_t, typename time_t>
int set_timeout(callback_t& callback, 
                        time_t&     time, 
                        io_service* io = nullptr) {

  auto id = timer_id::make_next_id().id;

  auto& io_service = *default_io_service(io);

  auto timer = std::make_shared<system_timer>(io_service, time);
  g_timers()[id] = timer;

  timer->async_wait([callback, id](auto& ec) {
    if (!ec)
      callback();
    g_timers().erase(id);
  });

  return id;
};

inline void clear_timeout(int id)
{
  using namespace std::literals::chrono_literals;

  if (g_timers().find(id) != g_timers().end())
  {
    g_timers()[id]->expires_from_now(0ms);
  }
}

}// end of namespace node_util

#endif //__NODE_UTIL_SET_TIMEOUT_HPP__