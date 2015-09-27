# CCipher.py
# 
# Ceaser Cipher example in Python. This one was hard to solve...
#	LU: 09-21-15
#

MIN_ORDINAL = 65 # ASCII alphabet starts here.
MAX_ORDINAL = 122 # ASCII alphabet ends there.
LOWER_ORDINAL_START = 97 # ASCII lowercase alphabet start.
UPPER_ORDINAL_LIMIT = 90 # ASCII uppercase alphabet ends.

def encryptor(key, message):
    uKey = key % 26
    cipher = []
    splitMessage = message.split()

    for i in splitMessage:
        tempCipher = ''

        for m in i:
            pairCheck = ord(m) + uKey
            print "pre pairCheck: " + str(pairCheck) # Debug

            # In case we go over the ASCII limit.
            if pairCheck > MAX_ORDINAL:
                pairCheck = (LOWER_ORDINAL_START + (pairCheck - MAX_ORDINAL - 1))            
            
            # In case we go over the ASCII uppercase letters.
            elif ord(m) < UPPER_ORDINAL_LIMIT and ord(m) > MIN_ORDINAL:
                if pairCheck > UPPER_ORDINAL_LIMIT:
                    pairCheck = (MIN_ORDINAL + (pairCheck - UPPER_ORDINAL_LIMIT - 1))

            # To handle special characters.
            elif pairCheck < MIN_ORDINAL:
                pairCheck = ord(m)

            tempCipher = tempCipher + chr(pairCheck)

        cipher.append(tempCipher);

    return " ".join(cipher)

# Test cases:

test.assert_equals(encryptor(13, ''), '')
test.assert_equals(encryptor(13, 'Caesar Cipher'), 'Pnrfne Pvcure')
test.assert_equals(encryptor(-5, 'Hello World!'), 'Czggj Rjmgy!')
test.assert_equals(encryptor(27, 'Whoopi Goldberg'), 'Xippqj Hpmecfsh')

### Here is another solution I found online. Not the most elegant, but the most readable 
### out of all the other pedantic entries.

def encryptor(key, message):
    import string
    lowers = string.lowercase*2
    uppers = string.uppercase*2
    result = ""
    while True:
        if key > 26:
            key = key - 26
        elif key < -26:
            key = key + 26
        else:
            break

    for m in message:
        try:
            if m.isupper():
                result += uppers[uppers.index(m)+key]
            else:
                result += lowers[lowers.index(m)+key]
        except:
            result += m
    return result

 