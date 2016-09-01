# coding=utf8

import sys
import numpy as np

def fast_pow(x, y):
    r = 1
    base = x
    while y != 0:
        if y & 1 != 0:
            r = r * base % 1000000007L
        base = base * base % 1000000007L
        y /= 2
    return r

def solve(kase):
    a, b, n, k = scanf("%d %d %d %d")
    cnt = 0
    for i in xrange(1, n+1):
        for j in xrange(1, n+1):
            if i != j:
                if (fast_pow(i, a) + fast_pow(j, b)) % k == 0:
                    cnt += 1
                    cnt = cnt % 1000000007L
    print "Case #%d: %d" % (kase, cnt % 1000000007L)

if __name__ == '__main__':
    if len(sys.argv) >= 2:
        sys.stdin = open(sys.argv[1], 'r')
    if len(sys.argv) >= 3:
        sys.stdout = open(sys.argv[2], 'w')
    
    from scanf import *

    kase, = scanf("%d\n")
    for i in xrange(1, kase+1):
        solve(i)
