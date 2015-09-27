# To check for maximum value that can be represented in 32-bit.

import numpy

def max_32_val():
	x = 0
	numpy.uint(x)
	x = 0xFFFFFFFFFF #Can go up to 10 byte representation? long int?
	#x = 0x800000000; # Mask for 1000 0000 0000.... 0000
	#x = x >> 32; Interestingly... it uses logic right shift, not arith.
	print x
	x = x/8
	print("Number of bytes: ", x)
	x = x/1024
	print("Number of Kilobytes: ", x)
	x = x/1024
	print("Number of Megabytes: ", x)
	x = x/1024
	print("Number of Gigabytes: ", x)

max_32_val()