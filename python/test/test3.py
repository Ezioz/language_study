'''
Descripttion: 
version: 
Author: ahtoh
Date: 2022-01-28 10:53:42
LastEditors: ahtoh
LastEditTime: 2022-01-28 10:53:42
'''

from test2 import ElectricCar

my_tesla = ElectricCar('tesla', 'model s', 2016)
print(my_tesla.get_descriptive_name())
my_tesla.battery.describe_battery()