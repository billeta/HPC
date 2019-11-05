#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>
int main() {
  int val=0;
  printf("Value before : %d\n", val);
#pragma omp parallel default(none) private(val)
  {
    val = rand(); // Pick a random number (integer)
#pragma omp barrier
    printf("My value (thread %d) : %d\n",
           omp_get_thread_num(), val);
  }
  printf("Value after : %d\n", val);
  return 0;
}

