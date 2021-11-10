#!/usr/bin/env python
# -*- coding:utf-8 -*-
# author: ahtoh

import requests



def ctfhub(headers):
    url = 'https://api.ctfhub.com/User_API/User/checkIn'
    data = {}
    ctfhub_headers = {
        'Host': 'api.ctfhub.com',
        'Authorization': 'ctfhub_sessid=fag77ussfvchalr3q6494so0ale0l1tc',
        'Origin': 'https://www.ctfhub.com',
        'Referer': 'https://www.ctfhub.com/',
        'Content-Length': '2',
    }
    result = requests.post(url=url, headers=dict(headers, **ctfhub_headers), data=data)
    print(result.content.decode('utf-8'))
    # return result.content.decode('utf-8')
