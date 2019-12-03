# Laboration 1

## Environment & Tools
Operating system: Windows 10 Pro.

IDE: JetBrains Clion

Compiler: CMake

Git: GitBash version 2.24.0.windows.2

## Purpose
The purpose of the lab is to solve common problems using simple data types and without using the built in libraries. 
This forces me to really comprehend the problem to be solve and the programmatically way of doing it from bottom up. 
Further more it's a way of getting to know the c++ syntax and structure before the more complicated and complexer laborious. 

## Procedures
For software used in this laboratory, see "Environment & Tools". 
All source code used in this laboratory is in the file "main.cpp". In the file there are two methods: main() and countDigits().
Content in countDigits() is the functions for validate that the input number is consistent with the requirements (2019-11-19 the required number of digits is five (5).)
Content in main(): Function for ensure the integrity of the code (input control). Method call to countDigits() and all the algorithms for calculate if the validated number is a palindrome.

###Problems:

When to validate the number of digits in the input number the algorithm adds 1 to many to the numberOfDigits (the loop iterate one time too many). 
This is solved by decreasing variable numberOfDigits in the validating if-statement where comparision is made.

The variables "divisor", "leadingNumber", "trailingNumber" have to be declared after the input control algorithms since it messed with the calculations if not (not sure why, it just did).
   
## Discussion
The requirements regarding the assigment was sa bit blurry and there where no explicit requirement on the expected procedure, and the constraints of allowed data types. Those requirements was added during the work.

That made that I was forced to remake the lab from start and rethink the whole solution, and lead to the lab taking more time to complete than originally assigned.

The changed requirements, although frustrating, reminded me about the fundamentals in system developments which are that changes will always occur and the best you can do is to accept and get along with it.

The more programmatic learning this laboratory gave me, was the use of pure mathematical algorithms for solving the problem, rather than a more programmatically approach, using existing libraries and functions.
This lead to insights regarding memory management and c++ which will be useful later on.

Further more this laboratory gave me experience in useful keywords and phrases for information research in problem solving for c++. And even if this might not been the underlying intent in the design of the laboratory,
searches for ideas and possible approaches is a fundamental, essential and crucial part in all kind of system development projects. 
The better I get at constructing relevant search strings containing good keywords, the bigger is the chance of finding good answers faster, and releases time for refactoring and improve the code.

When I can find good information about my problem in less time, giving me the opportunity to refactor and improve my code, it'll continuously improve my programming skills and make me a better programmer.