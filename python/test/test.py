'''
Descripttion: 
version: 
Author: ahtoh
Date: 2022-01-04 09:14:47
LastEditors: ahtoh
LastEditTime: 2022-01-10 17:19:49
'''

# 装饰器
# def funA(fn):
#     print("C zhong")
#     fn()
#     print('http://wwww')
#     return 'xx'

# @funA
# def funB():
#     print('study python')

# print(funB)

# def is_odd(n):
#     return n % 2 == 1

# L = list(filter(is_odd, range(1, 20)))
# print(L)


def decorator(F):
    def new_fa(a, b):
        print("input: ", a, b)
        return F(a, b)
    return new_fa


@decorator
def square_diff(a, b):
    return a**2 - b**2


@decorator
def square_add(a, b):
    return a**2 + b**2


print(square_add(3, 4))
print(square_diff(3, 4))
