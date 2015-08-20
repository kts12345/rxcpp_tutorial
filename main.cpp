#include <string>
#include "boost/asio.hpp"
#include "rxcpp/rx.hpp"
#include "node_util/util.hpp"


void test_01_01(boost::asio::io_service& io_service);

namespace aux1 {
  template<std::size_t...> struct seq {};

  template<std::size_t N, std::size_t... Is>
  struct gen_seq : gen_seq<N - 1, N - 1, Is...> {};

  template<std::size_t... Is>
  struct gen_seq<0, Is...> : seq<Is...> {};

  template<class Ch, class Tr, class Tuple, std::size_t... Is>
  void print_tuple(std::basic_ostream<Ch, Tr>& os, Tuple const& t, seq<Is...>) {
    using swallow = int[];
    (void)swallow {
      0, (void(os << std::get<Is>(t)), 0)...
    };
  }
} // aux::



int main(int argc, char** argv)
{
  auto vl = [](auto&& ...args)
  {
    auto args_tuple = std::make_tuple(args...);
    aux1::print_tuple(std::cout, args_tuple, aux1::gen_seq<sizeof...(args)>());
    std::cout << std::endl;
  };

  vl(1);
  vl(1, 2);
  vl(1, "3");
  vl("on_next: " + 5);

   

 // auto rc = test2();
  auto rc = 0;
  boost::asio::io_service io_service;
  test_01_01(io_service);

  io_service.run();
  return rc;
}
