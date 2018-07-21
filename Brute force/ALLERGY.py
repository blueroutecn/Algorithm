
def checkfood(fw,frdlist,cklist,foodidx,nfood,nfriend,fdhistory):
    """
    0. cklist를 sum 해서 모든 친구 값이 1 이상이면 종료
    1. ref = 9999 초기화
    2. 0번음식을 넣을지 말지 결정
    3. 리턴되는 값은 cnt
    """



    if foodidx == nfood:
        flag = True
        for f in frdlist:
            if f==0:
                flag = False
        if flag:
            fw.write('final frdlist: {} \n'.format(frdlist))
            #fw.write('final fdhistory: {} \n'.format(fdhistory))
            return 0
        else:
            return 99999

    ret = 99999

    for cnt in range(0,2):
        if cnt == 1:
            for j in range(0,nfriend):
                if cklist[j][foodidx] == 1:
                    frdlist[j] = frdlist[j] + 1
            fw.write('add food: {} \n'.format(foodidx))
            fw.write('frdlist new: {} \n'.format(frdlist))

        tmp = checkfood(fw,frdlist,cklist,foodidx+1,nfood,nfriend,fdhistory)

        if cnt == 1:
            for j in range(0,nfriend):
                if cklist[j][foodidx] == 1:
                    frdlist[j] = frdlist[j] - 1
            fw.write('frdlist recovered: {} \n'.format(frdlist))
            fw.write('remove food: {} \n'.format(foodidx))
        fw.write('current foodidx: {}, tmp: {}, current ret: {}, current cnt: {} \n'.format(foodidx,tmp,ret,cnt))
        ret = min(ret,tmp+cnt)
        fw.write('changed ret: {} \n'.format(ret))



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
    ret = checkfood(fw,frdlist,cklist,0,nfood,nfriend,fdhistory)
    print(ret)
    idx = idx + 1
fw.close()
f.close()
