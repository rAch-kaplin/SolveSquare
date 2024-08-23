// SolveSquare programm

#include<stdio.h>
#include<math.h>
#include<TXLib.h>
#include<assert.h>
#include"SolveSquare.hpp"




int main(void)
{

    AllTests();


    printf("#Square Solver! by rAch-kaplin\n");

    printf("#Enter a b c: ");


    double a = NAN, b = NAN, c = NAN;

    buffer_scanf(&a, &b, &c);



    double x1 = NAN, x2 = NAN;
    enum nRoots rootsCount = SolveSquare(a, b, c, &x1, &x2);

    print_roots(rootsCount, x1, x2);


    return 0;
}



enum nRoots SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (is_zero(a))
    {
        if (is_zero(b))
        {
            return (is_zero(c))? SS_INF_ROOTS : ZERO_ROOT;
        }
        else // if (a == 0) and  (b != 0)
        {
            *x1 = -c / b;
            return ONE_ROOT;
        }
    }
    else //  if (a != 0)
    {
        double discriminant = b * b - 4 * a * c;

        if (is_zero(discriminant))
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
}



void SkipLine()
{
    int line;
    while ((line = getchar()) != '\n' && line != EOF && line != '\t');

}

void buffer_scanf(double *a, double *b, double *c)
{
    printf("Enter a, b, c or enter (q) - close program\n");


    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {
        printf("error - a, b, c\n");
        printf("Enter a, b, c again: ");
        SkipLine();

    }



}





int CompareDoubles(double a, double b)
{
        if (fabs(a - b) > 1e-6)
            return 1;
        else
            return 0;
}

bool is_zero(double x)
{
    if (x <= num && x >= -num)
        return 1;
    else
        return 0;
}


int print_roots(int rootsCount, double x1, double x2)
{
    switch(rootsCount)
    {
        case ZERO_ROOT: printf("No roots\n");
                break;
        case ONE_ROOT: printf("x = %lg\n", x1);
                break;
        case TWO_ROOT: printf("x1 = %lg and x2 = %lg\n", x1, x2);
                break;
        case SS_INF_ROOTS: printf("Any number\n");
                break;
        default: printf("main() ERROR");
     }       return 1;
}
//
//void AllTests()
//{
//                                  a    b   c  x1c x2c  rootsCountCorrect
//
//    struct UNIT_variables data1 = {1, -3, 2, 2, 1, TWO_ROOT};
//    RunTest(data1);
//
//    struct UNIT_variables data2 = {1, -5, 6, 3, 2, TWO_ROOT};
//    RunTest(data2);
//
//    struct UNIT_variables data3 = {1, 2, 1, -1, -1, ONE_ROOT};
//    RunTest(data3);
//
//    struct UNIT_variables data4 = {1, 0, -9, -3, 3, TWO_ROOT};
//    RunTest(data4);
//
//    struct UNIT_variables data5 = {1, 0, 0, 0, 0, ONE_ROOT};
//    RunTest(data5);
//
//    struct UNIT_variables data6 = {1, 2, 3, NAN, NAN, ZERO_ROOT};
//    RunTest(data6);
//
//    struct UNIT_variables data7 = {1, 0, -4, -2, 2, TWO_ROOT};
//    RunTest(data7);
//
//    struct UNIT_variables data8 = {1, 0, 0, 0, NAN, ONE_ROOT};
//    RunTest(data8);
//}





