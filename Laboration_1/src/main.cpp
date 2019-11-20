#include <iostream>
# include <limits>

using namespace std;

/// Validate the length of the number to its set value
/// Parameter: inputNumber
bool isCorrectLength(int inputNumber) {
    // Source: https://stackoverflow.com/a/22649020

    unsigned int numberOfDigits = 0;
    int allowedDigits = 5;

    // Loops until allowedDigits is 0;
    do {
        numberOfDigits++;
        inputNumber /= allowedDigits;
    } while (inputNumber);

    // The do-while loop loops throught the numberOfDigits one time before evaluation and get increased by one to many
    // If the number_of_digits - 1 are the same as allowedDigits
    return numberOfDigits - 1 == allowedDigits;
}

int main() {

    // std::cout << "Laboration 1!" << std::endl;
    int inputNumber;

    cout << "Insert a 5 digit number" << endl;
    cin >> inputNumber;

    // Input control. Source: https://elearn20.miun.se/moodle/pluginfile.php/711615/mod_folder/content/0/Laborationer/Laboration%201.pdf?forcedownload=1
    if (cin.fail()) { // the input couldn't be cast as integer value

        // clear failure state
        cin.clear();
        // discard remaining unprocessed characters in the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "No alphabetic characters allowed";

    } else if (!isCorrectLength(inputNumber)) {

        cout << "Not correct length.";

    } else {

        // declares after inputcontrol
        int divisor = 1, leadingNumber, trailingNumber;


        /* Identify the divider to be able to split the number into digits by dividing input number with
         * the value of divisior, that increases by multiplying itself in each iteration.
         * Simplified: Creates a "decimal number" and split
         * Source: https://www.geeksforgeeks.org/check-number-palindrome-not-without-using-extra-space/
         */
        while (inputNumber / divisor >= 10) {

            divisor *= 10;
        }
        while (inputNumber != 0) {

            leadingNumber = inputNumber / divisor;
            trailingNumber = inputNumber % 10;

            // If first and last digit not the same output will be
            if (leadingNumber != trailingNumber) {

                cout << "This is not an palindrome" << endl;
                return 0;
            }

            // Removing the controlled digits (leading and trailing) the number
            inputNumber = (inputNumber % divisor) / 10;

            // Reducing divisor by a factor
            // of 2 as 2 digits are dropped
            divisor = divisor / 100;


        }
        cout << "The number: " << inputNumber << "is indeed a palindrome" << endl;

        return 0;

    }
}
