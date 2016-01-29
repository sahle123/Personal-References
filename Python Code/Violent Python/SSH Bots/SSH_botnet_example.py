# SSH_botnet_example.py
#
#	Des: 	This is a very basic (and poorly made thus far) SSH bot that will
#			connect to a list of servers that are in a user-speicfied text file
#			and then run the commands in the main() function. Still needs a lot
#			of work.
#	
#	Issues: 1) Fixed
#			2) Put in description for terminal and script
#			3) Need error handling for passing in hosts that are offline
#			4) Test for bad password/username error handling
#			5) If server has new keys, the script won't even try to connect.
#			6) Send commands through terminal or through text file?
#			7) Add ability to write output to files
#
#	Status: Functional - WIP
#
#	LU: 01/17/16

import argparse
import os
from pexpect import pxssh

## Global variables and consts
TIMEOUT = 20
DEBUG_MODE = False
##

class MyClient:
	def __init__(self, host, user, password):
		self.isConnected = False
		self.host = host
		self.user = user
		self.password = password
		self.session = self.connect()

	def connect(self):
		global DEBUG_MODE
		try:
			print "[*] Attempting to connect to " + self.host + "..."
			if DEBUG_MODE:
				print "using: " + self.user + " " + self.password

			s = pxssh.pxssh()
			s.login(self.host, self.user, self.password, login_timeout=TIMEOUT)
			self.isConnected = True
			return s

		except pxssh.ExceptionPxssh, e:
			if DEBUG_MODE:
				print "[-] Error in pxssh. Probably unable to connect to a host"
				print e
			if "password refused" in str(e):
				print "[-] Password or username for " + self.host + " is incorrect."

	def send_command(self, cmd):
		if not self.isConnected:
			print str(self.host) + " is down or refusing entry"
			return
		self.session.sendline(cmd)
		self.session.prompt()
		return self.session.before

# --------------------------------------------------------------------------- #
def botnetCommand(cmd, botNet_list):
	for client in botNet_list:
		output = client.send_command(cmd)
		if client.isConnected:
			print "[*] Output from " + client.host
			print "[+] " + output

# --------------------------------------------------------------------------- #
def addClient(host, user, password, botNet_list):
	client = MyClient(host, user, password)
	botNet_list.append(client)

# --------------------------------------------------------------------------- #
def openFile(filename, botNet_list):
	global DEBUG_MODE

	if not os.path.isfile(filename):
		print "Error opening file. Exiting..."
		exit(0)

	with open(filename, 'r') as fn:
		content = fn.readlines()

	for line in content:
		if "#" in line:
			continue
		elif line.startswith("\n"):
			continue
		else:
			vals = line.split()
			if DEBUG_MODE: print "[DEBUG] Vals == " + str(vals)
			addClient(vals[0], vals[1], vals[2], botNet_list)

# --------------------------------------------------------------------------- #
def parseInputs(botNet_list):
	global DEBUG_MODE

	parser = argparse.ArgumentParser(description="A simple SSH bot that will login to a server and run commands specified inside script. Still a WIP")

	parser.add_argument("-f ", dest="inputFile", type=str, \
		help="Input file with list of targets")
	parser.add_argument("-D", dest="debugMode", action="store_true", \
		help="Gives debug information on the terminal")

	leOptions = parser.parse_args()

	if leOptions.inputFile == None:
		parser.print_help()
		exit(0)
	else:

		if leOptions.debugMode:
			DEBUG_MODE = True
			print "[+] Debug mode is on!"

		openFile(leOptions.inputFile, botNet_list)

# --------------------------------------------------------------------------- #
def main():
	global DEBUG_MODE
	botNet = [] # Built in addClient()

	parseInputs(botNet)

	# Commands we want to run on the server
	botnetCommand("uname -v", botNet)
	botnetCommand("cat /etc/passwd", botNet)
	
# --------------------------------------------------------------------------- #
if __name__ == "__main__":
	main()