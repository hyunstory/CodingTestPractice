n, m = map(int, input().split())

a = [[0]*(m+1)] + [[0]+list(map(int, input().split())) for _ in range(n)]
d = [[0]*(m+1) for _ in range(n+1)]


for i in range(1, n+1):
    for j in range(1, m+1):
        d[i][j] = max(d[i-1][j], d[i][j-1], d[i-1][j-1]) + a[i][j]


print(d[n][m])