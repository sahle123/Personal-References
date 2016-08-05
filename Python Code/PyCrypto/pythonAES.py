## pythonAES.py
#
# Example on two-way encryption/decryption in AES for python
# Kudos goes to: https://gist.github.com/sekondus/4322469
# Another good ref: http://eli.thegreenplace.net/2010/06/25/aes-encryption-of-files-in-python-with-pycrypto
#
# LU: 08/03/16


## NOTES:
#   1 - AES requires two different parameters for encryption: A key and an
#   initialization vector (IV).
#
#   2 -
##

from Crypto.Cipher import AES
from Crypto import Random
import base64
import os

KEY_SIZE = 32     # Must be 16, 24, 32 for AES
PADDING = '{'       # Padding character

## Lambda expressions:
# Padding to make sure the KEY_SIZE is always satisfied
pad = lambda s: s + (KEY_SIZE - len(s) % KEY_SIZE) * PADDING;


# Encrypt, encode; decrypt, decoders
EncodeAES = lambda c, s: base64.b64encode(c.encrypt(pad(s)))
DecodeAES = lambda c, e: c.decrypt(base64.b64decode(e)).rstrip(PADDING)

# Generate a random secret key
#secret = os.urandom(KEY_SIZE)
secret = Random.new().read(AES.block_size); # Better alternative than the above snippet

# Create a cipher object using the random secret key
# The 2nd param is a block chaining mode. Avoid using MODE_ECB; use
# MODE_CFB or MODE_CBC instead.
cipher = AES.new(secret, AES.MODE_ECB)

# Get string to encode from user
userStr = raw_input("Please provide a string: ")

# Encode a string
encoded = EncodeAES(cipher, userStr)
print 'Encrypted string: ', encoded

# Decode the encoded string
decoded = DecodeAES(cipher, encoded)
print 'Decrypted string: ', decoded
