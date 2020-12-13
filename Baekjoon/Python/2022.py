import sys
import math


x, y, c = map(float, sys.stdin.readline().split())

left = 0
right = min(x, y)

for _ in range(10000):
    mid = (left + right) / 2
    d = mid

    h1 = math.sqrt(x*x-d*d)
    h2 = math.sqrt(y*y-d*d)
    h = (h1*h2)/(h1+h2)

    if h > c:
        left = mid
    else:
        right = mid






#result = format(left, '.3f')

#print('%.3f' % left)
print('{:.3f}'.format(left))
