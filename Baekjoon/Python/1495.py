import sys

input = sys.stdin.readline
n, s, m = map(int, input().split())

plist = list(map(int, input().split()))
dp = [[-1 for _ in range(m + 1)] for _ in range(n + 1)]


def go(idx, vol):

    if vol < 0 or vol > m:
        return -2

    if idx == n:
        dp[idx][vol] = vol
        return dp[idx][vol]

    if dp[idx][vol] != -1:
        return dp[idx][vol]


    dp[idx][vol] = max(go(idx + 1, vol + plist[idx]), go(idx + 1, vol - plist[idx]))

    return dp[idx][vol]








result = go(0, s)

if result == -2:
    print(-1)
else:
    print(result)