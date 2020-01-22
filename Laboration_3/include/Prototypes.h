#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include "Stats.h"
#include <iostream>
#include <chrono>
#include <limits>
#include <iomanip>
#include <fstream>

/**
 * Calculates Fibonacci sequence using for-loop by
 * @param nthNumber, integer to be calculated
 * @return the calculated number
 */
long_type fibonacciIteration(size_t nthNumber);

/**
 * Calculates Fibonacci sequence using recursion.
 * @param nthNumber,  integer to be calculated
 * @return the calculated number
 */
long_type fibonacciRecursion(size_t nthNumber);

/**
 * Calculates execution time for fibonacciRecursion(...) and fibonacciIteration(...) and adds it to object Stats properties.
 * Contains CALLS to fibonacciRecursion(...) and fibonacciIteration(...).
 * @param nthNumber, integer to calculate Fibonacci sequence on
 * @return a vector with Stats objects
 * */
std::vector<Stats> fibonacciTimer(size_t nthNumber);

/**
 * Function prints object Stats time properties
 * @param stats, constant vector of object Stats
 *
 * */
void printStats(const std::vector<Stats> &stats);

/**
 * Function decide type on object and writes object Stats time properties to .txt file
 * @param stats, one Stats object
 */
void writeToFile(const Stats &stats);

/**
 * Provides UI menu to user. Contains CALLS on functions subMenu,printStats,,writeToFile,fibonacciTimer
 */
void mainMenu();

/**
 * UI to get user input for calculation.
 * Including input validation
 * @return returns given value
 */
size_t subMenu();

/**
 * Function to validate input, throws exeption if value is moe then maxvalue int and if not number
 * @return true if validated
 */
bool inputValidation();

/**
 * Validates if input > 0 and < 3.
 * Prints a error message.
 * @param input, input to validate. Provided by user
 * @return true if validated
 */
bool inputValidationMainMenu(int input);

/**
 * Prints a error message.
 * @param input, input to validate. Provided by user
 * @return true if validated
 */
bool inputValidationSubMenu(int userInput);

/**
 * Calculates duration between start and end time in micro-, milli-, nano- and seconds.
 * @param stat,startTime .
 * @return Stats with set timing values
 * */
Stats setStatsTiming(Stats stat, std::chrono::high_resolution_clock::time_point startTime);

#endif //DT018G_PROTOTYPES_H
