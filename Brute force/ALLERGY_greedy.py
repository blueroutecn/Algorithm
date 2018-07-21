
import operator

def checkfood(frdlist,cklist,nfood,nfriend):

    flag = True
    for f in frdlist:
        if f==0:
            flag = False
    if flag:
        return 0

    bestfood = [0]*nfood
    for i in range(0,nfood):
        for j in range(0,nfriend):
            if cklist[j][i] == 1 and frdlist[j] == 0:
                bestfood[i] = bestfood[i] + 1

    max_index, max_value = max(enumerate(bestfood), key=operator.itemgetter(1))
    selectfood = [idx for idx,item in enumerate(bestfood) if item == max_value]

    ret = 9999
    for j in range(0,len(selectfood)):
        foodidx = selectfood[j]
        for i in range(0,nfriend):
            frdlist[i] = frdlist[i] + cklist[i][foodidx]

        tmp = 1 + checkfood(frdlist,cklist,nfood,nfriend)
        ret = min(ret,tmp)

        for i in range(0,nfriend):
            frdlist[i] = frdlist[i] - cklist[i][foodidx]
    return ret




f = open('.\Brute force\ALLERGY.txt', 'r')
fw = open('.\Brute force\ALLERGY_answer.txt', 'w')

idx = 0
n = int(f.readline())
while idx < n:
    nfriend,nfood = map(int,f.readline().split())
    name = f.readline().split()
    count = {}
    for nm in name:
        count[nm] = 0
    cklist = [[0]*nfood for i in range(0,nfriend)]

    fw.write('cklist: \n')
    for i in range(0,nfood):
        tmp = f.readline().split()
        tmp = tmp[1:]
        for j in tmp:
            pos = [idx for idx,item in enumerate(name) if item == j]
            cklist[pos[0]][i] = cklist[pos[0]][i] + 1
    for i in range(0,nfriend):
        fw.write('{} \n'.format(cklist[i]))
    print(cklist)
#    print(cklist[0:][5])
    frdlist = [0]*nfriend
    fdhistory = []
    ret = checkfood(frdlist,cklist,nfood,nfriend)
    print(ret)
    idx = idx + 1
fw.close()
f.close()
