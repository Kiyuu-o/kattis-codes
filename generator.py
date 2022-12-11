import random

maxn = 200000
f = open("input.txt", "w")
arr = [maxn - i for i in range(maxn)]
f.write(str(maxn) + "\n")
f.write(' '.join(map(str, arr)) + "\n")
f.write(str(maxn // 2))
f.close()
