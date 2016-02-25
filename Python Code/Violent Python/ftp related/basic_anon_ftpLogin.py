# basic_anon_ftpLogin.py
#
#	Des:	Anonymously logins into a FTP server that supports anonymous login.
#			It is not particularly useful as of now...
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
def anonLogin(hostname):
	try:
		ftp = ftplib.FTP(hostname, timeout=TIMEOUT)
		ftp.login('anonymous', 'nomad@yourstruly.com')
		print "\n[+] " + str(hostname) + " anonymous FTP login successful!" 
		ftp.quit()
		return True

	except Exception, e:
		print "\n[-] " + str(hostname) + " anonymous FTP login failed"
		return False


# --------------------------------------------------------------------------- #
def main():
	host = "69.5.29.188"
	anonLogin(host)

if __name__ == "__main__":
	main()
