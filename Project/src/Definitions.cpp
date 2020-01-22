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

std::string getSignature(const std::string &firstname, const std::string &lastname, int seqNumber) {

    auto seqNumToString = seqNumber > 9 ? std::to_string(seqNumber) : "0" + std::to_string(seqNumber);
    auto firstNameLength = firstname.length();
    auto lastNameLength = firstname.length();

    std::string signature = firstNameLength > 3 ?
                            convertStringToLowerCase(firstname).substr(0, 3) :
                            convertStringToLowerCase(firstname).append(3 - firstNameLength, 'x');

    signature.append(firstNameLength > 3 ?
                     convertStringToLowerCase(lastname).substr(0, 3) :
                     convertStringToLowerCase(lastname).append(3 - lastNameLength, 'x'));
    signature.append(seqNumToString);

    return signature;
}

std::string getPersonHeight(double height) { // No need? It doesn't matter how the values is stored as long as the output shows with two decimals
    std::string temp = std::to_string(height);
    auto pos = temp.find_first_of('.');
    temp = temp.erase(pos + 3);
    return temp;
}

std::vector<Person> getPersonsFromDatabase() { // TODO remove all code addding person to vector
    std::vector<Person> newDBPersons = databasePersons;
    Person person;
    person.firstname = "Erik";
    person.lastname = "Andersson";
    person.height = 1.5545;
    person.signature = "eriand01";

    newDBPersons.push_back(person);
    return newDBPersons;

}

void createPerson(const std::string &firstname, const std::string &lastname, double height) {

    std::vector<Person> newDBPersons = getPersonsFromDatabase();
    int nrOfPersons = newDBPersons.size();
    Person p;

    p.firstname = firstname;
    p.lastname = lastname;
    p.height = height;
    p.signature = getSignature(firstname, lastname, nrOfPersons);
    newDBPersons.push_back(p);
}
