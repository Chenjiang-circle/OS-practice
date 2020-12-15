#include "Mymalloc.h"

/**
 * 在block链表中寻找合适的空闲block
 * @param last
 * @param size 空间大小
 * @return 如果找到了符合要求的block就返回block的起始地址，如果找不到就返回NULL
 */
t_block find_block(t_block last, size_t size)
{
    t_block tmp_block = first_block;
    while (tmp_block && !(tmp_block->free && tmp_block->size >= size))
    {
        last = tmp_block;
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
    // 尝试后移break，分配更多的内存空间给用户；如果尝试失败返回NULL；否则继续操作
    if (sbrk(BLOCK_SIZE + size) == (void *) -1)
        return NULL;
    tmp_block->size = size;
    tmp_block->next = NULL;
    if (last)
    {
        last->next = tmp_block;
        tmp_block->prev = last;
    }
    tmp_block->free = 0;
    return tmp_block;
}

/**
 * 分裂block
 * @param block 待分裂block的起始地址
 * @param size block真正需要的数据区大小
 */
void split_block(t_block block, size_t size)
{
    t_block new_block;
    new_block = block->data + size;
    new_block->size = block->size - size - BLOCK_SIZE;
    new_block->next = block->next;
    if (block->next)
        block->next->prev = new_block;
    new_block->free = 1;
    block->size = size;
    block->next = new_block;
    new_block->prev = block;
}

/**
 * 将size调整为大于等于size的8的倍数
 * @param size 欲申请空间大小
 * @return 将size按8的倍数向上取整的结果
 */
size_t align8(size_t size)
{
    if (size & 0x7 == 0)
        return size;
    return ((size >> 3) + 1) << 3;
}

/**
 * 申请一段连续的内存空间，空间大小为size
 * @param size 申请的空间大小
 * @return 成功申请空间返回申请空间的首地址，否则返回NULL
 */
void *my_malloc(size_t size)
{
    t_block tmp_block, last;
    size_t s;
    s = align8(size);
    if (first_block)
    {
        // 查找合适的block
        last = first_block;
        tmp_block = find_block(last, s);
        if (tmp_block)
        {
            // 如果找到了合适的block就尝试分裂
            if ((tmp_block->size - s) > (BLOCK_SIZE + 8))
                split_block(tmp_block, s);
            // 将找到的block设置为不空闲
            tmp_block->free = 0;
        }
        else
        {
            // 如果没有找到合适的block，则开辟一个新的block
            tmp_block = extend_heap(last, s);
            if (!tmp_block)
                // 如果没有开辟成功，返回NULL
                return NULL;
        }
    }
    else
    {
        // 如果block链表为空，开辟新的block
        tmp_block = extend_heap(NULL, s);
        if (!tmp_block)
            return NULL;
        first_block = tmp_block;
    }
}

/**
 * 获取地址空间的首地址
 * @param p 地址空间
 * @return 返回该地址空间meta首地址
 */
t_block get_block(void *p)
{
    char *tmp;
    p = tmp;
    return (p = tmp -= BLOCK_SIZE);
}

/**
 * 检查地址的合法性
 * @param p 欲检查的地址
 * @return 如果地址合法返回首地址；否则返回0
 */
int valid_addr(void *p)
{
    // 如果block链表为空，直接返回0
    if (!first_block)
        return 0;
    if (p > first_block && p < sbrk(0))
        return p == get_block(p)->ptr;
}

/**
 * 合并block b和其之后的block
 * @param b 欲合并的block
 * @return 返回b的首地址
 */
t_block fusion_block(t_block block)
{
    // 如果block的下一个block存在且为空闲block
    if (block->next && block->next->free)
    {
        block->size += BLOCK_SIZE + block->next->size;
        block->next = block->next->next;
        // 合并之后的block如果存在后继block，需要将后继block的前驱指针指向此block
        if (block->next)
            block->next->prev = block;
    }
    return block;
}

/**
 * 释放地址空间
 * @param p 欲释放的地址空间
 */
void my_free(void *p)
{
    t_block tmp_block;
    if (valid_addr(p))
    {
        tmp_block = get_block(p);
        tmp_block->free = 1;
        // 如果释放的block的前驱也是空闲的，就将两个block合并
        if (tmp_block->prev && tmp_block->prev->free)
            tmp_block = fusion_block(tmp_block->prev);

        if (tmp_block->next)
        {
            // 如果释放的block的后继是空闲的，就将两个block合并
            if (tmp_block->next->free)
                fusion_block(tmp_block);
        }
        else
        {
            // 如果释放的block有前驱，将其前驱的后继置为NULL
            if (tmp_block->prev)
                tmp_block->prev->next = NULL;
            else // 如果释放的block没有前驱，说明block链表在释放完此block之后就为空了
                first_block = NULL;
            brk(tmp_block);
        }
    }
}

/**
 * bloc空间复制
 * @param src 源block
 * @param dst 目的block
 */
void copy_block(t_block src, t_block dst)
{
    size_t *source_data, *des_data;
    size_t i;
    source_data = src->ptr;
    des_data = dst->ptr;
    for (i = 0; (i * 8) < src->size && (i * 8) < dst->size; i++)
    {
        des_data[i] = source_data[i];
    }
}

/**
 * 重新分配内存空间
 * @param p 欲被重新分配内存的block
 * @param size 欲重新分配的空间大小
 * @return
 */
void *my_realloc(void *p, size_t size) {
    size_t s;
    t_block tmp_block, new_block;
    void *newp;
    if (!p)
        return my_malloc(size);
    if (valid_addr(p)) {
        s = align8(size);
        tmp_block = get_block(p);
        if (tmp_block->size >= s) {
            // 如果找到的block的空间大于需要分配的空间，就将找到的空间进行拆分
            if (tmp_block->size - s > (BLOCK_SIZE + 8))
                split_block(tmp_block, s);
        } else {
            // 如果找到的block空间不够分配，就看看是否可以和后面的block合并
            if (tmp_block->next && tmp_block->next->free
                && (tmp_block->size + BLOCK_SIZE + tmp_block->next->size) >= s) {
                fusion_block(tmp_block);
                // 如果合并置之后的block比需要的block大，要将合并的block拆分
                if (tmp_block->size - s >= (BLOCK_SIZE + 8))
                    split_block(tmp_block, s);
            } else {
                // 如果无法合并，需要开辟新的block
                newp = my_malloc(s);
                if (!newp)
                    return NULL;
                new_block = get_block(newp);
                copy_block(tmp_block, new_block);
                free(p);
                return newp;
            }
        }
    }
    return p;
}