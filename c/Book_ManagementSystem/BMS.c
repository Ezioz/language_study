/*
 * @Descripttion: https://github.com/shilela/Book-Management-System/blob/master/BMS.c
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-16 16:30:34
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-07 09:37:48
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "Stu.h"

#define welcome "欢迎使用图书管理系统"
// *************全局变量*************************
struct Stu *stu_head = NULL;         // 学生头指针
struct Book *book_head = NULL;       // 书本头指针
struct History *history_head = NULL; // 历史头指针

char upper_getchar(void);                                            // 修改选项为大写
void add_stu(void);                                                  // 添加学生信息
int search_stu(char no[], struct Stu **stu_p1, struct Stu **stu_p2); // 校验学生记录是否已存在

// **************学生管理系统********************
void stu_management(void); // 学生管理系统

// ************读写*********************
void write_file(void); // 写文件并释放内存空间
void read_file(void);  // 申请内存空间并读文件

int main(void)
{
    system("chcp 65001"); // 设置终端语言
    char option;          // 定义一个变量option用来接收用户的选项
    do                    // 使用do...while循环，肯定是先执行一次嘛
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
    char option;               // 选项
    struct Stu *stu_p1 = NULL; // 定义结构体变量指针p1
    struct Stu *stu_p2 = NULL; // 定义结构体变量指针p1
    struct Stu stu;            // 定义结构体变量 stu

    puts("请输入学号:");
    printf("学号：___\b\b\b");
    scanf("%s", stu.no); // 虽然是学号，但由于是char类型的，所以不需要取地址符&
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
// 传入的参数有学号，p1 指针的地址，p2 指针的地址
int search_stu(char no[], struct Stu **stu_p1, struct Stu **stu_p2)
{
    int flag = 0;
    *stu_p1 = *stu_p2 = stu_head; // 此时三个值均为NULL
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

/* 学生管理系统
第一个功能是学生管理系统，其实这个系统跟图书管理系统有点像了，也是一个小系统，会有很多的功能。
添加/修改/删除 学生信息
查看所有学生个人信息
返回图书管理系统
*/
void stu_management(void)
{
    char option;
    system("cls");
    do
    {
        puts("**********学生信息管理*************");
        puts("A 添加学生信息");
        puts("B 修改学生个人信息");
        puts("C 删除学生个人信息");
        puts("D 查看所有学生个人信息");
        puts("Q 返回图书管理系统");
        puts("请输入选项：按回车键确认，大小写均可");
        puts("所有信息存放在D盘");
        switch (option = upper_getchar())
        {
        case 'A':
            add_stu();
            break;

        default:
            break;
        }
        system("cls");
    } while (option != 'Q');
}

// 写文件
void write_file(void)
{
    FILE *fp;
    struct Stu *stu_p1 = NULL;
    struct Stu *stu_p2 = NULL;
    struct Book *book_p1 = NULL;
    struct Book *book_p2 = NULL;
    struct History *history_p1 = NULL;
    struct History *history_p2 = NULL;
    fp = fopen("stu.txt", "wb");
    if (stu_head != NULL)
    {
        stu_p1 = stu_p2 = stu_head;
        while (stu_p2 != NULL)
        {
            stu_p1 = stu_p2;
            fwrite(stu_p1, sizeof(struct Stu), 1, fp);
            stu_p2 = stu_p1->next;
        }
    }
    fclose(fp);
    // 写图书文件
    fp = fopen("book.txt", "wb");
    if (book_head != NULL)
    {
        book_p1 = book_p2 = book_head;
        while (book_p2 != NULL)
        {
            book_p1 = book_p2;
            fwrite(book_p1, sizeof(struct Book), 1, fp);
            book_p2 = book_p1->next;
        }
    }
    fclose(fp);
    //写历史文件
    fp = fopen("history.txt", "wb");
    if (history_head != NULL)
    {
        history_p1 = history_p2 = history_head;
        while (history_p2 != NULL)
        {
            history_p1 = history_p2;
            fwrite(history_p1, sizeof(struct History), 1, fp);
            history_p2 = history_p1->next;
        }
    }
    fclose(fp);
}

void read_file(void)
{
    FILE *fp;
    struct Stu *stu_p1 = NULL;
    struct Stu *stu_p2 = NULL;
    struct Book *book_p1 = NULL;
    struct Book *book_p2 = NULL;
    struct History *history_p1 = NULL;
    struct History *history_p2 = NULL;

    if ((fp = fopen("stu.txt", "rb")) == NULL)
    {
        fp = fopen("stu.txt", "wb+");
    }
    stu_head = stu_p1 = stu_p2 = (struct Stu *)malloc(sizeof(struct Stu));
    fread(stu_p1, sizeof(struct Stu), 1, fp);
    while (!feof(fp))
    {
        stu_p1 = stu_p2;
        stu_p2 = (struct Stu *)malloc(sizeof(struct Stu));
        stu_p1->next = stu_p2;
        fread(stu_p2, sizeof(struct Stu), 1, fp);
    }
    if (stu_p1 == stu_p2)
    {
        stu_head = NULL;
    }
    else
    {
        stu_p1->next = NULL;
    }
    free(stu_p2);
    fclose(fp);

    if ((fp = fopen("book.txt", "rb")) == NULL)
    {
        fp = fopen("book.txt", "wb+");
    }
    book_head = book_p1 = book_p2 = (struct Book *)malloc(sizeof(struct Book));
    fread(book_p1, sizeof(struct Book), 1, fp);
    while (!feof(fp))
    {
        book_p1 = book_p2;
        book_p2 = (struct Book *)malloc(sizeof(struct Book));
        book_p1->next = book_p2;
        fread(book_p2, sizeof(struct Book), 1, fp);
    }
    if (book_p1 == book_p2)
    {
        book_head = NULL;
    }
    else
    {
        book_p1->next = NULL;
    }
    free(book_p2);
    fclose(fp);
    // 读借阅历史文件
    if ((fp = fopen("history.txt", "rb")) == NULL)
    {
        fp = fopen("history.txt", "wb+");
        history_head = history_p1 = history_p2 = (struct History *)malloc(sizeof(struct History));
        fread(history_p1, sizeof(struct History), 1, fp);
        while (!feof(fp))
        {
            history_p1 = history_p2;
            history_p2 = (struct History *)malloc(sizeof(struct History));
            history_p1->next = history_p2;
            fread(history_p2, sizeof(struct History), 1, fp);
        }
        if (history_p1 == history_p2)
            history_head = NULL;
        else
            history_p1->next = NULL;
        free(history_p2);
        fclose(fp);
    }
}