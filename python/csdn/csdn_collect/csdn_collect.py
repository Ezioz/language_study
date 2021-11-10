'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-05-27 16:30:47
LastEditors: ahtoh
LastEditTime: 2021-09-28 16:30:50
'''
#!/usr/bin/env python
# -*- coding:utf-8 -*-
# author: ahtoh

import json
from urllib.parse import unquote
import requests

headers = {
    "authority": "blog.csdn.net",
    "method": "GET",
              "scheme": "https",
    "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
              "accept-encoding": "gzip, deflate, br",
    "accept-language": "zh-CN,zh;q=0.9",
    "cache-control": "max-age=0",
    "cookie": "your-cookie",
    "sec-ch-ua": "\"Google Chrome\";v=\"89\", \"Chromium\";v=\"89\", \";Not A Brand\";v=\"99\"",
    "sec-ch-ua-mobile": "?0",
    "sec-fetch-dest": "document",
    "sec-fetch-mode": "navigate",
    "sec-fetch-site": "none",
    "sec-fetch-user": "?1",
    "upgrade-insecure-requests": "1",
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36",
}

title_url = {}
def get_title_url():
    with open('./content.txt', 'r', encoding='utf-8') as f:
        content = f.read()
        data = json.loads(content)
        data_json = data['data']['list']
        for i in data_json:
            #部分文章标题汉字被url编码了，如果文章的标题中包含%，就进行url解码，比较暴力
            if '%' in i['title']:
                i['title'] = unquote(i['title'], 'utf-8')
                title_url[i['title']] = i['url']
            #在响应报文中，发现存在一个标题中间包含\n和多个空格的情况，全部替换为空
            elif '\n' in i['title']:
                title_url[(i['title'].replace(' ', '')).replace('\n', '')] = i['url']
            else:
                title_url[i['title']] = i['url']
        return title_url

def test_url(title_url):
    print('以下文章访问异常：')
    for k in list(title_url.keys()):
        #增加请求头后，响应正常
        url_code = requests.get(title_url[k], headers=headers)
        if url_code.status_code != 200:
            print(k + '\t' + title_url[k] + '\t' + str(url_code.status_code))
            del title_url[k]
            continue

    print('以下文章可以正常访问：')
    for k,v in title_url.items():
        print(k + '\t' + v)

if __name__=='__main__':
    test_url(get_title_url())