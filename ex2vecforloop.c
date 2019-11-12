#include <stdio.h>
#include <omp.h>

float main(void) 
{ 
    int size = 100;
  
    // array and counter declaration 
    float array1[size];
    float array2[size];
    float array3[size];
    int i;
    int tnb;
    int tid;

    for (i = 0; i < size ; i++){ 
        array1[i] = (i*1.0)/(size*1.0);
        array2[i] = (i*2*1.0)/(size*1.0);
    } 

    
    
    
    // initializing array elements of the arrays
    #pragma omp parallel shared(tnb)
    {
       tnb = omp_get_num_threads();
       int counter[tnb];


  
    // computing the third array
       #pragma omp for schedule(guided, 20)
       for (i = 0; i < size ; i++){
           array3[i] = array1[i] + array2[i];
           // increment the counter
           tid = omp_get_thread_num();

           counter[tid] = counter[tid] + 1;
       }
       
     // print the threads computation
     for (i = 0; i < tnb; i++){     
         printf("The thread number %d computes %d iterations \n", i, counter[i]);
     }  

     }

    return 0; 
} 
