'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-25 17:09:25
LastEditors: ahtoh
LastEditTime: 2021-12-25 17:13:38
'''

import time
import threading

def loop():
    print("thread %s if running...." % threading.current_thread().name)
    n = 0
    while n < 5:
        n = n + 1
        print("thread %s >>> %s" %(threading.current_thread().name, n))
        time.sleep(5)
    print('thread %s ended' % threading.threading.current_thread().name)

print('thread %s is running...' % threading.current_thread().name)
t = threading.Thread(target=loop, name='LoopThread')
t.start()
t.join()
print('thread %s ended' %threading.current_thread().name)

