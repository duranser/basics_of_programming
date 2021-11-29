#!/usr/bin/env python3.9


# Functions can also be called using keyword (named) arguments of the form "kwarg = value".


def myFunction( child1, child2, child3 )
	print( "The youngest child is "+ child3 )


myFunction( child1 = "Emily", child2 = "Riley", child3 = "Alicia" )



# Default and keyword arguments:

def parrot( voltage, state = 'a stiff', action = 'voom', type = 'Norwegian Blue'):
	print("-- This parrot wouldn't", action, end=' ')
	print("if you put", voltage, "volts through it.")
	print("-- Lovely plumage, the", type)
	print("-- It's", state, "!")


# one required argument and three optional arguments can be called
# in any of the following ways:

parrot(1000)											# 1 positional argument

parrot( voltage = 1000 )								# 1 keyword argument

parrot( voltage = 1000, action = 'VOOOOOM' )			# 2 keyword arguments

parrot( action = 'VOOOOOM', voltage = 1000 )			# 2 keyword arguments

parrot( 'a million', 'bereft of life', 'jump')  		# 3 positional arguments

parrot( 'a thousand', state='pushing up the daisies')   # 1 positional, 1 keyword arguments



# but all the following calls would be invalid:
parrot()							# required argument missing

parrot( voltage=5.0, 'dead' ) 		# non-keyword argument after a keyword argument

parrot( 110, voltage = 220 )		# duplicate alue for the same argument

parrot( actor = 'John Cleese' )	    # unknown keyword argument



# In a function call, keyword arguments must follow positional arguments!


