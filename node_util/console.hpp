#ifndef  __NODE_UTIL_CONSOLE_HPP__
#define  __NODE_UTIL_CONSOLE_HPP__

#include <iostream>

namespace node_util { 
namespace console {

  namespace imple_tuple_print{
    template<std::size_t...> struct seq {};

    template<std::size_t N, std::size_t... Is>
    struct gen_seq : gen_seq<N - 1, N - 1, Is...> {};

    template<std::size_t... Is>
    struct gen_seq<0, Is...> : seq<Is...> {};

    template<class Ch, class Tr, class Tuple, std::size_t... Is>
    void print(std::basic_ostream<Ch, Tr>& os, Tuple const& t, seq<Is...>) {
      using swallow = int[];
      (void)swallow {
        0, (void(os << std::get<Is>(t)), 0)...
      };
    }
  }

static auto log = [](auto&& ...args) {

  auto args_tuple = std::make_tuple(args...);

  imple_tuple_print::print(std::cout, 
                           args_tuple, 
                           imple_tuple_print::gen_seq<sizeof...(args)>());
  std::cout << std::endl;
};


}// end of namespace console
}// end of namespace node_util

#endif // __NODE_UTIL_CONSOLE_HPP__