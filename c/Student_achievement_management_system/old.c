/*
 * @Descripttion: 学生成绩管理系统，原GitHub链接
 * https://github.com/csyxwei/StudentScoreManagerSystem/blob/master/%E6%88%90%E7%BB%A9%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F.c
 * 用于学习。
 * @version: 1.0
 * @Author: ahtoh
 * @Date: 2021-10-29 15:23:39
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-30 16:22:54
 */
/**
 * @description:
 * 照着别人程序写的时候，需要考虑到程序的功能，不然可能不知道这些代码做了什么
 * emmm，看别人代码，发现他自己在写的时候也不是很明确需求。打算推倒自己重新写。x
 * 这个程序有个不好处,就是课程名不具体,只是几门课程,记忆起来有点混乱
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

int Menu(void);                                      // 添加菜单
STU *Create(int n, int m);                           // 创建链表并录入信息
STU *Create1(int n, int m);                          //
void Print(STU *head, int n, int m);                 // 打印函数
void AverSumofEveryStudent(STU *head, int n, int m); // 计算每门课程的总分和平均分
void AverSumofEveryCourse(STU *head, int n, int m);  // 计算每个学生的总分和平均分
STU *SortbyScore(STU *head, int n);                  // 按每个学生的总分由高到低排出名次表
STU *SortbyScore1(STU *head, int n);                 //按每个学生的总分由低到高排出名次表
STU *SortbyNum(STU *head);                           // 按学号由小到大排出成绩表

int main(void)
{
    system("chcp 65001");
    int n, m; // n 是学生数，m是课程数
    int i;
    STU *head;                         // 定义头节点
    head = (STU *)malloc(sizeof(LEN)); // 获取内存空间
    while (1)
    {
        i = Menu();
        if (i == 1) // 当i = 1时,除了触发这个if, 还触发下面的 case 1
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
            system("cls");
            break;
            // 计算每门课程的总分和平均分
        case 2:
            system("cls");
            AverSumofEveryStudent(head, n, m);
            break;
            // 计算每个学生的总分和平均分
        case 3:
            system("cls");
            AverSumofEveryCourse(head, n, m);
            break;
            // 按每个学生的总分由高到低排出名次表
        case 4:
            system("cls");
            printf("Sort in ascending order by score:");
            head = SortbyScore(head, n);
            Print(head, n, m);
            break;
            // 按每个学生的总分由低到高排出名次表
        case 5:
            system("cls");
            printf("Sort in ascending order by score:");
            head = SortbyScore1(head, n);
            Print(head, n, m);
            break;
            //
        case 6:
            system("cls");
            printf("Sort in ascending order by number:\n");
            head = SortbyNum(head);
            break;
            // case 7:
            //     system("cls");
            //     printf("Sort in dictionary order by name:\n");
            //     head = SortbyName(head, n);
            //     Print(head, n, m);
            //     break;
            // case 8:
            //     system("cls");
            //     printf("Input the number you want to search:\n");
            //     SearchbyNum(head, n, m);
            //     break;
            // case 9:
            //     system("cls");
            //     printf("Input the name you want to search:");
            //     SearchbyName(head, n, m);
            //     break;

        default:
            break;
        }
    }
}

// 菜单
int Menu(void)
{
    int i;
    system("title 学生成绩管理系统V1.0 By ahtoh");
    printf("1. Input record\n");
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
    STU *head, *p1, *p2; // head 是头指针，p2 是临时指针， p1 指向新创结点
    for (int i = 0; i < n + 1; i++)
    {
        p1 = (STU *)malloc(LEN);
        scanf("%ld", &p1->num);
        scanf("%s", p1->name);
        for (int j = 0; j < m; j++) // j 代表的是当前是第几门课程
        {
            printf("this is the %d class:", j + 1);
            scanf("%f", &p1->score[j]);
        }
        p1->next = NULL; // 创建新节点后，其指针域指向为NULL。
        if (i == 1)
        {
            head = p2 = p1; // 当是第一个节点的时候，三个指针均指向第一个结点,同时需要注意,这第一个结点数据域是有数据的
        }
        else
        {
            p2->next = p1; // 之后将下一个结点的地址放入上一个结点的指针域
            p2 = p1;       // 再调整p2 指针指向下一个结点的地址
        }
    }
    return head; // 返回头结点指针
}

// 计算每门课程的总分和平均分
void AverSumofEveryStudent(STU *head, int n, int m) // m为课程数量
{
    STU *p = head;
    // char ch; 该函数压根就没用到这个
    float sum; // sum 统计的是课程总分
    int j = 1; // j 的功能是输出当前是第几门课程
    if (head != NULL)
    {
        for (int i = 0; i < m; i++) // i 代表的是当前是第几门课程
        {
            p = head;
            sum = 0.0;
            do
            {
                sum += p->score[i];
                p = p->next;
            } while (p != NULL); // score[i] 代表的是某门课程,通过do...while不断循环计算
            printf("course %d: sum = %.0f, aver = %.0f\n", j, sum, sum / n);
            j++;
        }
    }
}

// 计算每个学生的总分和平均分
void AverSumofEveryCourse(STU *head, int n, int m)
{
    STU *p = head;
    if (head != NULL)
    {
        for (int i = 0; i < n; i++) // i 代表的是当前学生
        {
            p->sum = 0.0;
            for (int j = 0; j < m; j++) // j 代表的是当前课程
            {
                p->sum += p->score[j];
            }
            p->aver = p->sum / n;
            printf("sutdent %d: sum = %.0f, aver = %.0f\n", i + 1, p->sum, p->aver);
            p = p->next;
        }
    }
}

// 按每个学生的总分由高到低排出名次表
STU *SortbyScore(STU *head, int n)
{
    STU *endpt, *p, *p1, *p2; // endpt用于控制循环比较; p为临时指针变量
    p1 = (STU *)malloc(LEN);  // 为p1 开辟一段内存空间
    p1->next = head;          // 将p1 的指针域存储head的地址,此时p1 成为了链表的首结点,其数据域为空
    head = p1;                // 再让head 指向p1,此时 head 与 p1 指向同一地址
    /*
    第一次外层for循环时,endpt=null,其不等于head成立
    进入内层for循环.将p指针指向与p1与head相同的地址,p1->next->next不等于endpt成立,因为endpt=null.进入if判断.此处功能是判断链表程度,如果成立,则说明只有一个结点
    p1->next->sum代表的是第二个结点的数据域中的sum值,与第三个结点的sum值进行比较,如果小于,则
    p2 = p1->next->next: p2指向第三个结点
    p1->next->next = p2->next: 第二个结点的指针域存储的不再是第三个结点的地址,而是第四个
    p2->next = p1->next: 此时p1 指向的还是首结点,p1->next指向的是第二个结点,将其赋值给p2->next,
    原第三个结点指针域中存储的地址不再是第四个结点的地址,而是第二个,结合上一步,第二个结点和第三个结点调换了位置
    p1->next = p2: 将首结点指针域指向新的第二个结点,就是p2指向的地址
    p = p1->next->next: p1->next->next 指向的是新的第三个结点,将其赋值给p
    循环结束后, p1 = p1->next: p1 指向第二个结点
     */
    /*
    第二次内层for循环.如果 p1->next->next != endpt(null),成立,则跳出该循环
    endpt = p: 如果上式成立,则说明p指针指向的是最后一个结点;进入外层for循环 endpt != head 成立,进入内层for循环.
    p1->next->next != endpt 成立,因为此时endpt 的值不再为null,p1 指向第二个结点,endpt指向第三个结点,所以p1->next->next的值为null

    这段代码真的挺强的,还要注意最后一次循环时的,p = p1 = head, p指针会初始化
     */
    for (endpt = NULL; endpt != head; endpt = p) // endpt初始值为null,若不与head指向同一地址,它就和p指向同一地址
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
    head = head->next; // 将head指针移向第二个结点
    free(p1);
    p1 = NULL;
    return head;
}

// 按每个学生的总分由低到高排出名次表
STU *SortbyScore1(STU *head, int n)
{
    STU *endpt, *p, *p1, *p2;
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

// 按学号由小到大排出成绩表
STU *SortbyNum(STU *head)
{
    STU *first, *t, *p, *q;
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

// 创建  链表
/*
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
*/