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
double getPersonHeight(double height);

int main() {
    inputMenu();
    projectFunction();
    return 0;
}

void inputMenu() {
    using namespace std;
    Person person;
//    cout << "insert your first name" << endl;
//    cin >> person.firstname;
//    cin.clear();
//    cout << "Enter your last name " << endl;
//    cin >> person.lastname;
////    cout << "Enter your height " << endl;
////    cin >> person.height;
    person.firstname = "Erik";
    person.lastname = "Andersson";
    person.height = getPersonHeight(1.5545);
    auto test = 11;
    getSignature(person, test);
}


void printPersons(const std::vector<Person> &persons) {
    using namespace std;
    int sequence;

    for (int i = 0, sequence = 1; i > persons.size(); i++, sequence++) {

    }
    cout << "====================== NAME LIST ======================" << endl;
    cout << "Number of persons in list: " << sequence << "\n" << endl;
    cout << "Nr" << setw(20) << "Sign" << setw(20) << "Name" << setw(20) << "Length (m)" << endl;


    sequence = 1;
    for (Person person:persons) {
        cout << internal << sequence << "." << setw(20) << person.signature << setw(20) << person.firstname << " " << person.lastname << setw(50) << person.height << endl;
    }
}


void mainMenu() {

}