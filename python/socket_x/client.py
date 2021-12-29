'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-22 09:58:43
LastEditors: ahtoh
LastEditTime: 2021-12-29 16:50:15
'''

# import socket
# s = socket.socket()
# host= socket.gethostname()
# port = 9999
# s.connect((host, port))
# print(s.recv(1024))
# s.close()

from socket import *

HOST = 'localhost'
PORT = 12345
BUFSIZ = 1024
ADDR = (HOST, PORT)

tcpclient = socket(AF_INET, SOCK_STREAM)
tcpclient.connect(ADDR)

while True:
    data = input('> ').strip()
    print(type(data))
    if not data:
        break
    tcpclient.send(data.encode())
    print(type(data.encode()))
    data = tcpclient.recv(BUFSIZ).decode()
    if not data:
        break
    print(data)
tcpclient.close()