#include <vector>
#include <iomanip>
#include <cmath>
#include "Prototypes.h"
#include "constants.h"

/*
int main() {
    projectFunction();
    return 0;
}*/

int main() {
    printPersons();
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


void mainMenu() {

}