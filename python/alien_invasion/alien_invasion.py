'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-11-07 21:33:39
LastEditors: ahtoh
LastEditTime: 2021-11-08 21:24:58
'''

import sys
import pygame
from settings import Settings
from ship import Ship
import game_functions as gf

def run_game():
    pygame.init()
    ai_settings = Settings()
    screen = pygame.display.set_mode((ai_settings.screen_width, ai_settings.screen_height))
    pygame.display.set_caption("alien Invasion")
    ship = Ship(ai_settings, screen)
    while True:
        gf.check_events(ship)
        ship.update()
        gf.update_screen(ai_settings, screen, ship)
        


run_game()