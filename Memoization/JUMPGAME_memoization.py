
def runmap(mapinput,mapsize,mapcheck,x,y):

    """
    0. mapsize 벗어나면 return -1
    1. 끝점 (0) 을 만나면 종료
    2. 종료되지 않았다면, 재귀
       - 오른쪽으로
       - 아래로
    """
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


import os
cwd = os.getcwd()

f = open('.\Memoization\JUMPGAME.txt', 'r')
fw = open('.\Memoization\JUMPGAME_answer.txt', 'w')

k = 0
n = int(f.readline())
while k < n:
    mapsize = int(f.readline().split()[0])
    print(mapsize)
    kk = 0
    mapinput = [[0]*mapsize]*mapsize
    while kk < mapsize:
        tmp = list(map(int,f.readline().split()))
        mapinput[kk] = tmp
        kk = kk + 1
    mapcheck = [[False]*mapsize]*mapsize
    isanswer = runmap(mapinput,mapsize,mapcheck,0,0)
    if isanswer:
        print('YES')
    else:
        print('NO')
    k = k + 1

fw.close()
f.close()
