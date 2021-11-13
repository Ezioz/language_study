'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-11-11 20:10:53
LastEditors: ahtoh
LastEditTime: 2021-11-13 23:15:35
'''
#! -*- coding:utf8 -*-
import re
import os

filename = './students.txt'
def main():
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

def modify():
    show()
    if os.path.exists(filename):
        with open(filename, 'r') as rfile:
            student_old = rfile.readlines()
    else:
        return
    studentid = input("请输入学生ID：")
    with open(filename, 'w') as wfile:
        for student in student_old:
            d = dict(eval(student))
            if d['id'] == studentid:
                print("找到了这名学生，可以修改他的信息")
                while True:
                    try:
                        d['name'] = input("请输入姓名")
                        d['english'] = input("请输入英语成绩")
                        d['python'] = input("请输入python成绩")
                        d['c'] = input("请输入C语言成绩")
                    except:
                        print("您的输入有误，请重新输入！")
                    else:
                        break
                student = str(d)
                wfile.write(student + "\n")
                print("修改成功~")
            else: wfile.write(student)
    mark = input("是否继续修改其他学生信息？(y/n)")
    if mark == 'y':
        modify()

def search():
    mark = True
    student_query = []
    while mark:
        id = ""
        name = ''
        if os.path.exists(filename):
            mode = input('按ID查询输入1，按姓名查询输入2')
            if mode == '1':
                id = input('请输入学生ID：')
            elif mode == '2':
                name = input('请输入学生姓名：')
            else:
                print('您的输入有误，请重新输入！')
                search()
            with open(filename, 'r') as rfile:
                student = rfile.readlines()
                for list in student:
                    d = dict(eval(list))
                    if d is not '':
                        if d['id'] == id:
                            student_query.append(d)
                    elif name is not '':
                        if d['name'] == name:
                            student_query.append(d)
                show_student(student_query)
                student_query.clear()
                inputMark = input('是否继续查询？(y/n)：')
                if inputMark == 'y':
                    mark = True
                else:
                    mark = False
        else:
            print('暂未保存信息。。。')
            return

def show_student(studentList):
    if not studentList:
        print('(o@.@o) 无数据信息 (o@.@o)\n')
        return
    format_title = '{:^6}{:^12}\t{:^8}\t{:^10}\t{:^10}\t{:^10}'
    print(format_title.format('ID', '名字', '英语成绩', 'python成绩', 'C语言成绩', '总成绩'))
    format_data = '{:^6}{:^12}\t{:^12}\t{:^12}\t{:^12}\t{:^12}'
    for info in studentList:
        print(format_data.format(info.get('id'), info.get('name'),
        str(info.get('englisg')), str(info.get('python')), str(info.get('c')),
        str(info.get('englisg') + info.get('python') + info.get('c')).center(12)))
        
def total():
    if os.path.exists(filename):
        with open(filename, 'r') as rfile:
            student_old = rfile.readlines()
            if student_old:
                print('一共有 %d 名学生！' %len(student_old))
            else:
                print('还没有录入学生信息！')
    else:
        print('暂未保存数据信息。。。')

def show():
    student_new = []
    if os.path.exists(filename):
        with open(filename, 'r') as rfile:
            student_old = rfile.readlines()
        for list in student_old:
            student_new.append(eval(list))
        if student_new:
            show_student(student_new)
    else:
        print('暂未保存数据信息。。。')

def sort():
    show()
    if os.path.exists(filename):
        with open(filename, 'r') as file:
            student_old = file.readlines()
            student_new = []
        for list in student_old:
            d = dict(eval(list))
            student_new.append(d)
    else:
        return
    ascORdesc = input('请选择(0 升序；1 降序)：')
    if ascORdesc == '0':
        ascORdesc = False
    elif ascORdesc == '1':
        ascORdesc = True
    else:
        print('您的输入有误，请重新输入！')
        sort()
    mode = input("""
    1. 按英语成绩排序
    2. 按python成绩排序
    3. 按c成绩排序
    0. 按总成绩排序
    """)
    if mode == '1':
        student_new.sort(key=lambda x:x['english'], reverse=ascORdesc)
    elif mode == '2':
        student_new.sort(key=lambda x:x['python'], reverse=ascORdesc)
    elif mode == '3':
        student_new.sort(key=lambda x:x['c'], reverse=ascORdesc)
    elif mode == '0':
        student_new.sort(key=lambda x:x['english'] + x['python'] + x['c'], reverse=ascORdesc)
    else:
        print('您的输入有误，请重新输入！')
        sort()
    show_student(student_new)
    

if __name__ == '__main__':
    main()