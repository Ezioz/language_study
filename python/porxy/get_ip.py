'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-16 13:39:13
LastEditors: ahtoh
LastEditTime: 2021-12-16 13:42:19
'''

import requests
import re

url = 'http://www.89ip.cn/tqdl.html?api=1&num=10'
types = 'https'
proxys = {}

headers = {
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 12_10) AppleWebKit/600.1.25 (KHTML, like Gecko) Version/12.0 Safari/1200.1.25'}
r = requests.get(url, headers=headers).text
ip = re.findall('((?:[0-9]{1,3}\.){3}[0-9]{1,3})', r)
port = re.findall('(:\d{1,5})', r)
for i, j in zip(port[2:], ip):
    print(j+i)
