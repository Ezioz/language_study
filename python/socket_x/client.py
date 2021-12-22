'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-22 09:58:43
LastEditors: ahtoh
LastEditTime: 2021-12-22 09:59:56
'''

import socket
s = socket.socket()
host= socket.gethostname()
port = 9999
s.connect((host, port))
print(s.recv(1024))
s.close()