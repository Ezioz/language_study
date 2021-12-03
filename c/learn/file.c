/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-25 09:59:24
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-03 17:08:35
 */

#include <stdio.h>
#include <stdlib.h>

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

