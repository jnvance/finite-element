#include <stdio.h>
#include <stdlib.h>

#include "matrix_tools.h"
#include "vector_tools.h"
#include "solver.h"

void matrix_vector_tests();
void solver_tests();

int main(int argc, char const *argv[]){
    // matrix_vector_tests();
    solver_tests();

    return 0;
}


void solver_tests(){

    printf("\n****** Tests for solver ****** \n\n" );
    const int n  = 3;

    printf("** Generate a positive semi-definite symmetric matrix A **\n" );
    matrix_t A;
    allocate_m(&A, n, n);
    double Adata[9] = {2,-1,0,-1,2,-1,0,-1,2};
    // double Adata[4] = {4,1,1,3};
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            assign_mij(A,i,j,Adata[i*n+j]);
    print_m(A);

    printf("\n** Generate a vector b **\n" );
    vector_t b;
    allocate_v(&b,n);
    // fill_v(b);
    for (size_t i = 0; i < n; i++) {
        b.data[i] = i+1;
    }
    print_v(b);

    printf("\n** Generate an initial guess vector x **\n" );
    vector_t x;
    allocate_v(&x,n);
    // zero_v(x);
    x.data[0] = 2.0; x.data[1] = 1.0;
    print_v(x);

    double r_tol = 1.0e-10;
    printf("\n** Solve A.x = b with tolerance %e **\n", r_tol);
    conjugategradient(A, b, x, r_tol);

    printf("\n** Solution **\n");
    print_v(x);
}

void matrix_vector_tests(){
    printf("\n****** Tests for matrix_tools and vector_tools ****** \n\n" );
    printf("Matrix M\n" );
    matrix_t M;
    allocate_m(&M, 3, 4);
    fill_m(M);
    print_m(M);

    printf("\nVector v\n" );
    vector_t v;
    allocate_v(&v,4);
    fill_v(v);
    print_v(v);

    printf("\nVector M.v\n" );
    vector_t Mv;
    allocate_v(&Mv,M.m);
    vmult(M,v,&Mv);
    print_v(Mv);

    printf("\nDeallocating M\n" );

    deallocate_m(&M);
    print_m(M);

    printf("\nDeallocating v\n" );

    deallocate_v(&v);
    print_v(v);

    printf("\nDeallocating M.v\n" );

    deallocate_v(&Mv);
    print_v(Mv);
}
