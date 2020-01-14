#include "Prototypes.h"


int main() {
    mainMenu();
//    return 0;
}

void mainMenu() {

    int userMenuChoice = 0;
    bool exit = false;

    do {
        std::cout << "FIBONACCI SEQUENCE MEASUREMENTS" << "\n" << "===============================" << std::endl;
        std::cout << "1. Run measurements" << "\n" << "2. EXIT" << std::endl;
        do {
            std::cin >> userMenuChoice;

        } while (!inputValidationMainMenu(userMenuChoice));
        if (userMenuChoice == 2) { break; }

        size_t userInput = subMenu();

        std::vector<Stats> stats = fibonacciTimer(userInput);
        printStats(stats);

        for (Stats stat:stats) {
            writeToFile(stat);
        }

    } while (!system("pause")); //"press any key" for Windows);
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


void printStats(const std::vector<Stats> &stats) {
    using namespace std;
    cout << internal << setw(30) << "Nanosec" << setw(20) << "Microsec" << setw(20) << "Millisec" << setw(20) << "Seconds" << "\n" <<
         "================================================================================================" << endl;
    for (Stats stat:stats) {
        string seconds = to_string(stat.sec);
        size_t found = seconds.find_last_not_of('0');
        seconds.erase(found + 1);
        cout << internal << stat.type << ":" << setw(20) << stat.nanosec << setw(20) << stat.microsec << setw(20) << stat.millisec << setw(20) << seconds << endl;

    }

}

void writeToFile(const Stats &stats) {
    using namespace std;
    string path;

    if (stats.type == "Reqursion") {
        path = "../../_Resources/Reqursion.txt";
    } else if (stats.type == "Iteration") {
        path = "../../_Resources/Iteration.txt";
    }
    ofstream outputFile(path);

    for (int i = 0, j = stats.values.size(); i < stats.values.size(); i++, --j) {

        int reversedValue = stats.values[i];
        outputFile << left << j - 1 << ":" << " " << reversedValue << endl;
    }
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
