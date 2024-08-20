// SolveSquare programm

#include<stdio.h>
#include<math.h>
#include<TXLib.h>

const int SS_INF_ROOTS = -1;

bool is_zero(double x);

int SolveSquare( double a, double b, double c, double *x1, double *x2);

int main(void){
    printf("#Square Solver! by rAch-kaplin\n");

    printf("#Enter a b c: ");

    double a = NAN, b = NAN, c = NAN;
    scanf("%lg %lg %lg", &a, &b, &c);


    double x1 = NAN, x2 = NAN;
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
        default: printf("main() ERROR");
            return 1;
    }

    return 0;
}

bool is_zero(double x)
{
    const double num = 1e-6;
    if (x <= num && x >= -num)
        return 1;
    else
        return 0;
}

int SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    if (is_zero(a))
    {
        if (is_zero(b))
        {
            return (is_zero(c))? SS_INF_ROOTS : 0;
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

        if (is_zero(discriminant))
        {
            *x1 = *x2 = -b / (2 * a);
            return 1;
        }
        else
        {

            if (discriminant > 0)
            {
                double sqrt_discriminant = sqrt(discriminant);
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
