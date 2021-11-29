#!/usr/bin/env python3.9



# Python has no command for declaring a variable.
# A variable is created the moment you first assign a value to it.

x = 5
y = "John"
print( x, y )



# Variables do not need to be declared with any particular type, 
# and can even change type after they have been set.

x = 4
x = "Sally"
print( x )



# If you want to specify the data type of a variable, this can be done with casting.

x = str( 3 )	# '3'
y = int( 3 )    # 3
z = float( 3 )  # 3.0



# You can get the data type of a variable with the type() function.

x = 5
y = "John"
print( type(x) )
print( type(y) )


# Variable names are case-sensitive.
# Rules for Python variables: 
# 	1- A variable name must start with a letter or the underscore character
# 	2- A variable name cannot start with a number
# 	3- A variable name can only contain alpha-numeric characters and underscores (A-z, 0-9, and _ )
# 	4- Variable names are case-sensitive (age, Age and AGE are three different variables)

