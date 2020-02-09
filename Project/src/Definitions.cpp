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
    do {

        cout << "====================== Main menu ======================" << endl;

        cout << "1. Add " << DELIM << " 2. Delete " << DELIM << " 3. Find record " << DELIM << " 4. Get all " << DELIM << " 5. Sort database " << DELIM << " 6. Randomize database " << DELIM << " 7. Save records " <<
             DELIM << " 8. Load database " << endl;
        cin >> menuChoice;
        input = static_cast<MainMenu>(menuChoice);

        switch (input) {
            case addRecord:
                addPerson();
                break;
            case deleteRecord:
                deletePerson();
                break;
            case findRecord:
                findPerson();
                break;
            case getRecords:
                getPersons();
                break;
            case sortRecords:
                sortPersonsBy();
                break;
//        case randomizeRecords:
//            randomizeDatabase(getPersons());

        }
    } while (!system("pause"));


}

std::vector<Person> findPerson() {
    using namespace std;
    std::vector<Person> persons = getPersonsFromDatabase();
    string signature = getSignatureForPerson();

    bool found;

    auto itEnd = persons.end();

    for (auto pers:persons) {

        if (pers.signature == signature) {
            getPersons(pers);
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

    int size = databasePersons.size();


    cout << "====================== NAME LIST ======================" << endl;
    cout << "Number of databasePersons in list: " << size << "\n" << endl;
    cout << internal
         << left << setw(5)
         << "Nr"
         << left << setw(15)
         << left << "Sign"
         << left << setw(20)
         << "Name"
         << right << setw(20)
         << right << "Length (m)" << endl;

    for (int i = 0, sequence = 1; i < databasePersons.size(); i++, sequence++) {
        std::string heightString = getPersonHeight(databasePersons[i].height);
        std::string tempName = databasePersons[i].firstname + " " + databasePersons[i].lastname;

//        cout << internal << sequence << "." << setw(15) << right << databasePersons[i].signature << right << setw(20) << right << databasePersons[i].firstname << left << " " << right << databasePersons[i].lastname
////             << right << setw(30) << right << heightString << endl;

        cout << internal
             << left << setw(5)
             << left << sequence
             << left << setw(5)
             << left << setw(15)
             << left << databasePersons[i].signature
             << left << setw(20)
             << left << tempName
             << right << setw(20)
             << heightString << endl;
    }
}

void getPersons(std::vector<Person> persons) {
    using namespace std;

    int size = persons.size();


    cout << "====================== NAME LIST ======================" << endl;
    cout << "Number of databasePersons in list: " << size << "\n" << endl;
    cout << internal
         << left << setw(5)
         << "Nr"
         << left << setw(15)
         << left << "Sign"
         << left << setw(20)
         << "Name"
         << right << setw(20)
         << right << "Length (m)" << endl;

    for (int i = 0, sequence = 1; i < persons.size(); i++, sequence++) {
        std::string heightString = getPersonHeight(persons[i].height);
        std::string tempName = persons[i].firstname + " " + persons[i].lastname;

//        cout << internal << sequence << "." << setw(15) << right << databasePersons[i].signature << right << setw(20) << right << databasePersons[i].firstname << left << " " << right << databasePersons[i].lastname
////             << right << setw(30) << right << heightString << endl;

        cout << internal
             << left << setw(5)
             << left << sequence
             << left << setw(5)
             << left << setw(15)
             << left << persons[i].signature
             << left << setw(20)
             << left << tempName
             << right << setw(20)
             << heightString << endl;
    }
}

void getPersons(Person person) {
    using namespace std;

    cout << "====================== NAME LIST ======================" << endl;
    cout << "Number of databasePersons in list: " << "1" << "\n" << endl;
    cout << internal
         << left << setw(5)
         << "Nr"
         << left << setw(15)
         << left << "Sign"
         << left << setw(20)
         << "Name"
         << right << setw(20)
         << right << "Length (m)" << endl;

    std::string heightString = getPersonHeight(person.height);
    std::string tempName = person.firstname + " " + person.lastname;

//        cout << internal << sequence << "." << setw(15) << right << databasePersons[i].signature << right << setw(20) << right << databasePersons[i].firstname << left << " " << right << databasePersons[i].lastname
////             << right << setw(30) << right << heightString << endl;

    cout << internal
         << left << setw(5)
         << left << "1"
         << left << setw(5)
         << left << setw(15)
         << left << person.signature
         << left << setw(20)
         << left << tempName
         << right << setw(20)
         << heightString << endl;
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
    std::vector<Person> persons = getPersonsFromDatabase();

    SortType s;
    int menuChoice = 0;
    cout << "Sort list by: " << "\n" << "1. Last name" << "\t" << "2. Signature" << "\t" << "3. Height" << endl;
    cin >> menuChoice;
    s = static_cast<SortType>(menuChoice);
    persons = sortPersons(std::move(persons), s);
    getPersons(persons);


}