'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-23 10:33:52
LastEditors: ahtoh
LastEditTime: 2021-12-23 22:23:17
'''

from socket import *
import os

HOST = 'localhost'
PORT= 12345
ADDR = (HOST, PORT)

tcpsock = socket(AF_INET, SOCK_STREAM)
tcpsock.bind(ADDR)
tcpsock.listen(5)

while True:
    print('....waiting.....')
    consock, addr = tcpsock.accept()
    print('connected from .....', addr)
    while True:
        data = consock.recv(1024)
        if not data:
            break
        print(data)
        print(os.system(data.decode()))
        consock.send(bytes(os.system(data.decode())))
    consock.close()
tcpsock.close()
