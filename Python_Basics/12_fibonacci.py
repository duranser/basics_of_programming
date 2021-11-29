#!/usr/bin/env python3.9


a, b = 0, 1  # multiple assignment
             # the variables a and b simultaneously get the new values


while a < 10:
	print( a )
	a, b = b, a + b     # simultaneous assignment

# The body of the loop is indented: indentation is Python’s way of grouping statements.
# Note that each line within a basic block must be indented by the same amount.


