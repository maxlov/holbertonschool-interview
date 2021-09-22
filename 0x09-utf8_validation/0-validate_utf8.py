#!/usr/bin/python3
"""
Main file for testing
"""


def validUTF8(data):
    '''validates data'''
    num_ones = 0
    for value in data:
        value = str(bin(value))[2:].rjust(8, '0')
        if num_ones > 0:
            num_ones -= 1
            if value[:2] != "10":
                return False
        elif value[0] == '1':
            num_ones = len(value.split('0')[0]) - 1
    return True
