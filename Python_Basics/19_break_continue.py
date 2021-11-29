#!/usr/bin/env python3.9



# The break statement, like in C, breaks out of the innermost 
# enclosing for or while loop.


# Loop statements may have an else clause; it is executed when the loop 
# terminates through exhaustion of the iterable (with for) or when the 
# condition becomes false (with while), but not when the loop is terminated 
# by a break statement.


for n in range(2,10):
	for x in range(2,n):
		if n % x == 0:
			print(n, 'equals', x,'*', n//x)
			break
	else:
		print(n, 'is a prime number')

# the else clause belongs to the for loop, not the if statement.



# The continue statement, also borrowed from C, continues with the next iteration of the loop.

for num in range(2,10):
	if num % 2 == 0
		print( "Found an even number ", num)
		continue
	print("Found an odd number", num)
