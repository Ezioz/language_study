/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-29 13:52:15
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-29 16:46:09
 */

#include <stdio.h>
#include <string.h>
#include "windows.h"

// int main(void)
// {
//     unsigned long long a = 4294967296;
//     char buf[8] = "1234567";
//     unsigned long b = 1;
//     char overflow[65550];
//     printf("%d\n", sizeof(buf));
//     printf("%d\n", sizeof(b));
//     printf("%d\n", sizeof(a));
//     system("pause");
//     return 0;
// }

// // 基于栈的整数溢出
// int main(int argc, char *argv)
// {
//     int i;
//     char buf[8];             // 栈缓冲区
//     unsigned short int size; // 无符号短整型范围：0~65535
//     char overflow[65550];
//     // memset()函数的作用是将某一块内存中的全部内容设置为指定的值，这个函数通常为新申请的内存做初始化工作
//     // 第一个参数为指针，指向要填充的内存块；第二个参数为填充的值，该值以int形式传递；第三个参数是要设置该字符的个数
//     memset(overflow, 65, sizeof(overflow)); // 填充65550个“A”字符
//     printf("请输入数值：\n");
//     scanf("%d", &i); // 输入65540
//     size = i;
//     printf("size: %d\n", size); // 输出系统识别出来的size数值 4，因为65540 超出 65535的范围，又从0开始
//     printf("i: %d\n", i);       // 输出系统识别出来的i数据，65540
//     if (size > 8)               // 边界检查，size为4，不大于8
//     {
//         return -1;
//     }
//     // memcpy(void *str1, const void *str2, size_t n)函数用于从存储区s2复制n个字节到存储区s1
//     memcpy(buf, overflow, i); // 从数组overflow中复制65540个字节的“A”到buf数组中，而buf只有8个字节，也就是1个字节，从而导致栈溢出
//     return 0;
// }

// 双重释放漏洞

// int main(void)
// {
//     void *p1, *p2, *p3;
//     p1 = malloc(100);
//     printf("Alloc p1: %p\n", p1);
//     p2 = malloc(100);
//     printf("Alloc p2: %p\n", p2);
//     p3 = malloc(100);
//     printf("Alloc p2: %p\n", p3);

//     printf("Free p2\n");
//     printf("Double Free p2\n");
//     free(p2);
//     free(p2);
//     printf("Free p1\n");
//     free(p1);
//     printf("Free p3\n");
//     free(p3);

//     return 0;
// }

// 释放后重引用漏洞（UAF）
// #define size 32
// int main(void)
// {
//     char *buf1, *buf2;
//     buf1 = (char *)malloc(size);
//     printf("buf1: 0x%p\n", buf1);
//     free(buf1);
//     // 分配 buf2 去“占坑” buf1 的内存位置
//     buf2 = (char *)malloc(size);
//     printf("buf2: 0x%p\n", buf2);
//     // 对buf2进行内存清零
//     memset(buf2, 0, size);
//     printf("buf2: %d\n", *buf2);
//     // 重引用已释放的 buf1 指针，但却导致 buf2 值被篡改
//     printf("=== Use After Free ===\n");
//     strncpy(buf1, "hack", 5);
//     printf("buf2: %s\n", buf2);
//     free(buf2);
//     system("pause");
// }

// 数组越界
int main(void)
{
    system("chcp 65001");
    int index;
    int array[3] = {0x11, 0x22, 0x33};
    printf("输入数组索引下标.\n");
    scanf("%d", &index);
    printf("输出数组元素：array[%d] = 0x%x\n", index, array[index]);
    system("pause");
    return 0;
}