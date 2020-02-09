#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include <iostream>
#include <vector>
#include "constants.h"
#include "person.h"


// Arbitrary function prototype, replace with your own prototype(s)
void projectFunction();

/**
 * Foundation function printing menu where user chooses from.
 */
void mainMenu();

/**
 * Print databasePersons to screen
 */
void getPersons();

/**
 * Retrieves users info
 */
void addPerson();

/**
 * Creates a substring from 3 first char in first- and last-name. If length less then 3, x fill up to 3 char.
 *
 * @param const std::string &firstname, const std::string &lastname,, strings from which the signature are extracted from
 * @return std::string signature
 */
std::string getSignature(const std::string &firstname, const std::string &lastname);

/**
 * Format seqNumber to string. Adds "0" before if seqNumber less then 9. (ex 09)
 * Default value 1
 * @param int seqNumber
 * @return std::string
 * */
std::string getSequentialNumber(int seqNumber = 1);

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
std::vector<Person> deletePerson();

/**
 * Sorting vector. If last names same sorting by first name
 * @param vector<Person> persons,SortType sortType
 * @return vector<Person> persons, sorted
 */
std::vector<Person> sortPersons(std::vector<Person> persons, SortType sortType);

/**
 * Randomize the struct Person in database
 * @param vector<Person> persons
 */
std::vector<Person> randomizeDatabase(std::vector<Person> persons);

void writeToFile(std::vector<Person> &persons);

std::vector<Person> readFromFile();

void sortPersonsBy(std::vector<Person> persons);

/**
 * User input signature. Used in deletePerson
 * */
std::string getSignatureForPerson();

/**
 * Searches database for signature returns found record
 */
std::vector<Person> findPerson();

#endif //DT018G_PROTOTYPES_H
