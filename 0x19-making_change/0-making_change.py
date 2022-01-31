#!/usr/bin/python3
"""
Calculates minimum number of coins needed.
"""


def makeChange(coins, total):
    ''' coins is list of coin denomination, total is value to get '''
    if (total <= 0):
        return 0
    coins.sort(reverse=True)
    return findNumber(coins, total, 0)


def findNumber(coins, total, coinsUsed):
    ''' recursive helper function to find number of coins'''
    remainder = total % coins[0]
    if (remainder == 0):
        return coinsUsed + total // coins[0]
    if (remainder == total):
        if (len(coins) <= 1):
            return -1
        findNumber(coins[1:], total, coinsUsed)
    if (len(coins) <= 1):
        return -1
    return findNumber(coins[1:], remainder, coinsUsed + total // coins[0])
