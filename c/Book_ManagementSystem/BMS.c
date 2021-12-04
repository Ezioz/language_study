/*
 * @Descripttion: https://github.com/shilela/Book-Management-System/blob/master/BMS.c
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-16 16:30:34
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-04 21:37:24
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "Stu.h"

#define welcome "欢迎使用图书管理系统"

struct Stu *stu_head = NULL; // 学生头指针

char upper_getchar(void);                                            // 修改选项为大写
void add_stu(void);                                                  // 添加学生信息
int search_stu(char no[], struct Stu **stu_p1, struct Stu **stu_p2); // 校验学生记录是否已存在

int main(void)
{
    char option;
    do
    {
        puts("图书管理系统");
        puts("A 学生信息管理");
        puts("B 图书信息管理");
        puts("C 借/还书");
        puts("D 综合查询");
        puts("E 清空数据/初始化");
        puts("Q 退出");
        puts("请输入选项，按回车键确认，大小写均可");
        switch (option = upper_getchar())
        {
        case 'A':
            stu_management();
            write_file();
            break;

        default:
            break;
        }
    } while (option != 'Q');
}

char upper_getchar(void)
{
    char ch;
    while (ch = toupper(getchar()))
    {
        if (ch == '\n')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return ch;
}

// 添加学生信息
void add_stu(void)
{
    char option; // 选项
    struct Stu *stu_p1 = NULL;
    struct Stu *stu_p2 = NULL;
    struct Stu stu;

    puts("请输入学号:");
    printf("学号：___\b\b\b");
    scanf("%s", stu.no);
    puts("查找中....");
    if (search_stu(stu.no, &stu_p1, &stu_p2) == 1)
    {
        puts("已有该学生记录");
        Sleep(1000);
        return;
    }
    puts("请填写该新生详细信息，按回车键录入");
    printf("学号: %s\n", stu.no);
    printf("姓名: _____\b\b\b");
    scanf("%s", &stu.name);
    puts("姓名已录入！");

    printf("班级:______\b\b\b");
    scanf("%s", &stu.class_no);
    puts("班级已录入!");

    printf("性别:____\b\b");
    stu.gender = upper_getchar();
    puts("性别已录入！");

    printf("联系方式:______\b\b\b\b\b");
    scanf("%s", &stu.phone_number);
    puts("联系方式已录入！");
    stu.next = NULL;
    puts("是否保存，输入Y/N，不区分大小写\n");
    do
    {
        option = upper_getchar();
        if (option == 'Y')
        {
            stu_p2 = (struct Stu *)malloc(sizeof(struct Stu));
            *stu_p2 = stu;
            system("pause");
            if (stu_head == NULL)
            {
                stu_head = stu_p2;
            }
            else
            {
                stu_p2->next = stu_p2;
            }
            puts("已录入！");
            Sleep(500);
        }

    } while (!(option == 'Y' || option == 'N'));
}

// 校验学生记录是否已存在
int search_stu(char no[], struct Stu **stu_p1, struct Stu **stu_p2)
{
    int flag = 0;
    *stu_p1 = *stu_p2 = stu_head;
    while (*stu_p2 != NULL)
    {
        if (strcmp(no, (*stu_p2)->no) == 1)
        {
            flag = 1;
            break;
        }
        *stu_p1 = *stu_p2;
        *stu_p2 = (*stu_p1)->next;
    }
    if (flag)
    {
        puts("找到此学生");
        printf("学号: %s 姓名: %s 班级: %s 联系方式: %s 性别:%s\n", (*stu_p2)->no, (*stu_p2)->name,
               (*stu_p2)->class_no, (*stu_p2)->phone_number, (*stu_p2)->gender);
    }
    else
    {
        puts("无记录！");
        system("pause");
        return flag;
    }
}