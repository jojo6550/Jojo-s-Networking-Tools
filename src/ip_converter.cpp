/**
 * @file ip_converter.cpp
 * @brief Implementation of the IPv4Converter class.
 */

 #include "../include/ip_converter.h"
 #include <iostream>
 #include <regex>
 #include <sstream>
 
 namespace IPConverter {
 
     /**
      * @brief Checks if a given string is a valid IPv4 address.
      * 
      * @param ip The IPv4 address to check.
      * @return true If the IPv4 address is valid.
      * @return false If the IPv4 address is not valid.
      */
     bool IPv4Converter::isValidIPv4(const std::string& ip) {
         try {
             std::regex ipv4_pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
             return std::regex_match(ip, ipv4_pattern);
         } catch (const std::regex_error& e) {
             throw std::runtime_error(std::string("Error parsing IP address: ") + e.what());
         }
     }
 
     /**
      * @brief Checks if a given string is a valid decimal representation of an IPv4 address.
      * 
      * @param ip The decimal representation of the IPv4 address to check.
      * @return true If the decimal representation is valid.
      * @return false If the decimal representation is not valid.
      */
     bool IPv4Converter::isValidDecimal(const std::string& ip){
         std::regex binary_regex(R"(^[01]{8}\.[01]{8}\.[01]{8}\.[01]{8}$)");
         return std::regex_match(ip, binary_regex);
     }
 
     /**
      * @brief Splits a decimal or binary IPv4 address into its four parts.
      * 
      * @param b The IPv4 address to split.
      * @return std::vector<std::string> A vector of the four parts of the IPv4 address.
      */
     std::vector<std::string> IPv4Converter::splitNumeral(const std::string& b){
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
 
     /**
      * @brief Displays the split IPv4 address.
      * 
      * @param ipAddress The split IPv4 address to display.
      */
     void IPv4Converter::displaySplitNumeral(const std::vector<std::string>& ipAddress) {
         std::cout << "Ip Address: ";
         for(auto var : ipAddress){
             std::cout << " " << var;
         }
     }
 
     /**
      * @brief Converts a decimal IPv4 address to its binary representation.
      * 
      * @param ipAddress The decimal IPv4 address to convert.
      */
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
 
     /**
      * @brief Converts a binary IPv4 address to its decimal representation.
      * 
      * @param ipAddress The binary IPv4 address to convert.
      */
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
 
     /**
      * @brief Prompts the user to enter an IPv4 address and converts it to binary.
      */
     void IPv4Converter::ipv4Caller(){
         try{
 
         
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
         } catch (const std::exception& e) {
             std::cerr << "Exception caught: " << e.what() << '\n';
         }
     }
 
     /**
      * @brief Prompts the user to enter a decimal IPv4 address and converts it to binary.
      */
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