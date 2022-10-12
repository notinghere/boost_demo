#include <iostream>
#include "Class1.h"
#include <boost/asio.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;

    Class1 c1;
    c1.Print();

    boost::asio::ip::tcp::endpoint  edp;

//    boost::asio::io_service ios;

    return 0;
}
