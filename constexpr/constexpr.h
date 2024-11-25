// in cpp20, you can now do compile time calculations with algorithm, std string and vector

constexpr bool is_palindrome(const std::string_view str){
	return std::equal(str.begin(), str.end(), str.cbegin(), str.cend());
}

