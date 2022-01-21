'''
Descripttion: 
version: 
Author: ahtoh
Date: 2022-01-20 14:32:37
LastEditors: ahtoh
LastEditTime: 2022-01-20 17:08:23
'''
#!/usr/bin/python3
import sys
import time
import hashlib
import requests
import urllib3
from lxml import etree
# 禁用urllib3警告
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
string = "orderno=" + orderno + "," + "secret=" + secret + "," + "timestamp=" + timestamp
# 如果是python3，转换为字节
if is_python3:
    string = string.encode()
# 对字节进行md5的16位哈希，并转换为大写
md5_string = hashlib.md5(string).hexdigest()                
sign = md5_string.upper()                             
#print(sign)
auth = "sign=" + sign + "&" + "orderno=" + orderno + "&" + "timestamp=" + timestamp

#print(auth)
proxy = {"http": "http://" + ip_port, "https": "http://" + ip_port}
headers = {"Proxy-Authorization": auth, "User-Agent": "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.75 Safari/537.36"}
for i in range(10):
    # r = requests.get("http://pv.sohu.com/cityjson", headers=headers, proxies=proxy, verify=False,allow_redirects=False)
    r = requests.get("http://httpbin.org/get", headers=headers, proxies=proxy, verify=False,allow_redirects=False)

    # r.encoding='utf8'
    # print(r.status_code)
    print(r.content.decode('GB2312'))
# if r.status_code == 302 or r.status_code == 301 :
#     loc = r.headers['Location']
#     print(loc)
#     r = requests.get(loc, headers=headers, proxies=proxy, verify=False, allow_redirects=False)
#     r.encoding='utf8'
#     print(r.status_code)
#     print(r.text)
