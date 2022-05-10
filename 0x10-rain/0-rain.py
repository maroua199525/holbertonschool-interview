#!/usr/bin/python3
"""
Given a list of non-negative integers representing
the heights of walls with unit width 1,
as if viewing the cross-section of a relief map,
calculate how many square units of square_water
will be retained after it rains.
"""


def rain(walls):
    """
    a function that calculate how many square
    units of square_water will be retained after it rains
    """

    water = 0
    if walls is None:
        return 0
    if len(walls) == 0:
        return 0
    for i in range(1, len(walls) - 1):
        left= max(walls[:i])
        right = max(walls[i + 1:])
        min_square = min(left, right)
        if walls[i] < min_square:
            water += min_square - walls[i]
    return water