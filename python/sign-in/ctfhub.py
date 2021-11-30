'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-11-10 16:09:41
LastEditors: ahtoh
LastEditTime: 2021-11-30 16:57:40
'''
#!/usr/bin/env python
# -*- coding:utf-8 -*-
# author: ahtoh

import requests



def ctfhub(headers):
    url = 'https://api.ctfhub.com/User_API/User/checkIn'
    data = {}
    ctfhub_headers = {
        'Host': 'api.ctfhub.com',
        'Authorization': '',
        'Origin': 'https://www.ctfhub.com',
        'Referer': 'https://www.ctfhub.com/',
        'Content-Length': '2',
    }
    result = requests.post(url=url, headers=dict(headers, **ctfhub_headers), data=data)
    print(result.content.decode('utf-8'))
    # return result.content.decode('utf-8')
