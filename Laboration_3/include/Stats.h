#ifndef DT018G_STATS_H
#define DT018G_STATS_H

#include <string>
#include <vector>

typedef unsigned long long long_type;

struct Stats {
    std::string type;
    std::vector<long_type> values;
    long_type nanosec = 0, microsec = 0, millisec = 0;
    double sec = 0;
};

#endif //DT018G_STATS_H
