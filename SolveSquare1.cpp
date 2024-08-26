#include<stdio.h>
#include<math.h>
#include<TXLib.h>
#include<assert.h>
#include"SolveSquare.hpp"

int main(void)
{
    allTests();

    printf("#Square Solver! by rAch-kaplin\n");

    printf("#Enter a b c: ");

    double a = NAN, b = NAN, c = NAN;

    bufferScanf(&a, &b, &c);

    double x1 = NAN, x2 = NAN;

    NRoots roots_count = SolveSquare(a, b, c, &x1, &x2);
    printRoots(roots_count, x1, x2);

    return 0;
}



NRoots SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (isZero(a))
    {
        solveLinearSquare(b, c, x1);
    }


    else // a != 0
    {
        double discriminant = b * b - 4 * a * c;

        if (isZero(discriminant))
        {
            *x1 = *x2 = -b / (2 * a);
            return ONE_ROOT;
        }
        else
        {

            if (discriminant > 0)
            {
                double sqrt_discriminant = sqrt(discriminant);
                *x1 = (-b - sqrt_discriminant) / ( 2 * a);
                *x2 = (-b + sqrt_discriminant) / ( 2 * a);
                return TWO_ROOT;
            }
            else
            {
                return ZERO_ROOT;
            }

        }
    }
    return ZERO_ROOT;
}

int solveLinearSquare(double b, double c, double * x1)
{
    if (isZero(b))
    {
        return (isZero(c))? SS_INF_ROOTS : ZERO_ROOT;  // + TODO: в отдельную функцию решение линейного уравнения
    }
    else // if (a == 0) and  (b != 0)
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }
}

