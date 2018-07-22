

def FlipTree(fw,tree,idx):
    """
    0. input idx: 문제의 시작
    0. tree[idx] != 'x'이면 문제 종료
    0. idx가 tree 길이 넘는지 체크 필요없음
    1. 첫번째 부분 문제의 시작 인덱스를 찾는다.
    2. 시작 인덱스 이후의 문자열을 재귀로 돌린다
    3. 해당 문제의 끝 인덱스를 리턴 받는다
    4. 다음 인덱스에 대해서 재귀를 돌린다
    5. 4번 반복하면 문제가 끝나있다
    """
    """
    * Flip Tree 의 시간 복잡도는?
    """

    if tree[idx] != 'x':
        #fw.write('{}'.format(tree[idx]))
        return (idx + 1),tree[idx]
    #fw.write('{}'.format(tree[idx]))

    fliplist = {}
    idx = idx + 1
    for i in range(0,4):
        idx,fliped = FlipTree(fw,tree,idx)
        fliplist[i] = fliped

    fliped = fliplist[2] + fliplist[3] + fliplist[0] + fliplist[1]
    fliped = 'x' + fliped
    return idx,fliped




f = open('.\Divide_and_Conquer\QUADTREE.txt', 'r')
fw = open('.\Divide_and_Conquer\QUADTREE_answer.txt', 'w')

k = 0
n = int(f.readline())
while k < n:
    tree = f.readline().split()
    tree = tree[0]
    idx,fliped = FlipTree(fw,tree,0)
    fw.write(fliped)
    fw.write('\n')
    k = k + 1
fw.close()
f.close()
