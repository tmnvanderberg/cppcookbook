#include "string.h"
#include <iostream>

using namespace string_util;

int main() {
    std::cout << "upper:" << to_upper(std::string{"something"}) << std::endl;
    std::cout << "lower:" << to_lower(std::string{"SOMEthing"}) << std::endl;
    std::cout << "reversed:" << reverse(std::string{"something"}) << std::endl;
    std::cout << "trimmed:" << trim(std::string{" something "}) << std::endl;
    std::cout << "trimmed left:" << trimleft(std::string{" something "}) << std::endl;
    std::cout << "trimmed right:" << trimright(std::string{" something "}) << std::endl;
    return 0;
}
