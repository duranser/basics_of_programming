#!/usr/bin/env python3.9



# Small anonymous functions can be created with the lambda keyword. 
# This function returns the sum of its two arguments: lambda a, b: a+b.


def make_incrementor(n):
	return lambda x: x + n


f = make_incrementor(42)

print( f(0) )	# 42
print( f(1) )	# 43



# The above example uses a lambda expression to return a function. 
# Another use is to pass a small function as an argument:

pairs = [ (1, 'one'), (2, 'two'), (3, 'three'), (4, 'four') ]

pairs.sort( key=lambda pair: pair[1] )

print( pairs )
