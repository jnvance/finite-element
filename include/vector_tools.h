#ifndef VECTORDEF
#define VECTORDEF

typedef struct{
    size_t size;
    double * data;
} vector_t;

void print_v(vector_t v);

void allocate_v(vector_t* v_p, size_t size);

void deallocate_v(vector_t* v_p);

void assign_vi(vector_t v, size_t i, double val);

void fill_v(vector_t v);

void zero_v(vector_t v);

void ones_v(vector_t v);

void copy_v(vector_t v_in, vector_t* v_out_p);

double v_dot_prod(vector_t a_in, vector_t b_in);

void v_sca_prod_sum(vector_t a_in, double b_in, vector_t c_in, vector_t* d_out);

double v_norm(vector_t v);

#endif
