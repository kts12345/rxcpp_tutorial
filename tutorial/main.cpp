//main_creating.cpp 
//see https://github.com/Reactive-Extensions/RxJS/blob/master/doc/gettingstarted/creating.md

#include <boost/asio.hpp>
#include "node_util/node_util.hpp"

void test_01_01();
void test_01_02();
void test_01_03();

void test_main() {
//-----------------------------------------------------------------------------
  test_01_01();
  test_01_02();
//test_01_03();
//-----------------------------------------------------------------------------
}

int main(int argc, char** argv) {

  boost::asio::io_service io_service;

  node_util::default_io_service(&io_service);

  test_main();

  io_service.run();
}