#!/usr/bin/env python3.9


# Booleans represent one of two values: True or False.
# When you compare two values, the expression is evaluated and 
# Python returns the Boolean answer:

print( 10 > 9 )		# True
print( 10 == 9)		# False
print( 10 < 9 ) 	# False



# The bool() function allows you to evaluate any value, 
# and give you True or False in return,

print( bool("Hello") )
print( bool(15) )


# Any string is True, except empty strings.
# Any number is True, except 0.
# Any list, tuple, set, and dictionary are True, except empty ones.

print( bool( False ) )
print( bool( None ) )
print( bool( 0 ) )
print( bool( "" ) )
print( bool( () ) )
print( bool( [] ) )
print( bool( {} ) )



# Functions can Return a Boolean

def myFunction() :
  return True

print( myFunction())  
