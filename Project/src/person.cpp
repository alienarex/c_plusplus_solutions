//
// Created by annic on 2020-02-08.
//
#include "Prototypes.h"
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random> // randomize
#include <fstream>
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>
#include "person.h"

std::string convertStringToLowerCase(std::string name) {
    std::string stringLowerCase;

    for (int letter = 0; letter < name.length(); ++letter) {

        stringLowerCase += tolower(name[letter]);
    }
    return stringLowerCase;
}

std::string getSignature(const std::string &firstname, const std::string &lastname) {


    auto firstNameLength = firstname.length();
    auto lastNameLength = lastname.length();

    std::string signature = firstNameLength > 3 ?
                            convertStringToLowerCase(firstname).substr(0, 3) :
                            convertStringToLowerCase(firstname).append(3 - firstNameLength, 'x');

    signature.append(firstNameLength > 3 ?
                     convertStringToLowerCase(lastname).substr(0, 3) :
                     convertStringToLowerCase(lastname).append(3 - lastNameLength, 'x'));


    return signature;
}

std::string getSequentialNumber(int seqNumber) {
    return seqNumber > 9 ? std::to_string(seqNumber) : "0" + std::to_string(seqNumber);
}

std::string getPersonHeight(double height) { // No need? It doesn't matter how the values is stored as long as the output shows with two decimals
    std::string temp = std::to_string(height);
    auto pos = temp.find_first_of('.');
    temp = temp.erase(pos + 3);
    return temp;
}

std::vector<Person> systemDefaultDatabase() {

    std::vector<Person> newDBPersons;
    Person person;
    person.firstname = "Erik";
    person.lastname = "Andersson";
    person.height = 1.5545;
    person.signature = "eriand01";

    newDBPersons.push_back(person);

    Person pers3;
    pers3.firstname = "Mattias";
    pers3.lastname = "Bror";
    pers3.height = 1.20;
    pers3.signature = "matbro01";
    newDBPersons.push_back(pers3);

    Person p;
    p.firstname = "Anna";
    p.lastname = "Persdotter";
    p.height = 2.5545;
    p.signature = "annper01";
    newDBPersons.push_back(p);

    Person pers4;
    pers4.firstname = "Malas";
    pers4.lastname = "Bror";
    pers4.height = 1.20;
    pers4.signature = "malbro02";
    newDBPersons.push_back(pers4);
    return newDBPersons;

}

Person createPerson(const std::string &firstname, const std::string &lastname, double height, const std::vector<Person> &persons) {

    int sameSignature = 0;
    Person p;

    std::string signFirstPart = getSignature(firstname, lastname);

    // Counting signatures identical letters
    for (auto &person : persons) {

        auto getfirstPartOfSignature = person.signature.substr(0, 6);
        if (getfirstPartOfSignature == p.signature) {
            sameSignature++;
        }
    }

    p.firstname = firstname;
    p.lastname = lastname;
    p.height = height;
    p.signature = sameSignature < 1 ? signFirstPart.append(getSequentialNumber()) : signFirstPart.append(getSequentialNumber(sameSignature)); // If signature exist a sequential number appends
    return p;
}

std::vector<Person> sortPersons(std::vector<Person> persons, SortType sortType) {
    using namespace std;
    switch (sortType) {
        case lastname:
            sort(persons.begin(), persons.end(), compareByLastname()); // returns vector sorted by first name if last name is identical
            break;
        case signature:
            sort(persons.begin(), persons.end(), compareBySignature());
            break;
        case height:
            sort(persons.begin(), persons.end(), compareByHeight());
            break;
    }

    return persons;
}

std::vector<Person> randomizeDatabase(std::vector<Person> persons) {

    using namespace std;
    shuffle(begin(persons), end(persons), default_random_engine());
    return persons;
}




