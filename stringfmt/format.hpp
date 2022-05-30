#include <regex>
#include <string>
#include <tuple>

using namespace std::string_literals;

namespace format {

    bool is_valid_email_format(std::string const& email) {
        auto pattern {R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s};
        auto rx = std::regex{pattern, std::regex_constants::icase};
        return std::regex_match(email, rx);
    }

    template <typename CharT>
    using tstring = std::basic_string<CharT, 
                                      std::char_traits<CharT>, 
                                      std::allocator<CharT>
                                     >;
    template <typename CharT>
    bool is_valid_format(tstring<CharT> const& pattern, tstring<CharT> const& text) {
        auto rx = std::basic_regex<CharT>{pattern, std::regex_constants::icase};
        return std::regex_match(text, rx);
    }

    bool is_valid_email_format_w(std::wstring const& text) {
        return is_valid_format(
            LR"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s,
            text);
    }
    
    std::tuple<bool, std::string, std::string, std::string>
    is_valid_email_format_with_result(std::string const& email) {
        auto rx = std::regex{
            R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s,
            std::regex_constants::icase};
        auto result = std::smatch{};
        auto success = std::regex_match(email, result, rx);
        return std::make_tuple(
                success,
                success ? result[1].str() : ""s,
                success ? result[2].str() : ""s,
                success ? result[3].str() : ""s
                );
    }
}
