# TCP_full_connect_scan.py
#
#	Des:	Terminal command for performing port scans on given hostname.
#	Status: Functional
#
#	Ref: Violent Python, TJ O'Conner (Modified)
#
#	LU: 12/22/15

"""
Useful socket methods:

	socket.gethostbyname(hostname)
	socket.gethostbyaddr(ip_address)
	socket.socket([family[, type [, proto]]])
	socket.create_connection(address[, time[, source_address]])
"""

# ***
# Dev Notes:
#		
#	.OptionParser() ===> .ArgumentParser(description="blah")
#	.add_option() 	===> .add_argumetn()
# *** 

import argparse 
from socket import *

## Global constants
TIMEOUT_TIME = 1
##

# --------------------------------------------------------------------------- #
# Helper function for portScan()
# This function will attempt to connect to a hostname on a given port number
def connectionScan(tgtHost, tgtPort):
	try:
		connSocket = socket(AF_INET, SOCK_STREAM)
		connSocket.connect((tgtHost, tgtPort))
		print "[+] %d/tcp open"%tgtPort
		connSocket.shutdown(SHUT_RDWR)
		connSocket.close()

	except:
		print "[-] %d/tcp closed"%tgtPort

# --------------------------------------------------------------------------- #
# This function performs a port scan with the help of connectionScan().
def portScan(tgtHost, tgtPorts):
	# Resolve hostname-->IP address
	try:
		print "[*] Resolving host name..."
		tgtIP = gethostbyname(tgtHost)
		print "[*] "+tgtHost+" ---> "+str(tgtIP)

	except:
		print "[-] Cannot resolve '%s': Unknown host"%tgtHost
		return

	# Resolve IP address-->hostname. If fails, use IP address.
	try: 
		tgtName = gethostbyaddr(tgtIP)
		print "\n[+] Scan results for: "+tgtName[0]
	except:
		print "\n[+] Scan results for: "+tgtIP

	setdefaulttimeout(TIMEOUT_TIME)

	# Begin port scan
	if type(tgtPorts) == int:
		connectionScan(tgtHost, int(tgtPorts))

	elif type(tgtPorts) == list:
		for tgtPort in tgtPorts:
			print "Scanning port " +tgtPort
			connectionScan(tgtHost, int(tgtPort))
	else:
		print "[-] Port number given is neither int or a list..."

# --------------------------------------------------------------------------- #
# Parses user inputs from terminal. Utilizes argparse (optparse is deprecated)
def parseInputs():
	# Usage section
	parser = argparse.ArgumentParser(description="Performs port scan" +\
		" on given hostname and port numbers.", \
		epilog="--End of help--")

	parser.add_argument('-H', dest='tgtHost', type=str, \
		help='specify target host')

	parser.add_argument('-p', dest='tgtPort', type=int, \
		help='specify target port')

	# Get user passed-in arguments.
	leOptions = parser.parse_args()

	if(leOptions.tgtHost == None) | (leOptions.tgtPort == None):
		print parser.print_help()
		exit(0)

	else:
		print "[*] DEBUG: parseInputs() ran successfully"
		portScan(leOptions.tgtHost, leOptions.tgtPort)

# --------------------------------------------------------------------------- #
def main():
	parseInputs()
	return


# Boilerplate code
if __name__ == '__main__':
	main()