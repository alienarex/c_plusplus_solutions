#include <iostream>
#include <limits>

using namespace std;

/// Validate the length of the number to its set value
/// Parameter: inputNumber
bool countDigits(int inputNumber) {

    int numberOfDigits = 0;
    int allowedDigits = 5;

    while (inputNumber > 0) {
        inputNumber /= 10;
        numberOfDigits++;
    }

    return numberOfDigits == allowedDigits;
}

int main() {

    int inputNumber, reversedNumber = 0, nextDigit = 0, tempNumber;
    char toContinue;
    bool isOk = true;

    do {// As long as the user chooses 'Y' the program continues.

        /// Loop 1: Ask for input until it's correct
        do {
            cin.clear();
            isOk = true;
            reversedNumber = 0; // reset value for next input

            cout << "Insert a 5 digit number:" << endl;
            cin >> inputNumber;

            // Input control.
            // Source: https://elearn20.miun.se/moodle/pluginfile.php/711615/mod_folder/content/0/Laborationer/Laboration%201.pdf?forcedownload=1
            if (cin.fail()) { // the input couldn't be cast as integer value

                // clear failure state
                cin.clear();
                // discard remaining unprocessed characters in the input stream
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                isOk = false; // Continue the loop to insert a new number

                cout << "No alphabetic characters allowed. Try again with only digits! "
                     << endl; // Error message. Helps user to correct it's input

            } else if (!countDigits(inputNumber)) {

                // clear failure state
                cin.clear();

                isOk = false; // Continue the loop to insert a new number

                cout << "Not correct length. Try again!" << endl; // Error message. Helps user to correct it's input

            } else {

                tempNumber = inputNumber; // uses a temp variable for the calculations and manipulation of the number.
                do {

                    nextDigit = tempNumber % 10; // picks out last digit
                    reversedNumber = reversedNumber * 10 + nextDigit; // build reverted number

                    // Removes the last digit in the number
                    tempNumber = tempNumber / 10;

                } while (tempNumber > 0);

                if (reversedNumber != inputNumber) {

                    cin.clear(); // Clear the input stream.
                    isOk = false; // Continue the loop to insert a new number
                    cout << "The number " << inputNumber << " isn't a palindrome to " << reversedNumber << endl;
                }
            }
        } while (!isOk);

        cout << "The number: " << inputNumber << " is a palindrome!" << endl;

        // Allowed input keys --loop
        do {
            cout << "Run again? (Y/N): " << endl;
            cin >> toContinue;
            toContinue = toupper(toContinue); // make letter upper case.

//            if (toContinue != 'Y' || toContinue != 'N') {//
//                cout << "You can only use the 'Y' and 'N' key to reply "
//                     << endl; // Error messages to help user correct it's input.
//            }

        } while (!(toContinue == 'Y' || toContinue == 'N')); //only 'Y','y','n','N' is allowed

    } while (toContinue == 'Y');

    return 0;
}