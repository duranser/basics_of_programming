#!/usr/bin/env python3.9



# Python allows you to assign values to multiple variables in one line (simultaneously):

x, y, z = "Orange", "Banana", "Cherry"
print( x, y, z )



# And you can assign the same value to multiple variables in one line:

x = y = z = "Orange"
print( x, y, z )



# Unpack a Collection: 
# If you have a collection of values in a list, tuple etc. 
# Python allows you extract the values into variables. This is called unpacking.

fruits = ["apple", "banana", "cherry"]
x, y, z = fruits

print(x, y, z)
