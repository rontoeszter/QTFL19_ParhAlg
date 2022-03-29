#include <omp.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int N_SLEEPS = 6;

/**
 * No wait!
 */
int main(int argc, char* argv[])
{
  int thread_id;
  int wait_time;
  int i;
  #pragma omp parallel private (thread_id, wait_time)
  {
    #pragma omp for
    for (i = 0; i < N_SLEEPS; ++i) {
      thread_id = omp_get_thread_num();
      wait_time = rand() % 10 + 1;
      printf("[%d] Wait %d seconds ... (%d)\n", thread_id, wait_time, i + 1);
      sleep(wait_time);
      printf("[%d] Ok.\n", thread_id);
    }
    printf("[%d] Beyond.\n", thread_id);
  }
  printf(":: Ready!\n");

  return 0;
}

// #pragma omp for nowait
