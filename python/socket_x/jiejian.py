'''
Descripttion:
version:
Author: ahtoh
Date: 2022-01-20 15:45:33
LastEditors: ahtoh
LastEditTime: 2022-01-27 16:30:10
'''
#!/usr/bin/env python3
# coding:utf-8

import socket
import time
import random
import threading
import urllib3
import requests
import hashlib
import sys
import re
from socket import error

localtime = time.asctime(time.localtime(time.time()))


class ProxyServerTest():
    def __init__(self, proxyip):
        # 本地socket服务
        self.ser = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.proxyip = proxyip

    def run(self):
        try:
            # 本地服务IP和端口
            self.ser.bind(('127.0.0.1', 5320))
            # 最大连接数
            self.ser.listen(10)
        except error as e:
            print("[-]The local service : " + str(e))
            return "[-]The local service : " + str(e)

        while True:
            try:
                # 接收客户端数据
                client, addr = self.ser.accept()
                print('[*]accept %s connect' % (addr,))
                data = client.recv(1024)
                if not data:
                    break
                print('[*' + localtime + ']: Accept data...')
            except error as e:
                print("[-]Local receiving client : " + str(e))
                return "[-]Local receiving client : " + str(e)

            while True:
                # 目标代理服务器，将客户端接收数据转发给代理服务器
                mbsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

                print("[!]Now proxy ip:" + str(self.proxyip))
                prip = self.proxyip[0]
                prpo = self.proxyip[1]

                try:
                    mbsocket.settimeout(3)
                    mbsocket.connect((prip, prpo))
                except:
                    print("[-]RE_Connect...")
                    continue
                break

            try:
                mbsocket.send(data)
            except error as e:
                print("[-]Sent to the proxy server : " + str(e))
                return "[-]Sent to the proxy server : " + str(e)

            while True:
                try:
                    # 从代理服务器接收数据，然后转发回客户端
                    data_1 = mbsocket.recv(1024)
                    if not data_1:
                        break
                    print('[*' + localtime + ']: Send data...')
                    client.send(data_1)
                except socket.timeout as e:
                    print(self. proxyip)
                    print("[-]Back to the client : " + str(e))
                    continue
            # 关闭连接
        client.close()
        mbsocket.close()


def main():
    urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
    _version = sys.version_info
    # is_python3 = 3
    is_python3 = (_version[0] == 3)

    orderno = "ZF20221205084BQ4NiN"
    secret = "4bd862d5ec25443187ea37840afc4b00"

    # ip = "forward.xdaili.cn"
    # port = "80"

    ip_port = "forward.xdaili.cn:80"
    # 将时间转换为string
    timestamp = str(int(time.time()))
    string = ""
    # 将orderno、secret、时间戳拼接
    string = "orderno=" + orderno + "," + "secret=" + \
        secret + "," + "timestamp=" + timestamp
    # 如果是python3，转换为字节
    if is_python3:
        string = string.encode()
    # 对字节进行md5的16位哈希，并转换为大写
    md5_string = hashlib.md5(string).hexdigest()
    sign = md5_string.upper()
    # print(sign)
    auth = "sign=" + sign + "&" + "orderno=" + \
        orderno + "&" + "timestamp=" + timestamp

    # print(auth)
    proxy = {"http": "http://" + ip_port, "https": "http://" + ip_port}
    headers = {"Proxy-Authorization": auth,
               "User-Agent": "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.75 Safari/537.36"}
    ip_list = requests.get('http://forward.xdaili.cn:80', headers=headers, proxies=proxy, verify=False, allow_redirects=False)
    try:
        try_ip = ProxyServerTest(ip_list)
    except Exception as e:
        print("[-]main : " + str(e))
        return "[-]main : " + str(e)

    t = threading.Thread(target=try_ip.run, name='LoveJaky')
    print('[*]Waiting for connection...')
    # 关闭多线程
    t.start()
    t.join()


if __name__ == '__main__':
    main()
