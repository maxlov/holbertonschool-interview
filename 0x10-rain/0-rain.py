#!/usr/bin/python3
"""
rain: calculates # of square units of water after a rainfall
"""


def rain(walls):
    if (len(walls) == 0):
        return 0
    water = 0
    i = 0
    saved = -1
    for i in range(0, len(walls)):
        if (saved >= 0 and walls[i] > 0):
            water += min(walls[i], walls[saved]) * (i - saved - 1)
            saved = i
        elif (walls[i] > 0):
            saved = i
    return water
