import sys


n, m = map(int, sys.stdin.readline().split())

trees = list(map(int, sys.stdin.readline().split()))


left = 1
right = max(trees)

while left <= right:

    mid = (left + right) // 2

    log = 0

    for i in trees:
        if (i > mid):
            log += i - mid

    if log >= m:
        left = mid + 1

    else:
        right = mid - 1



print(right)


