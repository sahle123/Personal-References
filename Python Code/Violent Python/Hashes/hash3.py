# hash3.py

# Cracking hashes exercise
# Format of username: CCSF-username-PIN, e.g. CCSF-sam-01
#
# ming 52C4859C0617E4A8FEC24BA890C5FC57
# mohammed 39057EF3A9FE57D98E7A9BAB7CD2F4F9
# sam 19A641D2520B983ABB7C931CEFF933FA 

import hashlib, sys

username = "CCSF-" + sys.argv[1]
#username = username + raw_input("Please enter username (Ming, Mohammed, sam): ")
print "\n\nRunning hash3.py script...\n\n"

for pin in range(00, 100):
	if pin < 10:
		passwd = username + "-0" + str(pin)
		passwd = passwd.encode('utf-16le')
	else:
		passwd = username + "-" + str(pin)
		passwd = passwd.encode('utf-16le')

	passwd = hashlib.new('md4', passwd).hexdigest()
	print str(pin) + " " + passwd

print "Done!"


# ANS: 	CCSF-ming-91
#		CCSF-Mohammed-57
#		CCSF-sam-01