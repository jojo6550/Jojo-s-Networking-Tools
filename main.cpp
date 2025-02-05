#include <bits/stdc++.h>
using namespace std;


class NetworkingNumeralSystem{
    public:
        NetworkingNumeralSystem(){
            
        }

        //splits a ip address
        vector<string> splitNumeral(string b){

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
        //splits into pieces
        void displaySplitNumeral(vector <string> ipAddress){
            std::cout << "Ip Address: ";
            for(auto var : ipAddress){
                std::cout << var;
            }
        }

        //converts numeral to binary
        void numeralToBinary(vector <string> ipAddress){
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

        void mainFunctionCaller(){
            string container;
            cin>>container;
            vector <string> ipAddress = splitNumeral(container);
            numeralToBinary(ipAddress);
        }


        void numeralToHexadecimal(int n){
            //base 16

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
    NetworkingNumeralSystem converter;
    converter.mainFunctionCaller();



    
    return 0;
}