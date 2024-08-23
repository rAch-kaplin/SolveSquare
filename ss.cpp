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

struct UNIT_variables
{
    int numberTest;
    double a;
    double b;
    double c;
    double x1Correct;
    double x2Correct;
    enum nRoots rootsCountCorrect;

};

const double num = 1e-6;

void AllTests();

void RunTest(struct UNIT_variables data);

int print_roots(int rootsCount, double x1, double x2);

void SkipLine();
int input_coef();

bool is_zero(double x);
int CompareDoubles(double a, double b);



void buffer_scanf(double *a, double *b, double *c);


enum nRoots SolveSquare( double a, double b, double c, double *x1, double *x2);




int main(void)
{

//    AllTests();

    struct UNIT_variables data1 = {1, -3, 2, 2, 1, TWO_ROOT};

    struct UNIT_variables data2 = {1, -5, 6, 3, 2, TWO_ROOT};

    struct UNIT_variables data3 = {1, 2, 1, -1, -1, ONE_ROOT};

    struct UNIT_variables data4 = {1, 0, -9, -3, 3, TWO_ROOT};

    struct UNIT_variables data5 = {1, 0, 0, 0, 0, ONE_ROOT};

    RunTest(data1);
    RunTest(data2);
    RunTest(data3);
    RunTest(data3);
    RunTest(data4);
    RunTest(data5);


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
    while ((line = getchar()) != '\n' && line != EOF);

}

void buffer_scanf(double *a, double *b, double *c)
{
    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {
        printf("error - a, b, c\n");
        printf("Enter a, b, c again: ");
        SkipLine();
    }

}

void RunTest(struct UNIT_variables data)
{
    double x1 = NAN, x2 = NAN;
    enum nRoots rootsCount = SolveSquare(data.a, data.b, data.c, &x1, &x2);
    if (CompareDoubles(rootsCount, data.rootsCountCorrect) || CompareDoubles(x1, data.x1Correct) || CompareDoubles(x2, data.x2Correct))
    {
        if (CompareDoubles(x1, data.x2Correct) || CompareDoubles(x2, data.x1Correct))
        {
            printf("ERROR numberTest = %d, a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, rootsCount = %d\n"
            "x1Correct = %lg, x2Correct = %lg, rootsCountCorrect = %d\n", data.numberTest,
            data.a, data.b, data.c, x1, x2, rootsCount, data.x1Correct, data.x2Correct,
            data.rootsCountCorrect);
        }
        else
        {
            printf("test successfull\n");
        }
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
//


//
//    const int nTests = 3;
//
//    double a[nTests] = {1, 1, 1};
//    double b[nTests] = {2, 0, 0};
//    double c[nTests] = {3, -4, 1};
//    double x1Correct[nTests] = {NAN, -2, 0};
//    double x2Correct[nTests] = {NAN, 2, NAN};
//    int rootsCountCorrect[nTests] = {0, 2, 1};
//
//    for (int i = 0; i < nTests; i++)
//        RunTest(i, a[i], b[i], c[i], x1Correct[i], x2Correct[i], rootsCountCorrect[i]);
//
//}
