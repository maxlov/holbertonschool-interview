#!/usr/bin/python3
"""
0_main
"""
import time
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    start = time.time()
    print(rain(walls))
    print("Execution time: {}".format(time.time() - start))
    start = time.time()
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))
    print("Execution time: {}".format(time.time() - start))
