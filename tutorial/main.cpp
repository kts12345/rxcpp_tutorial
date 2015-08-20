#include <string>
#include <boost/asio.hpp>
#include "rxcpp/rx.hpp"

#include "node_util/node_util.hpp"

using namespace boost::asio;

void test_01_01();
void test_01_02();

void test()
{
  test_01_01();
  test_01_02();
}

int main(int argc, char** argv)
{
  boost::asio::io_service io_service;

  node_util::default_io_service(&io_service);

  test();

  io_service.run();
}