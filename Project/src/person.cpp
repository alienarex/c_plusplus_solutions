//
// Created by annic on 2020-02-08.
//

#include <string>
#include "person.h"
//struct Person {
//    std::string firstname;
//    std::string lastname;
//    std::string signature;
//    double height;
//
////    friend std::ostream &operator<<(std::ostream &os, Person const &person) {
////        return os << person.firstname
////                  << person.lastname
////                  << person.signature
////                  << person.height ;
////    }
//
//};
//
//struct compareByFirstname {
//    inline bool operator()(const Person &struct1, const Person &struct2) {
//        return (struct1.firstname < struct2.firstname);
//    }
//};
//
////TODO If last name is equal sort by first name
//struct compareByLastname {
//    inline bool operator()(const Person &struct1, const Person &struct2) {
//        return  struct1.lastname == struct2.lastname ? struct1.firstname < struct2.firstname : struct1.lastname < struct2.lastname;
////        return (struct1.lastname < struct2.lastname);
//    }
//};
//
//
//struct compareByHeight {
//    inline bool operator()(const Person &struct1, const Person &struct2) {
//        return (struct1.height > struct2.height);
//    }
//};
//
//struct compareBySignature {
//    inline bool operator()(const Person &struct1, const Person &struct2) {
//        return (struct1.signature < struct2.signature);
//    }
//};