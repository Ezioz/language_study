'''
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-28 21:52:26
LastEditors: ahtoh
LastEditTime: 2021-12-28 23:14:50
'''

# def build_profile(first, last, **user_info):
#     profile = {}
#     profile['first_name'] = first
#     profile['last_name'] = last
#     for k,v in user_info.items():
#         profile[k] = v
#     return profile

# user_profile = build_profile('albert', 'einstein', 
# location='princeton', field='physics')
# print(user_profile)

# class Car():
#     def __init__(self, make, model, year):
#         self.make = make
#         self.model = model
#         self.year = year
#         self.odometer_reading = 0

#     def get_descriptive_name(self):
#         long_name = str(self.year) + ' ' + str(self.make) + ' ' + self.model
#         return long_name.title()

# class ElectricCar(Car):
#     def __init__(self, make, model, year):
#         super().__init__(make, model, year)
#         self.battery = Battery()

# class Battery():
#     def __init__(self, battery_size=70):
#         self.battery_size = battery_size
    
#     def describe_battery(self):
#         print("This car has a " + str(self.battery_size) + ' kWh battery.')



# my_tesla = ElectricCar('tesla', 'model s', 2016)
# print(my_tesla.get_descriptive_name())
# my_tesla.battery.describe_battery()


import json

numbers = [1,2,3,4,5]

filename = './numbers.json'
with open(filename, 'w') as f_obj:
    json.dump(numbers, f_obj)