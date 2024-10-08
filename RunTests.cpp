#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "RunTests.hpp"
#include "compareDoubles.hpp"
#include "SolveSquare.hpp"

void allTests()
{
    const int nTests = 8;

    struct UNIT_variables data[nTests] = {{1,  -3,   2,   1,   2,   TWO_ROOT},
                                          {1,  -5,   6,   3,   2,   TWO_ROOT},
                                          {1,   2,   1,  -1,  -1,   ONE_ROOT},
                                          {1,   0,  -9,  -3,   3,   TWO_ROOT},
                                          {1,   0,   0,   0,   0,   ONE_ROOT},
                                          {1,   2,   3, NAN, NAN,  ZERO_ROOT},
                                          {1,   0,  -4,  -2,   2,   TWO_ROOT},
                                          {1,   0,   0,   0, NAN,  ONE_ROOT}};


    for (int i = 0; i < nTests; i++)
        runTest(data[i], i);

 }


 int runTest(struct UNIT_variables data, int test_number)
{
    double x1 = NAN, x2 = NAN;
    NRoots roots_count = SolveSquare(data.a, data.b, data.c, &x1, &x2);
    if (compareDoubles(roots_count, data.rootsCountCorrect) || compareDoubles(x1, data.x1Correct) ||
        compareDoubles(x2, data.x2Correct))
    {
        if (compareDoubles(x1, data.x2Correct) || compareDoubles(x2, data.x1Correct))
        {
            printf("ERROR: test ¹ %d, a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, rootsCount = %d\n"
                   "x1Correct = %lg, x2Correct = %lg, rootsCountCorrect = %d\n", test_number,
            data.a, data.b, data.c, x1, x2, roots_count, data.x1Correct, data.x2Correct,
            data.rootsCountCorrect);
            return 1;
        }

    }

    return 0;
}
