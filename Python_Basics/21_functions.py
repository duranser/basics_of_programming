#!/usr/bin/env python3.9



def myFunction():
	print( "Hello from a function" )


# To call a function, use the function name followed by parenthesis:
myFunction()



# Information can be passed into functions as arguments.

def myFunction( fname ):
	print( "Hello from the function" + fname )


myFunction( "FIRST" )
myFunction( "SECOND" )


# Parameters and arguments:
# A parameter is the variable listed inside the parentheses in the function definition.
# An argument is the value that is sent to the function when it is called.
