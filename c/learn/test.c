/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-11-11 19:52:00
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-15 14:03:34
 */

#include <stdio.h>
#include <stdlib.h>

/*

函数指针
int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    int (* p)(int, int) = &max;
    int a, b, c, d;
    printf("请输入三个数字：");
    scanf("%d %d %d", &a, &b, &c);
    d = p(p(a, b), c);
    printf("最大数字是：%d\n", d);
    return 0;
}
*/

/*
int getNextRandomValue(void);
void populate_array(int *array, size_t arraySize, int (*getNextvalue)(void)); //getNextvalue只是个形参

int main(void)
{
    int myarray[10];
    // getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针
    populate_array(myarray, 10, getNextRandomValue);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", myarray[i]);
    }
    
    return 0;
}

int getNextRandomValue(void)
{
    return rand();
}

void populate_array(int *array, size_t arraySize, int (*getNextvalue)(void))
{
    for (size_t i = 0; i < arraySize; i++)
    {
        array[i] = getNextvalue();
    }
    
}
*/