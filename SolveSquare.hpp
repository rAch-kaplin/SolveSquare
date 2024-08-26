 // TODO: прочитай про include guard

enum NRoots
{
    ZERO_ROOT    =  0,
    ONE_ROOT     =  1,
    TWO_ROOT     =  2,
    SS_INF_ROOTS = -1
};

struct UNIT_variables
{
    double a;
    double b;
    double c;
    double x1Correct;
    double x2Correct;
    enum NRoots rootsCountCorrect;

};

//void allTests();
//
//int runTest(struct UNIT_variables data, int test_number);

//int printRoots(NRoots roots_count, double x1, double x2);

//void skipLine();
//
//void bufferScanf (double *a, double *b, double *c);

//bool isZero (double x);
//
//int compareDoubles (double a, double b);

NRoots SolveSquare ( double a, double b, double c, double *x1, double *x2);

int solveLinearSquare (double b, double c, double * x1);



