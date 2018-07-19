

def moveclock(T,bt):
    for b in bt:
        T[b] = T[b] + 3
        if T[b] == 15:
            T[b] = 3
        elif T[b] == 0:
            T[b] = 12

def synchclock(T,current,button):
    if current == 10:
        flag = True
        for t in T:
            if t != 12:
                flag = False
        if flag:
            return 0
        else:
            return 9999999999

    ret = 9999999999
    for cnt in range(0,4):
        ret = min(ret, cnt + synchclock(T,current+1,button))
        moveclock(T,button[current])

    return ret


import sys
rl = lambda: sys.stdin.readline()

button = {}
button[0] = [0,1,2]
button[1] = [3,7,9,11]
button[2] = [4,10,14,15]
button[3] = [0,4,5,6,7]
button[4] = [6, 7, 8, 10, 12]
button[5] = [0, 2, 14, 15]
button[6] = [3, 14, 15]
button[7] = [4, 5, 7, 14, 15]
button[8] = [1, 2, 3, 4, 5]
button[9] = [3, 4, 5, 9, 13]


idx = 0
n = int(rl())
while idx < n:
    T = rl().split()
    T = list(map(int,T))
    Ntry = [0]*10
    cnt = 0
    ret = synchclock(T,0,button)
    if ret == 9999999999:
        print(-1)
    else:
        print(ret)
    idx = idx + 1
