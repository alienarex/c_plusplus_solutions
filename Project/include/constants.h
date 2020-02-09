//
// Created by anbj1001 on 2020-01-20.
//

#ifndef DT018G_CONSTANTS_H
#define DT018G_CONSTANTS_H

#include <string>
#include "person.h"
#include "Prototypes.h"

const std::string DELIM = "|";

enum SortType {
    lastname = 1,
    signature = 2,
    height = 3
};
enum MainMenu {
    addRec = 1,
    deleteRec,
    findRec,
    getList,
    sortList,
    randomizeList
};

std::vector<Person> getPersonsFromDatabase();

const std::vector<Person> databasePersons;

#endif //DT018G_CONSTANTS_H
