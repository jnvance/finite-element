#ifndef SOLVERDEF
#define SOLVERDEF


void conjugategradient();

void residual(vector_t r_in, double alpha, matrix_t A, vector_t x, vector_t* r_out_p);




#endif
