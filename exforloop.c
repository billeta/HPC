#include <stdio.h>
#include <omp.h>

float main(void) 
{ 
    int size = 10;
  
    // array declaration 
    float array[size]; 
    int i;
  
    // initializing array elements 
    #pragma omp parallel for 
    for (i = 0; i < size ; i++){ 
        array[i] = (i*1.0)/(size*1.0);
        printf("I'm thread  number %d in a group of %d threads computing the %dth number \n", omp_get_thread_num(), omp_get_num_threads(), i);
    } 
  
     // print array 
     printf("The array is:"); 
     for (i = 0; i < size ; i++){ 
         printf("%f ", array[i]); 
    } 
  
    return 0; 
} 
