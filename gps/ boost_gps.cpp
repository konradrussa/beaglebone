#include <iostream>
#include "boost/asio.hpp"
#include "boost/asio/serial_port.hpp"

#define BUFSIZE 256

int main() {
        boost::asio::io_service io;
        boost::asio::serial_port port(io, "/dev/ttyS2");
        port.set_option(boost::asio::serial_port_base::baud_rate(9600));
        port.set_option(boost::asio::serial_port_base::character_size(8));
        port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

        while(true) {
                char data[BUFSIZE];
                size_t n = port.read_some(boost::asio::buffer(data, BUFSIZE));
                std::cout.write(data, n);
        }
}
