# pyFileIO2.py
#
# Basic reference on python's file IO manipulation WITH encryption/decryption
#
#   Sahle "Nomad" Alturaigi
#
# LU: 08/04/16

import os
import re
from pythonAEScrypter import n_crypter
import datetime

F = []
extList = ["\.txt", "\.docx"]
DirSpace = "/Users/NomadHome/Desktop/htSandbox"

def main():

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
                if re.match(r'\w+'+j, i, re.I):
                    #print "[*] Opening " + i + " in " + dirpath

                    # Join the directory path and file name into single path.
                    # That way, it is OS-independent
                    f_path = os.path.join(dirpath, i)
                    # Open in reading, writing binary format
                    fo = open(f_path, "rb+")
                    # Read contents of the file
                    f_contents = fo.read()

                    f_contents = myCrypter.EncodeAES(f_contents)
                    print "[+] file contents after encryption: " + f_contents
                    f_contents = myCrypter.DecodeAES(f_contents)
                    print "[+] file contents after decryption: " + f_contents
                    #fo.write("The date is now " + str(datetime.datetime.today()) + "\n")
                    fo.close()

                else:
                    continue

    print "----------"

if __name__ == "__main__":
    print datetime.datetime.today()
    main()
    print ""
    print ""
