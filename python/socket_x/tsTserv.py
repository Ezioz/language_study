'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-22 09:50:26
LastEditors: ahtoh
LastEditTime: 2021-12-23 10:09:56
'''
# import socket

# tcpSocket = socket.socket()
# host=  socket.gethostname()
# port = 12345
# tcpSocket.bind((host, port))

# tcpSocket.listen(5)
# while True:
#     c, addr = tcpSocket.accept()
#     print('连接地址：', addr)
#     c.send('welcome')
#     c.close()

from os import truncate
from socket import *
from time import ctime

HOST = ''
PORT = 12345
BUFSIZ = 1024
ADDR = (HOST, PORT)

tcpSock = socket(AF_INET, SOCK_STREAM)
tcpSock.bind(ADDR)
tcpSock.listen(5)

while True:
    print('waiting for connection...')
    tcpclisock, addr = tcpSock.accept()
    print('...connected from : ', addr)
    while True:
        data = tcpclisock.recv(BUFSIZ)
        print(data)
        if not data:
            break
        tcpclisock.send(data)
    tcpclisock.close()
tcpSock.close()
