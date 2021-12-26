'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-23 10:33:52
LastEditors: ahtoh
LastEditTime: 2021-12-26 22:48:53
'''

from socket import *
import os
from time import ctime

HOST = 'localhost'
PORT= 12345
ADDR = (HOST, PORT)

udpSerSock = socket(AF_INET, SOCK_DGRAM)



'''
tcpser = socket(AF_INET, SOCK_STREAM)
tcpser.bind(ADDR)
tcpser.listen(5)

while True:
    print('---waiting---')
    sermsg, addr = tcpser.accept()
    print('connected from : ', addr)
    while True:
        data = sermsg.recv(1024)
        if not data:
            break
        print(data.decode())
        sermsg.send(data)
    sermsg.close()
tcpser.close()
'''
