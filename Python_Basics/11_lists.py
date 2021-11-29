#!/usr/bin/env python3.9


# Lists might contain items of different types, but usually the items all have the same type.
# It can be written as a list of comma-separated values (items) between square brackets.

squares = [ 1, 4, 9, 16, 25 ]



# lists can be indexed and sliced:

print( squares[0] )

print ( squares[-1] )

print ( squares[-3:] )



# Lists also support operations like concatenation:

new = squares + [ 36, 49, 81, 100 ]

print( new )


# Unlike strings, which are immutable, lists are a mutable type, i.e. 
# it is possible to change their content:

cubes = [ 1, 8, 27, 65, 125 ]

cubes[3] = 64

print( cubes )



# You can also add new items at the end of the list, by using the append() method

cubes.append( 216 )
cubes.append( 7 ** 3 )

print( cubes )



# Assignment to slices is also possible, and this can even change the size of the list 
# or clear it entirely:

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
print( letters )

letters [2:5] = ['C', 'D', 'E']
print( letters )


letters [2:5] = []    # remove them
print( letters )

letters [:] = []      # clear the list
print( letters )



# The built-in function len() also applies to lists:

letters = ['a', 'b', 'c', 'd']
len( letters )



# It is possible to nest lists (create lists containing other lists), for example:

a = ['a', 'b', 'c']
n = [1, 2, 3]
x = [a, n]	# nestling lists

print( x )








