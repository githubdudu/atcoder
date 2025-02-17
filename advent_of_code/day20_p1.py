M, N, T = [int(x) for x in input().split()]

m = []
for i in range(M):
    line = input()
    m.append(line)

def find_start():
    for i in range(M):
        for j in range(N):
            if m[i][j] == "S":
                return (i, j)

path = []
node = find_start();
while True:
    path.append(node)
    if m[node[0]][node[1]] == "E":
        break
    x, y = node
    if x > 0 and m[x-1][y] != "#" and (x-1, y) not in path:
        node = (x-1, y)
    elif x < N - 1 and m[x+1][y] != "#" and (x+1, y) not in path:
        node = (x+1, y)
    elif y > 0 and m[x][y-1] != "#" and (x, y-1) not in path:
        node = (x, y-1)
    elif y < M - 1 and m[x][y+1] != "#" and (x, y+1) not in path:
        node = (x, y+1)
    
print(*path)
print(len(path))

ans = 0
node_map = dict()
for i,p in enumerate(path):
    node_map[p] = i

for i,p in enumerate(path):
    x, y = p
    if (x - 2,y) in node_map and m[x-1][y] == "#":
        dec = node_map[(x-2,y)] - i
        if dec >= T + 2:
            print("saves ", dec-2, " ", x-1, y)
            ans += 1
    if (x + 2,y) in node_map and m[x+1][y] == "#":
        dec = node_map[(x+2,y)] - i
        if dec >= T + 2:
            print("saves ", dec-2, " ", x+1, y)
            ans += 1
    if (x, y - 2) in node_map and m[x][y-1] == "#":
        dec = node_map[(x,y-2)] - i 
        if dec >= T + 2:
            print("saves ", dec-2, " ", x, y-1)
            ans += 1
    if (x, y + 2) in node_map and m[x][y+1] == "#":
        dec = node_map[(x,y+2)] - i
        if dec >= T + 2:
            print("saves ", dec-2, " ", x, y+1)
            ans += 1
print(ans) # 1452