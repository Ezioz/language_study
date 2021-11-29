/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-17 10:29:43
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-28 17:35:07
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

void Menu(void);                               // 菜单
LinkList Iint();                               // 创建学生信息（链表）
void Search(LinkList head, int temp_id);       // 查找学生信息
LinkList Delete(LinkList head, int temp_id);   // 删除学生信息
LinkList Amelem(LinkList head, int temp_id);   // 修改学生信息
LinkList SortElem(LinkList head, int temp_id); // 根据成绩排序链表，排序暂放，因为涉及了算法
int total(LinkList head);                      // 统计学生个数
void show(LinkList h);                         // 展示学生信息

int main(void)
{
    system("chcp 65001");
    LinkList head;
    head = (LinkList)malloc(sizeof(LEN));
    head->next = NULL;
    int menu, temp_id;
    while (1)
    {
        Menu();
        printf("请输入您要选择的功能:\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            head = Iint();
            printf("信息录入完成!\n");
            break;
        case 2:
            printf("请输入您要查询学生的id：\n");
            scanf("%d", &temp_id);
            Search(head, temp_id);
            break;
        case 3:
            printf("请输入要删除的学生id：\n");
            scanf("%d", &temp_id);
            head = Delete(head, temp_id);
            printf("剩余学生信息如下：\n");
            show(head);
            break;
        case 4:
            printf("请输入要修改学生信息的id：\n");
            scanf("%d", &temp_id);
            head = Amelem(head, temp_id);
            show(head);
        case 5:
            printf("请您选择排序方式：1.英语 2.python 3.c\n");
            scanf("%d", &temp_id);
            head = SortElem(head, temp_id);
            show(head);
            break;
        case 6:
            printf("只统计学生个数。\n");
            temp_id = total(head);
            printf("目前共有学生 %d 名。\n", temp_id);
            break;
        case 7:
            show(head);
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}

// 创建学生信息，此处有bug，重复调用会覆盖
LinkList Iint()
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

// 查找学生信息
void Search(LinkList head, int temp_id)
{
    LinkList temp = head;
    if (temp->next != NULL)
    {
        while (temp)
        {
            if (temp->id == temp_id)
            {
                printf("学生id：%d，姓名：%s，English：%0.2f, python：%0.2f，c：%0.2f\n", temp->id, temp->name, temp->english, temp->python, temp->c);
                break;
            }
            else if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                printf("没有找到该id信息。\n");
                break;
            }
        }
    }
    else
    {
        printf("没有学生信息！\n");
    }
}

// 删除学生信息
LinkList Delete(LinkList head, int temp_id)
{
    LinkList temp = head;
    LinkList del = NULL;

    if (temp->next != NULL)
    {
        while (temp)
        {
            if (temp->next->id == temp_id)
            {
                del = temp->next;
                temp->next = temp->next->next;
                free(del);
                return head;
            }
            else if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                printf("没有该id信息。\n");
                break;
            }
        }
    }
    else
    {
        printf("没有学生信息！\n");
    }
}

// 修改学生信息
LinkList Amelem(LinkList head, int temp_id)
{
    LinkList temp = head;
    if (temp->next != NULL)
    {
        while (temp)
        {
            if (temp->id == temp_id)
            {
                printf("已查找到id为 %d 的学生信息。\n", temp_id);
                printf("请输入新的English、python、c 成绩：\n");
                scanf("%d %d %d", &temp->english, &temp->python, &temp->c);
                return head;
            }
            else if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                printf("没有找到该id学生信息！\n");
            }
        }
    }
    else
    {
        printf("没有学生信息！\n");
    }
}

// 排序学生成绩
LinkList SortElem(LinkList head, int temp_id)
{
    if (temp_id >= 1 || temp_id <= 3)
    {
        LinkList temp, p, p1, p2;
        temp = head;
    }else
    {
        printf("您的输入有误！排序失败！");
    }

}

// 统计学生个数
int total(LinkList head)
{
    int student_number = 0;
    LinkList temp = head;
    // 这样最后一个结点会进入循环而少一次，但又由于头节点不存放数据，所以两者相抵
    while (temp->next != NULL)
    {
        student_number++;
        temp = temp->next;
    }
    return student_number;
}

// 全部展示学生信息
void show(LinkList h)
{
    LinkList p = h;
    if (p->next != NULL)
    {
        while (p->next != NULL)
        {
            p = p->next;
            printf("学生id：%d，姓名：%s，English：%0.2f, python：%0.2f，c：%0.2f\n", p->id, p->name, p->english, p->python, p->c);
        }
    }
    else
    {
        printf("没有学生信息！\n");
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