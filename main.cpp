#include <bits/stdc++.h>
using namespace std;


class IPv4Converter{
    public:
        bool isValidIPv4(const string& ip) {
            std::regex ipv4_pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
            return std::regex_match(ip, ipv4_pattern);
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
                std::cout << var;
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
        

        void mainCaller(){
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
};





int main(){
    /*
    string container;
    cin>>container;

    NetworkingNumeralSystem converter;

    vector <string> ipAddress = converter.splitNumeral(container);
    converter.numeralToBinary(ipAddress);
    */
    IPv4Converter converter;
    converter.mainCaller();



    
    return 0;
}


