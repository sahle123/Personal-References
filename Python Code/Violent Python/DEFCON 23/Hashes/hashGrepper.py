# hashGrepper.py

insFile = raw_input("Specify filename: ")
winnerText = raw_input("Input hash we are searching for: ")

# Error checking if an illegal file was specified.
try:
	errorCheck = open (insFile) 
except:
	print "Could not open file! Closing..."
	quit()

for line in open(insFile):
	
	# Check lower and upper case string for match.
	if winnerText.lower() in line:
		print "Found it!\a\n"
		print line
		quit()
	elif winnerText.upper() in line:
		print "Found it!\a\n"
		print line
		quit()

	
print "No luck... /:\a"