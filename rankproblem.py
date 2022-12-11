n, m = map(int, input().split())
t = ['T'+str(x) for x in range(1, n + 1)]

for _ in range(m):
    w, l = input().split()
    ind1 = t.index(w)
    ind2 = t.index(l)
    if ind1 > ind2:
        t.pop(ind2)
        t.insert(ind1, l)

for team in t:
    print(team+' ',end='')
print()
