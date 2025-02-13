N, M = [int(x) for x in input().split()]
from heapq import *;
matrix = [];

for i in range(N):
    line = input()
    matrix.append(line);

_from = [[[[] for k in range(4)] for j in range(M)] for i in range(N)];
print(N, M);
dist = [[[-1] * 4 for x in range(M)] for _ in range(N)]

ans = 0; pq = [];
def get_init():
    for i in range(N):
        for j in range(M):
            if matrix[i][j] == 'S':
                return (i,j)
    return (-1,-1)

start = get_init();

heappush(pq, (0, start[0], start[1], 0, start[0], start[1], 0));

DIR = [(0, 1), (-1,0), (0,-1), (1, 0)]
while len(pq):
    cost, x, y, d, from_x, from_y, from_d = heappop(pq);
    if(matrix[x][y] == "E"):
        if(dist[x][y][0] == -1 or cost == dist[x][y][0]):
            ans = cost;
            end = (x, y);
            dist[x][y] = [cost] * 4;
            _from[x][y][d].append((from_x, from_y, from_d));


    elif(matrix[x][y] != "#" and (dist[x][y][d] == -1 or cost == dist[x][y][d])):
        dist[x][y][d] = cost;
        _from[x][y][d].append((from_x, from_y, from_d));
 
    #  move straight
    nd = d;
    v = DIR[nd]
    nx, ny, ncost = x + v[0], y + v[1], cost + 1
    if(matrix[nx][ny] != "#" and( dist[nx][ny][nd] == -1 or ncost == dist[nx][ny][nd])) :
        heappush(pq, (ncost, nx, ny, nd, x, y, d));
    # turn left
    nd = (d + 3) % 4
    v = DIR[nd]
    nx, ny, ncost = x, y, cost + 1000
    if(matrix[nx][ny] != "#" and (dist[nx][ny][nd] == -1 or ncost == dist[nx][ny][nd])):
        heappush(pq,( ncost, nx, ny, nd, x, y, d));

    # turn right
    nd = (d + 1) % 4
    v = DIR[nd]
    nx, ny, ncost = x, y, cost + 1000
    if(matrix[nx][ny] != "#" and (dist[nx][ny][nd] == -1 or ncost == dist[nx][ny][nd])):
        heappush(pq, (ncost, nx, ny, nd, x, y, d));

print(end)
visited = set();
stack = [(end[0], end[1], 0), (end[0], end[1], 1), (end[0], end[1], 2), (end[0], end[1], 3)]
for node in stack:
    visited.add(node);

while(len(stack)):
    x, y, d = stack.pop(0);
    for node in _from[x][y][d]:
        if node not in visited:
            visited.add(node);
            stack.append(node);

tiles = set();
for x, y, d in visited:
    tiles.add((x, y))

print(ans)
print(len(tiles));

for i in range(N):
    for j in range(M):
        if (i, j) in tiles:
            print("O", end="")
        else:
            print(matrix[i][j], end="")
    print()
from bisect import bisect_left, bisect_right
from itertools import permutations