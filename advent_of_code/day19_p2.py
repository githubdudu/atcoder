token = [x for x in input().split(", ")]
N = 400
ans = 0

class Node():
    def __init__(self):
        self.end_flag = False
        self.children = []

    def init_children(self):
        self.children = [Node(), Node(), Node(), Node(), Node()]
    
    def get_children(self):
        return self.children
    
    def has_children(self):
        return len(self.children) != 0
    
    def stoi(self, s):
        if s == "w": return 0
        elif s == "u": return 1
        elif s == "b": return 2
        elif s == "r": return 3
        else: return 4
    
    def get_one_child(self, ch):
        return self.children[self.stoi(ch)]
    
    def isEnd(self):
        return self.end_flag
    def setEndTrue(self):
        self.end_flag = True

    def __str__(self):
        string = str(self.end_flag) + " "
        if self.has_children():
            for i, ele in enumerate(self.get_children()):
                string += str(i) + "(" + str(ele) + ")"
        return string
class Tries():
    def __init__(self):
        self.root = Node()

    def add(self, pattern):
        container = self.root
        while True:
            if len(pattern) == 0:
                container.setEndTrue()
                return
            if not container.has_children():
                container.init_children()

            container = container.get_one_child(pattern[0])
            pattern = pattern[1:]

    def __str__(self):
        return str(self.root)

tree = Tries()
def search(pattern, idx) -> list[int]:
    ans = []
    container = tree.root
    while idx < len(pattern):
        if not container.has_children():
            break;
        container = container.get_one_child(pattern[idx])
        if container.isEnd():
            ans.append(idx)
        idx += 1
    return ans;



def dp(pattern):
    memo = [0] * (len(pattern) + 1)
    memo[-1] = 1
    for i in reversed(range(len(pattern))):
        ans = search(pattern, i)
        
        for a in ans:
            memo[i] += memo[a + 1]
    return memo[0]

for t in token:
    tree.add(t)
print(tree)
for i in range(N):
    puzzle = input()
    print("puzzle ", puzzle)
    ans += dp(puzzle)
print(ans)