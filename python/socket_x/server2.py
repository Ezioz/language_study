'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-23 10:33:52
LastEditors: ahtoh
LastEditTime: 2021-12-23 14:18:15
'''

from socket import *

HOST = 'localhost'
PORT= 12345
ADDR = (HOST, PORT)

tcpsock = socket(AF_INET, SOCK_STREAM)
tcpsock.bind(ADDR)
tcpsock.listen(5)

while True:
    print('...waiting...')
    tcpcall, addr = tcpsock.accept()
    print('...connect from :', addr)
    while True:
        data = tcpcall.recv(1024)
        if not data:
            break
        print(data.decode())
        tcpcall.send(data)
    tcpcall.close()
tcpsock.close()

