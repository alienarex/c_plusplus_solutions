#include <vector>
#include <iomanip>
#include <cmath>
#include "Prototypes.h"
#include "constants.h"
#include <algorithm>
#include <iterator>

/*
int main() {
    projectFunction();
    return 0;
}*/

bool compare(Person a, Person b) {
    //for descending order replace with a.roll >b.roll
    if (a.firstname < b.firstname)
        return 1;
    else
        return 0;
}

// Sort Container by name function
bool sortByName(const Person &lhs, const Person &rhs) {
    return lhs.lastname > rhs.lastname;
}

void sortPersons() {
    using namespace std;
    std::vector<Person> persons = getPersonsFromDatabase();
//    bool test = sortByName(persons[0], persons[1]);
    sort(persons.begin(), persons.end(), sortByName);
//    for (size_t i = 0; i < persons.size(); i++) {
////        sort(persons[i + 1].firstname.begin(), persons[i + 1].firstname.end());
//
//    }
//    for (auto it = persons.begin(); it != persons.end(); ++it) {
//
//        sort(persons.begin(), persons.end(), it);
//    }
}

int main() {
    sortPersons();
//    printPersons();
//    inputMenu();
//    projectFunction();
    return 0;
}

void inputMenu() {
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

void printPersons() {
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

void getSignatureForDeleting() {
    using namespace std;
    string signature;
    cout << "Write Signature of person you want to delete: " << endl;
    cin >> signature;
    vector<Person> persons = deletePerson(signature);
}

void mainMenu() {

}