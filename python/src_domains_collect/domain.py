'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-11-01 10:50:09
LastEditors: ahtoh
LastEditTime: 2021-11-02 11:21:47
'''

#!/usr/bin/python3
#-*- coding:utf-8 -*-

import src
import os
import time

domain_dict = src.src_domains()
dir_name = time.strftime("%Y_%m_%d_%H:%M:%S", time.localtime())
os.system('mkdir {}'.format(dir_name))

for k,v in domain_dict.items():
	for i in v:
		os.system('./subfinder -d {} -silent|./ksubdomain -verify -silent|./httpx -nc -title -content-length -status-code > ./{}'.format(i, dir_name + '/' + k + '_' + i + '.txt'))
	print(k + 'is over!')