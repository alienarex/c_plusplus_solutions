#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include <iostream>
#include <vector>
#include "constants.h"

// Arbitrary function prototype, replace with your own prototype(s)
void projectFunction();

/**
 * Print databasePersons to screen
 */
void printPersons();

/**
 * Retrieves users info
 */
void inputMenu();

/**
 * Creates a substring from 3 first char in first- and last-name. If length less then 3, x fill up to 3 char.
 *
 * @param const std::string &firstname, const std::string &lastname,, strings from which the signature are extracted from
 * @param int seqNumber, number of existing rows in database to add a sequential number to signature
 * @return std::string signature
 */
std::string getSignature(const std::string &firstname, const std::string &lastname, int seqNumber);


/**
 * Converts persons height to string with two decimals
 */
std::string getPersonHeight(double height);


/**Gets the list of persons from database*/
std::vector<Person> getPersonsFromDatabase();

/**
 * @param firstname, lastname,height,  info supplied by user
 */
void createPerson(const std::string &firstname, const std::string &lastname, double height);

/**
 * delete one person from vector returns m
 */
std::vector<Person> deletePerson(const std::string &signature);

// UNDER DEV!
std::vector<Person> sortPersons(std::vector<Person> persons, SortType sortType);

/**
 * Randoize the struct Person in database
 */
std::vector<Person> randomizeDatabase(std::vector<Person> &persons);

void writeToFile(std::vector<Person> &persons);

void readFromFile();
#endif //DT018G_PROTOTYPES_H
