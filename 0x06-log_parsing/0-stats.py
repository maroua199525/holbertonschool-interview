#!/usr/bin/python3
""" Parses Logs """
import sys


status = {'200': 0, '301': 0, '400': 0, '401': 0,
          '403': 0, '404': 0, '405': 0, '500': 0}
codes = ['200', '301', '400', '401', '403', '404', '405', '500']
count = 0
filesize = 0
try:
    for line in sys.stdin:
        count += 1
        n_line = line.split(' ')
        if len(n_line) > 2:
            filesize += int(n_line[-1])
            if n_line[-2] in status:
                status[n_line[-2]] += 1
        if count % 10 == 0:
            print("File size: {}".format(filesize))
            for code in codes:
                if status[code]:
                    print("{}: {}".format(code, status[code]))
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(filesize))
    for code in codes:
        if status[code]:
            print("{}: {}".format(code, status[code]))
