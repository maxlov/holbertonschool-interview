#!/usr/bin/python3
'''coding challenge function'''

import sys


def stats_print(stats):
    print("File size: {}".format(stats["total"]))
    keys = ['200', '301', '400', '401', '403', '404', '405', '500']
    for key in keys:
        if stats[key] < 1:
            continue
        print("{}: {}".format(key, stats[key]))


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
line_count = 0

try:
    for line in sys.stdin:
        input = line.split()
        try:
            line_count += 1
            stats["total"] += int(input[-1])
            stats[input[7]] += 1
        except Exception:
            continue
        if line_count % 10 == 0 and line_count > 0:
            stats_print(stats)
except Exception:
    pass
finally:
    stats_print(stats)
