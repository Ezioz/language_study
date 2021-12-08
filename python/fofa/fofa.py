'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-07 23:26:03
LastEditors: ahtoh
LastEditTime: 2021-12-07 23:37:37
'''

#-*- coding:utf-8 -*-

import base64
import argparse

def Args():
    parse = argparse.ArgumentParser(formatter_class=argparse.RawDescriptionHelpFormatter, description='''
    FOFA API
    ''')
    parse.add_argument('-a', '--api', help='需要保存的内容，例如xxx')
    parse.add_argument('-f', '--file', help='输入要保存的IP文件名, 最好以查询内容表示')
    args = parse.parse_args()
    if args.api is None and args.file is None:
        print(parse.print_help())
        exit()
    else:
        return args

def main():
    

if __name__ == '__main__':
    main()
