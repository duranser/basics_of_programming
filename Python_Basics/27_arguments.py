#!/usr/bin/env python3.9


# By default, arguments may be passed to a Python function 
# either by position or explicitly by keyword.

# For readability and performance, it makes sense to restrict 
# the way arguments can be passed so that a developer need only look at
# the function definition to determine if items are passed by position, 
# by position or keyword, or by keyword.


# A function definition may look like:

def f( pos1, pos2,/ , pos_or_kwd,  *, kwd1, kwd2 ):
#	  -------------   ----------   -----------
#          |             |              |   
#	       |             |         keyword only
#		   |             |
#		   |       pos or keyword
#          |
#   positional only 
	pass


def standard_arg( arg ):
	print( arg )

standard_arg( 2 )
standard_arg( arg = 2 )



def pos_only_arg( arg, / ):
	print( arg )

pos_only_arg( 1 )

	
	
def kwd_only_arg( *, arg ):
	print( arg )

kwd_only_arg( arg = 3 )




def combined( pos_only,/ , standard, *, kwd_only ):
	print( pos_only, standard, kwd_only )
	
combined( 1, 2, kwd_only = 3)
combined( 1, standard = 2, kwd_only = 3)







