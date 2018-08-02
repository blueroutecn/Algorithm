def checkfence(f0,f1,nfence,fencelen):
    if f0 == f1:
        return fencelen[f0]

    div = int((f1 + f0)/2)

    m1 = checkfence(f0,div,nfence,fencelen)
    m2 = checkfence(div+1,f1,nfence,fencelen)

    if m1<m2:
        maxarea = m2
    else:
        maxarea = m1

    i = div
    j = div+1
    height = min(fencelen[i],fencelen[j])
    maxarea = max(maxarea,height*2)
    while i>f0 or j <f1:

        if j<f1 and (i == f0 or fencelen[i-1]<fencelen[j+1]):
            j = j + 1;
            height = min(fencelen[j],height)
        else:
            i = i - 1;
            height = min(fencelen[i],height)
        maxarea = max(maxarea,height*(j - i + 1))

    return maxarea

from os import chdir  # 작업 위치를 바꾸기 위한 헤드
chdir('D:\Algorithm') # 작업 위치 변경
import os
cwd = os.getcwd()

f = open('.\Divide_and_Conquer\FENCE.txt', 'r')
fw = open('.\Divide_and_Conquer\FENCE_answer.txt', 'w')
max([1,2])
k = 0
n = int(f.readline())
while k < n:
    nfence = f.readline().split()
    fencelen = f.readline().split()
    nfence = int(nfence[0])
    fencelen = list(map(int,fencelen))
    maxarea = checkfence(0,nfence-1,nfence,fencelen)
    print('maxarea : {}'.format(maxarea))
    k = k + 1
fw.close()
f.close()
