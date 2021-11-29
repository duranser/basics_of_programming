#!/usr/bin/env python3.9


# Strings can be concatenated together with the + operator:

print( 'un' + 'ium')


# and repeated with *:

print( 3 * 'un' + 'ium' )



# Two or more string literals (i.e. the ones enclosed between quotes) 
# next to each other are automatically concatenated.
# This feature is particularly useful when you want to break long strings:

text = ( 'Put several strings within parentheses ' 
	 'to have them joined together.' )
print( text )



# Strings can be indexed, with the first character having index 0.

word = 'Python'

print ( word[0] )
print ( word[5] )




# Indices may also be negative numbers, to start counting from the right:

print ( word[-1] )  # last character

print ( word[-2] )  # second-last character

print ( word[-6] )  # first character




# In addition to indexing, slicing is also supported:

print ( word[0:2] )  # characters from position 0 (included) to 2 (excluded)

print ( word[2:5] )  # characters from position 2 (included) to 5 (excluded)




# Slice indices have useful defaults; 
# an omitted first index defaults to zero, 
# an omitted second index defaults to the size of the string being sliced.

print ( word[:2] )    # character from the beginning to position 2 (excluded)
print ( word[4:] )    # characters from position 4 (included) to the end
print ( word[-2:] )   # # characters from the second-last (included) to the end



# Python strings cannot be changed — they are immutable. 
# Therefore, assigning to an indexed position in the string results in an error

# word[0] = 'J'  # invalid assignment


# The built-in function len() returns the length of a string:

s = 'supercalifragilisticexpialidocious'
print ( len(s) )











