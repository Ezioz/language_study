/*
 * @Descripttion: https://github.com/shilela/Book-Management-System/blob/master/BMS.c
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-16 16:30:34
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-16 17:04:03
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "Stu.h"

#define welcome "欢迎使用图书管理系统"

// **********学生管理系统**********
void stu_management(void); // 学生管理系统
void add_stu(void);        //添加学生

int main(void)
{

    for (int i = 0; i < strlen(welcome); i++)
    {
        printf("%c", welcome[i]);
        // Sleep(100);
    }
    char option;
    do
    {
        puts("**********图书管理系统*********");
        puts("A. 学生信息管理系统");
        puts("B. 图书信息管理系统");
        puts("C. 借/还书");
        puts("D. 综合查询");
        puts("E. 清空数据/初始化");
        puts("Q. 退出");
        puts("请输入选项，按回车确认，大小写均可。");
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

    return 0;
}

// 学生管理系统
void stu_management(void)
{
    char option;
    system("cls");
    do
    {
        puts("**********学生信息管理**********");
        puts("A.添加学生信息");
        puts("B.修改学生个人信息");
        puts("C.删除学生个人信息");
        puts("D.查看所有学生个人信息");
        puts("Q.返回图书管理系统");
        puts("请输入选项：按回车键确认，大小写均可");
        puts("所有信息存放在d盘下");
        switch (option = upper_getchar())
        {
        case 'A':
            add_stu();
            break;
        default:
            break;
        }
    } while (option != 'Q');
}

// 添加学生
void add_stu(void)
{
    char option;
    struct Stu *stu_p1 = NULL;
    struct Stu *stu_p2 = NULL;
    struct Stu stu;
    
}