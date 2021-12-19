/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-17 15:49:19
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-19 22:50:56
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct Student)

typedef struct Student
{
    int id;
    char name[30];
    float english;
    float python;
    float c;
    struct Student *next;
} STU, *Linklist;

void Menu(void);
Linklist Init(void);
void Search(Linklist head, int temp_id);
STU *Delete(STU *head, int temp_id);
STU *Amelem(STU *head, int temp_id);
Linklist SortElm(STU *head, int temp_id);

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
            printf("请您选择排序方式：1.英语 2.python 3.c");
            scanf("%d", &temp_id);
            head = SortElm(head, temp_id);
            break;
        default:
            break;
        }
    }
    return 0;
}

// 排序学生成绩
Linklist SortElm(STU *head, int temp_id)
{
    Linklist temp;
    temp = head;
    
}

// 修改学生信息
STU *Amelem(STU *head, int temp_id)
{
    struct Student *temp;
    temp = head;
    if (temp->next != NULL)
    {
        while (temp)
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
        }
    }
    else
    {
        printf("暂时没有学生信息！");
    }
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
    if (temp->next != NULL)
    {
        while (temp)
        {
            if (temp->id == temp_id)
            {
                printf("学生id：%d, 姓名：%s, english：%f, python：%f, c：%f\n", temp->id, temp->name, temp->english, temp->python, temp->c);
                break;
            }
            else if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                printf("没有找到该id信息！");
                break;
            }
        }
    }
    else
    {
        printf("暂时没有学生信息！");
    }
}

// 创建链表
Linklist Init(void)
{
    STU *head, *next, *end;
    head = (Linklist)malloc(LEN);
    if (head == NULL)
    {
        return 0;
    }
    head->next = NULL;
    next = head;
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