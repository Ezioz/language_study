/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-17 15:49:19
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-21 17:30:45
 */

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

extern STU;

void Menu(void);
Linklist Init(void);
void Search(Linklist head, int temp_id);
STU *Delete(STU *head, int temp_id);
STU *Amelem(STU *head, int temp_id);
// Linklist SortElm(STU *head, int temp_id);
int total(Linklist head);
Linklist ClassSort(Linklist head);

int main(int argc, char const *argv[])
{
    system("chcp 65001");
    Linklist head;
    head = (Linklist)malloc(LEN);
    head->next = NULL;
    int menu, temp_id;
    while (1)
    {
        Menu();
        printf("请输入您要选择的功能：");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            head = Init();
            printf("信息录入完成！");
            break;
        case 2:
            printf("请输入您要查找的学生id：\n");
            scanf("%d", &temp_id);
            Search(head, temp_id);
            break;
        case 3:
            printf("请输入要删除的学生id：");
            scanf("%d", &temp_id);
            head = Delete(head, temp_id);
            break;
        case 4:
            printf("请输入要修改学生的id：");
            scanf("%d", &temp_id);
            head = Amelem(head, temp_id);
            show(head);
            break;
        case 5:
            printf("请您选择排序方式：1.英语 2.python 3.c\n");
            // scanf("%d", &temp_id);
            head = ClassSort(head);
            show(head);
            break;
        case 6:
            printf("只统计学生个数：\n");
            temp_id = total(head);
            printf("目前共有学生：%d 名。\n", temp_id);
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

// 展示学生信息
void show(Linklist head)
{
    Linklist temp = head;
    if (temp->next == NULL)
    {
        printf("没有学生信息。\n");
        return 0;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("学生id：%d，姓名：%s，English：%0.2f, python：%0.2f，c：%0.2f\n", temp->id, temp->name, temp->english, temp->python, temp->c);
    }
}

// 统计学生个数
int total(Linklist head)
{
    int student_number = 0;
    Linklist temp = head;
    while (temp->next != NULL)
    {
        student_number++;
        temp = temp->next;
    }
    return student_number;
}

// 排序学生成绩，1 英语， 2 python， 3 c
// Linklist SortElm(STU *head, int temp_id)
// {
//     switch (temp_id)
//     {
//     case 1:
//         char classname[8] = "english";
//         head = ClassSort(head);
//         break;
//     case 2:
//         char classname[8] = "python";
//     case 3:
//         char classname[8] = "c";
//     default:
//         printf("您的输入有误，没有排序！");
//         break;
//     }
// }

// 课程排序
Linklist ClassSort(Linklist head)
{
    Linklist temp, p, p2;
    temp = head;
    if (temp->next->next != NULL)
    {
        // p = temp;
        // p2 = temp->next;
        for (p = temp->next; p->next != NULL; p = p->next)
        {
            for (p2 = temp->next->next; p2->next != NULL; p2 = p2->next)
            {
                if (p->english < p2->english)
                {
                    p = p2->next;
                    p2 = temp->next;
                    temp = p2;
                }
            }
        }
        return head;
    }
    else if (temp->next != NULL)
    {
        printf("目前只有一个学生信息，不需要排序！\n");
        show(head);
    }
    else
    {
        printf("目前没有学生信息！");
    }
    return 0;
}

// 修改学生信息
STU *Amelem(STU *head, int temp_id)
{
    struct Student *temp;
    temp = head;
    if (temp->next == NULL)
    {
        printf("暂时没有学生信息！");
        return 0;
    }
    while (temp = temp->next)
    {
        if (temp->id == temp_id)
        {
            printf("请输入新的学生id：");
            scanf("%d", &temp->id);
            printf("请输入新的学生姓名：");
            scanf("%s", temp->name);
            printf("请输入新的英语成绩：");
            scanf("%f", &temp->english);
            printf("请输入新的python成绩：");
            scanf("%f", &temp->python);
            printf("请输入新的c成绩：");
            scanf("%f", &temp->c);
        }
        break;
    }
    return head;
}

// 删除学生信息
STU *Delete(STU *head, int temp_id)
{
    Linklist temp, rel_p = NULL;
    temp = head;
    if (temp->next != NULL)
    {
        while (temp)
        {
            if (temp->id == temp_id)
            {
                rel_p = temp->next;
                temp->next == temp->next->next;
                free(rel_p);
                printf("id 为 %d 的学生已被删除！", temp_id);
            }
            else if (temp->id != temp_id)
            {
                temp = temp->next;
            }
            else
            {
                printf("没有找到该学生信息！");
            }
        }
    }
    else
    {
        printf("暂时没有学生信息！");
    }
}

// 查找学生信息
void Search(Linklist head, int temp_id)
{
    Linklist temp = head;
    if (temp->next == NULL)
    {
        printf("暂时没有学生信息！");
        return 0;
    }
    while (temp = temp->next)
    {
        if (temp->id == temp_id)
        {
            printf("学生id：%d, 姓名：%s, english：%0.2f, python：%0.2f, c：%0.2f\n", temp->id, temp->name, temp->english, temp->python, temp->c);
            break;
        }
        else
        {
            printf("没有找到该id信息！");
            break;
        }
    }
    return head;
}

// 创建链表
Linklist Init(void)
{
    STU *head, *next, *end, *temp;
    head = (Linklist)malloc(LEN);
    if (head == NULL)
    {
        return 0;
    }
    head->next = NULL;
    temp = next = head;
    printf("请输入要录入的学生个数：\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        end = (Linklist)malloc(LEN);
        if (!end)
        {
            return 0;
        }
        printf("请输入学生id：");
        scanf("%d", &end->id);
        printf("请输入学生姓名：");
        scanf("%s", end->name);
        printf("请输入英语成绩：");
        scanf("%f", &end->english);
        printf("请输入python成绩：");
        scanf("%f", &end->python);
        printf("请输入c成绩：");
        scanf("%f", &end->c);
        next->next = end;
        end->next = NULL;
        next = end;
    }
    return head;
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