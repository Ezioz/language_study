/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-05 21:53:49
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-05 22:31:06
 */

#include <stdio.h>

int main(void)
{
    typedef struct student
    {
        char no[10];
        char name[20];
        struct student *next;
    } Stu;
    Stu stu_test = {"1001", "zhu", NULL};
    // Stu *stu_p0;
    Stu **stu_p2;
    Stu *stu_head = &stu_test;
    Stu **stu_p1 = stu_head;
    // *stu_p1 = *stu_p2 = stu_head;
    printf("test:%p\n", stu_test);
    printf("head:%p\n", *stu_head);
    printf("p1:%p\n", *stu_p1);
    // printf("p2:%p\n", &stu_p0);

    return 0;
}