#include "Prototypes.h"

//TODO move function heads to Prototypes.h
bool inputValidation();

bool inputValidationMainMenu(int input);

bool inputValidationSubMenu(int userInput);


int main() {
//    int test = subMenu();
    mainMenu();
    return 0;
}

void mainMenu() {
// TODO Add code as required in submission description
    do {
        int userMenuChoice = 0;
        bool exit = false;

        std::cout << "FIBONACCI SEQUENCE MEASUREMENTS" << "\n" << "===============================" << std::endl;
        std::cout << "1. Run measurements" << "\n" << "2. EXIT" << std::endl;
        std::cin >> userMenuChoice;

        if (inputValidationMainMenu(userMenuChoice)) {

            while (userMenuChoice == 1) {

                size_t userInput = subMenu();

                fibonacciTimer(userInput);
                // TODO add CALL printStats() and writeToFile()
            }
            if (userMenuChoice == 2) { exit = true; }
        }
    } while (!exit);
}

size_t subMenu() {
    using namespace std;
    int userInput;
    do {

        cout << "Select n'th number to find:" << "\n";
        cin >> userInput;


    } while (!inputValidationSubMenu(userInput));

    return userInput;
}

bool inputValidationSubMenu(int userInput) {

    if (inputValidation()) return true;
    else {
        std::cout << "Try again with a lower value" << std::endl;
        return false;
    }
}

bool inputValidationMainMenu(int userInput) {
    if (inputValidation() && (userInput > 0 && userInput < 3)) return true;
    else {
        std::cout << "You can only use the given options" << "\n" << std::endl; // Error message. Helps user to correct it's input
        return false;
    }

}

bool inputValidation() {
// WORKS
    using namespace std;

    if (cin.fail()) { // the input couldn't be cast as integer value

        // clear failure state
        cin.clear();

        // discard remaining unprocessed characters in the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Use only numeric values with a maximum of 2 147 483 647" << endl; // Error message. Helps user to correct it's input

        return false;


    } else return true;
}
