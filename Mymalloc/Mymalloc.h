//
// Created by 陈江超 on 12/7/20.
//

#ifndef MYMALLOC_MYMALLOC_H
#define MYMALLOC_MYMALLOC_H

#include <sys/types.h>
#include <unistd.h>

#define BLOCK_SIZE 24

typedef struct s_block *t_block;

struct s_block
{
    size_t size; /* 数据区大小 */
    t_block prev; /* 指向上一个块的指针 */
    t_block next; /* 指向下一个块的指针 */
    int free; /* 是否是空闲块 */
    int padding; /* 填充字节，保证meta块长度是8的倍数 */
    void *ptr; /* Magic pointer，指向data */
    char data[1]; /* 虚拟字段，表示数据块的第一个字节，长度不应该计入meta */
};

/**
 * 在block链表中寻找合适的空闲block
 * @param last
 * @param size 空间大小
 * @return 如果找到了符合要求的block就返回block的起始地址，如果找不到就返回NULL
 */
t_block find_block(t_block *last, size_t size);

/**
 * 开辟新的block
 * @param last block链表最后的一个block
 * @param size 申请空间大小
 * @return 新开辟的block起始地址
 */
t_block extend_heap(t_block last, size_t size);

/**
 * 分裂block
 * @param block 待分裂block的起始地址
 * @param size block真正去要的数据区大小
 */
void split_block(t_block block, size_t size);

/**
 * 将size调整为大于等于size的8的倍数
 * @param size 欲申请空间大小
 * @return 将size按8的倍数向上取整的结果
 */
size_t align8(size_t size);

/**
 * 申请一段连续的内存空间，空间大小为size
 * @param size 申请的空间大小
 * @return 成功申请空间返回申请空间的首地址，否则返回NULL
 */
void *my_malloc(size_t size);

/**
 * 检查地址合法性（检查欲释放地址空间的合法性）
 * @param p 欲释放空间地址
 * @return 如果合法，返回该地址空间的meta首地址，否则返回NULL
 */
t_block get_block(void *p);

#endif //MYMALLOC_MYMALLOC_H
