// SolveSquare programm

#include<stdio.h>
#include<math.h>
#include<TXLib.h>

const int SS_INF_ROOTS = -1;

bool compare_zero(double x);

int SolveSquare( double a, double b, double c, double *x1, double *x2);

int main(void){
    printf("#Square Solver! by rAch-kaplin\n");

    printf("#Enter a b c:\n");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    //verification - a
    if (isnan(a) == 0)
        puts ("a - it is number");
    else
        puts ("a - Nan");
    //verification - b
    if (isnan(b) == 0)
        puts ("b - it is number");
    else
        puts ("b - Nan");
    // verification - c
    if (isnan(c) == 0)
        puts ("c - it is number");
    else
        puts ("c - Nan");

    double x1 = 0, x2 = 0;
    int rootsCount = SolveSquare(a, b, c, &x1, &x2);

    switch(rootsCount)
    {
        case 0: printf("No roots\n");
                break;
        case 1: printf("x = %lg\n", x1);
                break;
        case 2: printf("x1 = %lg and x2 = %lg\n", x1, x2);
                break;
        case SS_INF_ROOTS: printf("Any number\n");
                break;
        default: printf("...");
    }

    return 1;
}

bool compare_zero(double x)
{
    const num = 1e-6;
    if (x <= num && x >= -num)
        return 1;
    else
        return 0;
}

int SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    if (a == 0)
    {
        if (b == 0)
        {
            return (c == 0)? SS_INF_ROOTS : 0;
        }
        else // if (a == 0) and  (b != 0)
        {
            *x1 = -c / b;
            return 1;
        }
    }
    else //  if (a != 0)
    {
        double discriminant = b * b - 4 * a * c;

        if (discriminant == 0)
        {
            *x1 = *x2 = -b / (2 * a);
            return 1;
        }
        else
        {
            double sqrt_discriminant = sqrt(discriminant);

            if (discriminant > 0)
            {
                *x1 = (-b - sqrt_discriminant) / ( 2 * a);
                *x2 = (-b + sqrt_discriminant) / ( 2 * a);
                return 2;
            }
            else
            {
                return 0;
            }

        }
    }
}
