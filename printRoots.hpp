#ifndef H_PRINTROOTS
#define H_PRINTROOTS
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

#endif // H_PRINTROOTS

