#include <iostream>

int main()
{
    // Initialize intergers
    int int_1{};
    int int_2{};

    // Get user inputs for intergers
    std::cout << "===========================================\n";
    std::cout << "Enter interger 1: ";
    std::cin >> int_1;
    std::cout << "Enter interger 2: ";
    std::cin >> int_2;
    std::cout << "===========================================\n";
    // Output results of addition, subtraction, and multiplication operations
    std::cout << "Addition: " << int_1 << " + " << int_2 << " = " << int_1 + int_2 << "\n";
    std::cout << "Subtraction: " << int_1 << " - " << int_2 << " = " << int_1 - int_2 << "\n";
    std::cout << "Multiplication: " << int_1 << " * " << int_2 << " = " << int_1 * int_2 << "\n";

    // Handle divide by zero error and output division and modulus results
    if (int_2 == 0)
    {
        std::cout << "Division: N/A, cannot divide by zero\n";
        std::cout << "Modulus: N/A, cannot divide by zero\n";
    }
    else
    {
        std::cout << "Division: " << int_1 << " / " << int_2 << " = " << int_1 / int_2 << "\n";
        std::cout << "Modulus: " << int_1 % int_2 << "\n";
    }
    std::cout << "===========================================\n";
    return 0;
}