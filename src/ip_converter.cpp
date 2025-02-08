#include "../headers/ip_converter.h"
#include <iostream>
#include <regex>
#include <sstream>

namespace IPConverter{
    bool IPv4Converter::isValidIPv4(const std::string& ip) {
        std::regex ipv4_pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
        return std::regex_match(ip, ipv4_pattern);
    }

    bool IPv4Converter::isValidDecimal(const std::string& ip){
        std::regex binary_regex(R"(^[01]{8}\.[01]{8}\.[01]{8}\.[01]{8}$)");
        return std::regex_match(ip, binary_regex);
    }


    std::vector<std::string> splitNumeral(const std::string& b){

        std::stringstream ss(b);
        char delimeter = '.';
        std::vector<std::string> ipAddress;
        std::string t;

        while(getline(ss,t,delimeter)){
            ipAddress.push_back(t);
        }
        std::cout << "Numeral split\n";
        return ipAddress;
    }

    void IPv4Converter::displaySplitNumeral(const std::vector<std::string>& ipAddress) {
        std::cout << "Ip Address: ";
        for(auto var : ipAddress){
            std::cout << " " << var;
        }
    }

    void IPv4Converter::numeralToBinaryConvert(const std::vector<std::string>& ipAddress) {
        std::vector<std::string> binary;
        std::cout << "Received" << std::endl;
        for(auto var : ipAddress){
            int n = stoi(var);
            //base 2
            if (n-128>=0){
                binary.emplace_back("1"); 
                n-=128;
                
            } else {
                binary.emplace_back("0");
            }
            if (n-64>=0){
                binary.emplace_back("1"); 
                n-=64;
                
            } else {
                binary.emplace_back("0");
            }
            if (n-32>=0){
                binary.emplace_back("1"); 
                n-=32;
                
            } else {
                binary.emplace_back("0");
            }
            if (n-16>=0){
                binary.emplace_back("1"); 
                n-=16;
                
            } else {
                binary.emplace_back("0");
            }
            if (n-8>=0){
                binary.emplace_back("1"); 
                n-=8;
                
            } else {
                binary.emplace_back("0");
            }
            if (n-4>=0){
                binary.emplace_back("1"); 
                n-=4;
                
            } else {
                binary.emplace_back("0");
            }
            if (n-2>=0){
                binary.emplace_back("1"); 
                n-=2;
                
            } else {
                binary.emplace_back("0");
            }
            if (n-1>=0){
                binary.emplace_back("1"); 
                n-=1;
                
            } else {
                binary.emplace_back("0");
            }

            binary.emplace_back(".");
        }
        binary.pop_back();
        for(auto var : binary){
            std::cout << var << std::endl;
        }
    }

    void IPv4Converter::binaryToNumeralConvert(const std::vector<std::string>& ipAddress){
        std::vector <std::string> newIpAddress;
        for (auto var: ipAddress){
            int decimal = stoi(var,0,2);
            newIpAddress.emplace_back(std::to_string(decimal));
            newIpAddress.emplace_back(".");
        }
            newIpAddress.pop_back();
            for(auto var : newIpAddress){
                std::cout << var;
            }
    }

    void IPv4Converter::ipv4Caller(){
        while (true){
            std::cout << "Enter ipv4: ";
            std::string container;
            std::cin>>container;

            if (isValidIPv4(container) == true){
                std::vector <std::string> ipAddress = splitNumeral(container);
                numeralToBinaryConvert(ipAddress);
                break;
            } else {
                std::cout << "Invalid ipv4" << std::endl;
                continue;

            }
        }
    }

    void IPv4Converter::decimalCaller(){
        while (true){
            std::cout << "Enter decimal: ";
            std::string container;
            std::cin>>container;
            if (isValidDecimal(container) == true){
                std::vector <std::string> ipAddress = splitNumeral(container);
                binaryToNumeralConvert(ipAddress);
                break;
            } else {
                std::cout << "Invalid decimal" << std::endl;
                continue;
            }
        }
    }
}