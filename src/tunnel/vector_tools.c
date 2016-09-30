#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "vector_tools.h"

void print_v(vector_t v){
    printf("size = %d\n", (int)v.size );
    for (size_t i = 0; i < v.size; i++) {
        printf("%f\t", v.data[i] );
    }
    printf("\n");
}

void allocate_v(vector_t* v_p, size_t size){
    vector_t v;
    v.size = size;

    double * data;
    data = (double*)malloc(size*sizeof(double));
    v.data = data;

    *v_p = v;
}

void deallocate_v(vector_t* v_p){
    free(v_p -> data);
    v_p -> size = 0;
}

void assign_vi(vector_t v, size_t i, double val){
    v.data[i] = val;
}

void fill_v(vector_t v){
    for (size_t i = 0; i < v.size; i++) {
        assign_vi(v,i,(double)i);
    }
}

void zero_v(vector_t v){
    for (size_t i = 0; i < v.size; i++) {
        assign_vi(v,i,0.0);
    }
}

void ones_v(vector_t v){
    for (size_t i = 0; i < v.size; i++) {
        assign_vi(v,i,1.0);
    }
}

void copy_v(vector_t v_in, vector_t* v_out_p){
    assert(v_in.size == v_out_p -> size);
    for (size_t i = 0; i < v_in.size; i++) {
        v_out_p -> data[i] = v_in.data[i];
    }
} // like dump_b_into_a

double v_dot_prod(vector_t a_in, vector_t b_in){
    assert(a_in.size == b_in.size);
    double dot_prod = 0.0;
    for (size_t i = 0; i < a_in.size; i++) {
        dot_prod += a_in.data[i] * b_in.data[i];
        // printf("%f\t%f\n",a_in.data[i] * b_in.data[i],dot_prod);
    }
    return dot_prod;
}

// a + b*c = d
void v_sca_prod_sum(vector_t a_in, double b_in, vector_t c_in, vector_t* d_out){
    for (size_t i = 0; i < a_in.size; i++) {
        (d_out -> data[i]) = a_in.data[i] + b_in * c_in.data[i];
    }
}

double v_norm(vector_t v){
    double dot_prod = sqrt( v_dot_prod(v,v) );
    return dot_prod;
}
