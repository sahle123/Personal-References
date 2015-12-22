# hash1.py

# MD4 hash generator


import hashlib

passwd = raw_input("Enter Password: ")
passwd = passwd.encode('utf-16le')	# Using UTF-16LE encoding instead of ASCII
print hashlib.new('md4', passwd).hexdigest() # Create hash and represent in hexidecimal