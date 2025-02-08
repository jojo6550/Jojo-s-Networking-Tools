#include "../headers/ip_converter.h"
#include <iostream>
using namespace IPConverter;

int main(){
    IPv4Converter IPv4;

    //Menu

    int choice = 0;

    while (choice !=3){
        std::cout << "\n1. Convert IPv4 Decimal to Binary" << std::endl;
        std::cout << "\n2. Convert Binary to IPv4 Decimal" << std::endl;
        std::cout << "\n3. Exit" << std::endl;
        std::cin >> choice;

        switch (choice){
        case 1:
            IPv4.ipv4Caller();
            break;
        

        case 2:
            IPv4.decimalCaller();
            break;

        case 3:
            std::cout << "Exiting...";
            break;
        default:
            std::cout << "Invalid choice. Please choose a valid option." << std::endl;
            break;
        }
    }

    return 0;
}


