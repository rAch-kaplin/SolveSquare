 #ifndef H_RUN_TEST
 #define H_RUN_TEST
 #include "SolveSquare.hpp"

struct UNIT_variables
{
    double a;
    double b;
    double c;
    double x1Correct;
    double x2Correct;
    enum NRoots rootsCountCorrect;

};

void allTests();

int runTest(struct UNIT_variables data, int test_number);

#endif //H_RUN_TEST
