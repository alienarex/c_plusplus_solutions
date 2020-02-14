#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include <iostream>
#include <vector>
#include "constants.h"
#include "person.h"

/**
 * Foundation function printing menu where user chooses from.
 */
void mainMenu();

/**
 * Print list
 * @param persons
 * @return std::vector<Person>
 * */
std::vector<Person> printPersons(std::vector<Person> persons);

/**
 * Print one person
 * @param person
 */
void printPersons(Person person);

/**
 * I
 * Retrieves users info
 * @param persons
 * @return persons , created person(s) added to vector
 */
std::vector<Person> addPerson(std::vector<Person> persons);

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

/**
 * @param firstname, lastname,height,  info supplied by user
 */
Person createPerson(const std::string &firstname, const std::string &lastname, double height, const std::vector<Person> &persons);

/**
 * delete one person from vector returns
 * @param persons, the vector that record deletes from
 * @return persons , vector with the removed record
 */
std::vector<Person> deletePerson(std::vector<Person> persons);

/**
 * Sets type of sort
 * @param persons
 * @return std::vector<Person>
 * */
std::vector<Person> sortPersonsBy(std::vector<Person> persons);

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

/**
 * Ask for filename
 * @return std::string
 */
std::string getFileNameFromUser();

/**
 * @param persons
 * */
void writeToFile(std::vector<Person> &persons);

/**
 * @return std::vector<Person>
 */
std::vector<Person> readFromFile();

/**
 * User input signature. Used in deletePerson
 * */
std::string getSignatureForPerson();

/**
 * Searches database for signature returns found record
 */
std::vector<Person> findPerson(std::vector<Person>);

/**
 * @return bool
 * */
bool inputValidation();

#endif //DT018G_PROTOTYPES_H
