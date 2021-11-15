/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-11 19:52:00
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-15 22:53:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

函数指针
int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    int (* p)(int, int) = &max;
    int a, b, c, d;
    printf("请输入三个数字：");
    scanf("%d %d %d", &a, &b, &c);
    d = p(p(a, b), c);
    printf("最大数字是：%d\n", d);
    return 0;
}
*/

/*
int getNextRandomValue(void);
void populate_array(int *array, size_t arraySize, int (*getNextvalue)(void)); //getNextvalue只是个形参

int main(void)
{
    int myarray[10];
    // getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针
    populate_array(myarray, 10, getNextRandomValue);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", myarray[i]);
    }
    
    return 0;
}

int getNextRandomValue(void)
{
    return rand();
}

void populate_array(int *array, size_t arraySize, int (*getNextvalue)(void))
{
    for (size_t i = 0; i < arraySize; i++)
    {
        array[i] = getNextvalue();
    }
    
}
*/

/*
int main(void)
{
    typedef struct student
    {
        int a;
        char b;
        double c;
    } Simple2;
    
    // 通过struct student的方式，可以通过 struct student s2的方式定义结构体变量；
    // 如果使用了typedef，则可以通过使用 Simple2 变量作为类型的方式定义其他结构体类型
    
    Simple2 u1 = {1, 'c', 9.9};
    struct student s2 = {2, 'c', 10.0};
    printf("u1 %d\n", u1.a);
    printf("s2 %d\n", s2.a);
    return 0;


}

*/

/*
// 结构用作函数参数
struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    long long int book_id;
};

// 指向结构的指针
void printBook(struct Books *book);
int main(void)
{
    struct Books Book1;
    struct Books Book2;
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Nuhua Ali");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495700;

    strcpy( Book2.title, "Telecom Billing");
    strcpy( Book2.author, "Zara Ali");
    strcpy( Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 4294967296;
    // 通过传 Book1/2 的地址来输出信息
    printBook(&Book1);
    printBook(&Book2);
    printf("%d\n", sizeof(long long int));
    return 0;
}

void printBook(struct Books *book)
{
    // 为了使用指向该结构的指针访问结构的成员，必须使用->
    printf("Book title: %s \n", book->title);
    printf("Book author: %s \n", book->author);
    printf("Book subject: %s \n", book->subject);
    printf("Book book_id: %lld \n", book->book_id);
}
*/

/*
int main(void)
{
    typedef struct Books
    {
        char title[50];
        char author[50];
        char subject[100];
        int book_id;
    } Book;
    Book book;
    strcpy( book.title, "C 教程");
    strcpy( book.author, "Runoob"); 
    strcpy( book.subject, "编程语言");
    book.book_id = 1000;
    printf( "书标题 : %s\n", book.title);
    printf( "书作者 : %s\n", book.author);
    printf( "书类目 : %s\n", book.subject);
    printf( "书 ID : %d\n", book.book_id);
    return 0;
    
}
*/

/*
// 内存管理，没搞懂
int main(void)
{
    char name[100];
    char *description;

    strcpy(name, "Zara Ali");
    description = (char *)malloc(200 * sizeof(char));
    if (description == NULL)
    {
        fprintf(stderr, "Error - unable to allocate required memory.\n");
    }else{
        strcpy(description, "Zara ali a DPS student in class 10th.\n");
    }
    printf("Name = %s \n", name);
    printf("Description: %s \n", description);
    return 0;
}
*/

/*
int test(void);
int main(void)
{
    int b = test();
    printf("%d\n", b);
    return 0;
}

int test(void)
{
    int a = 0;
    if (a > 0)
    {
        // 如果在这里 return 了，后面的内容都不再执行。
        return 10;
    }
    printf("aaa\n");
    return 0;
    
}
*/


/**
 * @name: 链表内容学习
 * @msg: https://blog.csdn.net/Endeavor_G/article/details/80552680
 * @param {*}
 * @return {*}
 */

/*
// 创建链表一般使用 typedef struct， 这样定义结构体变量时，就可以使用 LinkList *a 定义结构体类型变量
typedef struct student
{
    int score;
    struct strudent *next;  
} LinkList;

// 初始化一个链表，n为链表节点的个数
LinkList *create(int n)
{
    // 定义头节点、普通节点、尾部节点
    LinkList *head, *node, *end;
    // 分配地址
    head = (LinkList *)malloc(sizeof(LinkList));
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = (LinkList *)malloc(sizeof(LinkList));
        scanf("%d", &node->score);
        end->next = node;
    }
    end->next = NULL;
    return head;
    
}

*/


struct LinkNOde
    {
        int data;
        struct LinkNode *next;
    };
void test(void)
{
    struct LinkNOde node1 = {10, NULL};
    struct LinkNOde node2 = {20, NULL};
    struct LinkNOde node3 = {30, NULL};
    struct LinkNOde node4 = {40, NULL};
    struct LinkNOde node5 = {50, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    // 这有问题
    struct LinkNode *pCurrent = &node1;
    printf("%p\n", &pCurrent);
    printf("%p\n", &node1);

    
}

int main(void)
{
    
    test();
    return 0;
}
