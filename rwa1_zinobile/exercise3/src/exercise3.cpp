#include <iostream>
#include <string>
#include <cctype>

int main()
{
    // Initialize string of vowels
    std::string vowels = "aeiouAEIOU";


    //Collect user input as string
    std::string input_string{};
    std::cout << "========================\n";
    std::cout << "Enter character: ";

    //Reject input if more than 1 character
    while (true)
    {
        std::cin >> input_string;
        if (input_string.size() == 1)
        {
            break;
        }
        else
        {
            std::cout << "Please only enter 1 character: ";
        }
    }
    std::cout << "========================\n";
    //Convert string to character
    char input_char = input_string[0];

    // Determine if character is alphanumeric
    if (isalnum(input_char))
    {
        // Determine if character is a digit
        if (isdigit(input_char))
        {
            std::cout << input_char << " is a digit.\n";
        }
        else
        {
            // Determine if character is within vowel string
            if (vowels.find(input_char) != std::string::npos)
            {
                std::cout << input_char << " is a vowel.\n";

                // Change case of vowel input
                if (isupper(input_char))
                {
                    input_char = tolower(input_char);
                    std::cout << "Lowercase version: " << input_char << "\n";
                }
                else
                {
                    input_char = toupper(input_char);
                    std::cout << "Uppercase version: " << input_char << "\n";
                }
            }
            else
            {
                // Character alphanumeric but not a digit or vowel
                // Character must be a consonant
                std::cout << input_char << " is a consonant.\n";

                // Change case of consonant input
                if (isupper(input_char))
                {
                    input_char = tolower(input_char);
                    std::cout << "Lowercase version: " << input_char << "\n";
                }
                else
                {
                    input_char = toupper(input_char);
                    std::cout << "Uppercase version: " << input_char << "\n";
                }
            }
        }
    }

    else
    {
        // Character not alphanumeric
        // Character must be a special symbol
        std::cout << input_char << " is a special symbol.\n";
    }
    std::cout << "========================\n";
    return 0;
}