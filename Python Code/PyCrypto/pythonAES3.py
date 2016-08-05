## pythonAES3.py
#
# File encrypter/decrypter that needs the secret key.
# The key is found in the variable SECRET
#   Sahle "Nomad" Alturaigi
#
# LU: 08/04/16


from Crypto.Cipher import AES
from Crypto import Random
import base64
import os

KEY_SIZE = 32       # Must be 16, 24, 32 for AES. Block size?
PADDING = '{'       # Padding character
F = []              # List of all files found
SECRET = "123456789abcefdl" # Secret key MUST be 16, 24, or 32 bytes long
IV = Random.new().read(AES.block_size); # Generating an initialization vector. Needed for our chaining mode.


## Lambda expressions:
# Padding to make sure the KEY_SIZE is always satisfied
pad = lambda s: s + (KEY_SIZE - len(s) % KEY_SIZE) * PADDING;

## Encrypt, encode; decrypt, decoders

# Order of operations:
# Generate cipher obj, pad string, encrypt text, encode b64
def EncodeAES(s):

    global SECRET, IV

    # Create a cipher object using the random secret key
    # The 2nd param is a block chaining mode. Avoid using MODE_ECB; use
    # MODE_CFB or MODE_CBC instead.
    cipher = AES.new(SECRET, AES.MODE_CBC, IV)

    # Get our cipher text from the cipher object we passed into the function.
    # The string is also padded to meet size requirements
    cipher_text = cipher.encrypt(pad(s))

    # Remove secret key
    SECRET = ""

    # Encode cipher text into base64
    return base64.b64encode(IV + cipher_text)

# Order of operations:
# decode b64, create new cipher obj, decrypt, remove padding
def DecodeAES(encoded_input):

    # Decode base64 characters back to original format.
    # Still encrypted, however.
    dec = base64.b64decode(encoded_input)

    # Get first 16 bytes of decoded string.
    l_IV = dec[:16]

    # Create new cipher object with the same secret key.
    l_Cipher = AES.new(SECRET, AES.MODE_CBC, l_IV)

    # Return the decrypted output and strip the padded chars off.
    return l_Cipher.decrypt(dec[16:]).rstrip(PADDING)

# Get string to encode from user
userStr = raw_input("Please provide a string: ")

# Encode a string
encoded = EncodeAES(userStr)
print 'Encrypted string: ', encoded

# Decode the encoded string
SECRET = raw_input("What's the secret key? ")
decoded = DecodeAES(encoded)
print 'Decrypted string: ', decoded
