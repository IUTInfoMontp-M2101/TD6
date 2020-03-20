#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h> // nouvelle bibliothèque

static sem_t semaphore; // déclaration d'une variable globale

void *start_routine1 (void * arg) {
    printf ("Début du thread 1\n");
    sleep (1);
    sem_wait(&semaphore); // attendre le sémaphore printf ("Fin du thread 1\n");
    pthread_exit (0);
}

void *start_routine2 (void * arg) {
    printf ("Début du thread 2\n");
    sleep (2);
    printf ("Fin du thread 2\n");
    sem_post(&semaphore); // libérer le sémaphore pthread_exit (0);
}

int main (int argc, char **argv) {
    pthread_t th1, th2;
    sem_init(&semaphore, 0, 0); // initialiser le sémaphore (pas libre)

    if (pthread_create (&th1, NULL, start_routine1, NULL) < 0) {
        perror("");
        exit (1);
    }

    if (pthread_create (&th2, NULL, start_routine2, NULL) < 0) {
        perror("");
        exit (1);
    }

    pthread_join (th1, NULL);
    pthread_join (th2, NULL);
    return 0;
}
