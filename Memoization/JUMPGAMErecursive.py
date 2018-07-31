
def runmap(mapinput,mapsize,x,y):

    """
    0. mapsize 벗어나면 return -1
    1. 끝점 (0) 을 만나면 종료
    2. 종료되지 않았다면, 재귀
       - 오른쪽으로
       - 아래로
    """
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
    mapinput = [mapsize]*mapsize
    while kk < mapsize:
        tmp = list(map(int,f.readline().split()))
        mapinput[kk] = tmp
        kk = kk + 1
    a = runmap(mapinput,mapsize,0,0)
    if a == 1:
        print('YES')
    elif a == -1:
        print('NO')
    k = k + 1

fw.close()
f.close()
