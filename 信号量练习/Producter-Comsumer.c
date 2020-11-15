#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 10

int buffer[MAX];
int fill = 0;
int use = 0;

void put(int value)
{
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
}

int get()
{
    int tmp = buffer[use];
    use = (use + 1) % MAX;
    return tmp;
}

sem_t empty;
sem_t full;
sem_t mutex;

void *producer(void *arg)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("producer: put %d\n", i);
        put(i);
        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void *consumer(void *arg)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        int tmp = get();
        sem_post(&mutex);
        sem_post(&empty);
        printf("consumer: get %d\n", tmp);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    printf("生产者消费者问题：\n现在有一个buffer数组用来存放生产者生产的产品，数组大小为10,生产者总共要生产100件商品\n");
    // 信号量初始化
    sem_init(&empty, 0, MAX);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // 创建两个线程
    pthread_t pro;
    pthread_t con;
    pthread_create(&pro, NULL, producer, NULL);
    pthread_create(&con, NULL, consumer, NULL);
    pthread_join(pro, NULL);
    pthread_join(con, NULL);
    return 0;
}