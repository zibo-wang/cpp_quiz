#include "src/string_utils.h"
#include <gtest/gtest.h>

namespace cpp_quiz
{

    class StringUtilsTest : public ::testing::Test
    {
    };

    TEST_F(StringUtilsTest, CaseConversion)
    {
        EXPECT_EQ(StringUtils::to_upper("hello"), "HELLO");
        EXPECT_EQ(StringUtils::to_lower("WORLD"), "world");
        EXPECT_EQ(StringUtils::to_upper("MiXeD cAsE"), "MIXED CASE");
    }

    TEST_F(StringUtilsTest, StringReverse)
    {
        EXPECT_EQ(StringUtils::reverse("hello"), "olleh");
        EXPECT_EQ(StringUtils::reverse(""), "");
        EXPECT_EQ(StringUtils::reverse("a"), "a");
    }

    TEST_F(StringUtilsTest, PalindromeCheck)
    {
        EXPECT_TRUE(StringUtils::is_palindrome("racecar"));
        EXPECT_TRUE(StringUtils::is_palindrome("A man a plan a canal Panama"));
        EXPECT_FALSE(StringUtils::is_palindrome("hello"));
        EXPECT_TRUE(StringUtils::is_palindrome(""));
    }

    TEST_F(StringUtilsTest, AnagramCheck)
    {
        EXPECT_TRUE(StringUtils::is_anagram("listen", "silent"));
        EXPECT_TRUE(StringUtils::is_anagram("The Eyes", "They See"));
        EXPECT_FALSE(StringUtils::is_anagram("hello", "world"));
    }

    TEST_F(StringUtilsTest, WordCount)
    {
        EXPECT_EQ(StringUtils::count_words("hello world"), 2);
        EXPECT_EQ(StringUtils::count_words(""), 0);
        EXPECT_EQ(StringUtils::count_words("   spaced   out   "), 2);
    }

    TEST_F(StringUtilsTest, VowelCount)
    {
        EXPECT_EQ(StringUtils::count_vowels("hello"), 2);
        EXPECT_EQ(StringUtils::count_vowels("AEIOU"), 5);
        EXPECT_EQ(StringUtils::count_vowels("xyz"), 0);
    }

    TEST_F(StringUtilsTest, StringTrimming)
    {
        EXPECT_EQ(StringUtils::trim("  hello  "), "hello");
        EXPECT_EQ(StringUtils::trim_left("  hello  "), "hello  ");
        EXPECT_EQ(StringUtils::trim_right("  hello  "), "  hello");
    }

    TEST_F(StringUtilsTest, StringSplitting)
    {
        auto result = StringUtils::split("a,b,c", ',');
        EXPECT_EQ(result.size(), 3);
        EXPECT_EQ(result[0], "a");
        EXPECT_EQ(result[1], "b");
        EXPECT_EQ(result[2], "c");
    }

    TEST_F(StringUtilsTest, StringJoining)
    {
        std::vector<std::string> words = {"hello", "world", "test"};
        EXPECT_EQ(StringUtils::join(words, " "), "hello world test");
        EXPECT_EQ(StringUtils::join({}, ","), "");
    }

    TEST_F(StringUtilsTest, StringContains)
    {
        EXPECT_TRUE(StringUtils::contains("hello world", "world"));
        EXPECT_FALSE(StringUtils::contains("hello", "xyz"));
    }

} // namespace cpp_quiz
