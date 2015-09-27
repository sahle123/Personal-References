# hash5.py

# This might be CPU intensive. 
# Crack hashes with rounds of MD5 and even more SHA-1 rounds.
# We know there is less than 500 hashing rounds altogether.
#
# ming: ce788ed5f855e51e6fd78f923b43a6407467c5f2
# mohammed: 582d99006950cddeb2df9f40b3f65ebc283dc378
# sam: da660655f4d4714fe605e9063d1ded4b749c50a9 

import hashlib, sys

username = "CCSF-" + sys.argv[1]
print "\n\nRunning hash5.py script...\n\n"

iterations = sys.argv[2]

for i in range(0, int(iterations) + 1):

	for pin in range(00, 100):
		if pin < 10:
			passwd = username + "-0" + str(pin)
		else:
			passwd = username + "-" + str(pin)

		for num in range(0, i + 1):
			passwd = hashlib.new('md5', passwd).hexdigest()
		for num2 in range(0, i + 51):
			passwd = hashlib.new("sha1", passwd).hexdigest()
		#passwd = hashlib.new('md5', passwd)

		print str(pin) + " " + passwd

print "Done!"

# ANS: 	CCSF-ming-00
#		CCSF-Mohammed-50
#		CCSF-sam-01