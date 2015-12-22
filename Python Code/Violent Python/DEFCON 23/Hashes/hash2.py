# hash2.py

# Hash list directoy exercise
# Can be used to develop tables for cracking?

import hashlib

print "\n\nRunning hash2.py script...\n\n"

for pin in range(00, 100):
	if pin < 10:
		passwd = "0" + str(pin)
		passwd = passwd.encode('utf-16le')
	else:
		passwd = str(pin)
		passwd = passwd.encode('utf-16le')

	passwd = hashlib.new('md4', passwd).hexdigest()
	print str(pin) + " " + passwd

print "Done!"