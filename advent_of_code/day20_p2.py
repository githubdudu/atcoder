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

vec = [(0,1),(0,-1),(1,0),(-1,0)]
visited_start = set()

def bfs(sx, sy, start_cost):
    ans = 0
    path_cost = 1
    stack = [(sx, sy)]
    visited = set()
    visited.add((sx, sy))
    while len(stack):
        new_stack = []
        path_cost += 1
        if path_cost > 20:
            break;
        for x, y in stack:
            for vx, vy in vec:
                nx = x + vx
                ny = y + vy
                if nx >= 0 and ny >= 0 and nx < M and ny < N and (nx,ny) not in visited:
                    if m[nx][ny] == "#":
                        new_stack.append((nx, ny))
                        visited.add((nx, ny))
                    else:
                        target_cost = node_map[(nx,ny)]
                        if target_cost - start_cost - path_cost >= 76:
                            print("saves ",target_cost, start_cost, path_cost, target_cost - start_cost - path_cost, " ", nx, ny)
                            ans += 1
                        visited.add((nx, ny))
                        new_stack.append((nx, ny))
                       
        stack = new_stack
    return ans;

for i, (x1, y1) in enumerate(path):
    # x, y = p
    # for vx, vy in vec:
    #     nx = x + vx
    #     ny = y + vy
    #     if nx >= 0 and ny >= 0 and nx < M and ny < N and m[nx][ny] == "#"\
    #      and (nx, ny) not in visited_start:
    #         ans += bfs(nx, ny, i)
    #         visited_start.add((nx, ny))
    for j, (x2, y2) in enumerate(path):
        if j <= i: continue
        short_path = abs(x2 - x1) + abs(y2 - y1)
        if short_path <= 20 and j - i - short_path >= T :
            ans += 1
            # print(x1,y1, x2,y2, short_path)
    
print(ans) # 1452