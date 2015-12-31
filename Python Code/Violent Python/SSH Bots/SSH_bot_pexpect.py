# SSH_bot_pexpect.py
#
#	Des:	A weak implmentation of a bot that connects to
#			a hardcoded host with hardcoded password + username.
#			Utilizes Pexpect library which is useful for handling
#			user interactive I/O; fairly unintuitive albeit.
#			Requires 'sudo' to work
#	Status: Functional-WIP
#
#	Ref: Violent Python, TJ O'Conner (Modified)
#
#	LU: 12/24/15

import pexpect
PROMPT = ['# ', '>>> ', '> ', '\$ ']

# -------------------------------------------------------------------------- # 
def send_command(child, cmd):
	child.sendline(cmd)
	child.expect(PROMPT)
	print child.before

# -------------------------------------------------------------------------- #
def connect(user, host, password):

	ssh_newkey = 'Are you sure you want to continue connecting'
	connectionString = 'ssh ' + user + '@' + host

	print "[*] DEBUG: connectionString: "+connectionString

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
def main():
	host = '192.168.1.7'
	user = 'nomad'
	password = 'Noah123njosh123'
	child = connect(user, host, password)
	send_command(child, 'cat /etc/passwd | grep root')

if __name__ == '__main__':
	main()