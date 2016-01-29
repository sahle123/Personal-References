# SSH_bot_pexpect.py
#
#	Des:	A weak implmentation of a bot that connects to
#			a hardcoded host with hardcoded password + username.
#			Utilizes Pexpect library which is useful for handling
#			user interactive I/O; fairly unintuitive albeit.
#			Requires 'sudo' to work
#
#	Notes:	This SSH bot is ironically the most reliable...
#
#	Status: Functional-WIP
#
#	Ref: Violent Python, TJ O'Conner (Modified)
#
#	LU: 01/04/16

import pexpect
import argparse

## Globals
PROMPT = ['# ', '>>> ', '> ', '\$ ']
DEBUG_MODE = False
##

# -------------------------------------------------------------------------- # 
def send_command(child, cmd):
	child.sendline(cmd)
	child.expect(PROMPT)
	print child.before

# -------------------------------------------------------------------------- #
def connect(user, host, password):

	global DEBUG_MODE
	
	ssh_newkey = 'Are you sure you want to continue connecting'
	connectionString = 'ssh ' + user + '@' + host

	if DEBUG_MODE: print "[DEBUG] connectionString: "+connectionString

	child = pexpect.spawn(connectionString)

	ret = child.expect([pexpect.TIMEOUT, ssh_newkey, \
		'[P|p]assword:'])

	if ret == 0:
		print '[-] Error connecting'
		return
	if ret == 1:
		child.sendline('yes')
		ret = child.expect([pexpect.TIMEOUT, \
			'[P|p]assword'])

	if ret == 0:
		print '[-] Error connecting after sending command'
		return 

	child.sendline(password)
	child.expect(PROMPT)
	return child

# -------------------------------------------------------------------------- #
def parseInputs():
	global DEBUG_MODE

	parser = argparse.ArgumentParser(description="A weak implementation"+\
		" of an SSH bot. This is mostly a reference on how to use pexpect"+\
		". N.B. that pexpect appears more reliable than pxssh.")
	parser.add_argument("-H", dest="tgtHost", type=str, \
		help="Host to perform ssh on")
	parser.add_argument("-p", dest="tgtPass", type=str, \
		help="The host's password")
	parser.add_argument("-u", dest="tgtUser", type=str, \
		help="Host username")
	parser.add_argument("-D", dest="debugMode", action="store_true", \
		help="Gives debug information.")

	leOptions = parser.parse_args()

	if(leOptions.tgtHost == None) | (leOptions.tgtPass == None) | (leOptions.tgtUser == None):
		parser.print_help()
		exit(0)
	else:
		if leOptions.debugMode:
			DEBUG_MODE = leOptions.debugMode
		return leOptions

# -------------------------------------------------------------------------- #
def main():
	usrInputs = parseInputs()
	
	# Members found in parseInputs()
	child = connect(usrInputs.tgtUser, usrInputs.tgtHost, usrInputs.tgtPass)

	leCmd = raw_input("[+] We're in!!! Please give a command: ")

	send_command(child, str(leCmd))
	print "[*] Exiting script now."

if __name__ == '__main__':
	main()