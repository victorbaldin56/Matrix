#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"

/**
 * 
*/
static void getpoint(size_t x, size_t y, const Matrix *mtx1, const Matrix *mtx2, Matrix *resmtx);

/**
 * 
*/
static double getelm(size_t x, size_t y, const Matrix *mtx);

static void swap(size_t a, size_t b);

void PrintMtx(const Matrix *mtx, FILE *stream) {
    for (size_t y = 0; y < mtx->size_y; y++) {
        for (size_t x = 0; x < mtx->size_x; x++) {
            fprintf(stream, "%6.lf ", getelm(x, y, mtx));
        }
        
        fputc('\n', stream);
    }
}

Matrix *MltpMtx(const Matrix *mtx1, const Matrix *mtx2, Matrix *res) {
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

double *getscore(size_t x, size_t y, const ScoreTable *table) {
    assert(table);
    assert(table->score);

    if (x > table->nteams || y > table->nteams || x == y) {
        return NULL;
    }

    if (x < y) {
        swap(x, y);
    }

    x--;
    size_t offset = x * (x + 1) / 2 + y;
    return table->score + offset;
}

void PrintTriangle(const ScoreTable *table, FILE *stream) {
    assert(table);
    assert(table->score);

    for (size_t x = 0; x < table->nteams; x++) {
        for (size_t y = 0; y < x; y++) {
            fprintf(stream, "%6.lf ", *getscore(x, y, table));
        }

        fputc('\n', stream);
    }
}

double *setscore(size_t x, size_t y, ScoreTable *table, double val) {
    double *ptr = getscore(x, y, table); 
    *ptr = val;
    return ptr; 
}

static void getpoint(size_t x, size_t y, const Matrix *mtx1, const Matrix *mtx2, Matrix *resmtx) {
    assert(resmtx->matptr);
    double sum = 0;

    for (size_t k = 0; k < mtx1->size_x; k++) {
        sum += getelm(k, y, mtx1) * getelm(x, k, mtx2); 
    }

    *(resmtx->matptr + y * resmtx->size_x + x) = sum;
}

static double getelm(size_t x, size_t y, const Matrix *mtx) {
    return *((double *)((size_t)mtx->matptr + sizeof(double) * (y * mtx->size_x + x)));
}

static void swap(size_t a, size_t b) {
    size_t tmp = a;
    a = b;
    b = tmp;
}
