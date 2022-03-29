#include <omp.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Implicit barrier
 */
int main(int argc, char* argv[])
{
  printf(":: Start!\n");
  #pragma omp parallel
  {
    int thread_id;
    int wait_time;
    wait_time = rand() % 10 + 1;
    thread_id = omp_get_thread_num();
    printf("[%d] Wait %d seconds ...\n", thread_id, wait_time);
    sleep(wait_time);
    printf("[%d] Ok.\n", thread_id);
  }
  printf(":: Ready!\n");

  return 0;
}
