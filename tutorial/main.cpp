//main.cpp 

#include <boost/asio.hpp>
#include "node_util/node_util.hpp"

using namespace node_util; // console, default_io_service

void test_01_01();
void test_01_02();
void test_01_03();

int main(int argc, char** argv) {
  
  boost::asio::io_service io_service;
  default_io_service(&io_service);

  {
    console::log("----- test start -----");
  //-----------------------------------------------------------------------------
  //  test_01_01();
  //  test_01_02();
    test_01_03();
  //-----------------------------------------------------------------------------
  }

  io_service.run();
  console::log("----- test end    -----");
}
