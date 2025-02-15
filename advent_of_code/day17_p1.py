


A, B, C = [int(x) for x in input().split()]
program = [int(x) for x in input().split(",")]

def getCombo(oper):
    if(oper == 4):
        return A;
    elif(oper == 5): 
        return B
    elif(oper == 6):
        return C
    else:
        return oper

i = 0;    
while i < len(program):
    opcode, op_liter = program[i], program[i + 1] 
    op_combo = getCombo(op_liter)
    if(opcode == 0):
        A = int(A / (2 ** op_combo)) 
    elif opcode == 1:
        B = B ^ op_liter
    elif opcode == 2:
        B = op_combo % 8
    elif opcode == 3:
        if A != 0:
            i = op_liter;
            continue 
    elif opcode == 4:
        B = B ^ C
    elif opcode == 5:
        print(op_combo % 8, end=",")
    elif opcode == 6:
        B = int(A / (2 ** op_combo)) 
    else:
        C = int(A / (2 ** op_combo)) 
    i += 2;
ans = 0
print("ABC:", A, B, C, ans)
from bisect import bisect_left, bisect_right
from itertools import permutations
from math import ceil, inf
