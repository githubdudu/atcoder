

def getC(a, b):
    return int(a / (2 ** b));
def checkB(a, output):
    b = a % 8
    b = b ^ 5
    c = getC(a, b)
    b = b ^ c ^ 6
    return b % 8 == output

def revA(a):
    return a * 8;

answers = [0]
program = [2,4,1,5,7,5,0,3,4,1,1,6,5,5,3,0]
for num in reversed(program):
    last_answers = []
    for a in answers:
        for i in range(a * 8, a * 8 + 8):
            if (checkB(i, num)):
                last_answers.append(i);
    answers = last_answers
print(answers)

from bisect import bisect_left, bisect_right
from itertools import permutations
from math import ceil, inf
