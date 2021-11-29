#!/usr/bin/env python3.9



# The print() function writes the value of the argument(s) it is given.

i = 256 * 256 

print( 'The value of i is', i )



# The keyword argument "end" can be used to avoid the newline after the output, 
# or end the output with a different string:

a, b = 0, 1
while a < 100:
	print( a, end = ',' )
	a, b = b, a + b



