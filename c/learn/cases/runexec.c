/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-12-29 10:18:25
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-29 10:34:34
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char command[20];
    printf("input your command: \n");
    scanf("%s", command);
    system(command);
    return 0;
}
