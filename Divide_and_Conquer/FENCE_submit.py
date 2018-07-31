

def checkfence(f0,f1,nfence,fencelen):

    if f0 == f1:
        return fencelen[f0]
    elif f0<f1:
        div = int((f1 + f0)/2)
        m1 = checkfence(f0,div,nfence,fencelen)
        m2 = checkfence(div+1,f1,nfence,fencelen)


        if m1<m2:
            maxarea = m2
        else:
            maxarea = m1

        i = div
        j = div+1

        while i>=f0 and j <= f1:
            mtmp = min(fencelen[i:j+1])*(j-i+1) # i, ... , j-1
            if maxarea<mtmp:
                maxarea = mtmp
            if i-1<f0 or j+1>f1:
                break
            if fencelen[i-1] > fencelen[j+1]:
                i = i - 1
            elif fencelen[i-1] <= fencelen[j+1]:
                j = j + 1

        return maxarea

import sys
k = 0
n = int(sys.stdin.readline())
while k < n:
    nfence = sys.stdin.readline().split()
    fencelen = sys.stdin.readline().split()
    nfence = int(nfence[0])
    fencelen = list(map(int,fencelen))
    maxarea = checkfence(0,nfence-1,nfence,fencelen)
    sys.stdout.write(str(maxarea) + '\n')
    k = k + 1
