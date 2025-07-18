#include "src/string_utils.h"
#include <algorithm>
#include <cctype>
#include <sstream>

namespace cpp_quiz
{

    std::string StringUtils::to_upper(const std::string &str)
    {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), to_upper_char);
        return result;
    }

    std::string StringUtils::to_lower(const std::string &str)
    {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), to_lower_char);
        return result;
    }

    std::string StringUtils::reverse(const std::string &str)
    {
        std::string result = str;
        std::reverse(result.begin(), result.end());
        return result;
    }

    bool StringUtils::is_palindrome(const std::string &str)
    {
        std::string cleaned = to_lower(str);
        cleaned.erase(std::remove_if(cleaned.begin(), cleaned.end(),
                                     [](char c)
                                     { return !std::isalnum(c); }),
                      cleaned.end());
        return cleaned == reverse(cleaned);
    }

    bool StringUtils::is_anagram(const std::string &str1, const std::string &str2)
    {
        std::string s1 = to_lower(str1);
        std::string s2 = to_lower(str2);

        s1.erase(std::remove_if(s1.begin(), s1.end(),
                                [](char c)
                                { return !std::isalnum(c); }),
                 s1.end());
        s2.erase(std::remove_if(s2.begin(), s2.end(),
                                [](char c)
                                { return !std::isalnum(c); }),
                 s2.end());

        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        return s1 == s2;
    }

    size_t StringUtils::count_words(const std::string &str)
    {
        std::istringstream iss(str);
        std::string word;
        size_t count = 0;
        while (iss >> word)
        {
            ++count;
        }
        return count;
    }

    size_t StringUtils::count_vowels(const std::string &str)
    {
        const std::string vowels = "aeiouAEIOU";
        return std::count_if(str.begin(), str.end(),
                             [&vowels](char c)
                             { return vowels.find(c) != std::string::npos; });
    }

    std::string StringUtils::trim(const std::string &str)
    {
        return trim_left(trim_right(str));
    }

    std::string StringUtils::trim_left(const std::string &str)
    {
        auto start = std::find_if_not(str.begin(), str.end(), is_whitespace);
        return std::string(start, str.end());
    }

    std::string StringUtils::trim_right(const std::string &str)
    {
        auto end = std::find_if_not(str.rbegin(), str.rend(), is_whitespace);
        return std::string(str.begin(), end.base());
    }

    std::vector<std::string> StringUtils::split(const std::string &str, char delimiter)
    {
        std::vector<std::string> result;
        std::stringstream ss(str);
        std::string item;

        while (std::getline(ss, item, delimiter))
        {
            result.push_back(item);
        }

        return result;
    }

    std::string StringUtils::join(const std::vector<std::string> &strings, const std::string &delimiter)
    {
        if (strings.empty())
            return "";

        std::string result = strings[0];
        for (size_t i = 1; i < strings.size(); ++i)
        {
            result += delimiter + strings[i];
        }
        return result;
    }

    bool StringUtils::contains(const std::string &str, const std::string &substring)
    {
        return str.find(substring) != std::string::npos;
    }

    size_t StringUtils::find_nth_occurrence(const std::string &str, const std::string &substring, size_t n)
    {
        size_t pos = 0;
        for (size_t i = 0; i < n; ++i)
        {
            pos = str.find(substring, pos);
            if (pos == std::string::npos)
            {
                return std::string::npos;
            }
            if (i < n - 1)
            {
                pos += substring.length();
            }
        }
        return pos;
    }

    bool StringUtils::is_whitespace(char c)
    {
        return std::isspace(static_cast<unsigned char>(c));
    }

    char StringUtils::to_lower_char(char c)
    {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    char StringUtils::to_upper_char(char c)
    {
        return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }

} // namespace cpp_quiz
