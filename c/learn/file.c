/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-25 09:59:24
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-25 10:20:22
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char str[30];
    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open file strike any key exit!");
        getch();
        exit(1);
    }
    fgets(str, 30, fp);
    printf("%s\n", str);
    fclose(fp);
}


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