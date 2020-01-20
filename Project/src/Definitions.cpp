#include "Prototypes.h"

//#include "constants.h"

void projectFunction() {
    std::cout << "Project!" << std::endl;
}

std::string convertStringToLowerCase(std::string name) {
    std::string stringLowerCase;

    for (int letter = 0; letter < name.length(); ++letter) {

        stringLowerCase += tolower(name[letter]);
    }
    return stringLowerCase;
}

Person getSignature(Person person, int seqNumber) {

    auto seqNumToString = seqNumber > 9 ? std::to_string(seqNumber) : "0" + std::to_string(seqNumber);
    auto firstNameLength = person.firstname.length();
    auto lastNameLength = person.firstname.length();

    std::string signature = firstNameLength > 3 ?
                            convertStringToLowerCase(person.firstname).substr(0, 3) :
                            convertStringToLowerCase(person.firstname).append(3 - firstNameLength, 'x');

    signature.append(firstNameLength > 3 ?
                     convertStringToLowerCase(person.lastname).substr(0, 3) :
                     convertStringToLowerCase(person.lastname).append(3 - lastNameLength, 'x'));
    signature.append(seqNumToString);
    person.signature = signature;

    return person;
}

double getPersonHeight(double height) {
    std::string temp = std::to_string(height);
    auto pos = temp.find_first_of('.');
    temp = temp.erase(pos + 3);
    return std::stod(temp);
}