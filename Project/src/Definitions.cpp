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

void mainMenu() {
    using namespace std;
    size_t menuChoice;
    MainMenu input;
    vector<Person> persons;
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
                persons = printPersons(deletePerson(persons));
                break;
            case findRecord:
                findPerson();
                break;
            case getRecords:
                persons = printPersons(persons);
                break;
            case sortRecords:
                persons = printPersons(sortPersonsBy(persons));
                break;
            case randomizeRecords:
                persons = printPersons(randomizeDatabase(persons));
                break;
            case saveRecords:
                writeToFile(persons);
                break;
            case loadRecords:
                persons = printPersons(readFromFile());

        }
    } while (!system("pause"));


}

std::vector<Person> findPerson() {
    using namespace std;
    std::vector<Person> persons = systemDefaultDatabase();
    string signature = getSignatureForPerson();

    bool found;

    auto itEnd = persons.end();

    for (const auto &pers:persons) {

        if (pers.signature == signature) {
            printPersons(pers);
            found = true;
        }
    }
    if (!found) {
        cout << "No person with the signature " << signature << " was found" << endl;
    }

    return persons;
}

std::vector<Person> deletePerson(std::vector<Person> persons) {
    using namespace std;
    string signature = getSignatureForPerson();
    bool deleted = false;
    char choice;

    auto itEnd = persons.end();

    for (auto it = persons.begin(); it != persons.end(); ++it) {

        if (it->signature == signature) {

            do {
                cout << "Delete person (Y/N)? ";
                cin >> choice;
                choice = tolower(choice);
                cout << it->signature << setw(20) << it->firstname << " " << it->lastname << endl;
                if (choice == 'y') {
                    persons.erase(it);
                    deleted = true;

                }
            } while (choice != 'Y' and choice != 'y' and choice != 'N' and choice != 'n');
            it--;
        }
    }
    if (!deleted) {
        cout << "No person with the signature " << signature << " was found" << endl;
    }

    return persons;
}

std::vector<Person> printPersons(std::vector<Person> persons) {
    using namespace std;
    if (persons.capacity() < 1) {


        int choose = 0;

        do {
            cout << "Choose what database you want. \n 1. System default \n 2. Load your own" << endl;
            cin >> choose;

        } while (choose < 1 || choose > 2);
        switch (choose) {
            case 1:
                persons = systemDefaultDatabase();
                break;
            case 2:
                persons = readFromFile();
                break;
            default:
                cout << "Can't find anything...";
        }
    }
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
    return persons;
}

void printPersons(Person person) {
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
    //TODO fix so two names can be added
    using namespace std;
    std::vector<Person> persons;
    char choice;
    do {

        string firstname, lastname;
        double height;
        cout << "insert first name and press enter" << "\n" << "first name: " << endl;
        cin >> firstname;
        cout << "Enter your height " << endl;
        cin >> height;
        cout << "Last name: " << endl;
        getline(cin, lastname);

        persons.push_back(createPerson(firstname, lastname, height, persons));
        do {
            cout << "Do you add another one (Y/N) ? " << endl;
            cin >> choice;
        } while (choice != 'Y' and choice != 'y' and choice != 'N' and choice != 'n');

    } while (choice == 'y');

}

std::vector<Person> sortPersonsBy(std::vector<Person> persons) {
    using namespace std;
//    std::vector<Person> persons = systemDefaultDatabase();

    SortType s;
    int menuChoice = 0;
    cout << "Sort list by: " << "\n" << "1. Last name" << "\t" << "2. Signature" << "\t" << "3. Height" << endl;
    cin >> menuChoice;
    s = static_cast<SortType>(menuChoice);
    persons = sortPersons(std::move(persons), s);
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

std::string getFileNameFromUser() {
    using namespace std;
    std::vector<Person> persons;
    string fileName;

    cout << "Enter file name: ";
    cin >> fileName;
    return fileName;
}

std::vector<Person> readFromFile() {

    using namespace std;
    std::vector<Person> persons;
    string fileName = getFileNameFromUser();

//    cout << "Enter file name: ";
//    cin >> fileName;

    string line;
    ifstream infile("../../_Resources/" + fileName + ".txt");
    if (!infile.is_open()) {
        cout << "Unable to find your file";
    } else {


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

    }
    return persons;
}