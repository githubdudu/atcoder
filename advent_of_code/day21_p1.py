"""
+---+---+---+
| 7 | 8 | 9 |
+---+---+---+
| 4 | 5 | 6 |
+---+---+---+
| 1 | 2 | 3 |
+---+---+---+
    | 0 | A |
    +---+---+
"""
map_pw_to_rb = dict()

pw_pad = [
    ("7", 0, 0),
    ("4", 1, 0),
    ("1", 2, 0),
    ("8", 0, 1),
    ("5", 1, 1),
    ("2", 2, 1),
    ("0", 3, 1),
    ("9", 0, 2),
    ("6", 1, 2),
    ("3", 2, 2),
    ("A", 3, 2)
    ]

def rev_path(ch: str) -> str:
    assert len(ch) == 1
    if ch == "v": return "^"
    elif ch == "^": return "v"
    elif ch == ">": return "<"
    else: return ">"

def create_dict(d: dict, pad: list[tuple[str, int, int]], avoid: tuple[int, int]) -> None:
    for i, first in enumerate(pad):
        for j, second in enumerate(pad):
            if i >= j: continue
            y_dif = second[2] - first[2]
            x_dif = second[1] - first[1]
            xcode, ycode = "", ""
            if y_dif > 0:
                ycode = y_dif * ">"
            else:
                ycode = -y_dif * "<"
            if x_dif > 0:
                xcode = x_dif * "v"
            else:
                xcode = -x_dif * "^"
            if ((first[1], second[2]) not in [avoid, tuple(reversed(avoid))] and (first[2], second[1]) not in [avoid, tuple(reversed(avoid))]):
                if xcode + ycode != ycode + xcode:
                    d[(first[0], second[0])] = [xcode+ycode, ycode+xcode]
                else:
                    d[(first[0], second[0])] = [xcode+ycode]
            else:
                d[(first[0], second[0])] = [ycode+xcode]

            d[(second[0], first[0])] = [ "".join(map(rev_path, reversed(code))) for code in d[(first[0], second[0])]]
            
rb_pad = [
    ("<", 1, 0),
    ("^", 0, 1),
    ("v", 1, 1),
    ("A", 0, 2),
    (">", 1, 2),
]
map_rb_to_rb = dict()

create_dict(map_pw_to_rb, pw_pad, (3,0))
create_dict(map_rb_to_rb, rb_pad, (0,0))

print(map_pw_to_rb.items())
print(map_rb_to_rb.items())

def create_buttons(password: str, script_map: dict) -> list[str]:
    result = []
    def create_buttons_helper(prev: str, password):
        if len(password) == 1:
            result.append(prev)
            return

        if password[0] == password[1]:
            create_buttons_helper(prev+"A", password[1:])
            return

        tokens = script_map[(password[0], password[1])]
        for token in tokens:
            create_buttons_helper(prev+token+"A", password[1:]) 
            
    create_buttons_helper("", "A" + password)
    return result;

ans = 0

for i in range(5):
    password, solution = input().split()
    lvl1_buttons = create_buttons(password, map_pw_to_rb)
    
    print("lvl1_buttons: ")
    print(*lvl1_buttons)

    lvl2_buttons = []
    for pw in lvl1_buttons:
        lvl2_buttons += create_buttons(pw, map_rb_to_rb)

    print("lvl2_buttons: ")
    for output in lvl2_buttons:
        print(len(output), output)
    
    lvl3_buttons = []
    for pw in lvl2_buttons:
        lvl3_buttons += create_buttons(pw, map_rb_to_rb)
    
    print("lvl3_buttons: ")
    for output in lvl3_buttons:
        print(len(output), output)
    
    complexity  = min(map(len, lvl3_buttons)) * int(password[:3])
    print(complexity)
    ans += complexity
print(ans)
