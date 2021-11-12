'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-11-11 20:10:53
LastEditors: ahtoh
LastEditTime: 2021-11-12 20:14:05
'''
#! -*- coding:utf8 -*-
import re
import os

filename = './students.txt'
def main():
    test()
    ctrl = True
    while(ctrl):
        menu()
        option = input("请选择：")
        option_str = re.sub("\D", "", option)
        if option_str in ['0', '1', '2', '3', '4', '5', '6', '7']:
            option_int = int(option_str)
            if option_int == 0:
                print("您已经退出学生信息管理系统")
                ctrl = False
            elif option_int == 1:
                insert()
            elif option_int == 2:
                search()
            elif option_int == 3:
                delete()
            elif option_int == 4:
                modify()
            elif option_int == 5:
                sort()
            elif option_int == 6:
                total()
            elif option_int == 7:
                show()

def menu():
    print("""
    学生信息管理系统
    1. 录入学生信息
    2. 查找学生信息
    3. 删除学生信息
    4. 修改学生信息
    5. 排序
    6. 统计学生信息
    7. 显示所有学生信息
    0. 退出系统
    说明：通过数字或↑↓方向键选择菜单
    """)


def save(student):
    try:
        student_txt = open(filename, 'a')
    except Exception as e:
        student_txt = open(filename, 'w')
    for info in student:
        student_txt.write(str(info) + "\n")
    student_txt.close()

def insert():
    studentList = []
    mark = True
    while mark:
        id = input("请输入Id（如10001）")
        if not id:
            break
        name = input("请输入名字")
        if not name:
            break
        try:
            english = int(input("请输入英语成绩："))
            python = int(input("请输入python成绩："))
            c = int(input("请输入C成绩："))
        except:
            print("输入无效，不是整型值。。。重新录入信息")
            continue
        stdent = {"id": id, "name": name, "english": english, "python": python, "c": c}
        studentList.append(stdent)
        inputMark = input("是否继续添加？(y/n)：")
        if inputMark == 'y':
            mark = True
        else:
            mark = False
    save(studentList)
    print("学生信息录入完毕！")

def delete():
    mark = True
    while mark:
        studentId = input("请输入要删除学生的Id：")
        if studentId is not "":
            if os.path.exists(filename):
                with open(filename, 'r') as rfile:
                    student_old = rfile.readlines()
            else:
                student_old = []
            ifdel = False
            if student_old:
                with open(filename, 'r') as wfile:
                    d = {}
                    for list in student_old:
                        d = dict(eval(list))
                        if d['id'] != studentId:
                            wfile.write(str(d) + "\n")
                        else:
                            ifdel = True
                    if ifdel:
                        print("ID 为 %s 的学生信息已被删除"%studentId)
                    else:
                        print("没有找到ID为 %s 的学生信息。。。"%studentId)
            else:
                print("无学生信息。。。")
                break
            show()
            inputMark = input("是否继续删除？(y/n)：")
            if inputMark == 'y':
                mark = True
            else:
                inputMark = False


if __name__ == '__main__':
    main()