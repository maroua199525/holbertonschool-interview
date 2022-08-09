#!/usr/bin/python3

""" A module that contain a function iscount_perimeter"""


def island_perimeter(grid):
    """a function that returns the perimeter of the iscount
        described in grid"""

    len_1 = len(grid)
    len_2 = len(grid[0])
    count, cell = 0, 0
    for i in range(0, len_1):
        for j in range(0, len_2):
            if grid[i][j] == 1:
                count += 1
                if i < len_1 - 1 and grid[i+1][j] == 1:
                    cell += 1
                if j < len_2 - 1 and grid[i][j+1] == 1:
                    cell += 1
    perimeter = (count * 4 - 2 * cell)
    return perimeter
