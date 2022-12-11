year = int(input())

def isLeap(x):
    if x % 400 == 0:
        return True
    if x % 100 == 0:
        return False
    if x % 4 == 0:
        return True
    return False

y = 2000
m = 1
d = 1

day = 6
month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for i in range(2000, year):
    for j in range(12):
        if j == 1:
            if isLeap(y):
                day += 29
            else:
                day += 28
        else:
            day += month[j]
        m = (m + 1) % 12 + 1
    y += 1


# in the year 1 1

for j in range(4):
    if j == 1 and isLeap(y):
        day += 29
    else:
        day += month[j]
    m = (m + 1) % 12 + 1

may = day
cnt = 0
l = -1
for i in range(30):
    if may % 7 == 0:
        cnt += 1
    if cnt == 2:
        l = may
    may += 1

day += month[4]

cnt = 0
june = day
for i in range(29):
    if june % 7 == 0:
        cnt += 1
    if cnt == 3:
        r = june
    june += 1
ans = (r - l) // 7

if ans == 6:
    print('6 weeks')
else:
    print('5 weeks')
