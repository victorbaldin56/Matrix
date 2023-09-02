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
void PrintMtx(const Matrix *mtx, FILE *stream);

/**
 * 
*/
Matrix *MltpMtx(const Matrix *mtx1, const Matrix *mtx2, Matrix *res);


#endif // MATRIX