# zip_cracker_threads2.py
#
#	Zip password cracker. Utilizes threading and argparse.
# 	Note that optparse is deprecated.
#
#	Ref: Violent Python, TJ O'Conner (modified to use argparse in lieu of optparse)
#
#	LU: 12/17/15

import zipfile
import argparse
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
	# Usage section for argparse here
	parser = argparse.ArgumentParser(description="Cracks "+\
		"zip files with specified dictionary. Utilizes "+\
		"threads.\n")
	# file section for argparse here
	parser.add_argument('-f', dest='zname', type=str, \
		help='Specify zip file name')
	# dictionary section for argparse here
	parser.add_argument('-d', dest='dname', type=str, \
		help='specify dictionary file name')

	# Move the parsed arguments into tuple
	options = parser.parse_args()
	#print options

	if (options.zname == None) | (options.dname == None):
		print parser.print_help()
		exit(0)	

	else:
		zname = options.zname
		dname = options.dname

	# Assign parsed options here
	zFile = zipfile.ZipFile(zname)
	passFile = open(dname)

	# Password cracker runs and threads created
	for line in passFile.readlines():
		password = line.strip('\n')
		t = Thread(target=extractFile, args=(zFile, password))
		t.start()
	

if __name__ == '__main__':
	main()