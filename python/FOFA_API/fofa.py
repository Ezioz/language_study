'''
Descripttion: 通过脚本的方式调用FOFA
参考链接：https://blog.csdn.net/wuyou1995/article/details/105592102
version: 
Author: ahtoh
Date: 2021-12-07 18:39:56
LastEditors: ahtoh
LastEditTime: 2021-12-07 18:53:57
'''

import requests
import base64
import logging
import argparse

headers = {
    ''
}

def Args():
    parse = argparse.ArgumentParser(formatter_class=argparse.RawDescriptionHelpFormatter,description='''
    FoFa api 调用
    ''')
    parse.add_argument('-a', '--api', help = '需要查询内容，例如DIR_850L')
    parse.add_argument('-f', '--file', help= '输入需要保存IP的文件名')
    args = parse.parse_args()
    if args.api is None and args.file is None:
        print(parse.print_help())
        exit()
    else:
        return args