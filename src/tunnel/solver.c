#include <stdio.h>
#include <assert.h>

#include "matrix_tools.h"
#include "vector_tools.h"
#include "solver.h"

void conjugategradient(matrix_t A, vector_t b, vector_t x, double r_tol){
    // Inputs:
    // matrix_t A
    // vector_t b
    // vector_t* x_p (pointer to solution container)
    // vector_t x0 (initial guess) default: 0

    // Check sizes
    assert(A.m == A.n);
    assert(A.m == b.size);
    assert(b.size == x.size);

    // int k = 0;
    // printf("\n>>Counter: k = %d\n", k);

    // Initial guess x = 0
    printf("\nSet initial guess to zero\n");
    printf("\nInitial guess\n");
    // zero_v(x);
    print_v(x);


    // Initialize residual vector
    printf("\nInitial residual vector\n");
    vector_t r;
    allocate_v(&r, b.size);
    residual(b,1.0,A,x,&r);
    print_v(r);

    // Initialize conjugate vector
    printf("\nInitial conjugate vector\n");
    vector_t p;
    allocate_v(&p, b.size);
    copy_v(r, &p);
    print_v(p);


    // Iterate from k = 1 onwards
    double alpha;
    double beta;
    vector_t Ap;
    allocate_v(&Ap, b.size);

    vector_t r1;
    allocate_v(&r1, b.size);

    double r1_norm = 1e10;

    for (size_t k = 0; k < b.size + 1 && r1_norm > r_tol; k++) {
        printf("\n>>Counter: k = %d\n", (int)k);
        vmult(A,p,&Ap);

        alpha = v_dot_prod(r, r) / v_dot_prod(p,Ap);
        printf("\nalpha = %f\n",alpha);

        printf("\nx: \n");
        v_sca_prod_sum(x, alpha, p, &x); // x = x_k + a_k p_k
        print_v(x);

        printf("\nr1: \n");
        v_sca_prod_sum(r, -alpha, Ap, &r1); // r_(k+1) = r_k - a_k A p_k
        print_v(r1);

        r1_norm = v_norm(r1);
        printf("\n|r1| = %f\n", r1_norm );

        beta = v_dot_prod(r1,r1) / v_dot_prod(r,r);
        printf("\nbeta = %f\n", beta );

        printf("\np_next: \n");
        v_sca_prod_sum(r1, beta, p, &p); // p_(k+1) = r_(k+1) + b_k p_k
        print_v(p);

        copy_v(r1,&r);
    }




}

void residual(vector_t r_in, double alpha, matrix_t A,
              vector_t x,    vector_t* r_out_p){
    vmult(A, x, r_out_p);
    for (size_t i = 0; i < r_out_p -> size; i++) {
        r_out_p -> data[i] = r_in.data[i] - alpha * (r_out_p -> data[i]);
    }
}
