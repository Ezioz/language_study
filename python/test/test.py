'''
Descripttion: 
version: 
Author: ahtoh
Date: 2022-01-04 09:14:47
LastEditors: ahtoh
LastEditTime: 2022-01-04 09:19:22
'''

# 装饰器
def funA(fn):
    print("C zhong")
    fn()
    print('http://wwww')
    return 'xx'

@funA
def funB():
    print('study python')

print(funB)