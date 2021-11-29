#!/usr/bin/env python3.9


# Global variables can be used by everyone, both inside of functions and outside.

x = "awesome"

def myfunc():
	print( "Python is " + x )

myfunc()


# If you create a variable with the same name inside a function, 
# this variable will be local, and can only be used inside the function. 
# The global variable with the same name will remain as it was, 


def myfunc2():
	x = "fantastic"
	print( "Python is " + x )

myfunc2()

print( "Python is " + x )
