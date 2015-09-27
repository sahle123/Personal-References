# grepper.py

for line in open("TEST1.txt"):
	if "Successful" in line:
		print "Found it!\a"
		print line
		continue
	
print "No luck... /:\a"