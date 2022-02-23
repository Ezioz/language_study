/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2022-01-06 19:48:46
 * @LastEditors: ahtoh
 * @LastEditTime: 2022-02-23 11:26:26
 */

// #include <stdio.h>
// #include <string.h>

// int main(int argc, char const *argv[])
// {
//     char name[40];
//     scanf("%s", name);
//     printf("%zd %d", sizeof(name), strlen(name));
//     return 0;
// }

#include <stdio.h>

#define MAX_LEN 10
typedef struct Student
{
    long num;
    char name[MAX_LEN];
    float sum;
    struct Student *next;
} STU;

int main(int argc, char const *argv[])
{
    STU *head;
    head = (STU *)malloc(sizeof(struct Student));
    scanf("%s", head->name);
    head->num = 100.0;
    printf("head -> name %s", head->name);
    return 0;
}
