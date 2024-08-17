// SolveSquare programm

#include<stdio.h>
#include<math.h>
#include<TXLib.h>

const int EMPTY = 14378;

int SolveSquare( double a, double b, double c, double *x1, double *x2);

int main(void){
    printf("#Square Solver! by rAch-kaplin\n");

    printf("#Enter a b c:\n");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int searchRoots = SolveSquare(a, b, c, &x1, &x2);

    switch(searchRoots)
    {
        case 0: printf("No roots\n");
                break;
        case 1: printf("x = %lg\n", x1);
                break;
        case 2: printf("x1 = %lg and x2 = %lg\n", x1, x2);
                break;
        case EMPTY: printf("Any number\n");
                break;
        default: printf("...");
    }

    return 1;
}

int SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    if (a == 0)  // if (a == 0)
    {
        if (b == 0)  // if (a == 0) and (b == 0)
        {
        return (c == 0)? EMPTY : 0;  // if(a == 0) and (b == 0) and (c == 0)
        }
        else // if (a == 0) and  (b != 0)
        {
            *x1 = -c / b;
            return 1;
        }
    }
    else //  if (a != 0)
    {
        double d = b * b - 4 * a * c;  //d - discriminant

        if (d == 0)
        {
            *x1 = *x2 = -b / (2 * a);
            return 1;
        }
        else // d != 0
        {
            double sqrt_d = sqrt(d);

            *x1 = (-b - sqrt_d) / ( 2 * a);
            *x2 = (-b + sqrt_d) / ( 2 * a);
            return 2;
        }
    }
}
