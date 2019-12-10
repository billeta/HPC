#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>
#define n 500



int main(void)
{
  // creating the matrix
  float *matrix1 = calloc(n*n, sizeof(float));
  float *matrix2 = calloc(n*n, sizeof(float));
  float *matrix3 = calloc(n*n, sizeof(float));


  // filling up the matrix with 1s to test the product
  // If there product are a 4*4 matrix of 4, the computation is right
  //for (int i=0; i<n; i++){
  //  for (int j=0; j<n; j++){
  //      matrix1[4*i+j] = 1;
  //      matrix2[4*i+j] = 1;
  //  }
  //}

  //Randomly initialize the first matrix
  srand(time(NULL));
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        matrix1[i*n+j] = rand()/((float)RAND_MAX);
    }
  }

  //initialize the identity matrix
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        if (i==j){
           matrix2[i*n+j] = 1;
        }
        else{
           matrix2[i*n+j] = 0;
        }
    }
  }
  
  
  float t1 = omp_get_wtime(); //Gather the current time
  
  //for (int t=0; t<1000; t++){ //create a loop to compute the average time

  // Performing the matrix product
  for (int x = 0; x < n; x++) { 
    for (int y = 0; y < n; y++) {
        matrix3[4*x+y] = 0; //set to 0 the element of matrix 3
        #pragma omp parallel reduction(+:matrix3[:(n*n)])
        {
        #pragma omp for 
        for (int z = 0; z < n; z++) { 
            matrix3[4*x+y] += matrix1[4*x+z] * matrix2[4*z+y];
        }
        }
        // print out the results of one computation
        printf("%f ", matrix3[4*x+y]);
    }
    printf("\n");
  }
  //}
  float t2 = omp_get_wtime(); //Gather the after computation time
  //float total = (t2 - t1)/(float) 1000; //Compute average time
  float total = (t2 - t1);

  printf("The average computational time for one iteration is: %f\n", total);
}
