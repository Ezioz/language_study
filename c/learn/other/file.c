/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-25 09:59:24
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-09 11:14:24
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 4, b = 20, c = 2;
    // a *= b + c; // a = a * (b + c) 220
    // a = b = 10;
    // a = (b = 1) + 4; // a 5 b 1
    // a += a -= a * a; // -24
    // printf("%d", a == 0 && b != 0 || a != 0 && b == 0); // 1. b!=0, a!=0 2. a==0 b==0 3. 与或
    printf("%d", a < b ? a + b : a < c ? a
                                       : c); // 24
    return 0;
}

// int main(void)
// {
//     int a = 1, b = 4, c = 2;
//     float x = 10.5, y = 4.2, z;
//     z = (a + b) / c + (int)y % c * 1.2 + x;
//     printf("%f", z);
//     return 0;
// }

// int main(void)
// {
//     FILE *fp;
//     char str[30];
//     fp = fopen("file.txt", "r"); // fopen()函数的的头文件为 <stdio.h>
//     if (fp == NULL)
//     {
//         printf("Cannot open file strike any key exit!");
//         getch();
//         exit(1);
//     }
//     fgets(str, 30, fp);
//     printf("%s\n", str);
//     fclose(fp);
// }

/*
int main(void)
{
    FILE *fp;
    system("chdir");
    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("The file does not exist!");
        exit(0);
    }
    else
    {
        printf("Open the file.\n");
        if (fclose(fp) == 0)
        {
            printf("The file has been closed!\n");
        }
        else
        {
            printf("The file can't be closed!\n");
        }
    }
    return 0;
}
*/

// #define N 100

// int main(void)
// {
//     FILE *fp;
//     if ((fp = fopen("file.txt", "r")) == NULL)
//     {
//         printf("open file default");
//     }
//     char ch;
//     while ((ch = fgetc(fp)) != EOF)
//     {
//         putchar(ch);
//     }
//     putchar('\n');

//     fclose(fp);
//     system("pause");
//     return 0;
// }

// EOF，end of file，表示文件末尾，是在stdio.h中定义的宏，它的值是一个负数，往往是 -1

// int main(void)
// {
//     FILE *fp;
//     char ch;
//     if ((fp = fopen("./file.txt", "r")) == NULL)
//     {
//         puts("fail to open file\n");
//         exit(0);
//     }
//     while ((ch = fgetc(fp)) != EOF)
//     {
//         putchar(ch);
//     }
//     putchar('\n');
//     if (ferror(fp))
//     {
//         puts("read error");
//     }
//     else
//     {
//         puts("read success");
//     }
//     fclose(fp);
//     return 0;
// }

// int main(void)
// {
//     FILE *fp;
//     char ch;
//     if ((fp = fopen("./file.txt", "wt+")) == NULL)
//     {
//         puts("fail to open file\n");
//         exit(0);
//     }
//     printf("Input a string:\n");
//     while ((ch = getchar()) != '\n')
//     {
//         fputc(ch, fp);
//     }
//     fclose(fp);
//     return 0;
// }

// int main(void)
// {
//     FILE *fp;
//     char ch;
//     if ((fp = fopen("./test.txt", "w+")) == NULL)
//     {
//         puts("Fail to open file\n");
//         exit(0);
//     }
//     printf("Input a string:\n");
//     while ((ch = getchar()) != '\n')
//     {
//         fputc(ch, fp);
//     }

//     fclose(fp);
//     printf("read file\n");
//     if ((fp = fopen("./test.txt", "r")) == NULL)
//     {
//         printf("fail to read file\n");
//         exit(0);
//     }
//     while ((ch = fgetc(fp)) != EOF)
//     {
//         putchar(ch);
//     }
//     fclose(fp);

//     return 0;
// }
