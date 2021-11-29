#!/usr/bin/env python3.9


# If you do not know how many arguments that will be passed into your function, 
# add a * before the parameter name in the function definition.

# This way the function will receive a tuple of arguments, and 
# can access the items accordingly:

def myFunction( *kids )
	print( "The youngest child is " + kids[2] )


myFunction( "Emily", "Riley", "Alicia" )



# If you do not know how many keyword arguments that will be passed into your function, 
# add two asterisk: ** before the parameter name in the function definition.

def myFunction2( **kid ):
  print("His last name is " + kid["lname"])

myFunction2( fname = "Tobias", lname = "Refsnes" ) 


# *name receives a tuple containing the positional arguments.
# **name receives a dictionary containing keyword arguments.

