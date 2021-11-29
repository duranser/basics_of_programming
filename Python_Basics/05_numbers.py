#!/usr/bin/env python3.9

# There are three numeric types in Python:
#	1- int
#   2- float
#   3- complex


# Floats:

x = 1.10
y = 1.0
z = -35.59

print(type(x))
print(type(y))
print(type(z)) 


# Float can also be scientific numbers with an "e" to indicate the power of 10.

x = 35e3
y = 12E4
z = -87.7e100

print(type(x))
print(type(y))
print(type(z)) 



# Complex:
# Note: You cannot convert complex numbers into another number type.

x = 3+5j
y = 5j
z = -5j

print( x + y + z )
print(type(x))
print(type(y))
print(type(z)) 





# Random Numbers:
# Python has a built-in module called random that can be used to make random numbers:

import random

print( random.randrange(1, 10) )





