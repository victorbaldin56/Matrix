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

/**
 * 
*/
typedef struct {
    double *score;
    size_t nteams;
} ScoreTable;

/**
 * 
*/
double getscore(size_t x, size_t y, const ScoreTable *table);

/**
 * 
*/
void PrintTriangle(const ScoreTable *table, FILE *stream);


#endif // MATRIX