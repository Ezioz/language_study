/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-09 10:06:30
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-09 10:09:08
 */

#include <stdlib.h>
#include <conio.h>

int m[36] = {0}, s = 0, can = 0, air = 16, c = 0, i = 6, j, *p;

void move(int *q, int v)
{
    if (*q < 1 ? 0 : q[v] || (q[v] = *q, move(q + v, v), *q = can = 0))
    {
        q[v] - *q || (q[v] = ~*q, s += 1 << *q, *q = can = 0, ++air);
    }
}