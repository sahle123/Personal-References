# pyFileIOenc.py
#
# File IO Encrypter module
#
#   Sahle "Nomad" Alturaigi
#
# LU: 08/07/16

import os
import re
from pythonAEScrypter import n_crypter
import datetime

## NOTE: DEBUG CODE
import pdb

F = []
extList = ["\.txt", "\.jpg", "\.docx", "\.pages", "\.mp3"]
DirSpace = "/Users/NomadHome/Desktop/htSandbox"

def main():

    # Ask user for pass key
    passKey = raw_input("Please set passkey for module: ")

    # Initializing encrypter module
    myCrypter = n_crypter()
    myCrypter.SetKey(passKey)

    # Walking through directories and encrypting files
    for dirpath, dirnames, filenames in os.walk(DirSpace):
        #F.extend(filenames)
        F = filenames

        print "-----------"
        print "[*] Dirpath: ", dirpath

        if not F:
            print "[-] Directory is empty..."

        for i in F:
            for j in extList:
                if re.match(r'((([\w]+[\W]+)+\w+)|(\w+))'+j, i, re.I):

                    # Join the directory path and file name into single path.
                    # That way, it is OS-independent
                    f_path = os.path.join(dirpath, i)

                    print "Encrypting: " + f_path

                    # Open in reading, writing binary format
                    fo = open(f_path, "rb+")

                    # Read contents of the file
                    f_contents = fo.read()

                    # Encode inputs
                    f_contents = myCrypter.EncodeAES(f_contents)

                    #print "[+] "+ str(i) +" after encryption: " + f_contents

                    fo.truncate(0) # remove contents inside of file
                    fo.seek(0) # Set file pointer back to beginning of file
                    fo.write(f_contents)

                    fo.close()

                else:
                    continue

        # NOTE: DEBUG CODE
        #pdb.set_trace()
        #break # Remove this later to dive deeper

    print "----------"
    print "[*] Encryption completed"

if __name__ == "__main__":
    print datetime.datetime.today()
    main()
    print ""
    print ""
