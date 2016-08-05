# pyFileIO.py
#
# Basic reference on python's file IO manipulation
# Some helpful references:
#   http://stackoverflow.com/questions/5137497/find-current-directory-and-files-directory
#
#   Usage: python pyFileIO.py | tee -a logger.txt
#
# LU: 08/04/16

import os
import re
import datetime # for logger

F = []
extList = ["\.txt", "\.docx"]
DirSpace = "/Users/NomadHome/Desktop/htSandbox"

def main():

    ## Snippet to get path of file
    # Note that __file__ is the path name of the loaded file. In this case
    # this would be "pyFileIO.py"
    dir_path = os.path.dirname(os.path.realpath(__file__))
    print "dir_path is: " + dir_path
    print ""

    ## Snippet to get current working directory
    cwd = os.getcwd()
    print "Current working directory: " + cwd

    for dirpath, dirnames, filenames in os.walk(DirSpace):
        #F.extend(filenames)
        F = filenames

        print ""
        print "[+] Dirpath: ", dirpath
        print "[+] Files: ", F

        if not F:
            print "[-] Directory is empty..."

        for i in F:
            for j in extList:
                if re.match(r'\w+'+j, i, re.I):
                    print "[*] Opening " + i + " in " + dirpath

                    # Join the directory path and file name into single path.
                    # That way, it is OS-independent
                    f_path = os.path.join(dirpath, i)
                    # Open in reading, writing binary format
                    fo = open(f_path, "rb+")
                    # Read contents of the file
                    f_contents = fo.read()
                    print "file contents: " + f_contents

                    #fo.write("The date is now " + str(datetime.datetime.today()) + "\n")
                    fo.close()
                else:
                    continue

if __name__ == "__main__":
    print datetime.datetime.today()
    main()
    print "----------"
    print ""
    print ""
