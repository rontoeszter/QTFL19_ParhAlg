#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 60

void *perform_work(void *arguments){
  int index = *((int *)arguments);
  int sleep_time = 1;
  printf("Szal %d: Started\n", index);
  printf("Szal %d: Varakozik %d mp-ig.\n", index, sleep_time);
  sleep(sleep_time);
  printf("Szal %d: Ended\n", index);
  return NULL;
}

int main(void) {
  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  int i;
  int result_code;
  
  //Egyesével készülnek el
   for (i = 0; i < NUM_THREADS; i++) {
    printf("A(z) %d szal keszul.\n", i);
    thread_args[i] = i;
    result_code = pthread_create(&threads[i], NULL, perform_work, &thread_args[i]);
    assert(!result_code);
  }
  
  printf("Mindegyik szal kesz van.\n");
  
  //Meg varja hogy mindegyik szal elkeszuljon
  for (i = 0; i < NUM_THREADS; i++) {
    result_code = pthread_join(threads[i], NULL);
    assert(!result_code);
    printf("A(z) %d szal befejezodott.\n", i);
  }
  
  printf("A program befejezodott!\n");
  return 0;
}