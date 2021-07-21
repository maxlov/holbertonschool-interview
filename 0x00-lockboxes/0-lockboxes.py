#!/usr/bin/python3
'''coding challenge function'''


def canUnlockAll(boxes):
    '''determines if all boxes could be opened'''
    if (boxes is None):
        return False
    boxLen = len(boxes)
    if (boxLen <= 1):
        return True

    keys = [0]
    idx = 0
    while (idx < len(keys)):
        for key in boxes[keys[idx]]:
            if key not in keys and key < boxLen:
                keys.append(key)
        idx += 1

    if (len(keys) == boxLen):
        return True
    return False
