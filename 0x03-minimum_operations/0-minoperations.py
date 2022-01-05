#!/usr/bin/python3
""" Module Minimum Operations"""


def minOperations(n):
    """write a method that calculates the fewest number of operations
        needed to result in exactly n H characters in the file
    """
    x = isinstance(n, int)
    if (x is False):
        return (0)
    count = 0
    i = 2
    while(i <= n):
        if ((n % i) == 0):
            count = count + i
            n = n / i
            i = i - 1
        i = i + 1
    return count
