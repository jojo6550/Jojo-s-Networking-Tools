 #include "../include/ip_converter.h"
 #include <iostream>
 #include <regex>
 #include <sstream>
 
 namespace IPConverter {
     bool IPv4Converter::isValidIP(const std::string& ip) {
         try {
             std::regex ipv4_pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
             return std::regex_match(ip, ipv4_pattern);
         } catch (const std::regex_error& e) {
             throw std::runtime_error(std::string("Error parsing IP address: ") + e.what());
         }
     }

     bool IPv4Converter::isValidDecimal(const std::string& ip){
         std::regex binary_regex(R"(^[01]{8}\.[01]{8}\.[01]{8}\.[01]{8}$)");
         return std::regex_match(ip, binary_regex);
     }

     std::vector<std::string> IPv4Converter::splitNumeral(const std::string& ip, const char& delim){
         std::stringstream ss(ip);
         std::vector<std::string> ipAddress;
         std::string t;
 
         while(getline(ss,t,delim)){
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
         if (ipAddress.size() != 4) {
             throw std::invalid_argument("Invalid IP address. Expected 4 parts.");
         }
         for (const auto& part : ipAddress) {
             int value = std::stoi(part);
             if (value < 0 || value > 255) {
                 throw std::out_of_range("IP address part out of range: " + part);
             }
         }
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
             std::cout << var;
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

     void IPv4Converter::ipCaller(){
         try{
 
         
             while (true){
                 std::cout << "Enter ipv4: ";
                 std::string container;
                 std::cin>>container;
 
                 if (isValidIP(container) == true){
                     std::vector <std::string> ipAddress = splitNumeral(container, '.');
                     numeralToBinaryConvert(ipAddress);
                     break;
                 } else {
                     std::cout << "Invalid ipv4" << std::endl;
                     continue;
 
                 }
             }
         } catch (const std::exception& e) {
             std::cerr << "Exception caught: " << e.what() << '\n';
         }
     }
 
     void IPv4Converter::decimalCaller(){
         while (true){
             std::cout << "Enter decimal: ";
             std::string container;
             std::cin>>container;
             if (isValidDecimal(container) == true){
                 std::vector <std::string> ipAddress = splitNumeral(container, '.');
                 binaryToNumeralConvert(ipAddress);
                 break;
             } else {
                 std::cout << "Invalid decimal" << std::endl;
                 continue;
             }
         }
     }
 


    bool IPv6Converter::isValidIP(const std::string& ip) {
        try {
            std::regex ipv6_pattern("^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$");
            return std::regex_match(ip, ipv6_pattern);
        } catch (const std::regex_error& e) {
            throw std::runtime_error(std::string("Error parsing IP address: ") + e.what());
        }
    }
        // IPv6Converter class implementation

    bool IPv6Converter::isValidDecimal(const std::string& ip) {
        IPv4Converter ipv4Converter;
        ipv4Converter.isValidDecimal(ip);
        return ipv4Converter.isValidDecimal(ip);
    }

    std::vector<std::string> IPv6Converter::splitNumeral(const std::string& ip, const char& delim) {
        std::stringstream ss(ip);
        std::vector<std::string> ipAddress;
        std::string t;

        while(getline(ss,t,delim)){
            ipAddress.push_back(t);
        }
        std::cout << "Numeral split\n";
        return ipAddress;

    }

    void IPv6Converter::displaySplitNumeral(const std::vector<std::string>& ipAddress) {
        std::cout << "Ip Address: ";
        for(auto var : ipAddress){
            std::cout << " " << var;
        }
    }

    void IPv6Converter::numeralToBinaryConvert(const std::vector<std::string>& ipAddress) {
        // Implement the logic to convert an IPv6 address to binary
    }

    void IPv6Converter::binaryToNumeralConvert(const std::vector<std::string>& ipAddress) {
        // Implement the logic to convert a binary IPv6 address to decimal
    }

    void IPv6Converter::ipCaller() {
        try{
            while (true){
                std::cout << "Enter ipv6: ";
                std::string container;
                std::cin>>container;

                if (isValidIP(container) == true){
                    std::vector <std::string> ipAddress = splitNumeral(container, ':');
                    numeralToBinaryConvert(ipAddress);
                    break;
                } else {
                    std::cout << "Invalid ipv6" << std::endl;
                    continue;

                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << '\n';
        }    
    }

    void IPv6Converter::decimalCaller() {
        // Implement the logic to call the decimal converter
    }

}