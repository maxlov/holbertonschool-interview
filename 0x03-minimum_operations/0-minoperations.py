#!/usr/bin/python3
"""
Function that gets min num of ops
"""

import sys

def minOperations(n):
    """gets min operations"""

    sys.setrecursionlimit(100000)
    return minOpHelper(n, 1, 1, 1)


def minOpHelper(target, current, clipboard, operations):
    """uses recursion to calculate min ops"""
    
    copy = sys.maxsize
    paste = sys.maxsize

    if (target < 1):
        return 0
    if (target == current):
        return operations
    if (target < current or (clipboard + current) > target):
        return sys.maxsize
    if (clipboard != current):
        copy = minOpHelper(target, current, current, operations + 1)
    paste = minOpHelper(target, current + clipboard, clipboard, operations + 1)

    return copy if copy < paste else paste
