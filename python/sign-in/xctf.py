#!/usr/bin/env python
# -*- coding:utf-8 -*-
# author: ahtoh

import requests



def xctf(headers):
    url = 'https://adworld.xctf.org.cn/api/personal/daily_checkin'
    data = {}
    ctfhub_headers = {
        'Host': 'adworld.xctf.org.cn',
        'Cookie': 'Cookie: session=1203cd1d-af95-41c1-86be-92c5d159af87; X-CSRF-Token=IjRhMThjNzk5NWUzNDhmZjNmMWZmZTIwOTg4ZmI0OWRhOGU1YTViNWIi.E5dL4g.CRTbV5R_usEcAUaFlfhBmRi34cQ',
        'Origin': 'https://www.ctfhub.com',
        'Connection': 'close',
        'Referer': 'https://adworld.xctf.org.cn/personal',
        'X-CSRF-Token': 'IjRhMThjNzk5NWUzNDhmZjNmMWZmZTIwOTg4ZmI0OWRhOGU1YTViNWIi.E5dL4g.CRTbV5R_usEcAUaFlfhBmRi34cQ',
    }
    result = requests.get(url=url, headers=dict(headers, **ctfhub_headers))
    print(result.content.decode('utf-8'))
    # return result.content.decode('utf-8')
