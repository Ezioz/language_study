'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-22 09:58:43
LastEditors: ahtoh
LastEditTime: 2021-12-22 23:00:57
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
    data = input('> ')
    if not data:
        break
    tcpclient.send(data)
    data = tcpclient.recv(BUFSIZ)
    if not data:
        break
    print(data.decode('utf-8'))
tcpclient.close()