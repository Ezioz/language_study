/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-16 16:59:23
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-04 20:36:15
 */

#define PENALTY 0.1 // 罚金 0.1 元每天
#define DEADLINE 60 // 最长借书时间60天

struct Date
{
    int year;
    int month;
    int day;
};

struct Book
{
    char issn[30];      // issn编号
    char title[30];     // 书名
    char publisher[20]; // 出版社
    char author[20];    // 作者
    double price;       // 价格
    char available;     // 是否借走
    char no[10];        // 被谁借走
    struct Book *next;
};

struct History // 借阅历史
{
    char no[10];             // 学号
    char issn[30];           // issn编号
    struct Date borrow_date; // 借书时间
    struct Date return_date; // 还书时间
    double penalty;          // 违约金
    struct History *next;
};

struct Stu
{
    char no[10];           // 学号
    char name[10];         // 姓名
    char class_no[15];     // 班级
    char phone_number[15]; // 联系方式
    char gender;           // 性别
    struct Stu *next;
};
