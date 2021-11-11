/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-10 16:51:36
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-10 22:37:31
 */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *p1;
    float *p2;
    p1 = (int *)malloc(sizeof(int));
    p2 = (float *)malloc(sizeof(float));
    if (p1 != NULL && p2 != NULL)
    {
        printf("空间分配成功");
    }else{
        printf("空间分配失败");
    }
    return 0;
}
