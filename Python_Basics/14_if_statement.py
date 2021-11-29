#!/usr/bin/env python3.9


x = int( input("Please enter an integer: ") )

if x < 0 :
	x = 0
	print( 'Negative changed to zero')

elif x == 0 :
	print( 'Zero' )

elif x == 1:
	print( 'Single' )

else :
	print( 'More' )
	

# There can be zero or more elif parts, and the else part is optional.



# Short Hand If....Else
a = 2
b = 330
print("A") if a > b else print("B") 


a = 330
b = 330
print("A") if a > b else print("=") if a == b else print("B") 

