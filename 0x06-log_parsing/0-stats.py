#!/usr/bin/python3
'''coding challenge function'''

import sys


keys = ['200', '301', '400', '401', '403', '404', '405', '500']

stats = {
    'total': 0,
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

try:
    for line in sys.stdin:
        input = line.split()

        if len(input) != 9:
            continue
        stats["total"] += 1
        stats[input[7]] += 1
        if stats["total"] % 10 == 0 and stats["total"] != 0:
            stats_print(stats)
        print("File size: {}".format(stats["total"]))
        for key in keys:
            if stats[key] < 1:
                continue
            print("{}: {}".format(key, stats[key]))
except Exception:
    print("File size: {}".format(stats["total"]))
    for key in keys:
        if stats[key] < 1:
            continue
        print("{}: {}".format(key, stats[key]))
