'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-09-28 14:42:25
LastEditors: ahtoh
LastEditTime: 2021-09-28 16:28:58
'''
""" 
目标：
1. 将内容格式化输出，方便粘贴到excel表格中
~.~，很垃圾的脚本，用excel都能实现。。。
"""

#-*- conding:utf8 -*-

import requests

def get_contents():
    with open('./python_tools/butian_pb_src/补天全部公益src.txt', 'r', encoding='gbk') as f:
        contents_list = f.readlines()
        return contents_list

def get_cnameAndurl(contents_list):
    name_dict = {}
    for i in contents_list:
        company_url = (i.strip('企业名称：')).split('URL:')
        company_name = company_url[0].strip()
        company_url = company_url[1].strip('\n')
        if ('http://' or 'https://') not in company_url:
            company_url = 'http://' + company_url
        name_dict[company_name] = company_url
    return name_dict

def write_name_dict(name_dict):
    with open('./python_tools/butian_pb_src/name_dict.txt', 'w', encoding='utf-8') as f:
        for k,v in name_dict.items():
            f.write(k + '\t' + v + '\n')
    return 0


if __name__ == '__main__':
    contents_list = get_contents()
    name_dict = get_cnameAndurl(contents_list)
    write_name_dict(name_dict)
