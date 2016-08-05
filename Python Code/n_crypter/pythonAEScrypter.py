## pythonAEScrypter.py
#
# File encrypter/decrypter class in Python
#
#   Sahle "Nomad" Alturaigi
#
# LU: 08/05/16


from Crypto.Cipher import AES
from Crypto import Random
import hashlib
import base64
import os

class n_crypter():

    def __init__(self):
        self.KEY_SIZE = 32       # Must be 16, 24, 32 for AES. Block size?
        self.PADDING = '{'       # Padding character
        self.F = []              # List of all files found

        # Generate a random secret key.
        # If we lose this, we can no longer decrypt our file!
        self.SECRET = Random.new().read(AES.block_size);
        #self.SECRET = "1234567890abcdef"

        # Generating an initialization vector. Needed for our chaining mode.
        self.IV = Random.new().read(AES.block_size);

        print "n_crypter initialized"

    # Sets the key for encryption and decryption
    def SetKey(self, s):
        self.SECRET = hashlib.sha256(s).digest()
        return


    # Padding to make sure the KEY_SIZE is always satisfied
    def padInput(self, s):
        return s + ((self.KEY_SIZE - len(s) % self.KEY_SIZE) * self.PADDING)

    # Order of operations:
    # Generate IV, cipher obj, pad string, encrypt text, encode b64
    def EncodeAES(self, s):

        # Generate a new, random initailization vector
        self.IV = Random.new().read(AES.block_size);

        # Create a cipher object using the random secret key
        # The 2nd param is a block chaining mode. Avoid using MODE_ECB; use
        # MODE_CFB or MODE_CBC instead.
        cipher = AES.new(self.SECRET, AES.MODE_CBC, self.IV)

        # Get our cipher text from the cipher object we passed into the function.
        # The string is also padded to meet size requirements
        cipher_text = cipher.encrypt(self.padInput(s))

        # Encode cipher text into base64
        result = base64.b64encode(self.IV + cipher_text)

        if not result:
            print "[-] ERROR: Something went wrong in the encodeAES()"

        return result

    # Order of operations:
    # decode b64, create new cipher obj, decrypt, remove padding
    def DecodeAES(self, encoded_input):

        # Decode base64 characters back to original format.
        # Still encrypted, however.
        dec = base64.b64decode(encoded_input)

        # Get first 16 bytes of decoded string.
        l_IV = dec[:16]

        # Create new cipher object with the same secret key.
        l_Cipher = AES.new(self.SECRET, AES.MODE_CBC, l_IV)

        # Return the decrypted output and strip the padded chars off.
        result = l_Cipher.decrypt(dec[16:]).rstrip(self.PADDING)

        if not result:
            print "[-] ERROR: Something went wrong in the decodeAES()"

        return result

# ----------------------------------------------------------------------------

# NOTE: This code shouldn't be used for now... Might delete later
def main():

    # Instantiate class
    myObj = n_crypter()

    # Get string to encode from user
    userStr = raw_input("Please provide a string: ")

    # Encode a string
    encoded = myObj.EncodeAES(userStr)
    print 'Encrypted string: ', encoded

    # Decode the encoded string
    #secret = raw_input("What's the secret key? ")
    decoded = myObj.DecodeAES(encoded)
    print 'Decrypted string: ', decoded


if __name__ == "__main__":
    main()
