# grab2.py

import socket
socket.setdefaulttimeout(2) # After 2 seconds, program timesout. Need this to prevent lockups
s = socket.socket() # Create socket object s.

#target = "attack.samsclass.info"
#tport = 80
target = raw_input('Target URL: ')
tport = int(raw_input('Target Port: '))

s.connect((target, tport))
print s.recv(1024)
s.close()

