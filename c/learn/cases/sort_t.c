/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-13 20:20:37
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-13 20:25:32
 */

#include <stdio.h>

/* ζε₯ζεΊ */

#define LEN 5
int a[LEN] = {10, 5, 2, 4, 7};

void insertion_sort(void);
int main(int argc, char const *argv[])
{
    insertion_sort();
    return 0;
}

void insertion_sort(void)
{
    int key, i;
    for (int j = 1; j < LEN; j++)
    {
        printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }

    printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
}