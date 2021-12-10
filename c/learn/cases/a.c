/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-09 10:51:48
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-10 17:08:12
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
/*
// 输入若干个字符，分别统计数字字符和字母字符的个数，当输入换行时输出统计结果

int main(void)
{
    char ch;
    int st1 = 0, st2 = 0;            // st1 为 数字个数， st2 为字母个数
    while ((ch = getchar()) != '\n') // 先计算 ch = getchar() ，再判断 ch 是否等于 \n
    {
        // if (ch >= '0' && ch <= '9')
        // {
        //     st1++;
        // }

        // if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        // {
        //     st2++;
        // }
        ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ? st2++ : (ch >= '0' && ch <= '9') ? st1++
                                                                                                  : 1;
                                                                                                  // 从右往左结合
    }
    printf("num: %d \t letter: %d", st1, st2);
    return 0;
}
*/

// int main(void)
// {
//     int i, j, c1, c2, c3, c4;
//     i = 10;
//     j = 12;
//     c1 = ~i;
//     c2 = i & j;
//     c3 = i | j;
//     c4 = i ^ j;
//     printf("~i = %d \n", c1);
//     printf("i&j = %d \n", c2);
//     printf("i|j = %d \n", c3);
//     printf("i^j = %d \n", c4);
//     return 0;
// }

/* 已知圆的半价，求圆的面积 */

// #define PI 3.14

// int main(void)
// {
//     float r, area;
//     puts("input r");
//     scanf("%f", &r);
//     area = r * r * PI;
//     printf("area : %f\n", area);
//     return 0;
// }

/* 输入三个数，求最大值 */
/*
int main(void)
{
    int a, b, c, result;
    scanf("%d %d %d", &a, &b, &c);
    result = c > (a > b ? a : b) ? c : (a > b ? a : b);
    printf("max : %d", result);
    return 0;
}
*/

// int main(void)
// {
//     // int a = 10, b = 20, c, d;
//     // c = a + b, a - b;
//     // printf("%#x\n", c);
//     float a = 135.203, b = 452.33;
//     printf("%3.2f, %14.3f", a, b);
//     return 0;
// }

/* 输入某年某月某日，判断这一天是这一年第几个星期中的第几天 */
/*
int main(void)
{
    int year, month, february, day, sum = 0;

    printf("input your date\n");
    scanf("%d %d %d", &year, &month, &day);

    february = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)
                   ? 29
                   : 28; // 判断闰年
    int t_one[12][2] = {
        {1, 31},
        {2, february},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31},
    };
    for (int i = 0; i < month - 1; i++)
    {
        sum += t_one[i][1];
    }
    printf("%d\n", sum + day);                                // 一年当中的第几天
    printf("%d\t%d", ((sum + day) / 7) + 1, (sum + day) % 7); // 一年当中第几个周的第几天，这个还是有问题的

    // char name[4] = "aa";
    // if (strchr(name, 'a'))
    // {
    //     printf("1");
    // }
    // return 0;
}
*/

/* 斐波那契 */
/*
int main(void)
{
    int i, t, f1 = 1, f2 = 1;
    printf("%d %d ", 1, 1);
    while (i <= 20)
    {
        t = f1 + f2;
        printf("%d ", t);
        if (i % 5 == 0)
            printf("\n");
        f1 = f2;
        f2 = t;
        i++;
    }
}
*/

/* 将一个正整数分解质因数 90 = 2 * 3 * 3 * 5 */
/*
int main(void)
{
    int n, i;
    printf("\n please input a number:\n");
    scanf("%d", &n);
    printf("%d = ", n);
    for (int i = 2; i <= n; i++)
    {
        while (n != i)
        {
            if (n % i == 0)
            {
                printf("%d * ", i);
                n = n / i;
            }
            else
                break;
        }
    }
    printf("%d", n);
    return 0;
}
*/
/*
int main(void)
{
    int i;                       //它的作用域对整个函数有用
    for (int i = 0; i < 10; i++) // 如果在for循环中定义，它的作用域只在for循环中有用
    {
        printf("1\n");
    }
    printf("xx = %d", i);
}
*/

/* 判断一个数是否为素数 */
/*
int main(void)
{
    int n, m, flag = 0;
    scanf("%d", &n);
    m = sqrt(n);
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("%d is not a prime number", n);
    }
    else
    {
        printf("%d is a prime number", n);
    }
}
*/

/* 用辗转相除法对输入的两个正整数m和n求其最大公约数和最小公倍数 */
/*
int main(void)
{
    int m, n, a, b, r, t;
    printf("输入两个正整数:");
    scanf("%d, %d", &m, &n);
    a = m;
    b = n;
    if (m > 0 && n > 0)
    {
        if (m < n)
        {
            t = m;
            m = n;
            n = t;
        }
        r = m % n;
        while (r != 0)
        {
            m = n;
            n = r;
            r = m % n;
        }
        printf("%d and %d maximum is %d\n", a, b, n);
    }
    else
    {
        printf("Error\n");
    }
    printf("%d is %d lowest is %d\n", a, b, a * b / n);
}
*/
/* 猴子吃桃子问题。猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个。第二天早上又将剩下的桃子吃棹一半，
又多吃了一个。以后每天早上都吃了昨天的一半零一个。到第10 天早上一看，只剩下一个桃子了。求第一天共摘下多少个桃子。*/

// int main(void)
// {
//     int x = 0, y = 1;
//     for (int i = 9; i > 0; i--)
//     {
//         x = 2 * (y + 1);
//         y = x;
//     }
//     printf("%d\n", x);
// }

// int main(void)
// {
//     int x = 0, y = 1;
//     for (int i = 9; i > 0; i--)
//     {
//         x = 2 * (y + 1);
//         y = x;
//     }
//     printf("%d", y);
// }

/* 输出100以内所有素数 */

// int main(void)
// {
//     int k = 0, j;
//     for (int i = 2; i < 100; i++)
//     {
//         for (j = 2; j < i; j++)
//         {
//             if (i % j == 0)
//             {
//                 break;
//             }
//         }
//         if (i == j)
//         {
//             k++;
//             printf("%4d ", i);
//             if (k % 5 == 0)
//             {
//                 printf("\n");
//             }
//         }
//     }
// }

/* 输入一个字符串，当字符串没有超过10个字符时，输出没有超过10个字符的内容；当超过时，输出超过了10个字符的内容 */
// 好奇怪，为啥两个都输出啊
// int main(void)
// {
//     char str[100];
//     printf("char char char\n");
//     scanf("%s", str);
//     if (strlen(str) < 10)
//     {
//         printf("%d\n", strlen(str));
//         goto Label1;
//     }
//     else
//     {
//         printf("111\n");
//         goto Label2;
//     }
// Label1:
//     printf("&lt; 10\n");
// Label2:
//     printf("&gt; 10");
//     return 0;
// }

/* 有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少 */

// int main()
// {
//     int i, j, k, t;
//     int count = 0;
//     printf("they are as follows:\n");
//     for (t = 0, i = 1; i <= 4; i++)       //百位数字有4种选择
//         for (j = 1; j <= 4; j++)          //十位数字有3种选择
//             if (j != i)                   //遇到十位数字等于百位数字时跳过
//                 for (k = 1; k <= 4; k++)  //个位数字只有2种选择了
//                     if (k != i && k != j) //个位数字与十位或百位数字相等时跳过
//                     {
//                         count++;
//                         printf(++t % 10 ? "%4d" : "%4d\n", i * 100 + j * 10 + k); //输出该三位数
//                     }
//     if (t % 10)
//         printf("\n");
//     printf("have %d number", count);
//     return 0;
// }

/* 输入10个整数存入一维数组，按逆序重新存放后再输出 */

// int main(void)
// {
//     int a[10] = {0};
//     for (int i = 0; i < 10; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     printf("---------\n");
//     for (int i = 9; i >= 0; i--)
//     {
//         printf("%d ", a[i]);
//     }
// }

/* 打印杨辉三角 */

/* 一个数如果恰好等于它的因子之和，则这个数就称为“完数”。例如6=1+2+3。编程找出1000以内的所有完数。*/
/* 输入两个数组（数组元素个数自定），输出在两个数组中都不出现的元素。*/

// int main(void)
// {
//     char name[10];
//     char test[] = "string";
//     strncpy(name, test, 3);
//     printf("%s", name);
//     return 0;
// }

/* 从键盘输入10个字符串，并按照从小到大的顺序输出 */
/*
int main(void)
{
    char a[10][80], c[80];
    int k = 0;
    printf("input 10 words:\n");
    for (int i = 0; i < 10; i++)
    {
        gets(a[i]);
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++) // 不断进行对比排序，确定k的值，也就是在字符中的位置
        {
            if (strcmp(a[j], a[k]) < 0)
            {
                k = j;
            }
        }
        if (k != i)
        {
            strcpy(c, a[i]);
            strcpy(a[i], a[k]);
            strcpy(a[k], c);
        }
    }
    printf("--------------");
    for (int i = 0; i < 10; i++)
    {
        puts(a[i]);
    }
}
*/

/* 编写程序实现输出一个字符串后，将字符串的内容颠倒过来。*/
/*
int main(void)
{
    char str[30];
    gets(str);
    for (int i = 0; i <= strlen(str); i++)
    {
        printf("%c", str[(strlen(str) - i)]);

    }
    return 0;
}
*/


