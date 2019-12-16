# Laboration 2

## Environment & Tools
Operating system: Windows 10 Pro.

IDE: JetBrains Clion

Compiler: CMake

Git: GitBash version 2.24.0.windows.2

## Purpose
In programs where there are some kind of login or need to authenticate a user, there must exist an effective and secure authentication of the user login. 
There's some rather simple, but effective way of doing this, without adding more complexity to the program and source code than necessary. 
By constraining code complexity the code will be easier to write, maintain and increase the readability.

## Procedures
There's a need for good structure of the project aswell as the written code. 
To ensure this, the project are divided into separated directories, following current naming conventions. However, the project already contained a function named `decryptPassword(..)` but since that name suggests the decryption of the password, and since there's constraints of removing 
existing code, I chose to add a function named encryptPassword(..). I also needed to add the function to the prototype.h (header).  

###Project structure as following:
1. **include** - `Prototypes.h` containing all of the headers for the program. 
2. **src** -  
2.1.  `Definitions.cpp` with the functions:

        `mainArgumentParser(..)`
        `authenticateUser(..)`
       ` decryptPassword(..) `

    2.2. `main.cpp` with the function

    `main(..)`

The `authenticateUser(..)` splits the input string into two, username and password by using ``find_first_of(..)`` and return first position of ','. 

    Important!
    This means that the username cannot contain ',' whilst the authentication would fail!
    

When username and password been extracted the password is passed to `encryptPassword(..)` for encryption, rebuild the string and returns the encrypted password as a string. 
Variables in the function:

``` const int ROT7 = 7, ROT9 = 9;
    const string VOWELS = "AEIOUYaeiouy";
    string encrypted;
    stringstream ss;
    const size_t KEY 
    char thisChar , encryptedChar
    bool isVowel
```
The program uses two encryption keys, ROT7 and ROT9, witch means that the letter changes from it current state to moving up in the ASCII - table, either 7 or 9 steps.
 
In the for-loop the encryption keys alternate as follows:
        `(i % 2 == 0) ? ROT7 : ROT9;` witch means that when the iteration is on an even number it uses the encryption key ROT7 otherwise it uses ROT9.
        
In the iteration there's a control if the current char is a vowel, and if so, it adds a '0' before and after the current char using stringstream.
        
The function iterated through the string using a for-loop and in every other iteration it switches between the encryption keys, alternating between them every other iteration in the for-loop.   


The flow of `encryptPassword(..)`: 
1. Iterate through `param:pass`
2. Store the encryption key in  `KEY`
3. Initiate and implement `thisChar` and `encryptedChar`. `thisChar` gets the clear value of the string and `encryptedChar` uses `thisChar + KEY` to get its value. 
4. The non encrypted char, `thisChar` compares to the string VOWELS, which contains upper and lower case vowels. If the char exists in VOWELS it returns true and are assigned as so to isVowel, 
otherwise it's set to false by using `nopos` whitch means that no position of the char was found in VOWELS.
5. The stringstream function is the used for building of the encrypted string. If `isVowel` is set to `true` the outstream will add '0' before and after the `encryptedChar` otherwise the outpustream only contains the `encryptedChar`. 


The encrypted password is returned to `authenticateUser(..)` and are immediately checked against `PASSWORD` and in the same statement there's a validation for username.
If both are valid the `authenticateUser(..)` returns `true`.
 
## Discussion
There where some issues during the development, some of which could've been avoided, such as fully understand the task ahead before start writing code.
Some had to be taught before being able to avoid them, such as using the c++ syntax to the fullest to be able to maintain DRY and by that follow good coding practice.

There were also some misunderstandings around the requirements for the README which forced me to complement the submission and submit it again. 
Although a bit time consuming, it gave me the opportunity to improve the code based on the given feedback.
At the same time, I chose to modify the structure of the code, implementing the function `encryptPassword(..)` instead of using the function `decryptPassword(..)` that didn't follow the practice of naming the functions after what they do. 
In this case the name decryptPassword(..) implies that the password being decrypted instead of encrypted which is what actually happens.   
Therefor the function decryptPassword(..) is not in use, but need to maintain in the project due to explicit requirements not to alter already existing code. 

The frequent use of git should give any interested an overview of the working flow and the alternations of the code during the development.