#include <stdio.h>
#include <math.h>
#include <omp.h>

float main(void) 
{ 
   float a;
   float b;
   float N;
   float first;
   float midPoint;
   int i;
   float carre;

   N=10000;
   a=0;
   b=1;
   midPoint=0;

   first=((b-a)/N);
   #pragma omp parallel default(none) shared(N, a, b) private(i, carre) reduction(+:midPoint)

   #pragma for schedule(runtime)
   for(i=0; i <= (N-1); i++){
      carre = (1/(1+(a+(i+(1/2))*((b-a)/N))*(a+(i+(1/2))*((b-a)/N))));
      midPoint += carre;
   }
  
   midPoint = first*midPoint;

   printf("The approximate value is %f\n", midPoint);
      
   
    return 0; 
} 
