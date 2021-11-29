#!/usr/bin/env python3.9


# SINGLE QUOTES:
print( ' spam eggs ' )

print( ' doesn\'t ' )    # '\' escape character



# DOUBLE QUOTES:
print( " doesn't " )

print( ' "Yes," they said. ' )

print( " \"Yes,\" they said. " )

print( ' "Isn\'t," they said. ' )




# VARIABLES:
s = 'First line.\nSecond line.'
print( s )




# If you don’t want characters prefaced by \ to be interpreted as
# special characters, you can use raw strings by adding an r before 
# the first quote:

print( 'C:\some\name ')

print( r'C:\some\name ')



# String literals can span multiple lines. 
# One way is using triple-quotes: """...""" or '''...'''. 
# End of lines are automatically included in the string, 
# but it’s possible to prevent this by adding a \ at the end of the line. 
# The following example:

print( """\
Usage: thingy [OPTIONS]
	-h		   Display this usage message
	-H hostname       Hostname to connect to
""")



