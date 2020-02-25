# Laboration 3

## Environment & Tools
Operating system: Windows 10 Pro.

IDE: JetBrains Clion

Compiler: CMake

Git: GitBash version 2.24.0.windows.2

## Purpose
To be able to make decision what the best programmatic approach would be to attack a problem it's important to know how different approach might 
effect the response time. This is important due to several different reasons, such as how to write and optimize the program but also when one need to assign memory,
processor prioritisation and threads. 


Although, important as it is to be able to write effective code, it also important to be able to provide the user with relevant information's, in a structured and ordered way.
This is especially important working with only text based information. 

In this part of the project the user will be provided two menus, one where the user choose whether it want to run the program or EXIT. 
The other menu is where the user provides the number on witch the fibonacci's sequence will be calculated.
 
The calculation will be based on two different approaches and each approach executions time will be registered in milli-, micro-, nano- and seconds. 
The statistics will then be printed to the user in a coherent context which will provide the user with a aggregated information in a structured way. 


## Procedures 
The first thing was to identify and understand the requirements and study the code already implemented in the project. After identifying the existing data structures and functions an approach to solve the existing problem was developed.
The first thing that needed to be sorted out was the behaviour of the existing functions, but it wasn't possible to provide the functions with relevant data at first, therefor the absolute first thing to do was to add code that could provide them 
with necessary data.
That meant adding a way for the program to choose witch function to call. This is made in `fibonacciTimer(...)` and happens through a for-loop that iterates 2 times. The for-loop is implemented with a magic number, which basically means 
that there's no descriptive variable name for it.
In each iteration a new `Stats stat` object is created and startTime sets to `std::chrono::high_resolution_clock::now();`. Then it decides which function to be called with a simple if(..) which contains another for-loop that iterates the parameter `nthNumber` to 
fibonacciTimer and returns a calculated value witch is added to `stat.values`, where values is a vector of `long_type`.
    
    
  ![#f03c15](https://placehold.it/15/f03c15/000000?text=+) **NOTE** in the same for-loop as used to iterate through `nthNumber` there's also an initiation of a counter that makes it possible to add the numbers in reversed order to the `stat.values`**NOTE**
  
The loop also prints, via `std::cout` every fifth calculated fibonacci value, in descending value order, high to low. This is decided by using modilus as such  `if (counter % 5 == 0)`. 
When that part worked as supposed a function for setting the execution duration was made. That function takes a `Stats` object and `startTime` as parameter and sets appropriate values to the time variables . 
It then returns the `Stats` object to `fibonacciTimer(...)` and adds to the `std::vector stats`.

After the implementation of the "engine" of the program three validation functions was created:
        
           bool inputValidation() 
           bool inputValidationMainMenu(int userInput)
           bool inputValidationSubMenu(int userInput)
           
Where the first one is general and a "base" and the other two provides the user with information about the error occurred, this ensures that the program doesn't crash if input is of incorrect type and helps the user 
to avoid error in the future by providing the user with sufficient information when an error occurs. 
 
When the "engine" and input control was in place the two menu functions `mainMenu()` and `subMenu()` was created. 
`mainMenu()` contains the menu which the user chooses between ending the program or continue and the `subMenu()` where the user inputs the number on which the calculations will be provided. 

When the menus worked the printing of the stats was made by `printStats(vector<Stats>)` and `writeToFile(Stats)` where printStats takes a `vector<Stats>` as parameter and writeToFile takes a single `Stats` object. 

## Discussion
The project has progressed in a steady pace and there have not been any major difficulties arose. 
Although there've been some issues and lessons learned that I want to attend

- Magic number for set iterations on the for - loop in fibonacciTimer() - as a reflection it would be better to assign a value to a variable with a descriptive name.
- Commits - There have been commits without building before. It isn't such big of a deal since that was easily reverted this time but it might be a good thing to keep in mind to be able to minimize git problem in the future.
- Technical issues - during this work the computer I worked on decided to run updates that changed some core settings and that made my compiler run really slow, and messed with my program quite a bit.
As a consequence I poke around in code that actually worked.

Programming is problem solving and this assignment was fun to work with, even though, doing the same assigment again, I'd might use some different approaches in some cases.

The program fullfills the requirements in the submission description and therefore I consider the purpose fulfilled.

 ## UPDATES
The problems with aligning the `stat.values[counter]` output with `setw()` was caused by not assigning enough space for the output by using `" " ` to get a space in the `j th`.
More detailed comments are added to `fibonacciRecursion(...)` and `fibonacciIteration(...)`

Updates 2 - 2020-02-25
Modified `printStats(const std::vector<Stats> &stats,size_t userInput);` to get the user provided sequence number. An other alternative could be to iterate through the `vector<Stat> stats` and get the size
of the `vector<long_type>values` in Stats, but it seemed a bit unnecessary since the userInput value where easily available. However, if I'd modify the same thing in a real-life situation, I'd use the loop alternative to avoid
conflicts and other problems on other parts of the program.   