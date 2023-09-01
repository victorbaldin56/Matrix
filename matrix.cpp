#include <stdio.h>
#include <assert.h>
#include "matrix.h"

/**
 * 
*/
static void getpoint(size_t x, size_t y, Matrix *mtx1, Matrix *mtx2, Matrix *resmtx);

/**
 * 
*/
static double getelm(size_t x, size_t y, Matrix *mtx);

void PrintMtx(Matrix *mtx, FILE *stream) {
    for (size_t y = 0; y < mtx->size_y; y++) {
        for (size_t x = 0; x < mtx->size_x; x++) {
            fprintf(stream, "%6.lf ", getelm(x, y, mtx));
        }
        
        fputc('\n', stream);
    }
}

Matrix *MltpMtx(Matrix *mtx1, Matrix *mtx2, Matrix *res) {
    assert(mtx1);
    assert(mtx2);
    
    if (mtx1->size_x != mtx2->size_y) {
        return NULL;
    }

    res->size_x = mtx2->size_x;
    res->size_y = mtx1->size_y;

    for (size_t y = 0; y < mtx1->size_y; y++) {
        for (size_t x = 0; x < mtx2->size_x; x++) {
            getpoint(x, y, mtx1, mtx2, res);  
        }
    }

    return res;
}

static void getpoint(size_t x, size_t y, Matrix *mtx1, Matrix *mtx2, Matrix *resmtx) {
    assert(resmtx->matptr);
    double sum = 0;

    for (size_t k = 0; k < mtx1->size_x; k++) {
        sum += getelm(k, y, mtx1) * getelm(x, k, mtx2); 
    }

    *(resmtx->matptr + y * resmtx->size_x + x) = sum;
}

static double getelm(size_t x, size_t y, Matrix *mtx) {
    return *(mtx->matptr + y * mtx->size_x + x);
}
