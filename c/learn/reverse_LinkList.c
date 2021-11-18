/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-17 15:49:58
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-18 15:05:01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 还没弄
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList CreateList(int n);
void print(LinkList h);
int main(void)
{
    LinkList head = NULL;
    int n;
    scanf("%d", &n);
    head = CreateList(n);
    printf("刚刚建立的各个链表的值为：");
    print(head);
    system("pause");
    return 0;
}

LinkList CreateList(int n)
{
    LinkList L, p, q;
    L = (LNode *)malloc(sizeof(LNode));
    if (!L)
    {
        return 0;
    }
    L->next = NULL;
    q = L;
    for (int i = 0; i < n; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        printf("请输入第 %d 个元素的值：", i);
        scanf("%d", &p->data);
        q->next = p;
        p->next = NULL;
        q = p;
    }
    return L;
}

void print(LinkList h)
{
    LinkList p = h->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    
}