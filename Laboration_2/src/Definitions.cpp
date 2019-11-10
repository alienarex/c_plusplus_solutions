#include "Prototypes.h"
using std::string;
using std::stringstream;
using std::cout;
using std::endl;

string mainArgumentParser(int argc, char* argv[]) {
    if (argc < 3)
        return "fail";
    stringstream ss;
    ss << argv[1] << "," << argv[2];
    return ss.str();
}

bool authenticateUser(string value) {
    const string USERNAME = "Kalle";
    const string PASSWORD = "i0J0u0j0u0J0Zys0r0{";
    bool authPassed = false;
    /**
     * Add needed code as stated in the lab description
     */

    return authPassed;
}

string decryptPassword(string pass) {
    const int ROT7 = 7, ROT9 = 9;
    const string VOWELS = "AEIOUYaeiouy";
    string decrypted;
    /**
     * Add needed code as stated in the lab description
     */
    return decrypted;

}