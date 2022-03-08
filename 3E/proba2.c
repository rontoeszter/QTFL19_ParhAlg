#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>

//Compiler
/*gcc proba2.c -o proba2.exe -lpthread*/

const int N_THREADS = 20;

//Random ideig var
void wait_random_time(void* param)
{
  pid_t tid;
  int wait_time;

  tid = gettid();
  wait_time = *(int*)param;
  printf("[%d] Wait %d seconds ...\n", tid, wait_time);
  sleep(wait_time);
  printf("[%d] Ready!\n", tid);
}


int main(int argc, char* argv[])
{
  pthread_t threads[N_THREADS];
  int wait_time;
  int i;

  printf("Start\n");
  for (i = 0; i < N_THREADS; ++i) {
    wait_time = rand() % 10 + 1;
    pthread_create(&threads[i], NULL, wait_random_time, &wait_time);
  }

  printf("Join\n");
  for (i = 0; i < N_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf("Ready\n");

  return 0;
}
