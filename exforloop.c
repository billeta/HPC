#include <stdio.h>

float main(void) 
{ 
    int size = 10;
  
    // array declaration 
    float array[size]; 
    int i;
  
    // initializing array elements 
    for (i = 0; i < size ; i++){ 
        array[i] = (i*1.0)/(size*1.0);
    } 
  
     // print array 
     printf("The array is:"); 
     for (i = 0; i < size ; i++){ 
         printf("%f ", array[i]); 
    } 
  
    return 0; 
} 
