#ifndef  __NODE_UTIL_STRING_CONVERSION_HPP__
#define  __NODE_UTIL_STRING_CONVERSION_HPP__

#include <exception>
#include <string>

namespace node_util {
namespace string_conversion {

template<typename T>
std::string operator+ (const std::string& str, const T& t) {
  using namespace std;
  return str + to_string(t);
}

template<typename T>
std::string operator+ (const T& t, const std::string& str) {
  using namespace std;
  return  std::to_string(t) + str;
}


}// end of namespace string_conversion 
}// end of namespace node_util

static std::string to_string(std::exception_ptr eptr) {

  try {
    if (eptr) {
      std::rethrow_exception(eptr);
    }
  }
  catch (const std::exception& e) {
    return e.what();
  }
}

#endif //__NODE_UTIL_STRING_CONVERSION_HPP__