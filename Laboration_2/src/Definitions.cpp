#include "Prototypes.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

string mainArgumentParser(int argc, char *argv[]) {
    if (argc < 3)
        return "fail";
    stringstream ss;
    ss << argv[1] << "," << argv[2];
    return ss.str();
}

bool authenticateUser(string value) {
    const string USERNAME = "Kalle";
    const string PASSWORD = "i0J0u0j0u0J0Zys0r0{";

    bool authPassed = false;  // Not in use, but can't remove due to explicit restrictions.
    /**
     * Param: value contains password and username, separated by ','.
     * This function splits the string into two variables at the ',' and return the authentication state.
     */

    string pass, username; // variable for the password and username when splitted

    auto pos = value.find_first_of(
            ",");// Name does't contains "," the first occurence of that is not a part of the password

    // Splits the value string into two individual
    for (int i = 0; i < value.size(); ++i) {

        if (i < pos) {
            username += value[i];
        } else if (i > pos) {
            pass += value[i];
        }
    }
    // Returns as true if password is validated and input username is same as stored USERNAME. (Should I use the authPassed for clarifications?)
    return encryptPassword(pass) == PASSWORD && USERNAME == username;
}

string encryptPassword(string pass) {
    /**
     * Encrypts the password and returns it to authenticateUser(..) for validation.
     */

    const int ROT7 = 7, ROT9 = 9;
    const string VOWELS = "AEIOUYaeiouy";
    string encrypted;
    stringstream ss;

    for (size_t i = 0; i < pass.size(); ++i) {

        const size_t KEY = (i % 2 == 0) ? ROT7 : ROT9; // Sets the decrypt key in runtime

        char thisChar = pass[i], encryptedChar = thisChar + KEY; // Initiates and assign values to chars.

        bool isVowel = VOWELS.find(thisChar) !=
                       string::npos; // Initiates isVowel and assign value 'true' if thisChar exists in string VOWELS.

        isVowel ? ss << 0 << encryptedChar << 0 : ss
                << encryptedChar; // using stringStream to add '0' to modified string if isVowel == true.
    }

//    string check = ss.str();
    return ss.str();
}

string decryptPassword(string pass) {
    const int ROT7 = 7, ROT9 = 9;
    const string VOWELS = "AEIOUYaeiouy";
    string decrypted;
    /**
     * Not implemented
     */

    return decrypted;
}