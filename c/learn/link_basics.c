/*
 * @Descripttion: http://data.biancheng.net/view/161.html
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-22 21:15:17
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-23 11:34:31
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int elem;
    struct Link *next;
} link;

// 创建链表
link *initLink()
{
    link *p = (link *)malloc(sizeof(struct Link));
    link *tmp = p;
    for (int i = 0; i < 5; i++)
    {
        link *a = (link *)malloc(sizeof(struct Link));
        a->elem = i;
        a->next = NULL;
        tmp->next = a;
        tmp = tmp->next;
    }
    return p;
}

// 链表插入元素
link *insertElem(link *p, int elem, int add)
{
    link *temp = p;
    link *c = NULL;
    for (int i = 0; i < add; i++)
    {
        if (temp == NULL)
        {
            printf("插入的位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    c = (link *)malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;
}

// p 为原链表，elem 为新数据元素，add 表示新元素要插入的位置
link *insertElem(link *p, int elem, int add)
{
    link *temp = p;
    link *c = NULL;
    for (int i = 1; i < add; i++) // i 的值也很重要，其与add（要插入的位置）的关系很密切
    {
        if (temp == NULL)
        {
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    c = (link *)malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;
}

// 链表删除元素的两步：1. 将结点从链表上摘下来；2. 手动释放掉结点，回收被结点占用的存储空间
link *delElem(link *p, int add)
{
    link *temp = p;
    link *del = NULL;
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return p;
}

// 链表查找元素
int selectElem(link *p, int elem)
{
    link *t = p;
    int i = 1;
    while (t->next)
    {
        t = t->next;
        if (t->elem == elem)
        {
            return i;
        }
        i++;
    }
    return -1;
}

// 更新函数
link *amendElem(link *p, int add, int newElem)
{
    link *temp = p;
    temp = temp->next;
    for (int i = 0; i < add; i++)
    {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}