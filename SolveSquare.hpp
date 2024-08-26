 // TODO: прочитай про include guard
 #ifndef H_SOLVESQUARE
 #define H_SOLVESQUARE

enum NRoots
{
    ZERO_ROOT    =  0,
    ONE_ROOT     =  1,
    TWO_ROOT     =  2,
    SS_INF_ROOTS = -1
};


int printRoots(NRoots roots_count, double x1, double x2);

void skipLine();

void bufferScanf (double *a, double *b, double *c);

NRoots SolveSquare (double a, double b, double c, double *x1, double *x2);

NRoots solveLinearSquare (double b, double c, double * x1);

#endif // H_SOLVESQUARE



