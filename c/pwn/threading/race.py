'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-11-29 17:11:21
LastEditors: ahtoh
LastEditTime: 2021-11-29 17:17:38
'''

#-*- coding:utf-8 -*-

import threading
COUNT = 0

def Run(threads_name):
    global COUNT
    read_value = COUNT
    print("COUNT in Thread-%s is %d"%(str(threads_name), read_value))
    COUNT = read_value + 1

def main():
    threads = []
    for j in range(10):
        t = threading.Thread(target=Run, args=(j, ))
        threads.append(t)
        t.start()
    for i in range(len(threads)):
        threads[i].join()
    print("Finally, The count is %d" %(COUNT, ))

if __name__ == '__main__':
    main()