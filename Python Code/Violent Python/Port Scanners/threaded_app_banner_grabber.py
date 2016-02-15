# threaded_app_banner_grabber.py
#
#	Des:	A modified version of 'app_banner_grabber.py' with threading.
#			The functions have been modified to avoid race conditions.
#			A binary semaphore is also implemented (ref. probably?)
#	Status: Functional
#
#	Ref: Violent Python, TJ O'Conner (Modified)
#
#	LU: 02/02/16

import argparse
import socket
from socket import *
from threading import * # Semaphore from here too.

## Global Constants
TIMEOUT_TIME = 1
SCREEN_LOCK = Semaphore(value=1)
##

# --------------------------------------------------------------------------- #
# Helper function for portScan()
# Sends the message "Ciao" and waits for result from server.
def connectionScan(tgtHost, tgtPort):
	try:
		connSocket = socket(AF_INET, SOCK_STREAM)
		connSocket.connect((tgtHost, tgtPort))
		connSocket.send("Ciao\r\n")
		results = connSocket.recv(128)

		# We need to acquire a lock whenever we print to ensure
		# that the printed text is not coming from other threads
		# thus leading to garbled text.
		SCREEN_LOCK.acquire()
		print "[+] %d/tcp open"%tgtPort
		print "[+] Received: " + str(results)

	except:
		SCREEN_LOCK.acquire()
		print "[-] %d/tcp closed"%tgtPort

	# This keyword is run when the block ends.
	# A smart place to release locks?
	finally:
		SCREEN_LOCK.release()
		#connSocket.shutdown(SHUT_RDWR) # Can't get this to work w/ threads
		connSocket.close()

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
		# We don't need multithreading if there is only 1 port specified.
		connectionScan(tgtHost, int(tgtPorts))

	elif type(tgtPorts) == list:
		for tgtPort in tgtPorts:
			print "\nScanning port " +tgtPort
			t = Thread(target=connectionScan, args=(tgtHost, int(tgtPort)))
			#connectionScan(tgtHost, int(tgtPort))
			t.start()
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

	parser.add_argument('-p', dest='tgtPort', type=str, \
		help='specify target port[s] separated by commas')

	# Get user passed-in arguments.
	leOptions = parser.parse_args()

	if(leOptions.tgtHost == None) | (leOptions.tgtPort == None):
		print parser.print_help()
		exit(0)

	else:
		print "[*] DEBUG: parseInputs() ran successfully"
		tgtPorts = str(leOptions.tgtPort).split(', ')
		portScan(leOptions.tgtHost, tgtPorts)

# --------------------------------------------------------------------------- #
def main():
	parseInputs()


# Boilerplate code
if __name__ == '__main__':
	main()