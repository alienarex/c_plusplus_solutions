#include "Prototypes.h"
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>

long_type fibonacciIteration(size_t nthNumber) {
    size_t x = 0, y = 1, z = 0;
    for (size_t i = 0; i < nthNumber; i++) { // bubble sorting
        z = x + y;
        x = y;
        y = z;
    }
    return x;
}

Stats setStatsTiming(Stats stat, std::chrono::high_resolution_clock::time_point startTime) {

    std::chrono::high_resolution_clock::time_point endTime;

    using fpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
    using millisec=  std::chrono::duration<float, std::chrono::milliseconds::period>;
    using microsec=  std::chrono::duration<float, std::chrono::microseconds::period>;
    using nanosec=  std::chrono::duration<float, std::chrono::nanoseconds::period>;

    endTime = std::chrono::high_resolution_clock::now();
    stat.millisec = millisec(endTime - startTime).count();
    stat.nanosec = nanosec(endTime - startTime).count();
    stat.microsec = microsec(endTime - startTime).count();
    stat.sec = fpSeconds(endTime - startTime).count();
    stat.millisec = millisec(endTime - startTime).count();

    return stat;
}

std::vector<Stats> fibonacciTimer(size_t nthNumber) {

    std::vector<Stats> stats;

    std::chrono::high_resolution_clock::time_point startTime;


    for (int i = 0; i < 2; ++i) {
        Stats stat;
        int sequence = 0;
        startTime = std::chrono::high_resolution_clock::now();

        switch (i) {

            case 0: // iterationtypen
                stat.type = "Iteration";

                for (size_t j = nthNumber, counter = 0; j <= nthNumber; --j, counter++) {


                    size_t returnValueFibonacciIteration = fibonacciIteration(j);
                    stat.values.push_back(returnValueFibonacciIteration);

                    if (counter % 5 == 0) {
                        std::cout << std::internal << stat.type << " " << j << "th " << std::setw(10) << stat.values[counter] << std::endl;
                    }

                }
                stat = setStatsTiming(stat, startTime);

                break;

            case 1: // reqursion

                stat.type = "Reqursion";

                for (size_t j = nthNumber, counter = 0; j <= nthNumber; --j, counter++) {


                    size_t returnValueFibonacciRecursion = fibonacciRecursion(j);
                    stat.values.push_back(returnValueFibonacciRecursion);

                    if (counter % 5 == 0) {

                        std::cout << std::internal << stat.type << " " << j << "th " << std::setw(10) << stat.values[counter] << std::endl;

                    }

                }
                stat = setStatsTiming(stat, startTime);

                break;

            default:
                break;
        }
        stats.push_back(stat);// Initialized in the switch
    }
    return stats;
}

/*  */
long_type fibonacciRecursion(size_t nthNumber) {
    if (nthNumber <= 1)
        return nthNumber;
    return fibonacciRecursion(nthNumber - 1) + fibonacciRecursion(nthNumber - 2);
}