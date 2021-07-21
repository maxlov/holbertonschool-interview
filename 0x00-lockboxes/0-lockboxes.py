#!/usr/bin/python3
'''coding challenge function'''


def canUnlockAll(boxes):
    '''determines if all boxes could be opened'''
    if (len(boxes) <= 1):
        return True
    keys = []
    for key in boxes[0]:
        if key not in keys:
            keys.append(key)
        boxes[0] = None
    idx = 0
    while (idx < len(keys)):
        if (boxes[keys[idx]] is not None):
            for key in boxes[keys[idx]]:
                if key not in keys:
                    keys.append(key)
            boxes[keys[idx]] = None
        idx += 1
    if (all(box is None for box in boxes)):
        return True
    return False
