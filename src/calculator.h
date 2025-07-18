#pragma once

namespace cpp_quiz {

/**
 * A simple calculator class for basic arithmetic operations
 */
class Calculator {
public:
    Calculator() = default;
    ~Calculator() = default;

    // Basic arithmetic operations
    double add(double a, double b) const;
    double subtract(double a, double b) const;
    double multiply(double a, double b) const;
    double divide(double a, double b) const;

    // Advanced operations
    double power(double base, double exponent) const;
    double sqrt(double value) const;
    
    // Utility functions
    bool is_valid_number(double value) const;
    void reset_memory();
    
    // Memory operations
    void store_in_memory(double value);
    double recall_from_memory() const;
    
private:
    double memory_ = 0.0;
};

} // namespace cpp_quiz
