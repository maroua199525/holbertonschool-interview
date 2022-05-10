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
    square = 0
    if walls is None:
        return 0
    if  walls == []:
        return 0
    for i in range(len(walls)):
        if walls[i] != 0:
            break
    for j in range(i + 1, len(walls)):
        if walls[j] == 0:
            square = square + 1
        else:
            if walls[j] < walls[i]:
                water += walls[j] * square
            else:
                water += walls[i] * square
            i = j
            square = 0
    return water
