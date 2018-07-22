def checkfence(nfence,fencelen):





f = open('.\Divide_and_Conquer\FENCE.txt', 'r')
fw = open('.\Divide_and_Conquer\FENCE_answer.txt', 'w')

k = 0
n = int(f.readline())
while k < n:
    nfence = f.readline().split()
    fencelen = f.readline().split()

    k = k + 1
fw.close()
f.close()
