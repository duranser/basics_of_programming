#!/usr/bin/env python3.9


# Any parameters which occur after the *args parameter are 
# ‘keyword-only’ arguments, meaning that they can only be used 
# as keywords rather than positional arguments.


def concat( *args, sep = "/"):
	return sep.join(args)


print( concat( "earth", "mars", "venus") )

print( concat( "earth", "mars", "venus", sep="."), "\n" )



# *name receives a tuple containing the positional arguments.
# **name receives a dictionary containing keyword arguments.
# *name must occur before **name.


def cheeseshop( kind, *arguments, **keywords ):
	print("-- Do you have any", kind, "?")
	print("-- I am sorry, we're all out of", kind)
	for arg in arguments:
		print( arg )
	print("-" * 40)
	
	for kw in keywords:
		print( kw, ":", keywords[kw] )



# function call:

cheeseshop( "Limburger", "It's very runny, sir.",
			"It's really very, VERY runny, sir.",
			shopkeeper = "Michael Palin",
			client = "John Cleese",
			sketch = "Cheese Shop Sketch")

# Note that the order in which the keyword arguments are printed 
# is guaranteed to match the order in which they were provided 
# in the function call.

