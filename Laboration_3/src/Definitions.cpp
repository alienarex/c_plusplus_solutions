#include "Prototypes.h"
#include <iomanip>
#include <string>

long_type fibonacciIteration(size_t nthNumber) {
    size_t x = 0, y = 1, z = 0;
    for (size_t i = 0; i < nthNumber; i++) { // bubble sorting
        z = x + y;
        x = y;
        y = z;
    }
    return x;
}

std::vector<Stats> fibonacciTimer(size_t nthNumber) {
    /*Pseudo Code, fibonacciTimer(...) Output, example
    REPEAT {
    DETERMINE type of approach
    SET Stats.type
    MARK start time
    REPEAT {
    CALL appropriate Fibonacci function
    ADD Fibonacci value to Stats container
    FOR EACH 5th sequence OUTPUT information on screen**
    } IF iteration IS NOT 0*
    MARK end time
    CALCULATE duration of all needed formats
    SET duration for relevant Stats members
    } FOR each Fibonacci approach
    RETURN container filled with two Stats objects*/
    std::vector<Stats> stats;

    for (int i = 0; i < 2; ++i) {
        Stats stat;
        int sequence = 0;

        switch (i) {
            case 0: // iterationtypen
                stat.type = "iteration";
                for (size_t j = nthNumber; j <= nthNumber; j--) {
                    sequence++;
                    long long test = fibonacciIteration(j);
                    stat.values.push_back(test);
//                    stat.values.push_back(fibonacciIteration((j)));
                    if (sequence == 5 || nthNumber == j) {
                        sequence = 0;
                        std::cout << std::internal << stat.type << " " << j << "th " << std::setw(10) << stat.values[nthNumber - j] << std::endl;
                    }
                }
                break;

            case 1: // reqursion
                stat.type = "reqursion";
                for (size_t j = nthNumber; j <= nthNumber; --j) {
                    sequence++;
                    stat.values.push_back(fibonacciIteration((j)));

                    if (sequence == 5 || nthNumber == j) {

                        sequence = 0;
                        std::cout << std::internal << stat.type << " " << j << "th " << std::setw(10) << stat.values[nthNumber - j] << std::endl;

                    }
                }

                break;
            default:
                break;
        }
        stats.push_back(stat);

    }

    return stats;
}

long_type fibonacciRecursion(size_t nthNumber) {
    if (nthNumber <= 1)
        return nthNumber;
    return fibonacciRecursion(nthNumber - 1) + fibonacciRecursion(nthNumber - 2);
}