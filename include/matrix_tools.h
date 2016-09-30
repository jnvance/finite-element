#ifndef MATRIXDEF
#define MATRIXDEF

#include "vector_tools.h"

typedef struct{
    size_t m; // rows
    size_t n; // columns
    double * data;
} matrix_t;

void print_m(matrix_t M);

void allocate_m(matrix_t* M_p, size_t m, size_t n);

void deallocate_m(matrix_t* M_p);

void assign_mij(matrix_t M, size_t i, size_t j, double val);

void fill_m(matrix_t M);

void vmult(matrix_t M, vector_t v_in, vector_t* v_out_p);

#endif
