# zip_cracker.py
#
#	Zip password cracker WIP
#
#	Ref: Violent Python, TJ O'Conner
#
#	LU: 12/17/15

import zipfile

# -------------------------------------------------------------------------- #
def openFile():
	try:
		dictFile = open("dictionary.txt", "r")
		return dictFile
	except:
		print "[-] Could not open dictionary.txt."
		exit(0)

# -------------------------------------------------------------------------- #
def zipCrack(zFile):

	# Open the dictionary.txt file
	dictFile = openFile()

	# Dictionary attack!
	for line in dictFile.readlines():
		line = line.strip("\n") # parse the line

		try:
			zFile.extractall(pwd=line)
			print "[+] Cracked! Password = " +line+ "\n"
			exit(0)
		except Exception, e:
			pass

# -------------------------------------------------------------------------- #
def main():
	zFile = zipfile.ZipFile("evil.zip")

	zipCrack(zFile)

	return

if __name__ == "__main__":
	main()