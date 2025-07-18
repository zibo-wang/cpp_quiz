#include "src/simple_stack.h"
#include <gtest/gtest.h>
#include <string>

namespace cpp_quiz
{

    class SimpleStackTest : public ::testing::Test
    {
    protected:
        SimpleStack<int> int_stack;
        SimpleStack<std::string> string_stack;
    };

    TEST_F(SimpleStackTest, EmptyStack)
    {
        EXPECT_TRUE(int_stack.empty());
        EXPECT_EQ(int_stack.size(), 0);
    }

    TEST_F(SimpleStackTest, PushAndPop)
    {
        int_stack.push(42);
        EXPECT_FALSE(int_stack.empty());
        EXPECT_EQ(int_stack.size(), 1);
        EXPECT_EQ(int_stack.top(), 42);

        int value = int_stack.pop();
        EXPECT_EQ(value, 42);
        EXPECT_TRUE(int_stack.empty());
    }

    TEST_F(SimpleStackTest, MultipleElements)
    {
        int_stack.push(1);
        int_stack.push(2);
        int_stack.push(3);

        EXPECT_EQ(int_stack.size(), 3);
        EXPECT_EQ(int_stack.top(), 3);

        EXPECT_EQ(int_stack.pop(), 3);
        EXPECT_EQ(int_stack.pop(), 2);
        EXPECT_EQ(int_stack.pop(), 1);
        EXPECT_TRUE(int_stack.empty());
    }

    TEST_F(SimpleStackTest, StringStack)
    {
        string_stack.push("hello");
        string_stack.push("world");

        EXPECT_EQ(string_stack.top(), "world");
        EXPECT_EQ(string_stack.pop(), "world");
        EXPECT_EQ(string_stack.pop(), "hello");
    }

    TEST_F(SimpleStackTest, MoveSemantics)
    {
        std::string str = "movable";
        string_stack.push(std::move(str));
        EXPECT_EQ(string_stack.top(), "movable");
    }

    TEST_F(SimpleStackTest, ExceptionHandling)
    {
        EXPECT_THROW(int_stack.pop(), std::runtime_error);
        EXPECT_THROW(int_stack.top(), std::runtime_error);
    }

    TEST_F(SimpleStackTest, Clear)
    {
        int_stack.push(1);
        int_stack.push(2);
        int_stack.clear();

        EXPECT_TRUE(int_stack.empty());
        EXPECT_EQ(int_stack.size(), 0);
    }

    TEST_F(SimpleStackTest, Capacity)
    {
        size_t initial_capacity = int_stack.capacity();
        int_stack.reserve(100);
        EXPECT_GE(int_stack.capacity(), 100);
        EXPECT_GE(int_stack.capacity(), initial_capacity);
    }

} // namespace cpp_quiz
