# grab4.py 

import socket, time

socket.setdefaulttimeout(2) 
s = socket.socket() 
f = socket.socket()
h = socket.socket()

target = "attack.samsclass.info"
tport = int(raw_input('Target Port: '))

# The order here matters!!
f.connect((target, 3100))
s.connect((target, tport))
h.connect((target, 3003))

time.sleep(2)

print s.recv(1024)
print f.recv(1024)
print h.recv(1024)

s.close()
f.close()
h.close()

