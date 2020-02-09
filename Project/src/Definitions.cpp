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

void projectFunction() {
    std::cout << "Project!" << std::endl;
}


void mainMenu() {
    using namespace std;
    size_t menuChoice;
    MainMenu input;
    cout << "====================== Main menu ======================" << endl;

    cout << "1. Add " << DELIM << " 2. Delete " << DELIM << " 3. Find record " << DELIM << " 3. Get list " << DELIM << " 4. Sort list " << DELIM << " 5. Randomize list" << endl;
    cin >> menuChoice;
    input = static_cast<MainMenu>(menuChoice);

    switch (input) {
        case addRec:
            addPerson();
            break;
        case deleteRec:
            deletePerson();
            break;
        case findRec:
            findPerson();
            break;
        case getList:
            getPersons();
            break;
//        case sortList:
//            sortPersonsBy
    }


}

std::vector<Person> findPerson() {
    using namespace std;
    std::vector<Person> persons = getPersonsFromDatabase();
    string signature = getSignatureForPerson();

    bool found;

    auto itEnd = persons.end();

    for (auto it = persons.begin(); it != persons.end(); ++it) {

        if (it->signature == signature) {
            cout << it->signature << setw(20) << it->firstname << " " << it->lastname << endl;
            it--;
            found = true;
        }
    }
    if (!found) {
        cout << "No person with the signature " << signature << " was found" << endl;
    }

    return persons;
}

std::vector<Person> deletePerson() {
    using namespace std;
    std::vector<Person> persons = getPersonsFromDatabase();
    string signature = getSignatureForPerson();
    bool deleted = false;

    auto itEnd = persons.end();

    for (auto it = persons.begin(); it != persons.end(); ++it) {

        if (it->signature == signature) {
            cout << it->signature << setw(20) << it->firstname << " " << it->lastname << endl;
            persons.erase(it);
            it--;
            deleted = true;
        }
    }
    if (!deleted) {
        cout << "No person with the signature " << signature << " was found" << endl;
    }

    return persons;
}

void getPersons() {
    using namespace std;
    std::vector<Person> persons = getPersonsFromDatabase();
    int size = persons.size();


    cout << "====================== NAME LIST ======================" << endl;
    cout << "Number of databasePersons in list: " << size << "\n" << endl;
    cout << internal << "Nr" << setw(20) << "Sign" << setw(20) << "Name" << setw(50) << "Length (m)" << endl;

    for (int i = 0, sequence = 1; i < persons.size(); i++, sequence++) {
        std::string heightString = getPersonHeight(persons[i].height);


        cout << internal << sequence << "." << setw(20) << persons[i].signature << setw(20) << persons[i].firstname << " " << persons[i].lastname
             << setw(50) << heightString << endl;
    }
}

std::string getSignatureForPerson() {
    using namespace std;
    string signature;
    cout << "Write Signature for the person you search: " << endl;
    cin >> signature;
    return signature;

}


void addPerson() {
    using namespace std;
    string firstname, lastname;
    double height;
    cout << "insert your first name and press enter" << "\n" << "first name: " << endl;
    cin >> firstname;
    cout << "Last name; " << endl;
    cin >> lastname;
    cout << "Enter your height " << endl;
    cin >> height;

    createPerson(firstname, lastname, height);

}

void sortPersonsBy() {
    using namespace std;
    SortType s;
    int menuChoice = 0;
    std::vector<Person> persons = getPersonsFromDatabase();

    cout << "Sort list by: " << "\n" << "1. Last name" << "\t" << "2. Signature" << "\t" << "3. Height" << endl;
    cin >> menuChoice;
    s = static_cast<SortType>(menuChoice);
    persons = sortPersons(std::move(persons), s);


}