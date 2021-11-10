#-*- coding: utf-8 -*-


from ctfhub import *
from bugku_ import *
from xctf import *
import time
import requests
import re
import json
import sys


headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:88.0) Gecko/20100101 Firefox/88.0',
    'Content-Type': 'application/json;charset=UTF-8',
    'Accept-Encoding': 'gzip, deflate',
    'Accept': 'application/json, text/plain, */*',
}

def send_msg(qiandao_url):
    headers = {'Content-Type': 'application/json;charset=utf-8'}
    data = {
        "msgtype": "link",
        "link": {
            "text": "内容",
            "title": "标题",
            "picUrl": "图片连接",
            "messageUrl": "你需要发布的连接地址"
        }
    }
    r = requests.post(qiandao_url, data=json.dumps(data), headers=headers)
    return r.text


def start():
    ctfhub_result = ctfhub(headers)
    bugku_result = bugku(headers)
    xctf_result = xctf(headers)


if __name__=='__main__':
    # msg = sys.argv[1]
    # qiandao_url = 'https://oapi.dingtalk.com/robot/send?access_token=5e5eb107210af74072f9811c4fcc0b48c29b00062d24d7f17de518aee52a096b'

    start()
    # print(send_msg(qiandao_url))