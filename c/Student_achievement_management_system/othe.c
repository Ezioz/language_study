/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-15 11:00:22
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-15 20:59:14
 */

#include <stdio.h>
#include <stdlib.h>

// 宏定义
#define MAX_LEN 10
#define STU_NUM 30
#define COURSE_NUM 6
#define LEN sizeof(struct Student)

typedef struct Student
{
    long num;
    char name[MAX_LEN];
    float score[COURSE_NUM];
    float sum;
    float aver;
    struct Student *next;
} STU;

// 功能函数
int Menu(void);                                      // 菜单
STU *Create(int n, int m);                           // 创建学生链表
void AverSumofEveryStudent(STU *head, int n, int m); // 计算每门课程的总分和平均分
void AverSUmofEveryCourse(STU *head, int n, int m);  //

int main(int argc, char const *argv[])
{
    system("chcp 65001");
    int n, m;
    int i;
    STU *head;
    head = (STU *)malloc(sizeof(LEN));
    while (1)
    {
        i = Menu();
        if (i == 1)
        {
            system("cls");
            printf("Input student number(n<30):\n");
            scanf("%d", &n);
            printf("input course number(m<=6):\n");
            scanf("%d", &m);
        }
        switch (i)
        {
        case 1:
            printf("Input student's ID, name and score:\n");
            head = Create(n, m);
            break;
        case 2:
            system("cls");
            AverSumofEveryStudent(head, n, m);
            break;
        case 3:
            system("cls");
            AverSUmofEveryCourse(head, n, m);
            break;
        default:
            break;
        }
    }

    return 0;
}

// 创建学生信息链表
STU *Create(int n, int m)
{
    struct Student *head, *p1, *p2;
    for (int i = 0; i < n + 1; i++)
    {
        p1 = (STU *)malloc(sizeof(LEN));
        scanf("%ld", &p1->num);
        scanf("%s", p1->name);
        for (int j = 0; j < m; j++)
        {
            printf("this is the %d class:", j + 1);
            scanf("%f", &p1->score[j]);
        }
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
    STU *p = head;
    float sum;
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
    STU *p = head;
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