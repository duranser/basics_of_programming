#!/usr/bin/env python3.9


# The for statement in Python differs a bit from C or Pascal. 
# Rather than always iterating over an arithmetic progression of numbers,
# Python’s for statement iterates over the items of any sequence (a list or a string),
# in the order that they appear in the sequence. For example :


words = ['cat', 'window', 'defenestrate']

for w in words:
	print( w, len(w) )


