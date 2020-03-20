#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *start_routine1 (void * arg) {
    printf ("Début du thread 1\n");
    sleep (1);
    printf ("Fin du thread 1\n");
    pthread_exit (0);
}

void *start_routine2 (void * arg) {
    printf ("Début du thread 2\n");
    sleep (2);
    printf ("Fin du thread 2\n");
    pthread_exit (0);
}

int main (int argc, char **argv) {
    pthread_t th1, th2;
    void *ret;
    if (pthread_create (&th1, NULL, start_routine1, NULL) < 0) {
        perror("");
        exit (1);
    }
    if (pthread_create (&th2, NULL, start_routine2, NULL) < 0) {
        perror("");
        exit (1);
    }

    pthread_join (th1, &ret);
    pthread_join (th2, &ret);
    return 0;
}
