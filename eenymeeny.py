rhyme = input().split()
N = int(input())
names = []

for _ in range(N):
    name = input()
    names.append(name)

turn = 0
ind = 0
k = len(rhyme)
team = [[], []]
while N > 0:
    ind = (ind + k - 1) % N
#    print(ind)
    team[turn].append(names[ind])
    names.pop(ind)
    turn = 1 - turn
    N -= 1
    if N != 0:
        ind %= N

print(len(team[0]))
for t in team[0]:
    print(t)
print(len(team[1]))
for t in team[1]:
    print(t)
