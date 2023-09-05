#ifndef MATRIX
#define MATRIX

#include <stdio.h>

/**
 * @brief This structure includes:
 * @param matptr pointer to a 2D double array
 * @param size_x horizontal size
 * @param size_y vertical size
*/
typedef struct {
    double *matptr;
    size_t size_x;
    size_t size_y;
} Matrix;

/**
 * @brief Prints matrix to selected file
 * @param mtx pointer to a Matrix structure
 * @param stream pointer to a target file
*/
void PrintMtx(const Matrix *mtx, FILE *stream);

/**
 * @brief Multiplies 2 matrix if possible
 * @param mtx1 the first factor
 * @param mtx2 the second factor
 * @param res the final result of multiplying mtx1 and mtx2
 * @return NULL if mtx1 and mtx2 are uncompatible; in normal case res
*/
Matrix *MltpMtx(const Matrix *mtx1, const Matrix *mtx2, Matrix *res);

/**
 * @param mtx source matrix (must be square)
 * @param res the result of mtx to the power of n
 * @param pwr power
*/
Matrix *PwrMtx(const Matrix *mtx, Matrix *res, const size_t pwr);

/**
 * @brief This structure includes:
 * @param score pointer to a simple array, in this case used as score triangle table
 * @param nteams the number of members in this score table
*/
typedef struct {
    double *score;
    size_t nteams;
} ScoreTable;

/**
 * @brief Finds a score of 2 members in ScoreTable structures
 * @param x the first member
 * @param y the second member
 * @param table a sample of ScoreTable structure
 * @return pointer to cell with score
*/
double *getscore(size_t x, size_t y, const ScoreTable *table);

/**
 * @brief Sets score of 2 selected members
 * @param x the first member
 * @param y the second member
 * @param table a sample of ScoreTable structure
 * @param val the score to set
*/
double *setscore(size_t x, size_t y, ScoreTable *table, double val);

/**
 * @brief Prints score table as a tringle to file
 * @param table a sample of ScoreTable structure
 * @param stream pointer to a target file
*/
void PrintTriangle(const ScoreTable *table, FILE *stream);


#endif // MATRIX