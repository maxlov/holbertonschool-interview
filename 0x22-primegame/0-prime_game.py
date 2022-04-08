#!/usr/bin/python3
"""
Ben and Maria prime game.
"""


def isWinner(x, nums):
    ''' Determines winner of prime game '''
    maria = 0
    ben = 0

    for round in range(x):
        primeCount = 0
        for i in range(1, nums[round] + 1):
            for j in range(1, i):
                if (j == 1 or i % j == 0):
                    break
            else:
                primeCount += 1
        if primeCount % 2 == 0:
            maria += 1
        else:
            ben += 1
    if (maria == ben):
        return None
    if (maria > ben):
        return "Maria"
    else:
        return "Ben"
