# violent_python_ex.py
#
#	Script that is slow built in violent python.
#	This code is still a work in progress...
#
#	Ref: Violent Python, TJ O'Conner
#
#	LU: 12/16/15

import socket, os, sys

## Global Variables
TIMEOUT_TIME = 3
IP_RANGE = 255 # From 1 to IP_RANGE
SUBNET = '192.168.1.'
## 

def retBanner(ip, port):
	try:
		socket.setdefaulttimeout(TIMEOUT_TIME)
		s = socket.socket()
		s.connect((ip, int(port)))
		banner = s.recv(1024)

		print "[+] Successfully connected"
		return banner

	except:
		print "[-] Error: Could not connect..."
		return

def checkVulns(banner, filename):
	f = open(filename, 'r')
	for line in f.readlines():
		if line.strip('\n') in banner:
			print "[+] Server is vulnerable: " +\
			banner.strip('\n')

def main():
	
	if len(sys.argv) == 2:
		filename = sys.argv[1]

		if not os.path.isfile(filename):
			print "[-] \'" +filename+ "\' does not exist."
			exit(0)
		if not os.access(filename, os.R_OK)
			print "[-] \'" +filename+ "\' access denied."
			exit(0)

	else:
		print "[-] Usage: " +str(sys.argv[0]) +\
		" <vuln filename>"
		exit(0)

		# Should not reach here yet? Check later
		portList = [21, 22, 25, 80, 110, 443]

		for x in range(1, IP_RANGE):
			ip = SUBNET + str(x)
			for port in portList:
				banner = retBanner(ip, port)
				if banner:
					print "[+] " + ip + ": " + banner
					checkVulns(banner, filename)

# Boilerplate code
if __name__ == '__main__':
	main()