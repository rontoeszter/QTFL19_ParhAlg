#include <omp.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int N_VALUES = 10000;

/**
 * Generate the data for experimentation.
 */
double* generate_data(unsigned long size)
{
  double* data;
  int i;

  data = (double*)malloc(size * sizeof(double));
  for (i = 0; i < size; ++i) {
    data[i] = (double)(rand()) / RAND_MAX;
  }

  return data;
}

/**
 * Reduction
 */
int main(int argc, char* argv[])
{
  int thread_id;
  double* values;
  double s;
  int i;

  values = generate_data(N_VALUES);
  s = 0.0;
  // #pragma omp parallel for reduction (+:s)
  for (i = 0; i < N_VALUES; ++i) {
    s += values[i];
  }
  printf(":: Sum = %lf\n", s);
  free(values);

  return 0;
}

// #pragma omp single
