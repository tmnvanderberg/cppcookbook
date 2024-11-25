#include <iostream>
#include <string_view>
#include <vector>
#include <string>
#include <algorithm>

#include "constexpr.h"

constexpr auto use_vector() {
	std::vector<int> vec{1, 2, 3};
  return vec;
}

consteval auto const_vec_l() {
	std::vector<int> vec{1, 2, 3};
	return vec.size() < 5;
}

consteval auto const_vec_g() {
	std::vector<int> vec{1, 2, 3};
	return vec.size() > 5;
}

int main() {
	if constexpr (const_vec_g()) {
		std::cout << "vector bigger than 5" << std::endl;
	}
	if constexpr (const_vec_l()) {
		std::cout << "vector lesser than 5" << std::endl;
	}
	constexpr auto vs = use_vector().size();
	std::cout << "vector size: " << vs << std::endl;
	static_assert(is_palindrome("racecar"), "racecar should be a palindrome!");
	/* static_assert(!is_palindrome("hello"), "hello should not be a palindrome!"); */
}

