#include "src/calculator.h"
#include <cmath>
#include <stdexcept>
#include <limits>

namespace cpp_quiz
{

    double Calculator::add(double a, double b) const
    {
        return a + b;
    }

    double Calculator::subtract(double a, double b) const
    {
        return a - b;
    }

    double Calculator::multiply(double a, double b) const
    {
        return a * b;
    }

    double Calculator::divide(double a, double b) const
    {
        if (std::abs(b) < std::numeric_limits<double>::epsilon())
        {
            throw std::invalid_argument("Division by zero");
        }
        return a / b;
    }

    double Calculator::power(double base, double exponent) const
    {
        return std::pow(base, exponent);
    }

    double Calculator::sqrt(double value) const
    {
        if (value < 0)
        {
            throw std::invalid_argument("Cannot take square root of negative number");
        }
        return std::sqrt(value);
    }

    bool Calculator::is_valid_number(double value) const
    {
        return std::isfinite(value);
    }

    void Calculator::reset_memory()
    {
        memory_ = 0.0;
    }

    void Calculator::store_in_memory(double value)
    {
        if (is_valid_number(value))
        {
            memory_ = value;
        }
    }

    double Calculator::recall_from_memory() const
    {
        return memory_;
    }

} // namespace cpp_quiz
