#!/usr/bin/python3
""" a module that contain a method validUTF8(data) """


def validUTF8(data):
    """a method that determines
        if a given data set represents a valid UTF-8 encoding"""
    data.reverse()

    def check_byte(data, n):
        if len(data) < n-1:
            return False
        bytes_to_check = [data.pop() for _ in range(n-1)]
        for i in bytes_to_check:
            if not (i & 0xC0) == 0x80:
                return False
        return True
    while data:
        i = data.pop()
        if (i & 0xF8) == 0xF0:
            check = check_byte(data, 4)
        elif (i & 0xF0) == 0xE0:
            check = check_byte(data, 3)
        elif (i & 0xE0) == 0xC0:
            check = check_byte(data, 2)
        elif (i & 0x80) == 0x00:
            check = True
        else:
            check = False
        if not check:
            return False
    return True
