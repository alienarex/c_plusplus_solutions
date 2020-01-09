#include "Prototypes.h"

bool inputValidation(int userInput);

int main() {
    int test = subMenu();
    return 0;
}

void mainMenu() {

    do {
        int userInput = 0;
        bool exit = false;

        std::cout << "FIBONACCI SEQUENCE MEASUREMENTS" << "\n" << "===============================" << std::endl;
        std::cout << "1. Run measurements" << "\n" << "2. EXIT" << std::endl;
        std::cin >> userInput;

        if (inputValidation(userInput)) {

            while (userInput == 1) {
                std::cout << "Works!";
                fibonacciTimer(30);

            }
            if (userInput == 2) { exit = true; }
        }
    } while (!exit);
}

size_t subMenu() {
    using namespace std;
    int userInput;
    do {

        cout << "Select n'th number to find:" << "\n";
        cin >> userInput;

    } while (!inputValidation(userInput));

    return userInput;
}

bool inputValidation(int userInput) {

    using namespace std;

    if (cin.fail()) { // the input couldn't be cast as integer value

        // clear failure state
        cin.clear();

        // discard remaining unprocessed characters in the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Use only numeric values" << "\n" << endl; // Error message. Helps user to correct it's input

        return false;


    } else if (userInput < 1 || userInput > 2) {
        cout << "You can only use the given options" << "\n" << endl; // Error message. Helps user to correct it's input

        return false;

    }
    return true;
}
