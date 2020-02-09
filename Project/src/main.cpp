#include <utility>
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


int main() {
    std::vector<Person> persons = getPersonsFromDatabase();
    mainMenu();
//    readFromFile();
//    writeToFile(persons);
//    randomizeDatabase(persons);

//    sortPersonsBy(persons);
//    getPersons();
    addPerson();
//    projectFunction();
    return 0;
}


