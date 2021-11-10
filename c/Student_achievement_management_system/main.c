/*
 * @Descripttion: 学生成绩管理系统，原GitHub链接
 * https://github.com/csyxwei/StudentScoreManagerSystem/blob/master/%E6%88%90%E7%BB%A9%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F.c
 * 用于学习。
 * @version: 1.0
 * @Author: ahtoh
 * @Date: 2021-10-29 15:23:39
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-10 16:00:49
 */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include "malloc.h"
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
}STU;

int Menu(void);

int main(void)
{
	int n, m;
	int i;
	STU *head;
	head = (STU *)malloc(LEN);
	while (1)
	{
		i = Menu();
		if (i == 1)
		{
			system("cls");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number(n<30):\n"); //输入学生数
			printf("\t\t\t");
			scanf("%d", &n);
			printf("\t\t\tInput course number(m<=6):\n");
			printf("\t\t\t");
			scanf("%d", &m);
		}
		switch (i)
		{
		case 1:
			printf("\t\t\tInput student's ID, name and score:\n");
			// head = Creat(n, m);
			system("cls");  //清屏
			break;
		
		default:
			break;
		}	

	}
	
}


int Menu(void)
{
	int i;
	system("title 学成成绩管理系统V1.0 By ahtoh");
	printf("\n\n");
	printf("\t\t\t                         学生成绩管理系统V7.0\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\t*                Management for Students' scores                             *\n");
	printf("\t\t\t*                1.  Input record                                            *\n");
	printf("\t\t\t*                2.  Caculate total and average score of every course        *\n");
	printf("\t\t\t*                3.  Caculate total and average score of every student       *\n");
	printf("\t\t\t*                4.  Sort in descending order by score                       *\n");
	printf("\t\t\t*                5.  Sort in ascending order by score                        *\n");
	printf("\t\t\t*                6.  Sort in ascending order by number                       *\n");
	printf("\t\t\t*                7.  Sort in dictionary order by name                        *\n");
	printf("\t\t\t*                8.  Search by number                                        *\n");
	printf("\t\t\t*                9.  Search by name                                          *\n");
	printf("\t\t\t*                10. Statistic analysis                                      *\n");
	printf("\t\t\t*                11. List record                                             *\n");
	printf("\t\t\t*                12. Write to a file                                         *\n");
	printf("\t\t\t*                13. Read from a file                                        *\n");
	printf("\t\t\t*                0.  Exit                                                    *\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t*****************Please Input your choice:");
	scanf("%d", &i);
	return i;
}
