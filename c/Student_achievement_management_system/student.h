/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-12-20 21:11:09
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-20 22:48:36
 */

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

