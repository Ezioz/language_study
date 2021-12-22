'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-22 09:50:26
LastEditors: ahtoh
LastEditTime: 2021-12-22 10:01:46
'''
import socket

tcpSocket = socket.socket()
host=  socket.gethostname()
port = 12345
tcpSocket.bind((host, port))

tcpSocket.listen(5)
while True:
    c, addr = tcpSocket.accept()
    print('连接地址：', addr)
    c.send('welcome')
    c.close()

