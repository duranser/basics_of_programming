#!/usr/bin/env python3.9



# Default argument values:
# If we call the function without argument, it uses the default value:

def ask_ok( prompt, retries=4, reminder='Please try again!'):
	while True:
		ok = input(prompt)
		if ok in ('y', 'ye', 'yes'):
			return True
		if ok in ('n', 'no', 'nop', 'nope'):
			return False
		retries = retries - 1
		if retries < 0:
			raise ValueError('Invalid user response')
		print( reminder )



# The default values are evaluated at the point of function definition.
# The default value is evaluated only once.

i = 5

def f( arg = i ):
	print(arg)

i = 6
f()


# the default can be a mutable object such as a list, dictionary, 
# or instances of most classes.

def f( a, L=[] ):
	L.append(a)
	return L

print( f(1) )		# 1
print( f(2) )		# 1,2
print( f(3) )		# 1,2,3




# If you don’t want the default to be shared between subsequent calls, 
# you can write the function like this instead:

def f2( a, L=None ):
	if L is None:
		L = []
	L.append(a)
	return L
