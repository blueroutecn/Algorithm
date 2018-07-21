
def checkfood(frdlist,cklist,foodidx,nfood,nfriend,fdhistory):
    if foodidx == nfood:
        flag = True
        for f in frdlist:
            if f==0:
                flag = False
        if flag:
            return 0
        else:
            return 99999

    ret = 99999

    for cnt in range(0,2):
        if cnt == 1:
            for j in range(0,nfriend):
                if cklist[j][foodidx] == 1:
                    frdlist[j] = frdlist[j] + 1

        tmp = checkfood(frdlist,cklist,foodidx+1,nfood,nfriend,fdhistory)

        if cnt == 1:
            for j in range(0,nfriend):
                if cklist[j][foodidx] == 1:
                    frdlist[j] = frdlist[j] - 1

        ret = min(ret,tmp+cnt)
    return ret

import sys
rl = lambda: sys.stdin.readline()

idx = 0
n = int(rl())
while idx < n:
    nfriend,nfood = map(int,rl().split())
    name = rl().split()
    count = {}
    for nm in name:
        count[nm] = 0
    cklist = [[0]*nfood for i in range(0,nfriend)]

    for i in range(0,nfood):
        tmp = rl().split()
        tmp = tmp[1:]
        for j in tmp:
            pos = [idx for idx,item in enumerate(name) if item == j]
            cklist[pos[0]][i] = cklist[pos[0]][i] + 1
    #print(cklist)
    frdlist = [0]*nfriend
    fdhistory = []
    ret = checkfood(frdlist,cklist,0,nfood,nfriend,fdhistory)
    print(ret)
    idx = idx + 1
