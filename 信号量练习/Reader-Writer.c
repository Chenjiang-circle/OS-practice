#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct _rwlock_t
{
    sem_t lock;      // binary semaphore (basic lock)
    sem_t writelock; // used to allow ONE writer or MANY readers
    int readers;     // count of readers reading in critical section
} rwlock_t;

rwlock_t *lock;

void rwlock_init(rwlock_t *rw)
{
    rw->readers = 0;
    sem_init(&rw->lock, 0, 1);
    sem_init(&rw->writelock, 0, 1);
}

void rwlock_acquire_readlock(rwlock_t *rw)
{
    sem_wait(&rw->lock);
    rw->readers++;
    if (rw->readers == 1)
    {
        sem_wait(&rw->writelock); // first reader acquires writelock
    }
    sem_post(&rw->lock);
}

void rwlock_release_readlock(rwlock_t *rw)
{
    sem_wait(&rw->lock);
    rw->readers--;
    if (rw->readers == 1)
    {
        sem_post(&rw->writelock); // last reader releases writelock
    }
    sem_post(&rw->lock);
}

void rwlock_acquire_writelock(rwlock_t *rw)
{
    sem_wait(&rw->writelock);
}

void rwlock_release_writelock(rwlock_t *rw)
{
    sem_post(&rw->writelock);
}

void *reader(void *arg)
{
    // 多个读者去读
    int i;
    for (i = 0; i < 10; i++)
    {
        rwlock_acquire_readlock(lock);
        printf("I am the %dth reader. There are %d reader ahead of me\n", i, lock->readers);
        rwlock_release_readlock(lock);
    }
    return NULL;
}

void *writer(void *arg)
{
    // 多个写者去写
    int i;
    for (i = 0; i < 5; i++)
    {
        rwlock_acquire_writelock(lock);
        printf("I am the %dth writer.\n", i);
        rwlock_release_writelock(lock);
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    printf("读者写者问题（10个读者，56个写者）\n");
    lock = (rwlock_t *) malloc (sizeof(rwlock_t));
    rwlock_init(lock);
    pthread_t read;
    pthread_t write;
    pthread_create(&read, NULL, reader, lock);
    pthread_create(&write, NULL, writer, lock);
    pthread_join(read, NULL);
    pthread_join(write, NULL);
}