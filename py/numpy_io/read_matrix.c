#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr;

    int i;
    double* buffer;

    buffer = malloc(16*sizeof(double));

    ptr = fopen("np_array","rb");

    fread(buffer,16*sizeof(double),1,ptr);
    
    printf("size of buffe %ld \n", sizeof(buffer));
    printf("size of buffe %ld \n", 16*sizeof(double));

    for(i = 0; i<16; i++)
        printf("%e \n", buffer[i]);

    free(buffer);

    fclose(ptr);
    return 0;
}
