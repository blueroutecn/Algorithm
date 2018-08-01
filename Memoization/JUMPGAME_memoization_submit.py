



import sys

mapinput = [[0]*100 for x in range(100)]
mapcheck = [[False]*100 for x in range(100)]
mapsize = 0


def runmap(x,y):

    if (x >= mapsize) or (y >= mapsize):
        return False
    if x == (mapsize - 1) and y == (mapsize - 1):
        return True

    if mapcheck[x][y]:
        return mapcheck[x][y]

    cmov = mapinput[x][y]
    mapcheck[x][y] = runmap(x + cmov,y) or runmap(x,y + cmov)

    return mapcheck[x][y]



n = int(sys.stdin.readline())

for k in range(0,n):


    mapsize = int(sys.stdin.readline().split()[0])


    for kk in range(0,mapsize):
        tmp = list(map(int,sys.stdin.readline().split()))
        mapinput[kk][0:len(tmp)] = tmp


    isanswer = runmap(0,0)

    if isanswer:
        sys.stdout.write('YES' + '\n')
    else:
        sys.stdout.write('NO' + '\n')



    for i in range(0,mapsize):
        mapcheck[i][0:mapsize] = [False]*mapsize
