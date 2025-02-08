// ip_converter.h
#pragma once

#include <string>
#include <vector>

namespace IPConverter{

    class IPConverter {
    public:
        virtual bool isValidIPv4(const std::string& ip) = 0;
        virtual bool isValidDecimal(const std::string& ip) = 0;
        virtual std::vector<std::string> splitNumeral(const std::string& b) = 0;
        virtual void displaySplitNumeral(const std::vector<std::string>& ipAddress) = 0;
        virtual void numeralToBinaryConvert(const std::vector<std::string>& ipAddress) = 0;
        virtual void binaryToNumeralConvert(const std::vector<std::string>& ipAddress) = 0;
        virtual void ipv4Caller() = 0;
        virtual void decimalCaller() = 0;
    };

    class IPv4Converter : public IPConverter {
    public:
        bool isValidIPv4(const std::string& ip) override;
        bool isValidDecimal(const std::string& ip) override;
        std::vector<std::string> splitNumeral(const std::string& b) override;
        void displaySplitNumeral(const std::vector<std::string>& ipAddress) override;
        void numeralToBinaryConvert(const std::vector<std::string>& ipAddress) override;
        void binaryToNumeralConvert(const std::vector<std::string>& ipAddress) override;
        void ipv4Caller() override;
        void decimalCaller() override;

    };

    class IPv6Converter : public IPConverter {
    public:
        bool isValidIPv4(const std::string& ip) override;
        bool isValidDecimal(const std::string& ip) override;
        std::vector<std::string> splitNumeral(const std::string& b) override;
        void displaySplitNumeral(const std::vector<std::string>& ipAddress) override;
        void numeralToBinaryConvert(const std::vector<std::string>& ipAddress) override;
        void binaryToNumeralConvert(const std::vector<std::string>& ipAddress) override;
        void ipv4Caller() override;
        void decimalCaller() override;


    };
}
