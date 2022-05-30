#include "format.hpp"
#include <iostream>
#include <iomanip>

using namespace std::string_literals;
using namespace format;

auto ltest = [](std::string const& email) {
    std::cout << std::setw(30) 
              << std::left 
              << email 
              << " : "
              << (is_valid_email_format(email) ? "valid format" : "invalid format")
              << "\n";
};

auto ltest2 = [](auto const& email) {
    std::wcout << std::setw(30) 
              << std::left 
              << email 
              << L" : "
              << (is_valid_email_format_w(email) ? L"valid format" : L"invalid format")
              << "\n";
};

auto ltest3 = [](std::string const& email) {
    auto [valid, localpart, hostname, dnslabel] = is_valid_email_format_with_result(email);
    std::cout << std::setw(30) << std::left 
              << email << " : "
              << std::setw(10) << (valid ? "valid" : "invalid")
              << "local=" << localpart
              << ";domain=" << hostname
              << ";dns=" << dnslabel
              << "\n";
};

int main() {
    ltest("JOHN.DOE@DOMAIN.COM"s);
    ltest("JOHNDOE@DOMAIN.CO.UK"s);
    ltest("JOHN.DOE@DOMAIN.INFO"s);
    ltest("J.O.H.N.D.O.E@DOMAIN.INFO"s);
    ltest("ROOT@LOCALHOST"s);
    ltest("john.doe@domain.com"s);

    std::cout << "------------" << std::endl;

    ltest2(L"JOHN.DOE@DOMAIN.COM"s);
    ltest2(L"JOHNDOE@DOMAIN.CO.UK"s);
    ltest2(L"JOHN.DOE@DOMAIN.INFO"s);
    ltest2(L"J.O.H.N.D.O.E@DOMAIN.INFO"s);
    ltest2(L"ROOT@LOCALHOST"s);
    ltest2(L"john.doe@domain.com"s);

    std::cout << "------------" << std::endl;

    ltest3("JOHN.DOE@DOMAIN.COM"s);
    ltest3("JOHNDOE@DOMAIN.CO.UK"s);
    ltest3("JOHN.DOE@DOMAIN.INFO"s);
    ltest3("J.O.H.N.D.O.E@DOMAIN.INFO"s);
    ltest3("ROOT@LOCALHOST"s);
    ltest3("john.doe@domain.com"s);
}
