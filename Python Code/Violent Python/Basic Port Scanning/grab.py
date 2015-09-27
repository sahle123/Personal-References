# grab.py

import socket

socket.setdefaulttimeout(2) # After 2 seconds, program timesout. Need this to prevent lockups

s = socket.socket() # Create socket object s.

s.connect(("attack.samsclass.info",80)) # Connects to attack.samsclass.info on port 80
print s.recv(1024)	# Recieves data from server up to a max of 1024 chars.
s.close()

