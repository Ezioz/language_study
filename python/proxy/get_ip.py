'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-16 13:39:13
LastEditors: ahtoh
LastEditTime: 2021-12-22 14:13:34
'''
import requests
import re

url = "http://www.89ip.cn/tqdl.html?api=1&num=100"
headers = {
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 12_10) AppleWebKit/600.1.25 (KHTML, like Gecko) Version/12.0 Safari/1200.1.25',
}

# num=100&port=&kill_port=&address=&kill_address=&anonymity=2&type=&post=&sort=&key=8db082a5eed29124b168781811245249
try:
    url_contents = requests.get(url, headers=headers).text
except:
    print('error')
    exit()
ip_contentx = re.findall('((?:\d{1,3}\.){1,3}\d{1,3}:\d{1,5})', url_contents)
# print(ip_contentx)
proxys = {}
for i in ip_contentx:
    proxys['http'] = '%s'%('http://' + i)
    print(proxys)
    try:
        tar = requests.get('http://101.32.32.202:8090', headers=headers, proxies=proxys, timeout=5, verify=False).text
    except:
        continue
    print(tar)
