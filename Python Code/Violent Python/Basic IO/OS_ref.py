# OS_ref.py
#
#	Quick reference on how to use os and sys modules on python
#
#	Ref: Violent Python, TJ O'Conner
#
#	12/16/15

import sys
import os

if len(sys.argv) == 2:
	filename = sys.argv[1]

	if not os.path.isfile(filename):
		print "[-] \'"+filename+"\' doesn't exist."
		exit(0)

	if not os.access(filename, os.R_OK):
		print "[-] Could not access \'"+filename+"\'. Permission issue."
		exit(0)

	print "\n[+] Successfully accessed: \'"+filename+"\'"

else:
	print "Usage: <filename>"

