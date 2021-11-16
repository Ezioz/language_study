/*
 * @Descripttion:
 * @version:
 * @Author: ahtoh
 * @Date: 2021-11-16 16:59:23
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-11-16 17:00:44
 */

struct Stu
{
    char no[10];           // 学号
    char name[10];         // 姓名
    char class_no[15];     // 班级
    char phone_number[15]; // 联系方式
    char gender;           // 性别
    struct Stu *next;
};
