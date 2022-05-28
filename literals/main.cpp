#include <iostream>

#include "literals.h"

using namespace binary::binary_literals;

int main() {
    unsigned char test = 1010_b8;
    auto another = 10100101101010111_b32;
    std::cout << static_cast<unsigned int>(test) << std::endl;
    std::cout << static_cast<unsigned int>(another) << std::endl;
}

