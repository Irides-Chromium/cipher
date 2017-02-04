#!/usr/bin/python3

### rev: 5.0
### author: <zhq>
### features:
###     errors included
###     up to 63 bases (2 to 64)
###     caps recognition and same output format (deprecated)
### for the function parameters, `cur` represents the current (input) base, `res` represents the result (output) base, and `num` represents the current (input) number.

def scale(cur, res, num):
#         int, int, str -> str
# Default Settings
    num = str(num)
    iscaps = True   # To be compatible with higher bases
    positive = True

    # Input
    if cur == res: return num
    if num == "0": return "0"
    assert cur in range(2, 65) and res in range(2, 65), "Base not defined."
    if num[0] == "-":
        positive = False
        num = num[1:]
    result = 0
    unit = 1

    if cur != 10:
        for i in num[::-1]:
            value = ord(i)
            if value in range(48, 58): value -= 48
            elif value in range(65, 92):
                if cur <= 36: iscaps = True
                value -= 55
            elif value in range(97, 123):
                if cur <= 36: value -= 87
                else: value -= 61
            elif value == 64: value = 62
            elif value == 95: value = 63
            assert value <= cur, "Digit larger than original base. v:%d b:%d" % (value, cur)
            result += value * unit
            unit *= cur
        result = str(result)

    # Output
    if res != 10:
        num = int(result or num)
        result = ""
        while num > 0:
            num, value = divmod(num, res)
            if value < 10: value += 48
            elif value < 36:
                if iscaps: value += 55
                else: value += 87
            elif value < 62: value += 61
            elif value == 62: value = 64
            elif value == 63: value = 95
            result = chr(value) + result
    if not positive: result = "-" + result
    return result
