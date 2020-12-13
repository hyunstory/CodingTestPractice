import sys

dp = [0]*1010

n = int(sys.stdin.readline())

arr = list(map(int, sys.stdin.readline().split()))


dp[1] = 1

for i, v in enumerate(arr, start=1):

    if dp[i] == 0: break

    for j in range(1, v + 1):
        if i + j > 1000: break

        if dp[i + j] > dp[i] + 1 or dp[i + j] == 0:
            dp[i + j] = dp[i] + 1



if dp[n] == 0:
    print(-1)
else: print('{0}'.format(dp[n]-1))