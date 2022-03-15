'''
Descripttion: 
version: 
Author: ahtoh
Date: 2022-01-28 11:01:49
LastEditors: ahtoh
LastEditTime: 2022-03-15 17:04:22
'''

# try:
#     print(5/0)
# except ZeroDivisionError:
#     print("You can't divide by zero!")
# -*- coding:utf-8 -*-
content = input('请输入字符：')
sp = input('请输入分隔符：')
content_list = content.split(sp)
test_list = []
for i in content_list:
    test_list.append(chr(int(i)))
print('ascii is : \n\t', ''.join(test_list))
    
