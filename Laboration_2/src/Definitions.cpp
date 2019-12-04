#include "Prototypes.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using namespace std;

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

    bool authPassed = false;
    /**
     * Add needed code as stated in the lab description
     */
    string tempPass, tempUser;

    auto pos = value.find("'");
    auto findSeperation = value.find(",");
    int counter = 0;
    for (int i = 0; i < value.length(); ++i) {


        if (value[i] == '\'')//Hittar ' tecknet i stringen. Är det vad man ska göra? Tänker att man hittar infon mellan '' och kan extrahera username och password.
            counter = i;
    }
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