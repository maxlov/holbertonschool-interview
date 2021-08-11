#!/usr/bin/python3
"""
Function that gets min num of ops
"""

import sys


def minOperations(n):
    """gets min operations"""

    if (n < 2):
        return 0
    for i in range(n // 2, 0, -1):
        if n % i == 0:
            return n // i + minOperations(i)
