const double num = 1e-6;

enum nRoots {
    ZERO_ROOT = 0,
    ONE_ROOT  = 1,
    TWO_ROOT  = 2,
    SS_INF_ROOTS = -1
};

struct UNIT_variables
{
    double a;
    double b;
    double c;
    double x1Correct;
    double x2Correct;
    enum nRoots rootsCountCorrect;

};


void AllTests();

void RunTest(struct UNIT_variables data);

int print_roots(int rootsCount, double x1, double x2);

void SkipLine();

int input_coef();

void buffer_scanf(double *a, double *b, double *c);

bool is_zero(double x);

int CompareDoubles(double a, double b);

enum nRoots SolveSquare( double a, double b, double c, double *x1, double *x2);



