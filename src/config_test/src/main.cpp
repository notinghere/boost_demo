
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    boost::property_tree::ptree pt;
    try {
        boost::property_tree::ini_parser::read_ini("/home/evan/src/mygit/boost_demo/conf/config.ini", pt);
    }
    catch (std::exception e) {
        cout << e.what();
        return -1;
    }

    std::string ip = pt.get<string>("System.ip", "127.0.0.2");
    int port = pt.get<int>("System.port", 10000);

    cout << "ip=" << ip << "\nport=" << port << endl;

    return 0;
}