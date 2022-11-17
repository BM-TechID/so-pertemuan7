// ! MUTEX 0 - 20

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int bilangan = 0;
pthread_t T0;

void *tambah(void *a){
    int i, j;
    for (i = 0; i < 20;i++)
    {
        j = bilangan;
        j++;
        sleep(1);
        bilangan = j;
    }
    return NULL;
}

int main(){
    int i, j;
    printf("Nilai Bilangan awal = %i\n", bilangan);
    if (pthread_create(&T0, NULL, tambah, NULL)==-1)
        perror("Thread tidak bisa dibuat");
    for (i = 0; i < 20;i++)
    {
        j = bilangan;
        j++;
        sleep(1);
        bilangan = j;
    }
    void* result;
    pthread_join(T0, &result);
    printf("Nilai Bilangan Akhir = %i\n", bilangan);
    return 0;
}