cnt = 0
for i in xrange(1, 9999999):
    if i % 2 == 0 or i % 3 == 0:
        cnt += 1
        if cnt == 2333:
            print i
            break