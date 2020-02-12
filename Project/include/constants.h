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
    addRecord = 1,
    deleteRecord,
    findRecord,
    getRecords,
    sortRecords,
    randomizeRecords,
    saveRecords,
    loadRecords
};

/**
 * Default system vector
 * @return std::vector<Person>
 * */
std::vector<Person> systemDefaultDatabase();

#endif //DT018G_CONSTANTS_H
