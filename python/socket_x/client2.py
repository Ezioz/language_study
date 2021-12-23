'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-23 10:33:57
LastEditors: ahtoh
LastEditTime: 2021-12-23 13:41:13
'''

import socket

HOST = 'localhost'
PORT = 12345
ADDR = (HOST, PORT)

tcpclient = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcpclient.connect(ADDR)

while True:
    data = input('> ').strip()
    if not data:
        break
    tcpclient.send(data.encode())
    data = tcpclient.recv(1024)
    if not data:
        break
    print(data.decode())
tcpclient.close()
