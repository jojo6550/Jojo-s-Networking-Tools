#include <iostream>
#include "../include/ip_converter.h"
using namespace IPConverter;
int main(){
    IPv6Converter ipv6;
    std::string ip = "2001:db8:3333:4444:5555:6666:7777:8888";
    ipv6.isValidIP(ip);
    if (ipv6.isValidIP(ip) == true){
        std::cout << "IP is valid" << std::endl;
    } else {
        std::cout << "IP is not valid" << std::endl;
    }
    return 0;
}