from math import log
a, b, c = map(int, input().split())
EPS = 1e-9
if b == 1:
    if c == 1:
        print("What an excellent example!")
    else:
        print("Oh look, a squirrel!")
elif log(c, b) + 1 == c:
    print("What an excellent example!")
else:
    print("Oh look, a squirrel!")

