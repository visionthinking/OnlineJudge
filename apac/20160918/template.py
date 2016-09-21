# coding=utf8

import sys
import numpy as np

def solve(kase):
    n, = scanf("%d")
    a = map(int, raw_input().split())
    a[0] = -a[0]
    print "Case #%d: %.12f" % (kase, np.irr(a))

if __name__ == '__main__':
    if len(sys.argv) >= 2:
        sys.stdin = open(sys.argv[1], 'r')
    if len(sys.argv) >= 3:
        sys.stdout = open(sys.argv[2], 'w')
    
    from scanf import *

    kase, = scanf("%d\n")
    for i in xrange(1, kase+1):
        solve(i)