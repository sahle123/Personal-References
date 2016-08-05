## pythonAES2.py
#
# Example on two-way encryption/decryption in AES for python
# Kudos goes to: https://gist.github.com/sekondus/4322469
#
#   Sahle "Nomad" Alturaigi
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

KEY_SIZE = 32     # Must be 16, 24, 32 for AES. Block size?
PADDING = '{'     # Padding character

## Lambda expressions:
# Padding to make sure the KEY_SIZE is always satisfied
pad = lambda s: s + (KEY_SIZE - len(s) % KEY_SIZE) * PADDING

## Encrypt, encode; decrypt, decoders

# Order of operations:
# Pad string, encrypt text, encode b64
def EncodeAES(c, s):

    # Get our cipher text from the cipher object we passed into the function.
    # The string is also padded to meet size requirements
    cipher_text = c.encrypt(pad(s))

    # Encode cipher text into base64
    return base64.b64encode(iv + cipher_text)

# Order of operations:
# decode b64, create new cipher obj, decrypt, remove padding
def DecodeAES(encoded_input):
    # Decode base64 characters back to original format.
    # Still encrypted, however.
    dec = base64.b64decode(encoded_input)

    # Get first 16 bytes of decoded string.
    l_IV = dec[:16]

    # Create new cipher object with the same secret key.
    l_Cipher = AES.new(secret, AES.MODE_CBC, l_IV)

    # Return the decrypted output and strip the padded chars off.
    return l_Cipher.decrypt(dec[16:]).rstrip(PADDING)

# Generate a random secret key.
# If we lose this, we can no longer decrypt our file!
secret = Random.new().read(AES.block_size);

# Generating an initialization vector. Needed for our chaining mode.
iv = Random.new().read(AES.block_size);

# Create a cipher object using the random secret key
# The 2nd param is a block chaining mode. Avoid using MODE_ECB; use
# MODE_CFB or MODE_CBC instead.
cipher = AES.new(secret, AES.MODE_CBC, iv)

# Get string to encode from user
userStr = raw_input("Please provide a string: ")

# Encode a string
encoded = EncodeAES(cipher, userStr)
print 'Encrypted string: ', encoded

# Decode the encoded string
decoded = DecodeAES(encoded)
print 'Decrypted string: ', decoded
