#include<stdio.h>
#include<math.h>
#include<TXLib.h>
#include<assert.h>
#include"SolveSquare.hpp"

const double inaccuracy = 1e-6;

int compareDoubles(double a, double b) // TODO: стиль compareDoubles +
{
        if (fabs(a - b) > inaccuracy) // TODO: в константу +
            return 1;
        else
            return 0;
}

bool isZero(double x)
{
    if (x <= inaccuracy && x >= -inaccuracy)
        return 1;
    else
        return 0;
}

