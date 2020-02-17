#include "Prototypes.h"
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>

long_type fibonacciIteration(size_t nthNumber) {
    size_t x = 0, y = 1, z = 0;
    // iterates through the value and moves the values around as visualized in the comments beneath
    for (size_t i = 0; i < nthNumber; i++) {
        z = x + y; // assign value to z iteration EXAMPLE: 1. 10 = 5 + 5; iteration 2. 15 = 5 + 10;
        x = y; // The value y is assign to x. These values are then summed to z. EXAMPLE: iteration 1.  5 = 5; iteration 2. 10 = 10;
        y = z; // EXAMPLE: iteration 1. 10 = 10; iteration 2. 15 = 15;
    }

    return x;// Would return 10 if above EXAMPLE: is followed.
}

Stats setStatsTiming(Stats stat, std::chrono::high_resolution_clock::time_point startTime) {

    std::chrono::high_resolution_clock::time_point endTime;

    using fpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
    using millisec=  std::chrono::duration<float, std::chrono::milliseconds::period>;
    using microsec=  std::chrono::duration<float, std::chrono::microseconds::period>;
    using nanosec=  std::chrono::duration<float, std::chrono::nanoseconds::period>;

    endTime = std::chrono::high_resolution_clock::now();
    stat.millisec = millisec(endTime - startTime).count();
    stat.nanosec = nanosec(endTime - startTime).count();
    stat.microsec = microsec(endTime - startTime).count();
    stat.sec = fpSeconds(endTime - startTime).count();
    stat.millisec = millisec(endTime - startTime).count();

    return stat;
}

void outPutFibonacciValues(std::vector<Stats> stats);

std::vector<Stats> fibonacciTimer(size_t nthNumber) {
//TODO Remove redundancy based on given feedback
    std::vector<Stats> stats;

    std::chrono::high_resolution_clock::time_point startTime;


    for (int i = 0; i < 2; ++i) {
        Stats stat;
        int sequence = 0;
        startTime = std::chrono::high_resolution_clock::now();

        int justify = 0;
        switch (i) {

            case 0: // iterationtypen
                stat.type = "Iteration";
                for (size_t j = nthNumber, counter = 0; j <= nthNumber; --j, counter++) {


                    size_t returnValueFibonacciIteration = fibonacciIteration(j);
                    stat.values.push_back(returnValueFibonacciIteration);
                    //TODO FIX setw()!!

                    if (counter % 5 == 0) {
                        if (std::to_string(stat.values[counter]).size() > justify) {
                            justify = std::to_string(stat.values[counter]).size();
                        }
//                        else if (std::to_string(stat.values[counter]).size() != std::to_string(stat.values[counter - 5]).size()) {
//                            justify += std::to_string(stat.values[counter]).size();
//                        }
                        std::cout << stat.type << std::setw(3) << j << "th " << std::setw(justify) << stat.values[counter] << std::endl;

                    }

                }
                stat = setStatsTiming(stat, startTime);

                break;

            case 1: // reqursion

                stat.type = "Reqursion";

                for (size_t j = nthNumber, counter = 0; j <= nthNumber; --j, counter++) {


                    size_t returnValueFibonacciRecursion = fibonacciRecursion(j);
                    stat.values.push_back(returnValueFibonacciRecursion);

                    if (counter % 5 == 0) {

                        if (std::to_string(stat.values[counter]).size() > justify) {
                            justify = std::to_string(stat.values[counter]).size();
                        }
                        std::cout << stat.type << std::setw(3) << j << "th " << std::setw(justify) << stat.values[counter] << std::endl;
                    }

                }
                stat = setStatsTiming(stat, startTime);

                break;

            default:
                break;
        }
        stats.push_back(stat);// Initialized in the switch
    }
    return stats;
}

/* Recursion == calls itself (drilled down) until the number is 1 or 0. The values are then "pushed" and added through the function calls adding either 0 or 1   */
long_type fibonacciRecursion(size_t nthNumber) { // if nthNumber == 10.
    if (nthNumber <= 1)
        return nthNumber;
    // the function calls it self to return value1 and value2.
    return fibonacciRecursion(nthNumber - 1)
           + fibonacciRecursion(nthNumber - 2);
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
    //TODO .Add this to menu. If nthNumber is 30 this range would be 30 .. 0, with a header looking like:
    // Duration of running Fibonacci sequences within the range of 30..0.
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
// Ref: Erik Ström Lecture Miun 2020
    using namespace std;
    string path;
    ofstream outputFile("../../_Resources/" + stats.type + ".txt");

    size_t idx = stats.values.size();
    for (auto &value : stats.values)
        outputFile << --idx << ": " << value << endl;
    outputFile.close();

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