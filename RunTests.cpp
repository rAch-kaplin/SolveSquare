#include<stdio.h>
#include<math.h>
#include<TXLib.h>
#include<assert.h>
#include"SolveSquare.hpp"

void AllTests()
{
    const int nTests = 8;

    struct UNIT_variables data[nTests] = {{1, -3, 2, 2, 1, TWO_ROOT},
                                          {1, -5, 6, 3, 2, TWO_ROOT},
                                          {1, 2, 1, -1, -1, ONE_ROOT},
                                          {1, 0, -9, -3, 3, TWO_ROOT},
                                          {1, 0, 0, 0, 0, ONE_ROOT},
                                          {1, 2, 3, NAN, NAN, ZERO_ROOT},
                                          {1, 0, -4, -2, 2, TWO_ROOT},
                                          {1, 0, 0, 0, NAN, ONE_ROOT}};


    for (int i = 0; i < nTests; i++)
        RunTest(data[i]);

//    double a[nTests] = {1, 1, 1, 1, 1, 1, 1, 1};
//    double b[nTests] = {-3, -5, 2, 0, 0, 2, 0, 0};
//    double c[nTests] = {2, 6, 1, -9, 0, 3, -4, 1};
//    double x1Correct[nTests] = {2, 3, -1, -3, 0, NAN, -2, 0};
//    double x2Correct[nTests] = {1, 2, -1, 3, 0, NAN, 2, NAN};
//    int rootsCountCorrect[nTests] = {TWO_ROOT, TWO_ROOT, ONE_ROOT, TWO_ROOT, ONE_ROOT, ZERO_ROOT, TWO_ROOT, ONE_ROOT};

 }


 void RunTest(struct UNIT_variables data)
{
    double x1 = NAN, x2 = NAN;
    enum nRoots rootsCount = SolveSquare(data.a, data.b, data.c, &x1, &x2);
    if (CompareDoubles(rootsCount, data.rootsCountCorrect) || CompareDoubles(x1, data.x1Correct) ||
       CompareDoubles(x2, data.x2Correct))
    {
        if (CompareDoubles(x1, data.x2Correct) || CompareDoubles(x2, data.x1Correct))
        {
            printf("ERROR a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, rootsCount = %d\n"
                   "x1Correct = %lg, x2Correct = %lg, rootsCountCorrect = %d\n",
            data.a, data.b, data.c, x1, x2, rootsCount, data.x1Correct, data.x2Correct,
            data.rootsCountCorrect);
        }
        else
        {
            printf("test successfull\n");
        }
    }

}
