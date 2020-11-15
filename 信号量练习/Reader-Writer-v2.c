#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t lock;
sem_t write_lock;
int readers = 0;

void *reader(void *arg)
{
    sem_wait(&lock);
    readers++;
    if(readers == 1)
    {
        sem_wait(&write_lock);
    }
    printf("I am the %dth reader.\n", readers);
    sem_post(&lock);
    // 读完之后释放锁
    sem_wait(&lock);
    readers--;
    if(readers == 0)
    {
        sem_post(&write_lock);
    }
    sem_post(&lock);
    return NULL;
}

void *writer(void *arg)
{
    sem_wait(&write_lock);
    printf("I am a writer.\n");
    sem_post(&write_lock);
    return NULL;
}

int main(int argc, char *argv[])
{
    // 初始化信号量
    sem_init(&lock, 0, 1);
    sem_init(&write_lock, 0, 1);

    // 创建多个线程
    pthread_t read_1;
    pthread_t read_2;
    pthread_t read_3;
    pthread_t read_4;
    pthread_t read_5;
    pthread_t write_1;
    pthread_t write_2;
    pthread_t write_3;
    pthread_create(&read_1, NULL, reader, NULL);
    pthread_create(&read_2, NULL, reader, NULL);
    pthread_create(&read_3, NULL, reader, NULL);
    pthread_create(&read_4, NULL, reader, NULL);
    pthread_create(&read_5, NULL, reader, NULL);
    pthread_create(&write_1, NULL, writer, NULL);
    pthread_create(&write_2, NULL, writer, NULL);
    pthread_create(&write_3, NULL, writer, NULL);
    pthread_join(read_1, NULL);
    pthread_join(read_2, NULL);
    pthread_join(read_3, NULL);
    pthread_join(read_4, NULL);
    pthread_join(read_5, NULL);
    pthread_join(write_1, NULL);
    pthread_join(write_2, NULL);
    pthread_join(write_3, NULL);
    return 0;
}