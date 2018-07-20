
def moveclock(T,bt):
    for b in bt:
        T[b] = T[b] + 3
        if T[b] == 15:
            T[b] = 3
        elif T[b] == 0:
            T[b] = 12

def synchclock(T,current,button):
    """
    1. 현재 버튼 누른다
    2. 0,1,2,3 번 눌러본다
    3. 각각에 대해 재귀 돌린다
    4. 모든 버튼을 시도했을 때 솔루션을 못만들면 inf return
    5. 리턴된 경우의 수들을 현재 버튼 누른 횟수에 더한후 ret 과 비교한다
    6. 솔루션이 없으면 모두 inf 라서 inf return
    7. 솔루션이 있으면, inf 는 저장 안되고
    """
    if current == 10:
        flag = True
        for t in T:
            if t != 12:
                flag = False

        if flag:
            return 0
        else:
            return math.inf

    ret = math.inf
    for cnt in range(0,4):
        ret = min(ret, cnt + synchclock(T,current+1,button))
        moveclock(T,button[current])

    return ret

f = open('.\combination\CLOCKSYNC.txt', 'r')
fw = open('.\combination\CLOCKSYNC_answer.txt', 'w')
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
n = int(f.readline())
while idx < n:
    T = f.readline().split()
    T = list(map(int,T))
    ret = synchclock(T,0,button)
    if ret == math.inf:
        fw.write('{} \n'.format(-1))
    else:
        fw.write('{} \n'.format(ret))
    idx = idx + 1
fw.close()
f.close()
