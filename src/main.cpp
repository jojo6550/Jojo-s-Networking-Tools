#include "../include/ip_converter.h"
#include <iostream>
using namespace IPConverter;

int main(){
    IPv4Converter IPv4;
    IPv6Converter IPv6;


    //Menu
    int choice = 0;

    while (choice !=5){
        std::cout << "\n1. Convert IPv4 Decimal to Binary" << std::endl;
        std::cout << "\n2. Convert Binary to IPv4 Decimal" << std::endl;
        std::cout << "\n3. Converter IPv6 Decimal to Binary" << std::endl;
        std::cout << "\n4. Converter Binary to IPv6 Decimal" << std::endl;
        std::cout << "\n5. Exit" << std::endl;
        std::cin >> choice;

        switch (choice){
        case 1:
            try {
                IPv4.ipCaller();
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
            }
            break;
        

        case 2:
        try {
            IPv4.decimalCaller();
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
                }
            break;

        case 3:
        try {
            IPv6.ipCaller();
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
            }
            break;
        case 4:
            IPv6.decimalCaller();
            break;
        case 5:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please choose a valid option." << std::endl;
            break;
        }
    }

    return 0;
}


