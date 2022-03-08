#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>

//Compiler
/*gcc proba1.c -o proba1.exe -lpthread*/

const int N_THREADS = 20;

//Random ideig var
void wait_random_time(void* _)
{
  pid_t tid;
  int wait_time;

  tid = gettid();
  wait_time = rand() % 10 + 1;
  printf("%d. szal var %d mp-et ...\n", tid, wait_time);
  sleep(wait_time);
  printf("%d. szál kész. \n", tid);
}


int main(int argc, char* argv[])
{
  pthread_t threads[N_THREADS];
  int i;

  printf("Start\n");
  for (i = 0; i < N_THREADS; ++i) {
    pthread_create(&threads[i], NULL, wait_random_time, NULL);
  }

  printf("JOIN\n");
  for (i = 0; i < N_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf("Ready\n");

  return 0;
}
