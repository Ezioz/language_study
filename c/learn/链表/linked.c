/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-11 11:04:24
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-11 11:07:07
 */

#include <malloc.h>

typedef struct student
{
    int sorce;
    struct student *next;
} LinkList;

LinkList *create(int n)
{
    LinkList *head, *node, *end;
    head = (LinkList *)malloc(sizeof(LinkList));
}
