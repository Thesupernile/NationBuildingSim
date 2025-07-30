#include <string>
#include <iostream>

namespace utilities{
    int getIntInput(std::string messageToDisplay, int min = INT_MIN, int max = INT_MAX){
        std::string userInput {};
        bool validInput { false };
        int intInput {};

        while (!validInput){
            std::cout << messageToDisplay;
            std::cin >> userInput;
            validInput = true;

            for (char character : userInput){
                if (character < 48 || character > 57){
                    validInput = false;
                }
            }

            if (!validInput){
                std::cout << "Invalid input. Please enter an integer number (eg. 1, 2)\n";
            }
            else{
                intInput = stoi(userInput);
                if (intInput < min || intInput > max){
                    validInput = false;
                    std::cout << "Invalid input. Please enter a number in the range " << min << ", " << max << "\n";
                }
            }
        }

        return intInput;
    }

    std::string stringToLower(std::string inputString){
        for (char &character : inputString){
            character = tolower(character);
        }

        return inputString;
    }
}
