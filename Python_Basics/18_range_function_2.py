#!/usr/bin/env python3.9



# In many ways the object returned by range() behaves as if it is a list, 
# but in fact it isn’t. It is an object which returns the successive items 
# of the desired sequence when you iterate over it, but it doesn’t really 
# make the list, thus saving space.


print ( range(10) )     # prints "range(0, 10)" 

list ( range(4) )       # [0,1,2,3]

sum ( range(4) )        # 6
