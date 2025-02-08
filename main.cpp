#include <bits/stdc++.h>
using namespace std;


class IPv4Converter{
    public:
        bool isValidIPv4(const string& ip) {
            std::regex ipv4_pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
            return std::regex_match(ip, ipv4_pattern);
        }

        bool isValidDecimal(const string& ip){
            std::regex binary_regex(R"(^[01]{8}\.[01]{8}\.[01]{8}\.[01]{8}$)");
            return std::regex_match(ip, binary_regex);
        }

        //splits a ip address
        vector<string> splitNumeral(const string& b){

            stringstream ss(b);
            char delimeter = '.';
            vector<string> ipAddress;
            string t;

            while(getline(ss,t,delimeter)){
                ipAddress.push_back(t);
            }
            cout << "Numeral split\n";
            return ipAddress;
        }

        void displaySplitNumeral(const vector <string>& ipAddress){
            std::cout << "Ip Address: ";
            for(auto var : ipAddress){
                std::cout << " " << var;
            }
        }

        //converts numeral to binary
        void numeralToBinary(const vector <string>& ipAddress){
            vector<string> binary;
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
                cout << var;
            }
        }

        void binaryToDecimal(const vector <string>& ipAddress){
            vector <string> newIpAddress;
            for (auto var: ipAddress){
                int decimal = stoi(var,0,2);
                newIpAddress.emplace_back(to_string(decimal));
                newIpAddress.emplace_back(".");
                }
                newIpAddress.pop_back();
                for(auto var : newIpAddress){
                    cout << var;
                }
            
            }

        void ipv4Caller(){
        while (true){
            std::cout << "Enter ipv4: ";
            string container;
            cin>>container;

            if (isValidIPv4(container) == true){
                vector <string> ipAddress = splitNumeral(container);
                numeralToBinary(ipAddress);
                break;
            } else {
                std::cout << "Invalid ipv4" << std::endl;
                continue;

                }
            }
        }

        void decimalCaller(){
            while (true){
                std::cout << "Enter decimal: ";
                string container;
                cin>>container;
                if (isValidDecimal(container) == true){
                    vector <string> ipAddress = splitNumeral(container);
                    binaryToDecimal(ipAddress);
                    break;
                } else {
                    std::cout << "Invalid decimal" << std::endl;
                    continue;
                }
            }
        }
};


class IPv6Converter{
    public:
        vector<string> splitNumeral(const string& b){

            stringstream ss(b);
            char delimeter = ':';
            vector<string> ipAddress;
            string t;

            while(getline(ss,t,delimeter)){
                ipAddress.push_back(t);
            }
            cout << "Numeral split\n";
            return ipAddress;
        }

        void displaySplitNumeral(const vector <string>& ipAddress){
            cout <<"Ip Address: ";
            for(auto var : ipAddress){
                cout << var;
                cout << "Complete";
            }
        }

};




int main(){
    IPv4Converter IPv4;

    //Menu

    int choice = 0;

    while (choice !=3){
        cout << "\n1. Convert IPv4 Decimal to Binary" << endl;
        cout << "\n2. Convert Binary to IPv4 Decimal" << endl;
        cout << "\n3. Exit" << endl;
        cin >> choice;

        switch (choice){
        case 1:
            IPv4.ipv4Caller();
            break;
        

        case 2:
            IPv4.decimalCaller();
            break;

        case 3:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
            break;
        }
    }

    return 0;
}


