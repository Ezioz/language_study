'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-16 13:39:13
LastEditors: ahtoh
LastEditTime: 2021-12-21 14:59:30
'''

import requests
import re

url = 'http://www.89ip.cn/tqdl.html?api=1&num=10'
types = 'https'
proxys = {}

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:95.0) Gecko/20100101 Firefox/95.0'}
r = requests.get(url, headers=headers).text
print(r)
ip = re.findall('((?:[0-9]{1,3}\.){3}[0-9]{1,3})', r)
port = re.findall('(:\d{1,5})', r)
for i, j in zip(port[2:], ip):  # i是端口，j是ip地址
    proxy = j + i
    proxys[types.lower()] = proxy
    try:
        tar = requests.get('https://ifconfig.me/ip', headers=headers,
                           proxies=proxys, timeout=5, verify=False).text
        if tar in str(proxys):
            with open('./ip.txt', 'a') as file:
                file.write( + '\n')
    except:
        pass
