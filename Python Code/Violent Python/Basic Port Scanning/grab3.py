# grab3.py
# The answer is port 3000.

import socket
socket.setdefaulttimeout(2) # After 2 seconds, program timesout. Need this to prevent lockups
s = socket.socket() # Create socket object s.

#target = "attack.samsclass.info"
#tport = 80
target = "attack.samsclass.info"
tport = int(raw_input('Target Port: '))

s.connect((target, tport))
print s.recv(1024)
s.close()

#for i in xrange(1000, 9000, 1000):
#	tport = int(i)
#	s.connect((target, tport))
#	print s.recv(1024)
#	s.close()
	
