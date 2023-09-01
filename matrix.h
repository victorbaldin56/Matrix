#ifndef MATRIX
#define MATRIX

#include <stdio.h>

/**
 * 
*/
typedef struct {
    double *matptr;
    size_t size_x;
    size_t size_y;
} Matrix;

/**
 * 
*/
void PrintMtx(Matrix *mtx, FILE *stream);

/**
 * 
*/
Matrix *MltpMtx(Matrix *mtx1, Matrix *mtx2, Matrix *res);


#endif // MATRIX