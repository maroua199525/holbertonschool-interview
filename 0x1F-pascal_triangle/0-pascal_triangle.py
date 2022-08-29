#!/usr/bin/python3

""" A module that contain a function pascal_triangle"""


def pascal_triangle(n):
    """ a function that returns a list of lists of integers
       of Pascalstriangle"""
    if n <= 0:
        return []
    if n == 1:
        return [[1, ], ]
    triangle = [[1, ], ]
    for i in range(2, n + 1):
        pascal = [1, ]
        for x in range(len(triangle[-1]) - 1):
            pascal.append(triangle[-1][x] + triangle[-1][x + 1])
        pascal.append(1)
        triangle.append(pascal)
    return triangle
