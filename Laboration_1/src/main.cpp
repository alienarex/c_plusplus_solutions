#include <iostream>
# include <limits>

using namespace std;

/// Validate the length of the number to its set value
/// Parameter: inputNumber
bool isCorrectLength(int inputNumber) {
    // Source: https://stackoverflow.com/a/22649020

    int numberOfDigits = 0;
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
    int reversedNumber = 0, tempNumber;
    char toContinue;
    bool isOk = true;
    do {

        /// Loop 1: Ask for input until it's correct
        do {
            cout << "Insert a 5 digit number" << endl;
            cin >> inputNumber;

            // Input control.
            // Source: https://elearn20.miun.se/moodle/pluginfile.php/711615/mod_folder/content/0/Laborationer/Laboration%201.pdf?forcedownload=1
            if (cin.fail()) { // the input couldn't be cast as integer value

                // clear failure state
                cin.clear();
                // discard remaining unprocessed characters in the input stream
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                isOk = false;
                cout << "No alphabetic characters allowed. Try again with only digits! " << endl;
            } else if (!isCorrectLength(inputNumber)) {
                isOk = false;

                cout << "Not correct length. Try again!" << endl;
            }
            // declares after inputcontrol
            int divisor = 1, leadingNumber = 0, trailingNumber = 0;


            /* Identify the divider to be able to split the number into digits by dividing input number with
             * the value of divisior, that increases by multiplying itself in each iteration.
             * Simplified: Creates a "decimal number" and split
             * Source: https://www.geeksforgeeks.org/check-number-palindrome-not-without-using-extra-space/
             */
            while (inputNumber / divisor >= 10) {

                divisor *= 10;
            }

            tempNumber = inputNumber;
            do {
//
//                leadingNumber = tempNumber / divisor; // picks out first digit
                trailingNumber = tempNumber % 10; // picks out last digit
                reversedNumber = reversedNumber * 10 + trailingNumber; // build reverted number

                // Removing the controlled digits (leading and trailing) the number
//                tempNumber = (tempNumber % divisor) / 10;

                // Reducing divisor by a factor
                // of 2 as 2 digits are dropped
                divisor = divisor / 100;
                tempNumber = tempNumber / 10;

            } while (tempNumber > 0);

        } while (!isOk);

        cout << "Run again? (Y/N): " << endl;
        // Allowed input keys --loop
        do {
            cin >> toContinue;
            toContinue = toupper(toContinue); // make all letter same case.
        } while (!(toContinue == 'Y' || toContinue == 'N')); //only 'Y','y','n','N' is allowed


    } while (toContinue = 'Y');



//
//
//        }
//        cout << "The number: " << inputNumber << "is indeed a palindrome" << endl;

    return 0;

}