// SolveSquare programm

#include<stdio.h>
#include<math.h>
#include<TXLib.h>
#include<assert.h>

enum nRoots {
    ZERO_ROOT = 0,
    ONE_ROOT  = 1,
    TWO_ROOT  = 2,
    SS_INF_ROOTS = -1
};

void SkipLine();

int RunTest(int numberTest, double a, double b, double c, double x1Correct, double x2Correct, int rootsCountCorrect);

bool is_zero(double x);

int input_coef();


nRoots SolveSquare( double a, double b, double c, double *x1, double *x2);




int main(void)
{
    RunTest(1, 1, 2, -3, 1, -3, 2);
    printf("#Square Solver! by rAch-kaplin\n");

    printf("#Enter a b c: ");

    double a = NAN, b = NAN, c = NAN;
    while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        printf("error - a, b, c\n");
        printf("Enter a, b, c again: ");
        SkipLine();
    }


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
     }       return 1;

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


 //-------------------------------------------------
 //! Solve Square equation ax^2 + bx + c = 0




 //-------------------------------------------------


nRoots SolveSquare(double a, double b, double c, double *x1, double *x2)
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
    while ( (line = getchar()) != '\n' && line != EOF );

}

int RunTest(int numberTest, double a, double b, double c, double x1Correct, double x2Correct, int rootsCountCorrect)
{
    double x1 = 0, x2 = 0;
    int rootsCount = SolveSquare(a, b, c, &x1, &x2);
    if (rootsCount != rootsCountCorrect || x1 != x1Correct || x2 != x2Correct)
    {
        if (x1 != x2Correct || x2 != x1Correct)
        {
        printf("ERROR nTest = ¹%d, a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, rootsCount = %d\n"
        "x1Correct = %lg, x2Correct = %lg, rootsCountCorrect = %d\n", numberTest, a, b, c, x1, x2, rootsCount, x1Correct, x2Correct, rootsCountCorrect);
        }
        else
        printf("test successfull\n");
    }

}
