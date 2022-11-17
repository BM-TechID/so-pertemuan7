// ! YANG INI HARUS DICOBA DI LINUX LANGSUNG

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
int bilangan = 0; // VARIABEL GLOBAL YANG DISHARE BERSAMA ANTARA
// THREAD 1 DAN THREAD TAMBAH
pthread_t T0;
int sempor; /* variabel semaphore */
// FUNCTION DARI SEMAPHORE
void sem_p(int id, int value)
{ // untuk ganti nilai semaphore dengan -1 atau 1
    struct sembuf sem_b;
    int v;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1; /* P() */
    sem_b.sem_flg = SEM_UNDO;
    if (semop(id, &sem_b, 1) == 1)
        fprintf(stderr, "\nError...Semaphore P Decrement Gagal");
}

void sem_v(int id, int value)
{ // untuk ganti nilai semaphore dengan -1 atau 1
    struct sembuf sem_b;
    int v;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1; /* V() */
    sem_b.sem_flg = SEM_UNDO;
    if (semop(id, &sem_b, 1) == -1)
        fprintf(stderr, "\nError...Semaphore V Increment Gagal");
}
void sem_create(int semid, int initval)
{
    int semval;
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } s;
    s.val = initval;
    if ((semval = semctl(semid, 0, SETVAL, s)) < 0)
        fprintf(stderr, "\nsemctl error....");
}
void sem_wait(int id)
{ // Decrement P
    int value = -1;
    sem_p(id, value);
}
void sem_signal(int id)
{ // Increment V
    int value = 1;
    sem_v(id, value);
}
// END FUNCTION SEMAPHORE

// THREAD
void *tambah(void *a)
{
    int i, j;
    sem_wait(sempor);
    for (i = 0; i < 20; i++)
    {
        j = bilangan;
        j++;
        sleep(1);
        bilangan = j;
    }
    return NULL;
}
int main()
{
    int i, j;
    printf("Nilai Bilangan Awal = %i\n", bilangan);
    // BUAT SEMAPHORE "sempor"
    if ((sempor = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT)) == -1)
    {
        printf("\nError... Tidak bisa buat semaphore sempor");
        exit(1);
    }
    sem_create(sempor, 0);
    if (pthread_create(&T0, NULL, tambah, NULL) == -1)
        perror("thread tidak bisa dibuat");
    // THREAD INI YANG RUNNING DULUAN KEMUDIAN THREAD TAMBAH
    for (i = 0; i < 20; i++)
    {
        j = bilangan;
        j++;
        sleep(1);
        bilangan = j;
    }
    sem_signal(sempor);

    void *result;
    pthread_join(T0, &result);
    printf("Nilai Bilangan Akhir = %i\n", bilangan);
    return 0;
}