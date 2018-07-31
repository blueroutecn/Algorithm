
def runmap(mapinput,mapsize,x,y):

    if not (x >= 0 and x < mapsize and y >= 0 and y < mapsize):
        return -1
    if mapinput[x][y] == 0:
        return 1

    cmov = mapinput[x][y]
    a = runmap(mapinput,mapsize,x + cmov,y)
    b = runmap(mapinput,mapsize,x,y + cmov)
    if a == 1 or b == 1:
        return 1
    else:
        return -1

import sys

k = 0
n = int(sys.stdin.readline())
while k < n:
    mapsize = int(sys.stdin.readline().split()[0])

    kk = 0
    mapinput = [mapsize]*mapsize
    while kk < mapsize:
        tmp = list(map(int,sys.stdin.readline().split()))
        mapinput[kk] = tmp
        kk = kk + 1
    a = runmap(mapinput,mapsize,0,0)
    if a == 1:
        print('YES')
    elif a == -1:
        print('NO')
    k = k + 1
