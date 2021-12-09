/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-09 10:51:48
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-09 16:20:20
 */
#include <stdio.h>
#include <string.h>

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