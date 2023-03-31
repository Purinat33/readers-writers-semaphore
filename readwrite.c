#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_READERS 10
#define NUM_WRITERS 10
#define NUM_READS 50
#define NUM_WRITES 20
#define MAX_VALUE 99

int data[100];
sem_t data_sem;
sem_t writer_sem;
pthread_mutex_t output_mutex = PTHREAD_MUTEX_INITIALIZER;

void *reader(void *arg)
{
    int id = *((int *)arg);
    int read_count = 0;
    int value;

    while (read_count < NUM_READS)
    {
        // randomly choose an index to read
        int index = rand() % 100;

        // lock the data semaphore and read the value
        sem_wait(&data_sem);
        value = data[index];
        sem_post(&data_sem);

        // lock the output mutex and print the message
        pthread_mutex_lock(&output_mutex);
        printf("R%d reads data at %d, the number is %d\n", id, index, value);
        pthread_mutex_unlock(&output_mutex);

        // increment read count and sleep for a short time
        read_count++;
        usleep(rand() % 10000);
    }

    // print the message when the reader is done
    pthread_mutex_lock(&output_mutex);
    printf("R%d is done.\n", id);
    pthread_mutex_unlock(&output_mutex);

    return NULL;
}

void *writer(void *arg)
{
    int id = *((int *)arg);
    int write_count = 0;
    int value;

    while (write_count < NUM_WRITES)
    {
        // randomly choose an index to write to
        int index = rand() % 100;

        // wait for writer_sem
        sem_wait(&writer_sem);

        // lock the data semaphore and increment the value
        sem_wait(&data_sem);
        value = data[index] + 1;
        data[index] = value;
        sem_post(&data_sem);

        // lock the output mutex and print the message
        pthread_mutex_lock(&output_mutex);
        printf("W%d writes the data at %d, the number is %d\n", id, index, value);
        pthread_mutex_unlock(&output_mutex);

        // signal waiting writers
        sem_post(&writer_sem);

        // increment write count and sleep for a short time
        write_count++;
        usleep(rand() % 10000);
    }

    // print the message when the writer is done
    pthread_mutex_lock(&output_mutex);
    printf("W%d is done.\n", id);
    pthread_mutex_unlock(&output_mutex);

    // decrement writer_sem
    sem_wait(&writer_sem);
    sem_post(&writer_sem);

    return NULL;
}

// int main(int argc, char *argv[])
// {
//     int num_readers, num_writers;
//     pthread_t reader_threads[NUM_READERS];
//     pthread_t writer_threads[NUM_WRITERS];
//     int reader_ids[NUM_READERS];
//     int writer_ids[NUM_WRITERS];
//     int i;
//     FILE *fp;

//     // parse command line arguments for number of readers and writers
//     if (argc != 4)
//     {
//         printf("Usage: %s <num_readers
int main(int argc, char *argv[])
{
    int num_readers, num_writers;
    pthread_t reader_threads[NUM_READERS];
    pthread_t writer_threads[NUM_WRITERS];
    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];
    int i;
    FILE *fp;

    // parse command line arguments for number of readers and writers
    if (argc != 4)
    {
        printf("Usage: %s <num_readers> <num_writers> <output_file>\n", argv[0]);
        return 1;
    }
    num_readers = atoi(argv[1]);
    num_writers = atoi(argv[2]);
    fp = fopen(argv[3], "w");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // initialize the data array with random values
    for (i = 0; i < 100; i++)
    {
        data[i] = rand() % (MAX_VALUE + 1);
    }

    // initialize semaphores
    sem_init(&data_sem, 0, 1);
    sem_init(&writer_sem, 0, num_writers);

    // create reader threads
    for (i = 0; i < num_readers; i++)
    {
        reader_ids[i] = i + 1;
        pthread_create(&reader_threads[i], NULL, reader, &reader_ids[i]);
    }
    // create writer threads
    for (int i = 0; i < num_writers; i++)
    {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&writer_threads[i], NULL, writer, id);
    }

    // Wait for reader threads to finish
    for (int i = 0; i < num_readers; i++)
    {
        pthread_join(reader_threads[i], NULL);
    }
    // Wait for writer threads to finish
    for (int i = 0; i < num_writers; i++)
    {
        pthread_join(writer_threads[i], NULL);
    }

    // Write outputs to file
    fprintf(fp, "Final Data Array:\n");
    for (i = 0; i < 100; i++)
    {
        fprintf(fp, "%d ", data[i]);
    }
    fclose(fp);

    // destroy semaphores
    sem_destroy(&data_sem);
    sem_destroy(&writer_sem);

    return 0;
}
