import sys
from subprocess import *

def usage():
    print('Usage: %s (-e | -d) (text or punycode)' % sys.argv[0])
if len(sys.argv) != 3:
    usage()
    exit()
else:
    if sys.argv[1] == '-e':
        uni_hexs = ' '.join([('u+%s' % hex(ord(char)).replace('0x', '')) for char in sys.argv[2]])
        pipe = Popen(['./punycode', '-e'], stdin=PIPE, stdout=None, stderr=STDOUT)
        pipe.stdin.write(uni_hexs.encode())
        pipe.stdin.close()
    elif sys.argv[1] == '-d':
        pipe = Popen(['./punycode', '-d'], stdin=PIPE, stdout=PIPE, stderr=STDOUT)
        pipe.stdin.write(sys.argv[2].encode())
        pipe.stdin.close()
        uni_hexs = pipe.stdout.readlines()
        for code in uni_hexs:
            print(chr(int(code[2:], 16)), end='')
        print()
