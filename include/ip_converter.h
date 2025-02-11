// ip_converter.h
#ifndef IP_CONVERTER_H
#define IP_CONVERTER_H

#include <string>
#include <vector>



class IPConverter {
    public:
        virtual bool isValidIP(const std::string& ip) = 0;
        virtual bool isValidDecimal(const std::string& ip) = 0;
        virtual std::vector<std::string> splitNumeral(const std::string& b, const char & delim) = 0;
        virtual void displaySplitNumeral(const std::vector<std::string>& ipAddress) = 0;
        virtual void numeralToBinaryConvert(const std::vector<std::string>& ipAddress) = 0;
        virtual void binaryToNumeralConvert(const std::vector<std::string>& ipAddress) = 0;
        virtual void ipCaller() = 0;
        virtual void decimalCaller() = 0;
    };

class IPv4Converter : public IPConverter {
    public:
        bool isValidIP(const std::string& ip) override;
        bool isValidDecimal(const std::string& ip) override;
        std::vector<std::string> splitNumeral(const std::string& b, const char & delim) override;
        void displaySplitNumeral(const std::vector<std::string>& ipAddress) override;
        void numeralToBinaryConvert(const std::vector<std::string>& ipAddress) override;
        void binaryToNumeralConvert(const std::vector<std::string>& ipAddress) override;
        void ipCaller() override;
        void decimalCaller() override;

    };

class IPv6Converter : public IPConverter {
    public:
        bool isValidIP(const std::string& ip) override;
        bool isValidDecimal(const std::string& ip) override;
        std::vector<std::string> splitNumeral(const std::string& b, const char & delim) override;
        void displaySplitNumeral(const std::vector<std::string>& ipAddress) override;
        void numeralToBinaryConvert(const std::vector<std::string>& ipAddress) override;
        void binaryToNumeralConvert(const std::vector<std::string>& ipAddress) override;
        void ipCaller() override;
        void decimalCaller() override;


};
#endif
