#include "userInterface.h"
#include <iostream>


float UserInterface::getValidInputValue(const std::string& valueMessage) {
    int value;
    while (true) {
        std::cout << "\n" << valueMessage;
        std::cin >> value;

        if (std::cin.fail()) {  //if the input is invalid
            std::cin.clear();   //clears the fail flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     //clears the buffert
            std::cout << "\nInvalid Input: Please enter an integer! \n";       
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}
std::string UserInterface::getValidTimestamp(const std::string& timestampMessage) {
    std::string userInput;
    while (true) {
        std::cout << timestampMessage;
        std::getline(std::cin, userInput);

        if (userInput.empty()) {        //checks if the user did write something
            std::cout << "Invaild Input: Must enter something! \n";
        }
        else {
            return userInput;
        }
    }
}
void UserInterface::clearWindow(){
    std::cout << "\x1B[2J \x1B[H";          //clears the window and move cursor back to start
}
void UserInterface::startMenu() const {
    std::cout << ""
        "\n_______MENU_______\n"
        "\n[1] Add new values "
        "\n[2] Display statistics "
        "\n[3] Search"
        "\n[4] Sorting"
        "\n[5] Exit" << std::endl;
}