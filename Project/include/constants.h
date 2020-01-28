//
// Created by anbj1001 on 2020-01-20.
//

#ifndef DT018G_CONSTANTS_H
#define DT018G_CONSTANTS_H

#include <string>

struct Person {
    std::string firstname;
    std::string lastname;
    std::string signature;
    double height;

};



const std::vector<Person> databasePersons;
// TODO Create a kind of get function? Like createOnePerson(firstname,lastname, height);

#endif //DT018G_CONSTANTS_H
