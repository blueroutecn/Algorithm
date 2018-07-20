
def checkfood(fdlist,cklist,foodidx,nfood,nfriend):
    """
    0. cklist를 sum 해서 모든 친구 값이 1 이상이면 종료
    1. ref = 9999 초기화
    2. 0번음식을 넣을지 말지 결정
    3. 리턴되는 값은 cnt
    """
    if foodidx == nfood:
        return 99999

    flag = True
    for f in fdlist:
        if f==0:
            flag = False
    if flag:
        return



    ret = 99999
    cnt = 0
    for i in range(0,2):
        tmp = checkfood(fdlist,cklist,foodidx+1,nfood,nfriend)
        ret = min(ret,tmp+cnt)
        for j in range(0,nfriend):
            if cklist[j][foodidx] == 1:
                fdlist[j] = fdlist[j] + 1
        cnt = cnt + 1
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

    for i in range(0,nfood):
        tmp = f.readline().split()
        tmp = tmp[1:]
        for j in tmp:
            pos = [idx for idx,item in enumerate(name) if item == j]
            cklist[pos[0]][i] = cklist[pos[0]][i] + 1
    #print(cklist)
#    print(cklist[0:][5])
    fdlist = [0]*nfriend
    ret = checkfood(fdlist,cklist,0,nfood,nfriend)
    print(ret)
    idx = idx + 1
fw.close()
f.close()
