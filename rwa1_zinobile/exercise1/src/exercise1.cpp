#include <iostream>

int main()
{
    //Initialize variables
    int int_var{250};
    float float_var{987.654};
    double double_var{543.210987};

    //Print variables
    std::cout << "=======================================\n";
    std::cout << "Initial value for int_var is " << int_var << "\n";
    std::cout << "Initial value for float_var is " << float_var << "\n";
    std::cout << "Initial value for double_var is " << double_var << "\n";
    std::cout << "=======================================\n";

    //Modify variables
    int_var = int_var - 20;
    float_var = float_var * 1.5;
    double_var = double_var / 3;

    //Print new variable values
    std::cout << "New value for int_var is " << int_var << "\n";
    std::cout << "New value for float_var is " << float_var << "\n";
    std::cout << "New value for double_var is " << double_var << "\n";
    std::cout << "=======================================\n";
    return 0;
}