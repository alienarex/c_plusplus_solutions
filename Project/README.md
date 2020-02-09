# Project Assignment

## Environment & Tools
Operating system: Windows 10 Pro.

IDE: JetBrains Clion

Compiler: CMake

Git: GitBash version 2.24.0.windows.2

## Purpose
This project is the examination part of the course _Introduction to c++_ at Mid Sweden University VT-20.
 
The program will simulate a database with persons name, height and system generated signature with a text file where the name on the file are provided by the user.
When a new file is opened this is replacing existing list of persons.

Through several menus and alternative will the user be able to get complete list of persons and their height, shuffle the list and add, get and delete records. 

## Procedures
Identify requirements
Create struct person and `vector<Person>` in constant.h.
Added a 
Get list. Add record. Create signature,
Get record with `person.signature`. Delete record with `person.signature`. 
Shuffle list.  Sort list. 
Write to file. Read from file.
Moved `struct Person` related to person.h. Linked to `Prototype.h`, `constants.h` and `Definitions.cpp`.


###Problems 
Problems when sort the vector due to memory issues. Passed variable by value and assign the sorted vector into same memory location. Fixed by passing variable as Reference.

Not sure how to structure the code. Used to add a new file for every `class` and abstract and dived my code in a larger extend.

## Discussion
Don't know where to put person struct. didn't work when was in own .cpp file. moved to .h file and works. 
Tried to use constants when possible to ensure the consistency of the program.
