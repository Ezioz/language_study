/*
 * @Descripttion: http://data.biancheng.net/view/161.html
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-22 21:15:17
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-22 22:06:20
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int elem;
    struct Link *next;
}link;

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
    return *p;
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