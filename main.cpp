#include <stdio.h>
#include <assert.h>
#include "matrix.h"

int main() {
    const size_t size_x1 = 5, size_y1 = 5;
    const size_t size_x2 = 1, size_y2 = 5;
    double sample1[size_y1][size_x1] = 
    {{ 0,  1,  2,  3,  4},
     {10, 11, 12, 13, 14},
     {20, 21, 22, 23, 24},
     {30, 31, 32, 33, 34},
     {40, 41, 42, 43, 44}
    };
    double sample2[size_y2][size_x2] =
    {{1},
     {2},
     {3},
     {4},
     {5}};
    double ans[size_y1][size_x2] = {{}};
    Matrix matrix1 = 
    {(double *)&sample1,
     size_x1,
     size_y1,};

    Matrix matrix2 = 
    {(double *)&sample2,
     size_x2,
     size_y2,};

    Matrix res = 
    {(double *)&ans};

    printf("Printing matrix1:\n");
    PrintMtx(&matrix1, stdout);

    printf("Printing matrix2:\n");
    PrintMtx(&matrix2, stdout);
    
    printf("MltpMtx:\n");
    PrintMtx(MltpMtx(&matrix1, &matrix2, &res), stdout);

    double score[] = 
        {100,
         200, 300,
         400, 500, 600,
         700, 800, 900, 1000};

    ScoreTable table = 
    {score,
     5};
    printf("Printing ScoreTable sample:");
    PrintTriangle(&table, stdout);
    //printf("end printing\n");
    //printf("score(2, 3) = %lf\n", getscore(2, 3, &table));
    return 0;
}