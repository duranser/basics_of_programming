#!/usr/bin/env python3.9



# Comparisons can be chained:
if b < a < c:
	print("The chain condition is True")



# And : used to combine conditional statements
a = 200
b = 33
c = 500
if a > b and c > a:
	print("Both conditions are True")



# Or : used to combine conditional statements
a = 200
b = 33
c = 500
if a > b or a > c:
	print("At least one of the conditions is True")



# in : used to check if a specified object exists 
name = "Serdar"
if name in ["Serdar", "Duran"]:
	print("Your name is either Serdar or Duran")


if name not in ["Duran", "Duran"]:
	print("What is your name?")



# is : Unlike the double equals operator "==", the "is" operator 
#      does not match the values of the variables, but the instances themselves.
x = [1,2,3]
y = [1,2,3]
print(x == y)		# True
print(x is y)   	# False
print(x is not y)   # True








