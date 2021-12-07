'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-11-10 16:09:41
LastEditors: ahtoh
LastEditTime: 2021-12-07 18:44:55
'''
#!/usr/bin/env python
# -*- coding:utf-8 -*-
# author: ahtoh

import requests



def xctf(headers):
    url = 'https://adworld.xctf.org.cn/api/personal/daily_checkin'
    data = {}
    ctfhub_headers = {
        'Host': 'adworld.xctf.org.cn',
        'Cookie': 'x',
        'Origin': 'https://www.ctfhub.com',
        'Connection': 'close',
        'Referer': 'https://adworld.xctf.org.cn/personal',
        'X-CSRF-Token': 'IjRhMThjNzk5NWUzNDhmZjNmMWZmZTIwOTg4ZmI0OWRhOGU1YTViNWIi.E5dL4g.CRTbV5R_usEcAUaFlfhBmRi34cQ',
    }
    result = requests.get(url=url, headers=dict(headers, **ctfhub_headers))
    print(result.content.decode('utf-8'))
    # return result.content.decode('utf-8')
