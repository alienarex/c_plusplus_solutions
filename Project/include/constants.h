//
// Created by anbj1001 on 2020-01-20.
//

#ifndef DT018G_CONSTANTS_H
#define DT018G_CONSTANTS_H

#include <string>

enum SortType {
    lastname = 1,
    signature = 2,
    height = 3,
    firstname = 4
};


struct Person {
    std::string firstname;
    std::string lastname;
    std::string signature;
    double height;

};

struct compareByLastName {
    inline bool operator()(const Person &struct1, const Person &struct2) {
        return (struct1.lastname < struct2.lastname);
    }
};

struct compareByFirstname {
    inline bool operator()(const Person &struct1, const Person &struct2) {
        return (struct1.firstname < struct2.firstname);
    }
};

struct compareByHeight {
    inline bool operator()(const Person &struct1, const Person &struct2) {
        return (struct1.height > struct2.height);
    }
};

struct compareBySignature {
    inline bool operator()(const Person &struct1, const Person &struct2) {
        return (struct1.signature < struct2.signature);
    }
};

const std::vector<Person> databasePersons;
// TODO Create a kind of get function? Like createOnePerson(firstname,lastname, height);

#endif //DT018G_CONSTANTS_H
