/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-17 10:29:43
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-19 10:00:36
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 宏定义
#define BOOL int
#define TRUE 1
#define FALSE 0
#define LEN sizeof(struct student)

// 学生结构体，只有id，名字，英语、python、c的成绩
typedef struct student
{
    int id;
    char name[30];
    float english;
    float python;
    float c;
    struct student *next;
} Stu, *LinkList;

// 函数定义
void Menu(void);
LinkList insert();
void show(LinkList h);

int main(void)
{
    system("chcp 65001");
    LinkList head;
    head = (LinkList)malloc(sizeof(LEN));
    while (1)
    {
        printf("请输入您要选择的功能:\n");
        Menu();
        switch (1)
        {
        case 1:
            head = insert();
            printf("信息录入完成!\n");
            break;
            case 2:
            
        default:
            break;
        }

    }  
    return 0;
}

// 创建学生信息
LinkList insert()
{
    Stu *head, *next, *end;
    head = (LinkList)malloc(sizeof(Stu));
    if (head == NULL)
    {
        return 0;
    }
    head->next = NULL;
    next = head;
    printf("请输入要录入学生的个数\n");
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        end = (LinkList)malloc(sizeof(Stu));
        if (!end)
        {
            return 0;
        }
        printf("请输入学生id：");
        scanf("%d", &end->id);
        printf("请输入姓名:");
        scanf("%s", end->name);
        printf("请输入英语成绩：");
        scanf("%f", &end->english);
        printf("请输入python成绩：");
        scanf("%f", &end->python);
        printf("请输入 c 成绩：");
        scanf("%f", &end->c);
        next->next = end;
        end->next = NULL;
        next = end;
    }
    return head;
}

// 全部展示学生信息
void show(LinkList h)
{
    LinkList p = h->next;
    while (p != NULL)
    {
        printf("学生id：%d，姓名：%s，English：%0.2f, python：%0.2f，c：%0.2f\n", p->id, p->name, p->english, p->python, p->c);
        p = p->next;
    }
    
}

// 菜单
void Menu(void)
{
    puts("学生信息管理系统\n\
    1. 录入学生信息\n\
    2. 查找学生信息\n\
    3. 删除学生信息\n\
    4. 修改学生信息\n\
    5. 排序\n\
    6. 统计学生信息\n\
    7. 显示所有学生信息\n\
    0. 退出系统");
}