#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "matrix_tools.h"

void print_m(matrix_t M){
    printf("rows = %d\t", (int)M.m );
    printf("cols = %d\n", (int)M.n );

    for (size_t i = 0; i < M.m; i++) {
        for (size_t j = 0; j < M.n; j++) {
            printf("%f\t", M.data[i*M.n+j]  );
        }
    printf("\n" );
    }
}

void allocate_m(matrix_t* M_p, size_t m, size_t n){
    matrix_t M;
    M.m = m;
    M.n = n;

    double * data;
    data = (double*)malloc(m*n*sizeof(double));
    M.data = data;

    *M_p = M;
}

void deallocate_m(matrix_t* M_p){
    free(M_p -> data);
    M_p -> m = 0;
    M_p -> n = 0;
}

void assign_mij(matrix_t M, size_t i, size_t j, double val){
    M.data[i*M.n+j] = val;
}

void fill_m(matrix_t M){
    for (size_t i = 0; i < M.m; i++) {
        for (size_t j = 0; j < M.n; j++) {
            assign_mij(M,i,j,(double)(i+j));
        }
    }
}

void vmult(matrix_t M, vector_t v_in, vector_t* v_out_p ) {
    assert(M.n == v_in.size);
    vector_t v_out;
    allocate_v(&v_out,M.m);
    // v_out.size = M.m;
    for (size_t i = 0; i < M.m; i++) {
        double vi = 0;
        for (size_t j = 0; j < M.n; j++) {
            vi += M.data[i*M.n+j]*v_in.data[j];
        }
        assign_vi(v_out,i,vi);
    }
    *v_out_p = v_out;
}
