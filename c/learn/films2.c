/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-17 21:15:38
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-18 13:02:56
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

// 定义结构体
struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
};

char *s_gets(char *st, int n);
int main(void)
{
    struct film *head = NULL; // 头指针指向空
    struct film *prev, *current; // prev，上一个；current 当前
    char input[TSIZE];
    puts("Entert first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
        {
            head = current;
        }else{
            prev->next = current;
            strcpy(current->title, input);
            puts("Enter your rating <0-10>:");
            scanf("%d", &current->rating);
            while (getchar() != '\n')
            {
                continue;
            }
            puts("Enter next movie title (empty line to stop):");
            prev = current;
            
        }
    }
    if (head == NULL)
    {
        printf("No data entered.");
    }else{
        printf("Here is the movie list:\n");
    }
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);

    }
    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
        printf("bye\n");
        return 0;
    }
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';

        }else{
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}