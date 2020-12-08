//
// Created by 陈江超 on 2020/12/8.
//

#include "Mymalloc.h"

/**
 * 在block链表中寻找合适的空闲block
 * @param last
 * @param size 空间大小
 * @return 如果找到了符合要求的block就返回block的起始地址，如果找不到就返回NULL
 */
t_block find_block(t_block *last, size_t size)
{
    t_block tmp_block = first_block;
    while (tmp_block && !(tmp_block->free && tmp_block->size >= size))
    {
        *last = tmp_block;
        tmp_block = tmp_block->next;
    }
    return tmp_block;
}

/**
 * 开辟新的block
 * @param last block链表最后的一个block
 * @param size 申请空间大小
 * @return 新开辟的block起始地址
 */
t_block extend_heap(t_block last, size_t size)
{
    t_block tmp_block;
    tmp_block = sbrk(0);
}

/**
 * 分裂block
 * @param block 待分裂block的起始地址
 * @param size block真正去要的数据区大小
 */
void split_block(t_block block, size_t size)
{

}

/**
 * 将size调整为大于等于size的8的倍数
 * @param size 欲申请空间大小
 * @return 将size按8的倍数向上取整的结果
 */
size_t align8(size_t size)
{

}

/**
 * 申请一段连续的内存空间，空间大小为size
 * @param size 申请的空间大小
 * @return 成功申请空间返回申请空间的首地址，否则返回NULL
 */
void *my_malloc(size_t size)
{

}

/**
 * 获取地址空间的首地址
 * @param p 地址空间
 * @return 返回该地址空间meta首地址
 */
t_block get_block(void *p)
{

}

/**
 * 检查地址的合法性
 * @param p 欲检查的地址
 * @return 如果地址合法返回首地址；否则返回0
 */
int valid_addr(void *p)
{

}

/**
 * 合并block b和其之后的block
 * @param b 欲合并的block
 * @return 返回b的首地址
 */
t_block fusion_block(t_block b)
{

}

/**
 * 释放地址空间
 * @param p 欲释放的地址空间
 */
void my_free(void *p)
{

}

/**
 * bloc空间复制
 * @param src 源block
 * @param dst 目的block
 */
void copy_block(t_block src, t_block dst)
{

}

/**
 * 重新分配内存空间
 * @param p 欲被重新分配内存的block
 * @param size 欲重新分配的空间大小
 * @return
 */
void *my_realloc(void *p, size_t size)
{

}