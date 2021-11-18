/*
 * @Descripttion: 学生成绩管理系统，原GitHub链接
 * https://github.com/csyxwei/StudentScoreManagerSystem/blob/master/%E6%88%90%E7%BB%A9%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F.c
 * 用于学习。
 * @version: 1.0
 * @Author: ahtoh
 * @Date: 2021-10-29 15:23:39
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-18 17:24:13
 */
/**
 * @description:
 * 照着别人程序写的时候，需要考虑到程序的功能，不然可能不知道这些代码做了什么
 * emmm，看别人代码，发现他自己在写的时候也不是很明确需求。打算推倒自己重新写。x
 * 功能如下：
 * 1.录入每个学生的学号、姓名和各科考试成绩
 * 2.计算每门课程的总分和平均分
 * 3.计算每个学生的总分和平均分
 * 4.按每个学生的总分由高到低排出名次表
 * 5.按每个学生的总分由低到高排出名次表
 * 6.按学号由小到大排出成绩表
 * 7.按姓名的字典顺序排出成绩表
 * 8.按学号查询学生排名及其考试成绩
 * 9.按姓名查询学生排名及其考试成绩
 * 10.按优秀（90-100）、良好（80-89）、中等（70-79）、及格（60-69）、不及格（0-59）5个类别，对每门课程分别统计每个类别的人数以及所占的百分比
 * 11.输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分
 * 12.将每个学生的纪录信息写入文件
 * 13.从文件中读出每个学生的纪录信息并显示
 * @param {*}
 * @return {*}
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// 宏定义
#define MAX_LEN 10                 // 字符串最大程度
#define STU_NUM 30                 // 最多学生数量
#define COURSE_NUM 6               // 最多考试科目
#define LEN sizeof(struct Student) // 结构体长度

// 自定义Student 结构体类型，里面有指针域，用于构成链表
typedef struct Student
{
    long num;
    char name[MAX_LEN];
    float score[COURSE_NUM];
    float sum;
    float aver;
    struct Student *next;
} STU;

int Menu(void);            // 添加菜单
STU *Create(int n, int m); // 创建链表并录入信息
STU *Create1(int n, int m);
void Print(STU *head, int n, int m);                 // 打印函数
void AverSumofEveryStudent(STU *head, int n, int m); // 计算每门课程的总分和平均分
void AverSumofEveryCourse(STU *head, int n, int m);  // 计算每个学生的总分和平均分

int main(void)
{
    int n, m; // n 是学生数，m是课程数
    int i;
    STU *head; // 定义头节点
    // head = (STU *)malloc(sizeof(LEN)); // 获取内存空间
    while (1)
    {
        i = Menu();
        if (i == 1)
        {
            system("cls");                             // 清屏
            printf("Input student number(n < 30):\n"); //输入学生数
            scanf("%d", &n);
            printf("Input course number(m <= 6):\n");
            scanf("%d", &m);
        }
        switch (i)
        {
            // 录入学生成绩
        case 1:
            printf("Input student's ID, name and score:\n");
            head = Create(n, m);
            break;
            // 计算每门课程的总分和平均分
        case 2:
            system("cls");
            AverSumofEveryStudent(head, n, m);
            break;
        case 3:
            system("cls");
            AverSumofEveryCourse(head, n, m);
            break;
        case 4:
            system("cls");
            printf("Sort in ascending order by score:");
            head = SortbyScore(head, n);
            Print(head, n, m);
            break;
        case 5:
            system("cls");
            printf("Sort in ascending order by score:");
            head = SortbyScore(head, n);
            Print(head, n, m);
            break;

        default:
            break;
        }
    }
}

/**
 * @description: 定义1个整数变量i，获取用户的输入；根据用户的输入，通过case，进入响应的功能。
 * @param i
 * @return i
 */

// 菜单
int Menu(void)
{
    int i;
    system("title 学生成绩管理系统V1.0 By ahtoh");
    printf("1. Input record");
    printf("2. Caculate total and average score of every course\n");
    printf("3. Caculate total and average score of every student\n");
    printf("4. Sort in descending order by score\n");
    printf("5. Sort in ascending order by score\n");
    printf("6. Sort in ascending order by number\n");
    printf("7. Sort in dictionary order by name\n");
    printf("8. Search by number\n");
    printf("9. Search by name\n");
    printf("10. Statistic analysis\n");
    printf("11. List record\n");
    printf("12. Write to a file\n");
    printf("13. Read from a file\n");
    printf("0. Exit\n");
    printf("Please input your choice:");
    scanf("%d", &i);
    return i;
}

// 创建链表
STU *Create(int n, int m)
{
    STU *head, *p1, *p2; // head 是头指针，p2 是临时指针， p1 是新创建结点指针
    for (int i = 0; i < n + 1; i++)
    {
        p1 = (STU *)malloc(LEN);
        scanf("%ld", &p1->num);
        scanf("%s", p1->name);
        for (int j = 0; j < m; j++)
        {
            printf("第 %d 门课程", j + 1);
            scanf("%f", &p1->score[j]);
        }
        p1->next = NULL; // 创建新节点后，其指针域指向为NULL。
        if (i == 1)
        {
            head = p2 = p1; // 当是第一个节点的时候，三个指针均指向第一个结点
        }
        else
        {
            p2->next = p1; // 之后将下一个结点的地址放入上一个结点的指针域
            p2 = p1;       // 再调整p2 指针指向下一个结点的地址
        }
    }
    return head; // 返回头结点指针
}

// 创建  链表

STU *Create1(int n, int m)
{
    STU *head, *p1, *p2;
    for (int i = 0; i < n + 1; i++)
    {
        p1 = (STU *)malloc(LEN);
        p1->next = NULL;
        if (i == 1)
        {
            head = p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }
    }
    return head;
}

void AverSumofEveryStudent(STU *head, int n, int m)
{
    STU *p;
    char ch;
    float sum;
    p = head;
    int j = 1;
    if (head != NULL)
    {
        for (int i = 0; i < m; i++)
        {
            p = head;
            sum = 0.0;
            do
            {
                sum += p->score[i];
                p = p->next;
            } while (p != NULL);
            printf("course %d: sum = %.0f, aver = %.0f\n", j, sum, sum / n);
            j++;
        }
    }
}

void AverSumofEveryCourse(STU *head, int n, int m)
{
    STU *p;
    p = head;
    if (head != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            p->sum = 0.0;
            for (int j = 0; j < m; j++)
            {
                p->sum += p->score[j];
            }
            p->aver = p->sum / n;
            printf("sutdent %d: sum = %.0f, aver = %.0f\n", i + 1, p->sum, p->aver);
            p = p->next;
        }
    }
}

STU *SortbyScore(STU *head, int n)
{
    STU *endpt;
    STU *p;
    STU *p1, *p2;
    p1 = (STU *)malloc(LEN);
    p1->next = head;
    head = p1;
    for (endpt = NULL; endpt != head; endpt = p)
    {
        for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
        {
            if (p1->next->sum < p1->next->next->sum)
            {
                p2 = p1->next->next;
                p1->next->next = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p = p1->next->next;
            }
        }
    }
    p1 = head;
    head = head->next;
    free(p1);
    p1 = NULL;
    return head;
}

STU *SortbyScore1(STU *head, int n)
{
    STU *endpt;
    STU *p;
    STU *p1, *p2;
    p1 = (STU *)malloc(sizeof(LEN));
    p1->next = head;
    head = p1;
    for (endpt = NULL; endpt != head; endpt = p)
    {
        for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
        {
            if (p1->next->sum > p1->next->next->sum)
            {
                p2 = p1->next->next;
                p1->next->next = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p = p1->next->next;
            }
        }
    }
    p1 = head;
    head = head->next;
    free(p1);
    p1 = NULL;
    return head;
}

STU *SortbyNum(STU *head)
{
    STU *first;
    STU *t;
    STU *p, *q;
    first = head->next;
    head->next = NULL;
    while (first != NULL)
    {
        for (t = first, q = head; ((q != NULL) && (q->num < t->num)); p = q, q = q->next)
            ;

        first = first->next;
        if (q == head)
        {
            head = t;
        }
        else
        {
            p->next = t;
        }
        t->next = q;
    }
    return head;
}

STU *SortbyName(STU *head, int n)
{
    STU *endpt;
    STU *p;
    STU *p1, *p2;
    p1 = (STU *)malloc(LEN);
    p1->next = head;
    head = p1;
    for (endpt = NULL; endpt != head; endpt = p)
    {
        for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
        {
            if (strcmp(p1->next.name, p1->next->next.name) > 0)
            {
                p2 = p1->next->next;
                p1->next->next = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p = p1->next->next;
            }
        }
    }
    p1 = head;
    head = head->next;
    free(p1);
    p1 = NULL;
    return head;
}

void Print(STU *head, int n, int m)
{
    STU *p;
    p = head;
    if (head != NULL)
    {
        do
        {
            printf("%ld\t%s\t", p->num, p->name);
            for (int i = 0; i < m; i++)
            {
                printf("%.0f\t", p->score[i]);
            }
            printf("%.0f\t%.0f\n", p->sum, p->sum / n);
            p = p->next;
        } while (p != NULL);
    }
}

void SearchbyNum(STU *head, int n, int m)
{
    long num;
    int flag = 1;
    scanf("%ld", &num);
    STU *p;
    p = head;
    if (head != NULL)
    {
        do
        {
            if (p->num == num)
            {
                printf("%ld\t%s\t", p->num, p->name);
                for (int i = 0; i < m; i++)
                {
                    printf("%.0f\t", p->score[i]);
                }
                printf("%.0f\t%.0f\n", p->sum, p->sum / n);
            }
            p = p->next;
        } while (p != NULL);
        if (flag)
        {
            printf("Not fount!\n");
        }
    }
}

void SearchbyName(STU *head, int n, int m)
{
    char name[MAX_LEN];
    int flag = 1;
    scanf("%s", name);
    STU *p = head;
    if (head != NULL)
    {
        do
        {
            if (strcmp(name, p->name) == 0)
            {
                printf("%ld\t%s\t", p->num, p->name);
                for (int i = 0; i < m; i++)
                {
                    printf("%.0f\t", p.score[i]);
                }
                printf("%.0f\t%.0f\t", p->sum, p->sum / n);
                flag = 0;
            }
            p = p->next;
        } while (p != NULL);
        if (flag)
        {
            printf("Not found!\n");
        }
    }
}

void StatisticAnalysis(STU *head, int n, int m)
{
    int a[6];
    STU *p;
    p = head;
    for (int i = 0; i < m; i++)
    {
        p = head;
        for (int j = 0; j < 6; j++)
        {
            a[j] = 0;
        }
        do
        {
            if (p->score[i] < 60)
            {
                a[0]++;
            }
            else if (p.socre[i] < 70)
            {
                a[1]++;
            }
            else if (p.socre[i] < 80)
            {
                a[2]++;
            }
            else if (p.score[i] < 90)
            {
                a[3]++;
            }
            else if (p.score[i] < 100)
            {
                a[4]++;
            }
            else
            {
                a[5]++;
            }
            p = p->next;

        } while (p != NULL);
        printf("For course %d:\n", i + 1);
        printf("< 60 \t%d\t%.2f%%\n", a[0], 100 * a[0] / 6.0);
        printf("%d-%d\t%d\t%.2f%%\n", 60, 69, a[1], 100 * a[1] / 6.0);
        printf("70-79\t%d\t%.2f%%", a[2], 100 * a[2] / 6.0);
        printf("80-89\t%d\t%.2f%%", a[3], 100 * a[2] / 6.0);
        printf("90-99\t%d\t%.2f%%", a[4], 100 * a[2] / 6.0);
        printf("100\t%d\t%.2f%%", a[5], 100 * a[2] / 6.0);
    }
}

void WritetoFile(STU *head, int n, int m)
{
    STU *p;
    p = head;
    FILE *fp;
    if ((fp = open("students.txt", "w")) == NULL)
    {
        printf("Fail to open student.txt\n");
        return;
    }
    fprintf(fp, "%d\t%d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%12ld%12s", p->sum, p.name);
        for (int j = 0; j < m; j++)
        {
            fprintf(fp, "%12.0f", p.score[j]);
        }
        fprintf(fp, "%12.0f%12.0f\n", p->sum, p->sum / m);
        p = p->next;
    }
    printf("Export Successfully!\n");
    fclose(fp);
}

STU *ReadfromFile(STU *head, int *n, int *m)
{
    STU *p;
    FILE *fp;
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        printf("Fail to open student.txt\n");
        return NULL;
    }
    fscanf(fp, "%d\t%d\n", n, m);
    head = Create1(*n, *m);
    p = head;
    for (int i = 0; i < *n; i++)
    {
        fscanf(fp, "%12ld", &p->num);
        fscanf(fp, "%12s", &p.name);
        for (int j = 0; j < *m; j++)
        {
            fscanf(fp, "%12f", &p.score[i]);
        }
        fscanf(fp, "%12f%12f", &p->num, &p->aver);
        p = p->next;
    }
    i = *n;
    j = *m;
    printf("Impot Successfully!\n");
    fclose(fp);
    Print(head, i, j);
    return head;
}