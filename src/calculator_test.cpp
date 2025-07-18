#include "src/calculator.h"
#include <gtest/gtest.h>
#include <stdexcept>

namespace cpp_quiz
{

    class CalculatorTest : public ::testing::Test
    {
    protected:
        Calculator calc;
    };

    TEST_F(CalculatorTest, BasicArithmetic)
    {
        EXPECT_DOUBLE_EQ(calc.add(2.0, 3.0), 5.0);
        EXPECT_DOUBLE_EQ(calc.subtract(5.0, 3.0), 2.0);
        EXPECT_DOUBLE_EQ(calc.multiply(4.0, 3.0), 12.0);
        EXPECT_DOUBLE_EQ(calc.divide(10.0, 2.0), 5.0);
    }

    TEST_F(CalculatorTest, DivisionByZero)
    {
        EXPECT_THROW(calc.divide(5.0, 0.0), std::invalid_argument);
    }

    TEST_F(CalculatorTest, PowerFunction)
    {
        EXPECT_DOUBLE_EQ(calc.power(2.0, 3.0), 8.0);
        EXPECT_DOUBLE_EQ(calc.power(5.0, 0.0), 1.0);
        EXPECT_DOUBLE_EQ(calc.power(9.0, 0.5), 3.0);
    }

    TEST_F(CalculatorTest, SquareRoot)
    {
        EXPECT_DOUBLE_EQ(calc.sqrt(9.0), 3.0);
        EXPECT_DOUBLE_EQ(calc.sqrt(16.0), 4.0);
        EXPECT_THROW(calc.sqrt(-1.0), std::invalid_argument);
    }

    TEST_F(CalculatorTest, MemoryOperations)
    {
        calc.store_in_memory(42.0);
        EXPECT_DOUBLE_EQ(calc.recall_from_memory(), 42.0);

        calc.reset_memory();
        EXPECT_DOUBLE_EQ(calc.recall_from_memory(), 0.0);
    }

    TEST_F(CalculatorTest, ValidNumberCheck)
    {
        EXPECT_TRUE(calc.is_valid_number(42.0));
        EXPECT_TRUE(calc.is_valid_number(-3.14));
        EXPECT_TRUE(calc.is_valid_number(0.0));
    }

} // namespace cpp_quiz
