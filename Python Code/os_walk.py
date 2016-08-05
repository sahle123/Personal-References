# os_walk.py
#
#   Lists all files in a current directory
#   Useful SO post: http://stackoverflow.com/questions/3207219/how-to-list-all-files-of-a-directory-in-python
#
#   LU: 08/03/16
#

import os

f = []
i = raw_input("Please specify a directory: ")

for dirpath, dirnames, filenames in os.walk(i):
    f.extend(filenames)
    print "Dirpath: ", dirpath
    print "Files: ", f
    print ""
    print ""
    #break # remove this break if you want to dig deeper into other dirs

if not f: #empty list
    print "[-] Bad input. Exiting..."
