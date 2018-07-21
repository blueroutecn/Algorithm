

def FlipTree(tree,idx):
    if tree[idx] != 'x':
        return (idx + 1),tree[idx]

    fliplist = {}
    idx = idx + 1
    for i in range(0,4):
        idx,fliped = FlipTree(tree,idx)
        fliplist[i] = fliped

    fliped = fliplist[2] + fliplist[3] + fliplist[0] + fliplist[1]
    fliped = 'x' + fliped
    return idx,fliped


import sys
rl = lambda: sys.stdin.readline()

k = 0
n = int(rl())
while k < n:
    tree = rl().split()
    tree = tree[0]
    idx,fliped = FlipTree(tree,0)
    print(fliped)
    k = k + 1
