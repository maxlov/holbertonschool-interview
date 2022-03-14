#!/usr/bin/python3
"""pascal's triangle"""


def pascal_triangle(n):
    """returns list of ints"""
    if n <= 0:
        return []
    triangle = []
    for i in range(0, n):
        row = [1] * (i + 1)
        if i >= 2:
            for j in range(1, i):
                row[j] = prev[j - 1] + prev[j]
                row[-j-1] = row[j]
        prev = row
        triangle.append(row)
    return triangle
