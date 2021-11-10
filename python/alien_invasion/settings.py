'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-11-08 20:21:04
LastEditors: ahtoh
LastEditTime: 2021-11-09 22:25:02
'''

class Settings():

    def __init__(self):
        self.screen_width = 1200
        self.screen_height = 800
        self.bg_color = (230, 230, 230)
        self.ship_speed_factor = 1.5

        #子弹设置
        self.bullet_speed_factor = 1
        self.bullet_width = 3
        self.bullet_height = 15
        self.bullet_color = 60, 60, 60
        