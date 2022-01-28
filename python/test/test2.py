'''
Descripttion: 
version: 
Author: ahtoh
Date: 2022-01-28 10:52:42
LastEditors: ahtoh
LastEditTime: 2022-01-28 10:52:42
'''
from test import Car

class Battery():
    def __init__(self, battery_size=70) -> None:
        self.battery_size = battery_size

    def describe_battery(self):
        print("This car has a " + str(self.battery_size) + "-kWh battery.")


class ElectricCar(Car):
    def __init__(self, make, model, year) -> None:
        super().__init__(make, model, year)
        self.battery = Battery()

    def describe_battery(self):
        print("This car has a " + str(self.battery_size) + "-kWh battery.")

