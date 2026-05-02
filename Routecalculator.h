#ifndef ROUTECALCULATOR_H
#define ROUTECALCULATOR_H

#include "MetroData.h"

class RouteCalculator {
public:
    void shortestPath(MetroData &metro, string src, string dest);
};

#endif
