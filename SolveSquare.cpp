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

struct solveSquare
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    nRoots rootsCount;
};


void RunTest(int numberTest, double a, double b, double c, double x1Correct, double x2Correct, int rootsCountCorrect);



int print_roots(solveSquare roots);

void buffer_scanf(solveSquare * roots);

int input_coef();
void SkipLine();

int CompareDoubles(double a, double b);
bool is_zero(double x);


void SolveSquare(solveSquare * roots);


int main(void)
{
    RunTest(1, 1, 2, -3, 1, -3, 2);
    RunTest(2, 1, -4, 8, 0, 0, 0);
    RunTest(3, 1, 0, -4,-2, 2, 2);

    struct solveSquare roots = {0};

    printf("#Square Solver! by rAch-kaplin\n");

    printf("#Enter a b c: ");


    buffer_scanf(&roots);


    SolveSquare(NULL); //  по-другому считывать количество корней

    print_roots(roots);


    return 0;
}



void SolveSquare(solveSquare * roots)
{
    assert(isfinite(roots->a));
    assert(isfinite(roots->b));
    assert(isfinite(roots->c));
    assert(roots != NULL);

    if (is_zero(roots->a))
    {
        if (is_zero(roots->b))
        {

            roots->rootsCount = (is_zero(roots->c))? SS_INF_ROOTS : ZERO_ROOT;
        }
        else // if (a == 0) and  (b != 0)
        {
            roots->x1 = -(roots->c) / (roots->b);

            roots->rootsCount = ONE_ROOT;
        }
    }
    else //  if (a != 0)
    {
        double discriminant = (roots->b) * (roots->b) - 4 * (roots->a) * (roots->c);

        if (is_zero(discriminant))
        {
            roots->x1 = roots->x2 = -(roots->b) / (2 * (roots->a));
            roots->rootsCount = ONE_ROOT;
        }
        else
        {

            if (discriminant > 0)
            {
                double sqrt_discriminant = sqrt(discriminant);
                roots->x1 = (-(roots->b) - sqrt_discriminant) / ( 2 * (roots->a));
                roots->x2 = (-(roots->b) + sqrt_discriminant) / ( 2 * (roots->a));
                roots->rootsCount = TWO_ROOT;
            }
            else
            {
                roots->rootsCount = ZERO_ROOT;
            }

        }
    }
}



void SkipLine()
{
    int line;
    while ((line = getchar()) != '\n' && line != EOF);

}

void RunTest(int numberTest, double a, double b, double c, double x1Correct, double x2Correct, int rootsCountCorrect)
{

    struct solveSquare equation_test = {a, b, c, NAN, NAN, ZERO_ROOT};
    SolveSquare(&equation_test);

    if (CompareDoubles(equation_test.rootsCount, rootsCountCorrect) || CompareDoubles(equation_test.x1, x1Correct) || CompareDoubles(equation_test.x2, x2Correct))
    {
        if (CompareDoubles(equation_test.x1, x2Correct) || CompareDoubles(equation_test.x2, x1Correct))
        {
            printf("ERROR numberTest = %d, a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, rootsCount = %d\n"
                   "x1Correct = %lg, x2Correct = %lg, rootsCountCorrect = %d\n",
                   numberTest, equation_test.a, equation_test.b, equation_test.c, equation_test.x1, equation_test.x2,
                   equation_test.rootsCount, x1Correct, x2Correct, rootsCountCorrect);
        }
        else
        {
            printf("test successfull\n");
        }
    }

}

void buffer_scanf(solveSquare * roots)
{
    while (scanf("%lg %lg %lg", roots->a, roots->b, roots->c) != 3)
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
    const double num = 1e-6;
    if (x <= num && x >= -num)
        return 1;
    else
        return 0;
}


int print_roots(solveSquare roots)
{
    switch(roots.rootsCount)
    {
        case ZERO_ROOT: printf("No roots\n");
                break;
        case ONE_ROOT: printf("x = %lg\n", roots.x1);
                break;
        case TWO_ROOT: printf("x1 = %lg and x2 = %lg\n", roots.x1, roots.x2);
                break;
        case SS_INF_ROOTS: printf("Any number\n");
                break;
        default: printf("main() ERROR");
     }       return 1;
}
