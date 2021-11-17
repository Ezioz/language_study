/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-11 19:52:00
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-17 14:45:43
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
// 结构体用作函数参数
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

// 结构体的使用
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
// 内存管理，没搞懂 x
// 现在搞懂了
int main(void)
{
    char name[100];
    char *description;

    strcpy(name, "Zara Ali");
    // malloc() 函数的返回值必须是一个指针变量
    // 并且需要将返回值强制转换为指针变量所指向的类型，详细内容往后看
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

/*
// malloc() 函数
int main(void)
{
    int *p1;
    float *p2;
    // malloc 函数返回的值必须是一个指针变量，而且使用强制类型转换的方式
    // 将返回值转换成指针变量所指向的类型
    p1 = (int *)malloc(sizeof(int));
    p2 = (float *)malloc(sizeof(float));

    if (p1 != NULL && p2 != NULL)
    {
        printf("空间分配成功。\n");
        printf("%p \n %p", p1, p2);
    }
    else
    {
        printf("空间分配失败！");
    }

}

*/

/*
// calloc() 函数
// (类型说明符 *)calloc(items, size)
// 该函数的功能是在内存动态存储区分配items块大小为size字节的连续空间
// 若分配成功，返回分配内存单元的首地址；分配失败，返回NULL
int main(void)
{
    float *p;
    int m = 3;
    p = (float *)calloc(m, sizeof(float));
    if (p != NULL)
    {
        printf("分配空间成功。\n");
        printf("%p\n", p);
        printf("%p", &p);
    }




}
*/

/*
// free() 函数用来释放指针 p 所指向的内存区，参数 p 必须是先前调用
// malloc() 函数或 calloc() 函数时返回的指针

int main(void)
{
    int *p;
    p = (int *)malloc(sizeof(int));
    if (p == NULL)
    {
        printf("空间分配失败!");
    }else{
        *p = 8;
        printf("%d\n", *p);
        free(p);

    }

}

*/

/*
// 结构体的动态内存分配

struct person
{
    char name[20];
    int age;
    char address[100];
};

int main(void)
{
    struct person *pt;
    pt = (struct person *)malloc(sizeof(struct person));
    printf("%d\n", sizeof(pt->name));
    printf("%d\n", sizeof(pt->age));
    printf("%d\n", sizeof(pt->address));
    printf("%d\n", sizeof(pt));
    if (pt == NULL)
    {
        printf("failure");
    }else{
        printf("input name:");
        // pt是一个结构体指针，指向结构体内的name元素，而name又是一个数组类型
        // 数组名称代表的就是该数组的首地址，所以不需要取地址符 &
        scanf("%s", pt->name);
        printf("input age:");
        scanf("%d", &pt->age);
        printf("input address:");
        scanf("%s", pt->address);
        printf("%s, %d, %s", pt->name, pt->age, pt->address);
        free(pt);
    }
    return 0;

}

*/

/* 单链指向这一块还是没有搞懂，感觉这个例子在瞎指
// 单链表的建立分为三步
// 1. 调用malloc()函数，动态分配某个结点大小的存储空间
// 2. 向结点中的数据域存放数据
// 3. 将该结点的指针域指向下一个结点的首地址

struct student
{
    int number;
    char name[20];
    float score;
    struct student *point;
};

int main(void)
{
    struct student *head, *end, *next, *p;
    int snumber;
    char sname[20];
    float sscore;
    head = (struct student *)malloc(sizeof(struct student));
    if (head == NULL)
    {
        printf("failure!");
    }else{
        scanf("%d, %s, %f", &snumber, sname, &sscore);
        head->number = snumber;
        strcpy(head->name, sname);
        head->score = sscore;
        head->point = NULL;
        end = head;
        for (int i = 1; i < 4; i++)
        {
            next = (struct student *)malloc(sizeof(struct student));
            scanf("%d, %s, %f", &snumber, sname, &sscore);
            next->number = snumber;
            strcpy(next->name, sname);
            next->score = sscore;
            next->point = NULL;
            end->point = next;
            end = next;
        }

    }
    return 0;
}

*/

/*
// https://www.bilibili.com/video/BV1yv411y7AW?p=2&spm_id_from=pageDriver
// 这个静态链表的示例比较清晰
struct LinkNode
{
    int data;
    struct LinkNode *next;
};

int main(void)
{
    struct LinkNode node1 = {10, NULL};
    struct LinkNode node2 = {20, NULL};
    struct LinkNode node3 = {30, NULL};
    struct LinkNode node4 = {40, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    struct LinkNode *pCurrent = &node1;
    while (pCurrent != NULL)
    {
        printf("%d\n", pCurrent->data);
        pCurrent = pCurrent->next;
    }

    return 0;
}
*/
/*
// 动态链表

struct LinkNode
{
    int data;
    struct LinkNode *next;
};
// 初始化链表
struct LinkNode *Init_LinkList();
// 在值为oldval后插入一个新的newval
void InsertByvalue_LinkList(struct LinkNode *head, int oldval, int newval);
*/