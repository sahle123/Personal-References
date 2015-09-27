# For problem set 4, question 2c. CSCI 2824
# Sahle "Nomad" Alturaigi
# Nov. 27th, 2012

def main():
	n = input("Sil vous plait, enter a value for n: ")
	result = T(n)
	print 'Final answer = ', result
	
def T(n):
	if n == 0:
		return 2
	result = (T(n - 1) + 5*n)
	return result
	
if __name__ == '__main__':
	main()