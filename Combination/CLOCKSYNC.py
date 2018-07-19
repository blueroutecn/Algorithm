
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
def moveclock(T,bt):
    for b in bt:
        T[b] = T[b] + 3
        T[b] = T[b] % 12

f = open('.\combination\CLOCKSYNC.txt', 'r')
fw = open('.\combination\CLOCKSYNC_answer.txt', 'w')
idx = 0
n = int(f.readline())
while idx < n:
    T = f.readline().split()
    T = list(map(int,T))
    moveclock(T.button[0])
    print(T)
    fw.write('time {}'.format(T))
    idx = idx + 1
fw.close()
f.close()
