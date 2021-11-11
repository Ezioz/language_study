/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-10 16:51:36
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-11 13:44:11
 */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    struct student
    {
        int num;
        char name[40];
        float score[7];
    };

    struct student student1 = {1, "aaaa0", 7.0};
    printf("%d", student1.num);
    
    return 0;
}
