/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2022-01-11 19:55:52
 * @LastEditors: ahtoh
 * @LastEditTime: 2022-01-11 23:33:19
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

// int main(void)
// {
//     printf("some number limits for this system:\n");
//     printf("biggest int : %d\n", INT_MAX);
//     printf("Smallest long long : %lld\n", LLONG_MIN);
//     printf("one byte = %d bits ont this system.\n", CHAR_BIT);
//     printf("Largest dobule : %e\n", DBL_MAX);
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int jane, tarzan, cheeta;
//     cheeta = tarzan = jane = 68;
//     printf("first round score %4d %8d %8d\n", cheeta, tarzan, jane);

//     return 0;
// }

#define SQUARES 64
int main(int argc, char const *argv[])
{
    const double CROP = 2E16;
    double current, total;
    int count = 1;
    printf("square  grains  total");
    printf("fraction of \n");
    printf("added   grains  ");
    printf("world total\n");
    total = current = 1.0;
    printf("%4d %13.2e  %12.2e %12.2e\n", count, current, total, total / CROP);
    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;
        total = total + current;
        printf("%4d %13.2e  %12.2e %12.2e\n", count, current, total, total / CROP);
    }
    printf("That's all\n"); 
    return 0;
}
