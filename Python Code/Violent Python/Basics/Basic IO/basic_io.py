# basic_io.py
#
#	Basic file I/O in python
#	This program checks if a string is inside "io_text.txt"
#
#	Ref: Violent Python, TJ O'Conner
#
#	12/16/15

def checkVulns(banner):
	f = open("io_text.txt", 'r')

	for line in f.readlines():
		if line.strip('\n') == banner:
			print "[+] We found the text in the file: "+banner
			return

	print "[-] We did not find your text in the file io_text.txt"

def main():
	leInput = raw_input("Give me a string: ")

	checkVulns(leInput)
	print "[+] Done"

if __name__ == '__main__':
	main()