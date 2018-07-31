def checkfence(f0,f1,nfence,fencelen):
    """
    1. 문제를 나눈다
    2. 짝수개로 나누고
    3. 홀수(1개) 될때까지 쪼개고
    4. merge하면서 각자 넓이, 그리고 가운데 양쪽 경계선을 각각 포함하는 넓이 조사
     - 왼쪽,오른쪽 경계 넣고
     - 하나씩 늘려가면서 넓이 체크
    3. merge할때 어떻게 하지
    4. min 값 * width
"""
    if f0 == f1:
        return fencelen[f0]
    elif f0<f1:

        return 0

from os import chdir  # 작업 위치를 바꾸기 위한 헤드
chdir('D:\[3] BMI\[2] northwestern\[6] CNN_pytorch\Algorithm') # 작업 위치 변경
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
