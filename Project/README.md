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
The foundation was `struct Person` and `std::vector<Person>` and to test the different functions ini the program, there was a "default" `std::vector<Person>` created in `std::vector<Person> systemDefaultDatabase()`. 
This is then used as a regular vector and called in every function to be tested. 
There was also a `const vector<Person> ` created in constant.h after submissions requirement, and by define the const vector with `std::vector<Person> systemDefaultDatabase()` that could be called from all instances of the program. 
That approach was abandoned since, even though possible, one does not define a cont in runtime. 

Functions that was created after that was `printPersons(std::vector<Person> persons);`. 
This function, even though the foundation of it didn't change a lot, went though some improvements and variations during the development. 
Ie an a UI menu was added to prompt the user to choose a database, either from file or system default, if the passes vector 
 didn't contained any records.

To be able to insert a person into the "database" the function `addPerson()` is called in `mainMenu();` `addPerson()` has dependency in `createPerson()` witch is the actual "creator" of the `struct Person`.
The `person.signature` creates by passing first and last name to `std::string getSignatureForPerson(...)` and convert the letters to small case in `convertStringToLowerCase(...)`. 
The signature creates, using the returning first and last name in lower case, and takes the first three letters in first and then the first three letters in the last name. 
If the names are shorter then three letters, an `x` fills up the missing letters (ie `myxalx` ). 

The string is returned to `createPerson()` and a search in existing "database" for duplicates (of the first six (6) characters) are made. To ensure the uniquely of the signature a
sequential number appends to the letters by counting hits on signature and pass it to `std::string getSequentialNumber(...)`. 

The program should also provide the possibility to find and delete a person using `person.signature`. This takes place in the `deletePerson(...);` and `findPerson(...)` and the both calls 
`getSignatureForPerson()` that prompts the user to enter the `person.signature` that it want to search for.
The function `findPerson()` calls the overloaded  function `printPerson(Person person)` to give printing of the person the same appearance without looping thought a list and adding other surrounding stuff.
 
For managing the `vector` there's a function for shuffle and one for sorting the list. 
`sortPersonsBy();` prompts the user for input, choosing the type of sorting that will occur. When sort type chosen the `sortPersons(std::vector<Person, SortType sortType>` is called). The sorting occurs in the Person.h as struct 
 `struct compareByLastname` sorts primary from last name, if last name is same, sorting occurs from first name.  
 `struct compareBySignature` 
 `struct compareByHeight`
The sorted vector is passed back to `sortPersonsBy()` and is catch by `printPersons(...)` in main menu.
To shuffle the list items `randomizeDatabase(...)` is called. When passed vector is shuffled it returns the vector to `mainMenu()` where it's catch by `printPersons(...)` and get printed.
  
The other requirements were read and write to file. These functions are provided by `readFromFile()` and `writeToFile()`. Both are depended on `getFileNameFromUser()` that prompts a name on the file. 
Since prompt only for the name on the file, this function can be used both to find and set filename. 
`readFromFile();` returns the vector from file into `mainMenu();` where it's catch by `printPersons();`.

###Problems 
* Naming conventions: I found it hard to set proper, describing names. And since the developing is a iterating process, the functions have varied over time. This made the namings even more troublesome. 
* Memory issues: When developing the sorting function, tbe vector to be sorted were passed by value and the modified vector were then returned to the same variable, causing memory failure. 
Solved by passing the vector as reference instead. 
* Code structure: Good structure with a natural flow makes is easier to read and understand, which makes everyone's job easier. 
And even thought my intention is to write good, comprehen§ded and self explaining code, I find it mind blowing hard. 
Especially since this is a smaller program and knowing in which degree the abstraction should be.
  

## Discussion
This development has iterated several times. Functions renaming and redeclared was eventually a "ordinary" thing to do. I'm not sure if this can be seen as something good, 
that shows my own development and growth. 
Or if it's a consequent of a sloppy back ground work and lack of working structure. Most likely it's a combination of them both.

Further more there been some restructure and relocation of both code and structs, clearly visible in commits history. 
First I wanted to put `struct Person` into it's own file with associated .h file, but initially I thought the program was going to be far to small to be able to  defend it. 
But as the time went, it was my opinion that it would make the code more structured and readable if it was moved to an own file. 
So the `struct Person` is declared and defined in the person.h where the `struct compareByLastname`, `struct compareByHeight` and `struct compareBySignature` is declared and defined.
There's also a associated person.cpp where I tried to put code directly associated to `struct Person`. For me this is a logic project structure, often used in structure projects in other 
languages. Thought, after a bit googling I am not convinced that is the proper way of structure a c++ project.

Last, but not least, there's a requirement omitted in this program and that is the deceleration of `const std::vector<Person> persons`. 
Const variables and struct are not supposed to be altered, and even though possible, there's not seen as good practice doing so. Especially since it contradicts the very essenes of `const`.
Therefore it is my perception that using a global const variable std::vector<Person> was a way of facilitate during development.
And due to my reluctance to global variables, my solution is instead a function returning a `std::vector<Person>`.
As a way of mimic the `const std::vector<Person>` required in the submission description, I choose to pass the vector though `mainMenu()`. This is probably not the best way of doing it, 
due to eventual conflicts if using pointers, const, passing as reference or value. 

Also, .gitignore are modified in a way where it should omits the .txt files, making it possible to add those in a commit if that is what one wants.