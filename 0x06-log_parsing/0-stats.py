#!/usr/bin/python3
'''coding challenge function'''

import sys
from signal import signal, SIGINT
from collections import OrderedDict

def handler(signal_received, frame):
    stats_print(stats)
    exit(0)

def stats_print(stats):
    print("File size {}".format(stats["total"]))
    for key, value in stats.items():
        if (key == 'total' or value < 1):
            continue
        print("{}: {}".format(key, value))

if __name__ == '__main__':
    stats = {
        'total' : 0,
        '200' : 0,
        '301' : 0,
        '400' : 0,
        '401' : 0,
        '403' : 0,
        '404' : 0,
        '405' : 0,
        '500' : 0
    }

    signal(SIGINT, handler)

    for line in sys.stdin:
        input = line.split()

        if len(input) != 9:
            continue
        stats["total"] += 1
        stats[input[7]] += 1
        if stats["total"] % 10 == 0 and stats["total"] != 0:
            stats_print(stats)
