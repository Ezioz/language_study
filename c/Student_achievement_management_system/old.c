/*
 * @Descripttion: 学生成绩管理系统，原GitHub链接
 * https://github.com/csyxwei/StudentScoreManagerSystem/blob/master/%E6%88%90%E7%BB%A9%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F.c
 * 用于学习。
 * @version: 1.0
 * @Author: ahtoh
 * @Date: 2021-10-29 15:23:39
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-17 10:28:03
 */
/**
 * @description:
 * 照着别人程序写的时候，需要考虑到程序的功能，不然可能不知道这些代码做了什么
 * emmm，看别人代码，发现他自己在写的时候也不是很明确需求。打算推倒自己重新写。
 * @param {*}
 * @return {*}
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// // 宏定义
// #define MAX_LEN 10				   // 字符串最大程度
// #define STU_NUM 30				   // 最多学生数量
// #define COURSE_NUM 6			   // 最多考试科目
// #define LEN sizeof(struct Student) // 结构体长度

// // 自定义Student 结构体类型，里面有指针域，用于构成链表
// typedef struct Student
// {
// 	long num;
// 	char name[MAX_LEN];
// 	float score[COURSE_NUM];
// 	float sum;
// 	float aver;
// 	struct Student *next;
// } STU;

// int Menu(void);						 // 添加菜单
// STU *Create(int n, int m);			 // 创建链表并录入信息
// void Print(STU *head, int n, int m); // 打印函数

// int main(void)
// {
// 	int n, m; // n 是学生数，m是课程数
// 	int i;
// 	STU *head;						   // 定义头节点
// 	head = (STU *)malloc(sizeof(LEN)); // 获取内存空间
// 	while (1)
// 	{
// 		i = Menu();
// 		if (i == 1)
// 		{
// 			system("cls");							   // 清屏
// 			printf("Input student number(n < 30):\n"); //输入学生数
// 			scanf("%d", &n);
// 			printf("Input course number(m <= 6):\n");
// 			scanf("%d", &m);
// 		}
// 		switch (i)
// 		{
// 		case 1:
// 			printf("Input student's ID, name and score:\n");
// 			head = Create(n, m);
// 			break;

// 		default:
// 			break;
// 		}
// 	}
// }

// /**
//  * @description: 定义1个整数变量i，获取用户的输入；根据用户的输入，通过case，进入响应的功能。
//  * @param i
//  * @return i
//  */

// int Menu(void)
// {
// 	int i;
// 	system("title 学生成绩管理系统V1.0 By ahtoh");
// 	printf("1. Input record");
// 	printf("2. Caculate total and average score of every course\n");
// 	printf("3. Caculate total and average score of every student\n");
// 	printf("4. Sort in descending order by score\n");
// 	printf("5. Sort in ascending order by score\n");
// 	printf("6. Sort in ascending order by number\n");
// 	printf("7. Sort in dictionary order by name\n");
// 	printf("8. Search by number\n");
// 	printf("9. Search by name\n");
// 	printf("10. Statistic analysis\n");
// 	printf("11. List record\n");
// 	printf("12. Write to a file\n");
// 	printf("13. Read from a file\n");
// 	printf("0. Exit\n");
// 	printf("Please input your choice:");
// 	scanf("%d", &i);
// 	return i;
// }

// STU *Create(int n, int m)
// {
// 	STU *head, *p1, *p2;
// 	for (int i = 0; i < n + 1; i++)
// 	{
// 		p1 = (STU *)malloc(LEN);
// 		scanf("%ld", &p1->num);
// 		scanf("%s", p1->name);
// 		for (int j = 0; j < m; j++)
// 		{
// 			printf("第 %d 门课程", j + 1);
// 			scanf("%f", &p1->score[j]);
// 		}
// 		p1->next = NULL;
// 		if (i == 1)
// 		{
// 			head = p2 = p1;
// 		}else{
// 			p2->next = p1;
// 			p2 = p1;
// 		}
// 	}
// 	return head;
// }