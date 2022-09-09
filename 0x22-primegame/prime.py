#!/usr/bin/python3
""" a module that contain the function prime """

def isPrime(x):
    """ checks if a number is prime """
    for i in range(2, x):
        if x % i == 0:
            return False
    return True