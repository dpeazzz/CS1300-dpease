/*
Calculator 
Author: Dawson Pease
Date: 10/5/2024
*/

#include <iostream>
#include <cmath>
#include <limits>

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

template <typename T>
T divide(T a, T b) {
    if (b == 0) {
        std::cerr << "Error!" << std::endl;
        return std::numeric_limits<T>::quiet_NaN();
    }
    return a / b;
}

template <typename T>
T subtract(T a, T b) {
    return a - b;
}

int modulus(int a, int b) {
    if (b == 0) {
        std::cerr << "Error" << std::endl;
        return 0;
    }
    return a % b;
}

template <typename T>
T power(T a, T b) {
    return std::pow(a, b);
}

template <typename T>
T square_root(T a) {
    if (a < 0) {
        std::cerr << "Error: Square root of negative number!" << std::endl;
        return std::numeric_limits<T>::quiet_NaN();
    }
    return std::sqrt(a);
}

int main() {
    double num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Addition: " << add(num1, num2) << std::endl;
    std::cout << "Multiplication: " << multiply(num1, num2) << std::endl;
    std::cout << "Division: " << divide(num1, num2) << std::endl;
    std::cout << "Subtraction: " << subtract(num1, num2) << std::endl;
    std::cout << "Modulus (only for integers): " << modulus(static_cast<int>(num1), static_cast<int>(num2)) << std::endl;
    std::cout << "Power: " << power(num1, num2) << std::endl;
    std::cout << "Square root of first number: " << square_root(num1) << std::endl;

    return 0; 
}
