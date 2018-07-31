
def runmap(mapinput,mapsize,mapcheck,x,y):

    if not (x >= 0 and x < mapsize and y >= 0 and y < mapsize):
        return False
    if mapinput[x][y] == 0:
        return True

    if mapcheck[x][y]:
        return mapcheck[x][y]

    cmov = mapinput[x][y]
    mapcheck[x][y] = runmap(mapinput,mapsize,mapcheck,x + cmov,y) or \
    runmap(mapinput,mapsize,mapcheck,x,y + cmov)

    return mapcheck[x][y]



import sys

k = 0
n = int(sys.stdin.readline())
while k < n:
    mapsize = int(sys.stdin.readline().split()[0])
    kk = 0
    mapinput = [[0]*mapsize]*mapsize
    while kk < mapsize:
        tmp = list(map(int,sys.stdin.readline().split()))
        mapinput[kk] = tmp
        kk = kk + 1
    mapcheck = [[False]*mapsize]*mapsize
    isanswer = runmap(mapinput,mapsize,mapcheck,0,0)
    if isanswer:
        print('YES')
    else:
        print('NO')
    k = k + 1
