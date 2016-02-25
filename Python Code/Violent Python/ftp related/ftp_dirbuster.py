# ftp_dirbuster.py
#
#	Des:	Opens a FTP connection with a server and uses NLST to get
#			back any directory contents. Nothing fancy.
#
#	Issues: 1) Needs to take in user input--not hardcoded.
#			2) Implement a debug mode
#			3) Needs more tests
#
#	Status:	WIP
#	
#	LU: 01/22/16

import ftplib

DEBUG_MODE = False
TIMEOUT = 20

# --------------------------------------------------------------------------- #
def returnDefault(ftp_obj):

	# Try to obtain a list of directories
	try:
		dirList = ftp_obj.nlst()
	except:
		dirList = []
		print "[-] Could not list any directories"
		print "[-] Going to next target"
		return

	# Go through the dirList and find any web file matches and append to retList
	retList = []
	for fileName in dirList:
		fn = fileName.lower()
		if ((".php" in fn)|(".htm" in fn)|(".asp" in fn))
			print "[+] Found a page: " + str(fileName)
			retList.append(fileName)

	return retList


# --------------------------------------------------------------------------- #
def main():
	host = None
	userName = None
	passWord = None

	ftp_obj = ftplib.FTP(host)
	ftp_obj.login(userName, passWord)
	returnDefault(ftp_obj)


if __name__ == "__main__":
	main()