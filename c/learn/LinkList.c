/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-17 14:58:35
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-17 14:58:35
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://www.runoob.com/cprogramming/c-exercise-example72.html
// 创建一个链表
// 我的妈呀，通过这个程序可终于摸到一点链表的门道了
// 定义结构体，并使其称为自定义类型；结构体类型和结构体指针类型
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList CreateList(int n); //用来创建链表
void print(LinkList h);     // 用来打印链表

int main(void)
{
    LinkList Head = NULL; // head是一个结构体指针类型，初始值为NULL
    int n;                // n的作用是链表结点的长度
    scanf("%d", &n);
    Head = CreateList(n); // head 用来接收创建的链表的第一个指针（L）
    printf("刚刚建立的各个链表元素的值为：\n");
    print(Head); // 调用 print 函数遍历输出指针
    system("pause");
    return 0;
}

LinkList CreateList(int n)
{
    LinkList L, p, q;                   // L, p, q 这里都是 LinkList 指针类型
    L = (LNode *)malloc(sizeof(LNode)); // 动态分配内存空间
    if (!L)                             // 如果空间分配失败，退出函数
    {
        return 0;
    }
    L->next = NULL;              // 首先将结构体变量 L 指向内存空间（第一个结点）的指针域置为空；L指针指向的是第一个结点，在链表中，得到第一个结点的指针代表着取到了整条链表。
    q = L;                       // q 的作用是一个临时变量
    for (int i = 0; i <= n; i++) // 根据n的长度创建结点
    {
        p = (LinkList)malloc(sizeof(LNode)); // LinkList 和 LNode * 的意义是一样的
        printf("请输入第 %d 个元素的值：", i);
        scanf("%d", &(p->data)); // 获取用户输入的值，并保存到结点的数据域
        q->next = p;             // 从这开始的三步很重要，用来构建链表。在该步之前，q 和 L 结构体指针变量指向的地址空间是相同的，所以它们指向的结构体的数据域和指针域是相同的，此时，将p 的地址传入
        // 结点的指针域。指针域中存放的是下一个结点的地址，从而构成链表。
        p->next = NULL; // 以第一次循环为例，此时链表中有两个结点，q(L) 和 p，下一个结点的空间还没有开辟，所以p 结点的指针域指向NULL
        q = p;          // 将p 指针的值赋给 q指针，q指针不再和 L指针指向第一个结点的首地址，p 和 q 共同指向第二个结点的首地址。往复循环，构成链表。
        // 自始至终，L 指针所指向的第一个结点的数据域为空
    }
    return L; // 因为创建的是链表，所以返回链表第一个结点的首地址，即 结构体变量指针 L 所指向的地址即可。
}

void print(LinkList h)
{
    LinkList p = h->next; // 这里的h 其实就是 L，第一个数据域为空，不需要输出，直接输出第二个结点的数据域即可
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next; // 不断移动指针指向不同的结点
    }
}