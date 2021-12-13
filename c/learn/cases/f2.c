/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-12-13 13:36:49
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-13 13:47:02
 */

int funct(int x, int y)
{
    extern int A, B;
    if (x > A && y > B)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}