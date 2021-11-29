#!/usr/bin/env python3.9


# Fibonacci series:

def fib(n):
	a,b = 0,1
	while a < n:
		print(a, end=' ')
		a,b = b, a+b
	print()
	

# arguments are passed using call by value.

# global variables and variables of enclosing functions cannot be directly assigned 
# a value within a function.


# function call:
fib(100) 

f = fib(100)



# Coming from other languages, you might object that fib is not a function but a procedure 
# since it doesn’t return a value. 
# In fact, even functions without a return statement do return a value. 
# This value is called None (it’s a built-in name). Writing the value None is normally 
# suppressed by the interpreter if it would be the only value written. 
# You can see it if you really want to using print():


print( fib(0) )   # Return None



# It is simple to write a function that returns a list of the numbers 
# of the Fibonacci series, instead of printing it:


def fib2(n):
	result = []
	a, b = 0, 1
	while a < n:
		result.append(a)       # result = result + [a]
		a, b = b, a + b
	return result


# The return statement returns with a value from a function. 
# return without an expression argument returns None. 
# Falling off the end of a function also returns None.


# function call
f2 = fib2(100)

print( f2 )	







