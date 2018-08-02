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
        height = min(fencelen[i],fencelen[j])
        while i>=f0 or j <= f1:
            if i>=f0 and j<=f1:
                if fencelen[i] < fencelen[j]:
                    height = min(fencelen[j],height)
                    maxarea = max(maxarea,height*(j - i))
                    j = j + 1
                else:
                    height = min(fencelen[i],height)
                    maxarea = max(maxarea,height*(j - i))
                    i = i - 1
            elif j>f1:
                height = min(fencelen[i],height)
                maxarea = max(maxarea,height*(j - i))
                i = i - 1
            elif i<f0:
                height = min(fencelen[j],height)
                maxarea = max(maxarea,height*(j - i))
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
