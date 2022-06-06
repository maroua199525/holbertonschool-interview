#!/usr/bin/python3

""" a module contain the function Given an n x n 2D matrix"""


def rotate_2d_matrix(matrix):
    """a function that rotate a matrix 2D 90 degrees clockwise"""

    n = len(matrix)
    for i in range(0, (n // 2)):
        for j in range(i, n - i - 1):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[j][n - 1 - i]
            matrix[j][n - 1 - i] = matrix[n - 1 - i][n - 1 - j]
            matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i]
            matrix[n - 1 - j][i] = tmp
    for i in range(0, n):
        for j in range(0, len(matrix[i])):
            matrix[i].reverse()
        matrix.reverse()
