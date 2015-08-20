#ifndef  __NODE_UTIL_SET_TIMEOUT_HPP__
#define  __NODE_UTIL_SET_TIMEOUT_HPP__

#include "boost/asio/system_timer.hpp"
#include "boost/optional.hpp"

namespace node_util {

using namespace boost::asio;

inline 
io_service* default_io_service(io_service* service = nullptr) {

    static io_service* service_ = nullptr;
    service_ = (service != nullptr) ? service : service_;
    return service_;
}

template<typename callback_t, typename time_t>
static auto set_timeout(callback_t& callback, 
                        time_t& time, 
                        io_service* io = nullptr) {

  auto& io_service = *default_io_service(io);

  auto timer = std::make_shared<system_timer>(io_service, time);

  timer->async_wait([timer, callback](auto& ec) {
    callback();
  });
};

}// end of namespace node_util

#endif //__NODE_UTIL_SET_TIMEOUT_HPP__