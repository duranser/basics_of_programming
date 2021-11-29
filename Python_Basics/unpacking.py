#!/usr/bin/env python3.9



# the built-in range() function expects separate start and stop arguments. 
# If they are not available separately, write the function call with the 
# *-operator to unpack the arguments out of a list or tuple:


print( list( range(3, 6) ) )

args = [3, 6]

print( list( range(*args) ) )




# In the same fashion, dictionaries can deliver keyword arguments with the **-operator:

def parrot( voltage, state='a stiff', action='voom'):
	print("-- This parrot wouldn't", action, end=' ')
	print("if you put", voltage, "volts through it.", end=' ')
	print("E's", state, "!")

d = {"voltage": "four million", "state": "bleeding' demised", "action": "VOOM"}

parrot( **d )
