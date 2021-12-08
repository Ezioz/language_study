/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-08 12:35:34
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-08 12:46:08
 */

#include <stdio.h>

int main(void)
{
    double num1 = 0.0;
    double num2 = 0.0;
    char operation = 0; // 虽然是char类型，但不是数组
    printf("Enter your formula\n");
    scanf("%lf%c%lf", &num1, &operation, &num2); // 此处符号的输入，需要&取地址符，因为不是数组

    switch (operation)
    {
    case '+':
        printf("=%lf", num1 + num2);
        break;
    case '-':
        printf("=%lf", num1 - num2);
        break;
    case '*':
        printf("=%lf", num1 * num2);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("The divisor cannot equal 0");
        }
        else
        {
            printf("=%lf", num1 / num2);
            break;
        }
    case '%':
        if ((long)num2 == 0)
        {
            printf("The divisor cannot equal 0");
        }
        else
        {
            printf("=%ld", (long)num1 % (long)num2); // 余数是整数
            break;
        }

    default:
        printf("da sha x");
        break;
    }
}