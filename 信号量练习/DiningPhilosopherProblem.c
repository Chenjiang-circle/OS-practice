#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t forks[5];
int people[5];

int left(int p)
{
    return p;
}

int right(int p)
{
    return (p + 1) % 5;
}

void *getforks(void *arg)
{
    int *p = (int*) arg;
    if(*p == 4)
    {
        sem_wait(&forks[right(*p)]);
        printf("我是第%d个哲学家，我拿到了右筷子！\n", *p);
        sem_wait(&forks[left(*p)]);
        printf("我是第%d个哲学家，我拿到了左筷子，我现在可以吃东西了！\n", *p);
    }
    else
    {
        sem_wait(&forks[left(*p)]);
        printf("我是第%d个哲学家，我拿到了左筷子！\n", *p);
        sem_wait(&forks[right(*p)]);
        printf("我是第%d个哲学家，我拿到了右筷子，我现在可以吃东西了！\n", *p);
    }
    // 哲学家吃完了东西，要放下筷子
    sem_post(&forks[left(*p)]);
    sem_post(&forks[right(*p)]);
    printf("我是第%d个哲学家，我吃完放下筷子啦！\n", *p);
    return NULL;
}

int main(int argc, char* argv[])
{
    // 初始化数组
    for (int i = 0; i < 5; i++)
    {
        people[i] = i;
    }
    
    // 初始化信号量
    for (int i = 0; i < 5; i++)
    {
        sem_init(&forks[i], 0, 1);
    }
    pthread_t p[5];
    
    // 创建线程
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&p[i], NULL, getforks, &people[i]);
    }

    
    //pthread_create(&p1, NULL, getforks, 1);
    // 主线程等待其他线程结束
    for (int i = 0; i < 5; i++)
    {
        pthread_join(p[i], NULL);
    }
    return 0;
}