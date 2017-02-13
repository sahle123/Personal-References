# n_crypter_v2.py
#
# Slightly updated File IO Encrypter/Decrypter script. Mostly the same as V1.
#
#   Sahle "Nomad" Alturaigi
#
# LU: 08/30/16

import os           # OS-independent functions
import platform     # For detecting OS version
import sys
import re           # Regex
import argparse     # For terminal version
from pythonAEScrypter import n_crypter
import datetime

## NOTE: DEBUG CODE
import pdb

###
# Globals
F = []
extList = ["\.txt", "\.jpg", "\.docx", "\.pages", "\.mp3"]
DirSpace = "/Users/NomadHome/Desktop/htSandbox"
Acceptable_OS_List = ["Darwin", "darwin", "Linux", "linux", "Windows", "windows"]
###

# --------------------------------------------------------------------------- #
# Parse user inputs from terminal.
def parseInputs():

    detect_OS()

    # Usage section
    parser = argparse.ArgumentParser(description="n_crypter BETA v2", \
        epilog="--End of help--")

    # encrypt option
    parser.add_argument("-E", dest="encryptMode", action="store_true", \
        help="To encrypt files")

    # decrypt option
    parser.add_argument("-D", dest="decryptMode", action="store_true", \
        help="To decrypt files. You only get one attempt. Beware")

    leOptions = parser.parse_args()

    if(leOptions.encryptMode == True) & (leOptions.decryptMode == True):
        print "[-] You cannot encrypt and decrypt at the same time. Bad inputs.\n"
        exit(0)

    # Encryption
    elif (leOptions.encryptMode == True):
        print "[*] Executing encryption\n"
        x = raw_input("Please set a passkey for module: ")
        EncryptFiles(x)
        exit(0)

    # Decryption
    elif (leOptions.decryptMode == True):
        print "[*] Executing decryption\n"
        x = raw_input("[!!!] Please provide correct passkey or close script: ")
        DecryptFiles(x)
        exit(0)

    else:
        parser.print_help()
        exit(0)
# --------------------------------------------------------------------------- #
def EncryptFiles(passKey):

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

    print "----------"
    print "[*] Encryption completed"

# --------------------------------------------------------------------------- #
def DecryptFiles(passKey):
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

                    print "Decrypting: " + f_path

                    # Open in reading, writing binary format
                    fo = open(f_path, "rb+")

                    # Read contents of the file
                    f_contents = fo.read()

                    # Decode inputs
                    f_contents = myCrypter.DecodeAES(f_contents)

                    # Make sure file isn't empty
                    if f_contents != None:
                        #print "[+] "+ str(i) +" after decryption: " + f_contents
                        # Clear file
                        fo.truncate(0)
                        # Set file pointer back to beginning
                        fo.seek(0)
                        # Write contents to file
                        fo.write(f_contents)

                    else:
                        print "[-] There was an issue in the decryption process"

                    # Close file
                    fo.close()

                else:
                    continue

    print "----------"
    print "[*] Decryption completed"

# --------------------------------------------------------------------------- #
def detect_OS():

    #machine_OS = str(platform.system());

    for i in Acceptable_OS_List:
        if sys.platform.startswith(i.lower()):
            print "[+] n_crypter supports your system"
            return
        else:
            continue

    print "[-] Your system is not supported. Exiting..."
    print machine_OS
    exit(0)
# --------------------------------------------------------------------------- #

print datetime.datetime.today()
parseInputs()
print ""
print ""
