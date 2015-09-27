# hash4.py

# Cracking hashes exercise with MD5 instead of MD4
# Format of username: CCSF-username-PIN, e.g. CCSF-sam-01
# We do not know the encoding. Doesn't use Unicode. Maybe ASCII?
#
# ming: 7621eca98fe6a1885d4f5f56a0525915
# mohammed: b2173861e8787a326fb4476aa9585e1c
# sam: 42e646b706acfab0cf8079351d176121 

import hashlib, sys

username = "CCSF-" + sys.argv[1]
print "\n\nRunning hash4.py script...\n\n"

iterations = sys.argv[2]

for i in range(0, int(iterations) + 1):

	for pin in range(00, 100):
		if pin < 10:
			passwd = username + "-0" + str(pin)
		else:
			passwd = username + "-" + str(pin)

		for num in range(0, i + 1):
			passwd = hashlib.new('md5', passwd).hexdigest()
		#passwd = hashlib.new('md5', passwd)

		print str(pin) + " " + passwd

print "Done!"

# ANS: 	CCSF-ming-11
#		CCSF-Mohammed-97
#		CCSF-sam-01