'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-23 10:33:57
LastEditors: ahtoh
LastEditTime: 2021-12-25 22:28:50
'''

import socket

HOST = 'localhost'
PORT = 12345
ADDR = (HOST, PORT)

udpCliSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    data = input('>  ').strip()
    if not data:
        break
    udpCliSock.sendto(data.encode(), ADDR)
    data, ADDR = udpCliSock.recvfrom(1024)
    print(data)
    if not data:
        break
udpCliSock.close()

''' TCP
tcpclient = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcpclient.connect(ADDR)

while True:
    data = input('> ').strip()
    if not data:
        break
    tcpclient.send(data.encode())
    data = tcpclient.recv(1024)
    print(data.decode())
tcpclient.close()
'''

