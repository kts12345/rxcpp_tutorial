#ifndef  __NODE_UTIL_CONSOLE_HPP__
#define  __NODE_UTIL_CONSOLE_HPP__

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

namespace node_util { 
namespace console {

inline  void print(std::string arg) {
  auto t = time(nullptr);
  std::cout << "[" << std::put_time(std::localtime(&t), "%H:%M:%S") << "]"  
            << arg << std::endl;
}

inline void log(std::string arg) {
  print(" [LOG]   " + arg);
}

inline void error(std::string arg) {
  print(" [ERROR] " + arg);
}

}// end of namespace console
}// end of namespace node_util

#endif // __NODE_UTIL_CONSOLE_HPP__