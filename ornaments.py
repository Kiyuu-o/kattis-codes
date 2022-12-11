'''
Time: 10/30/2022
Author: Kexuan Miao
'''
from math import pi, sqrt, acos

while True:
    r, h, s = map(int, input().split())
    if r == h == s == 0:
        break
    angle = acos(r/h)
    res = (2*pi - 2*angle) * r + 2 * sqrt(h**2 - r**2)
    print('{0:.2f}'.format(res*(1+s/100)))
