# http2.py

# https://samsclass.info/124/proj14/p5-http.htm

import socket
socket.setdefaulttimeout(2)
s = socket.socket()

target = "attack.samsclass.info"
tport = 80

user = raw_input('Username: ')
pw = raw_input('Password: ')

length = len(user) + len(pw) + 5

s.connect((target, tport))

s.send("POST /python/login1.php HTTP/1.1\nHost: " + target \
	+ "\nContent-Length: " + str(length) \
	+ "\nContent-Type: application/x-www-form-urlencoded" \
	+ "\n\nu=" + user + "&p=" + pw)

print "s.recv:"
print s.recv(1024)

s.close()
#	The code above sends an HTTP POST request like this:
#
#		POST /python/login1.php HTTP/1.1
#		Host: attack.samsclass.info
#		Content-Type: application/x-www-form-urlencoded
#		u=SomeUsername&p=SomePassword
#