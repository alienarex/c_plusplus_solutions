#include "Prototypes.h"
#include <vector>
#include <iterator>

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

//TODO fix the mindfart!
//  The input value shall be the clear password, decrypt in decryptPassword(..) and then be checked against the encrypted password
bool authenticateUser(string value) {
    const string USERNAME = "Kalle";
    const string PASSWORD = "i0J0u0j0u0J0Zys0r0{";

    bool authPassed = false;
    /**
     * Add needed code as stated in the lab description
     */


    string pass; // variable name is same as param in decryptPassword.

    auto pos = value.find_first_of(
            ",");// Name does't contains "," the first occurence of that is not a part of the password
    int startPassword = pos + 1; // Gets position of the first character in password

    for (int i = startPassword; i < value.size(); ++i) { // Loops through the passwords characters

        pass += value[i];
    }
    decryptPassword(pass);
    return authPassed;
}

string decryptPassword(string pass) {
    const int ROT7 = 7, ROT9 = 9;
    const string VOWELS = "AEIOUYaeiouy";
    string decrypted;
    /**
     * Add needed code as stated in the lab description
     */
//TODO Fix so it also checks after digits . Now it omits them.
    int test = pass.size();
    char vowel;
    for (int i = 0; i < test; ++i) {

        if (i % 2 == 0) {

            for (auto ch :VOWELS) {

                if (pass[i] == ch) {
                    decrypted.append("0");
                    decrypted.append(1, pass[i] + ROT7);
                    decrypted.append("0");
                    break;
                } else {
                    decrypted.append(1, pass[i] + ROT7);
                    break;
                }
            }
        } else {

            for (auto ch :VOWELS) {

                if (pass[i] == ch) {
                    decrypted.append("0");
                    decrypted.append(1, pass[i] + ROT9);
                    decrypted.append("0");
                    break;

                } else {
                    decrypted.append(1, pass[i] + ROT9);
                    break;

                }
            }
        }

    }

    return decrypted;
}