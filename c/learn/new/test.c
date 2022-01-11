/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2022-01-06 19:48:46
 * @LastEditors: ahtoh
 * @LastEditTime: 2022-01-11 19:37:18
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char name[40];
    scanf("%s", name);
    printf("%zd %d", sizeof(name), strlen(name));
    return 0;
}
