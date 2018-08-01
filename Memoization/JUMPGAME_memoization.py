
import os
cwd = os.getcwd()


mapinput = [[0]*100 for x in range(100)]
mapcheck = [[False]*100 for x in range(100)]
mapsize = 0

def runmap(x,y):

    if (x >= mapsize) or (y >= mapsize):
        return False
    if mapinput[x][y] == 0:
        return True

    if mapcheck[x][y]:
        return mapcheck[x][y]

    cmov = mapinput[x][y]
    mapcheck[x][y] = runmap(x + cmov,y) or runmap(x,y + cmov)

    return mapcheck[x][y]



f = open('.\Memoization\JUMPGAME.txt', 'r')
fw = open('.\Memoization\JUMPGAME_answer.txt', 'w')


n = int(f.readline())
for k in range(0,n):


    mapsize = int(f.readline().split()[0])

    for kk in range(0,mapsize):
        tmp = list(map(int,f.readline().split()))
        mapinput[kk][0:len(tmp)] = tmp
        
    isanswer = runmap(0,0)
    if isanswer:
        print('YES')
    else:
        print('NO')



    for i in range(0,mapsize):
        mapcheck[i][0:mapsize] = [False]*mapsize


    k = k + 1

fw.close()
f.close()
