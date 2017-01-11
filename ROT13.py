#!/usr/bin/python3
for char in input("Input your text: "):
    num = ord(char)
    if (num > 96 and num < 123) or (num > 64 and num < 91):
        print(chr((num + 26) % 26))
    else:
        print(char, end="")
        continue
    print(chr(27 + diff - num + diff), end="")
print()
