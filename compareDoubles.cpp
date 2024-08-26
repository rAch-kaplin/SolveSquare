#include<stdio.h>
#include<math.h>
#include<TXLib.h>
#include"compareDoubles.hpp"

const double inaccuracy = 1e-6;

int compareDoubles(double a, double b)
{
        if (fabs(a - b) > inaccuracy)
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

