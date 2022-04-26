#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREADS 50

pthread_t thread_id[MAX_THREADS];    

void * PrintHello(void * data)
{
    printf("Hello from thread %u - I was created in iteration %d !\n", (int)pthread_self(), (int)data);
    pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
    int rc, i, n;

    if(argc < 2) 
    {
        printf("Please add the number of threads to the command line\n");
        exit(1); 
    }
    n = atoi(argv[1]);
    if(n > MAX_THREADS) n = MAX_THREADS;

    for(i = 0; i < n; i++)
    {
        rc = pthread_create(&thread_id[i], NULL, PrintHello, (void*)i);
        if(rc)
        {
             printf("\n ERROR: return code from pthread_create is %d \n", rc);
             exit(1);
        }
        printf("\n I am thread %u. Created new thread (%u) in iteration %d ...\n", 
                (int)pthread_self(), (int)thread_id[i], i);
        if(i % 5 == 0) sleep(1);
    }

    pthread_exit(NULL);
}

// Kimenet
/*      1. szál vagyok. Új szál (4) jött létre a 0. iterációban...
       Hello a 4. szálból – a 0. iterációban hoztak létre
       Én vagyok az 1. szál. Új szál (6) jött létre az 1. iterációban...
       1. szál vagyok. Új szál (7) jött létre a 2. iterációban...
       1. szál vagyok. Új szál (8) jött létre a 3. iterációban...
       1. szál vagyok. Új szál (9) jött létre a 4. iterációban...
       1. szál vagyok. Új szál (10) jött létre az 5. iterációban...
       Hello a 6. szálból – az 1. iterációban hoztak létre
       Hello a 7. szálból – a 2. iterációban hoztak létre
       Hello a 8. szálból – a 3. iterációban hoztak létre
       Hello a 9. szálból – a 4. iterációban hoztak létre
       Hello a 10. szálból – az 5. iterációban hoztak létre
       Én vagyok az 1. szál. Új szál (11) jött létre a 6. iterációban...
       Én vagyok az 1. szál. Új szál (12) jött létre a 7. iterációban...
       Hello a 11. szálból – a 6. iterációban hoztak létre
       Hello a 12. szálból – a 7. iterációban hoztak létre */
