# basic_grab_banner.py
#
#	Basic reference on how to open a connectio and grab a banner.	
#
#	Ref: Violent python, TJ O'Conner
#
#	12/16/15

import socket

def getBanner(ip, port):
	socket.setdefaulttimeout(10)

	print "Testing connection..."

	# Default family is AF_INET , and the
	# default socket type is SOCK_STREAM
	# Protocol number is usually 0.
	# Thus, socket.socket() == socket.socket(AF_INET, SOCK_STREAM, 0)
	s = socket.socket()

	# Basic exception handling
	try:
		s.connect((ip, int(port))) # my Kali ip 

	except Exception, e:
		print "[-] Got an error: "+str(e)
		return

	ans = s.recv(1024) # receive 1024 bytes (1 KB) from the socket.
	print "[+] We got back: "+ans

def main():
	leIP = raw_input("Input IP addr: ")
	lePort = raw_input ("Input port #: ")

	getBanner(leIP, lePort)

	print "[+] Exit successful"


# Boilerplate code
if __name__ == '__main__':
	main()
