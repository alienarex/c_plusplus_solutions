#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include <iostream>
#include <vector>
#include "constants.h"

// Arbitrary function prototype, replace with your own prototype(s)
void projectFunction();

/**
 * Print persons to screen
 */
void printPersons(const std::vector<Person> &persons);

/**
 * Retrieves users info
 */
void inputMenu();

/**
 * Creates a substring from 3 first char in first- and last-name. If length less then 3, x fill up to 3 char.
 *
 * @param Person destructure, seqNumber = number of existing rows in database
 */
Person getSignature(Person person, int seqNumber);


#endif //DT018G_PROTOTYPES_H
