#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#define LARGENUMBER 1e20
#define N 1000000
#define SMALL 10000  // arbitrary
#define NREP 100  // arbitrary

#define min(a,b) ((a)<(b))?(a):(b)

void init(float *t, int n)
{
  // Initialisation
  srand(0);
  float s=LARGENUMBER;
  for(int i=0;i<N;i++) {
    t[i] = -1.0+2.0*(rand()/((float)RAND_MAX));
    s = min(s,fabs(t[i]));
  }
}

static float minabs_seq(float *t, int n) {
    int i;
    for(i=n-2;i>=0;i--)
      t[i] = min(fabs(t[i]),fabs(t[i+1]));
    return t[0];
}

int main(int argc, char *argv[argc])
{
  float t[N], m;
  double time;
  int l;

  // Sequential reduction
  m=0.0;
  init(t,N);
  time = omp_get_wtime();
  for (l=0; l<NREP; l++)
    m = minabs_seq(t, N);
  time = omp_get_wtime() - time;
  if(NREP>1)
    printf("Sequentiel    %lf s\n", time/(1.0*NREP));
  else
    printf("Sequentiel    %lf s (min=%g)\n", time/(1.0*NREP), m);

  return 0;
}

