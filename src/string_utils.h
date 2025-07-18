#pragma once

#include <string>
#include <vector>

namespace cpp_quiz {

/**
 * Utility functions for string manipulation and processing
 */
class StringUtils {
public:
    // String transformation
    static std::string to_upper(const std::string& str);
    static std::string to_lower(const std::string& str);
    static std::string reverse(const std::string& str);
    
    // String analysis
    static bool is_palindrome(const std::string& str);
    static bool is_anagram(const std::string& str1, const std::string& str2);
    static size_t count_words(const std::string& str);
    static size_t count_vowels(const std::string& str);
    
    // String manipulation
    static std::string trim(const std::string& str);
    static std::string trim_left(const std::string& str);
    static std::string trim_right(const std::string& str);
    
    // String splitting and joining
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static std::string join(const std::vector<std::string>& strings, const std::string& delimiter);
    
    // String searching
    static bool contains(const std::string& str, const std::string& substring);
    static size_t find_nth_occurrence(const std::string& str, const std::string& substring, size_t n);
    
private:
    static bool is_whitespace(char c);
    static char to_lower_char(char c);
    static char to_upper_char(char c);
};

} // namespace cpp_quiz
