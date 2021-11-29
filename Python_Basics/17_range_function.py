#!/usr/bin/env python3.9


# If you do need to iterate over a sequence of numbers, 
# the built-in function range() comes in handy. It generates arithmetic progressions:


for i in range(5):
	print(i)



# It is possible to let the range start at another number, 
# or to specify a different increment (even negative):


for i in range(5,10):
	print(i)	# 5,6,7,8,9


for i in range(0,10,3):
	print(i)	# 0,3,6,9


for i in range(-10,-100,-30):
	print(i)	#-10,-40,-70
	
	
	
	
# To iterate over the indices of a sequence, you can combine range() and len() as follows:

a = ['Mary','had','a','little','lamb']

for i in range( len(a) ):
	print( i, a[i] )





