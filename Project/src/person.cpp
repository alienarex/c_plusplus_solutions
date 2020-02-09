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


std::string convertStringToLowerCase(std::string name) { // TODO control if needed in prototype.h
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

    Person pers3;
    pers3.firstname = "Mattias";
    pers3.lastname = "Bror";
    pers3.height = 1.20;
    pers3.signature = "mabr03";
    newDBPersons.push_back(pers3);

    Person p;
    p.firstname = "Anna";
    p.lastname = "Persdotter";
    p.height = 2.5545;
    p.signature = "annper02";
    newDBPersons.push_back(p);

    Person pers4;
    pers4.firstname = "Malas";
    pers4.lastname = "Bror";
    pers4.height = 1.20;
    pers4.signature = "mabr03";
    newDBPersons.push_back(pers4);
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

std::vector<Person> sortPersons(std::vector<Person> persons, SortType sortType) {
    using namespace std;
    switch (sortType) {
        case lastname:
            sort(persons.begin(), persons.end(), compareByLastname());
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

std::vector<Person> randomizeDatabase(std::vector<Person> &persons) {

    using namespace std;
    shuffle(begin(persons), end(persons), default_random_engine());

    return persons;
}


void writeToFile(std::vector<Person> &persons) {
// Ref: Erik Ström Lecture Miun 2020
    using namespace std;
    string fileName = "database";
    ofstream outputFile("../../_Resources/" + fileName + ".txt");

    size_t idx = persons.size();
    for (auto &person : persons)

        outputFile << --idx << ": " << person.firstname << DELIM << person.lastname << DELIM << person.signature << DELIM << person.height << endl;

    outputFile.close();

}

std::vector<Person> readFromFile() {

    using namespace std;
    std::vector<Person> persons;
    string fileName = "database";
    string line;
    ifstream infile("../../_Resources/" + fileName + ".txt");
    Person person;

    while (getline(infile, line)) {
        size_t omitIndex = line.find_first_of(' ');
        line = line.substr(omitIndex);
        size_t charNumber1 = line.find(DELIM);
        person.firstname = line.substr(0, charNumber1);
        size_t charNumber2 = line.find(DELIM, charNumber1 + 1);
        person.lastname = line.substr(charNumber1 + 1, charNumber2 - (charNumber1 + 1));
        size_t charNumber3 = line.find(DELIM, charNumber2 + 1);
        person.signature = line.substr(charNumber2 + 1, charNumber3 - (charNumber2 + 1));
        size_t charNumber4 = line.find(DELIM, charNumber3 + 1);
        person.height = stof(line.substr(charNumber3 + 1, charNumber4 - (charNumber3 + 1)));
        persons.push_back(person);
    }
    return persons;
}