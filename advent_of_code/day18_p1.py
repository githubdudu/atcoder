N, M, C = [int(x) for x in input().split()]

m = []
for i in range(N):
    m.append(["."] * M)
visited_record = [[False for j in range(M)] for i in range(N)]

for i in range(C):
    x, y = [int(x) for x in input().split()]
    m[x][y] = "#"
def neighbor(node):
    nei = []
    x, y = node
    v = [(1,0),(0,1),(-1,0),(0,-1)]
    for vv in v:
        xv, yv = x + vv[0], y + vv[1]
        if xv >= 0 and yv >= 0 and xv < N and yv < M and m[xv][yv] == ".":
            nei.append((xv, yv))
    return nei
    
def visited(node):
    return visited_record[node[0]][node[1]] 

def set_visited(node):
    visited_record[node[0]][node[1]] = True

def bfs():
    stack = [(0, 0)] 
    set_visited((0, 0))
    step = 1
    while len(stack):
        new_stack = []
        for st in stack:
            for node in neighbor(st):
                if not visited(node):
                    if node == (N-1, M-1):
                        print(step)
                        return;
                    new_stack.append(node)
                    set_visited(node)
        stack = new_stack
        step += 1
bfs() # ans = 302