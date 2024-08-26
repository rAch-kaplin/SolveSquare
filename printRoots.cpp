#include<stdio.h>
#include<math.h>
#include<TXLib.h>
#include<assert.h>
#include"SolveSquare.hpp"

void skipLine()
{
    int symbol = 0; // TODO: неинициализированная переменная и название поменять +
    while ((symbol = getchar()) != '\n' && symbol != EOF && symbol != '\t'); // TODO: проверить таб

}

void bufferScanf(double *a, double *b, double *c)
{
    printf("Enter a, b, c or enter (q) - close program\n");

    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {
            printf("error - a, b, c\n");
            printf("Enter a, b, c again: ");
            skipLine();
    }
}


int printRoots(NRoots roots_count, double x1, double x2)
{
    switch(roots_count)
    {
        case ZERO_ROOT:
            printf("No roots\n"); // TODO: остальное по аналогии +
            break;
        case ONE_ROOT:
            printf("x = %lg\n", x1);
            break;
        case TWO_ROOT:
            printf("x1 = %lg and x2 = %lg\n", x1, x2);
            break;
        case SS_INF_ROOTS:
            printf("Any number\n");
            break;
        default:
            printf("main() ERROR");
            return 1; // TODO: скобка криво +
     }
     return 0; // TODO: нет возвращаемого значения +
}
