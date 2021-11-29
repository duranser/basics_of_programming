#!/usr/bin/env python3.9


# A lambda function is a small anonymous function.
# A lambda function can take any number of arguments, but can only have one expression.

x = lambda a : a + 10
print( x(5) ) 


x = lambda a, b, c : a + b + c
print( x(5, 6, 2) ) 



# The power of lambda is better shown when you use them as an anonymous function 
# inside another function.

# Say you have a function definition that takes one argument, and that argument 
# will be multiplied with an unknown number:

def myfunc(n):
	return lambda a : a * n


# Use that function definition to make a function that always doubles the number you send in:
mydoubler = myfunc(2)

print( mydoubler(11) )



# Or, use the same function definition to make a function that always triples the number you send in:
mytripler = myfunc(3)

print( mytripler(11) )
