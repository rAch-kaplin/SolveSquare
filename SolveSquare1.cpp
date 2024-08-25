#include<stdio.h>
#include<math.h>
#include<TXLib.h>
#include<assert.h>
#include"SolveSquare.hpp" // TODO: ������ ������� +

const double inaccuracy = 1e-6;

int main(void)
{

    allTests();

    printf("#Square Solver! by rAch-kaplin\n");

    printf("#Enter a b c: ");

    double a = NAN, b = NAN, c = NAN;

    bufferScanf(&a, &b, &c);

    double x1 = NAN, x2 = NAN;

    NRoots roots_count = SolveSquare(a, b, c, &x1, &x2); // + TODO: �������� ����� � ������� �����, ����� enum �� ������
    // TODO: + ��� �������� ���������� � ����� �����
    printRoots(roots_count, x1, x2); // TODO: ������������ ������������ �������� +

    return 0;
}



NRoots SolveSquare(double a, double b, double c, double *x1, double *x2) // TODO: ����� enum..  +
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
    else //  if (a != 0)
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



void skipLine()
{
    int symbol = 0; // TODO: �������������������� ���������� � �������� �������� +
    while ((symbol = getchar()) != '\n' && symbol != EOF && symbol != '\t'); // TODO: ��������� ���

}

void bufferScanf(double *a, double *b, double *c)
{
    printf("Enter a, b, c or enter (q) - close program\n"); // TODO: ���������

    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {
            printf("error - a, b, c\n");
            printf("Enter a, b, c again: ");
            skipLine();
    }
}



int compareDoubles(double a, double b) // TODO: ����� compareDoubles +
{
        if (fabs(a - b) > inaccuracy) // TODO: � ��������� +
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

int solveLinearSquare(double b, double c, double * x1)
{
    if (isZero(b))
    {
        return (isZero(c))? SS_INF_ROOTS : ZERO_ROOT;  // + TODO: � ��������� ������� ������� ��������� ���������
    }
    else // if (a == 0) and  (b != 0)
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }
}


int printRoots(NRoots roots_count, double x1, double x2)
{
    switch(roots_count)
    {
        case ZERO_ROOT:
            printf("No roots\n"); // TODO: ��������� �� �������� +
            break;
        case ONE_ROOT:
            printf("x = %lg\n", x1);
            break;
        case TWO_ROOT:
            printf("x1 = %lg and x2 = %lg\n", x1, x2);
            break;
        case SS_INF_ROOTS:
            printf("Any number\n");
            break;
        default:
            printf("main() ERROR");
            return 1; // TODO: ������ ����� +
     }
     return 0; // TODO: ��� ������������� �������� +
}

