N, M = [int(x) for x in input().split()]
from heapq import *;
matrix = [];
for i in range(N):
    line = input()
    matrix.append(list(line));
print(N, M);
dist = [[-1 for x in range(M)] for _ in range(N)]
ans = 0
pq = [];
def get_init():
    for i in range(N):
        for j in range(M):
            if matrix[i][j] == 'S':
                return (i,j)
    return (-1,-1)

start = get_init();

heappush(pq, (0, start[0], start[1], 0));

DIR = [(0, 1), (-1,0), (0,-1), (1, 0)]
while len(pq):
    cost, x, y, d = heappop(pq);
    if(matrix[x][y] == "E"):
        print(cost);
        exit();
    elif(matrix[x][y] == "#"):
        continue;
    else:
        matrix[x][y] = "#";
    
    for i in range(4):
        _d = (d+i) % 4;
        v = DIR[_d]
        if(matrix[x+v[0]][y+v[1]] != "#"):
            heappush(pq, (cost + 1 + (1 if i==3 else i) *1000, x+v[0], y+v[1], _d));


print(ans)
from bisect import bisect_left, bisect_right
from itertools import permutations