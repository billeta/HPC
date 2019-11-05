#include <stdio.h>
#include <omp.h>
int main()
{
#pragma omp parallel
printf("Hello, World! I'm thread #%d in a group of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
printf("Hello, World! I'm thread #%d in a group of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
return 0;
}

