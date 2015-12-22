# zip_cracker_threads.py
#
#	Zip password cracker WIP. Utilizes threading
#
#	Ref: Violent Python, TJ O'Conner
#
#	LU: 12/17/15

import zipfile
from threading import Thread

# -------------------------------------------------------------------------- #
def extractFile(zFile, password):
	try:
		zFile.extractall(pwd=password)
		print "[+] Password = "+password+ "\n"

	except:
		pass

# -------------------------------------------------------------------------- #
def main():
	zFile = zipfile.ZipFile('evil.zip')
	passFile = open('dictionary.txt', 'r')

	for line in passFile.readlines():
		password = line.strip('\n')
		t = Thread(target=extractFile, args=(zFile, password))
		t.start()

	# Learn how to clean up threads.
	

if __name__ == '__main__':
	main()