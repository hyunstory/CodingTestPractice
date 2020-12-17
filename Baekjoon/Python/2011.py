import sys






def dfs(n, lens, idx):

    if (idx >= lens):
        return 1




    s1 = n[idx:idx+1]
    s2 = n[idx:idx+2]

    t1 = int(s1)
    t2 = int(s2)

    sum1 = 0
    sum2 = 0

    if t1 >= 1 and t1 <= 26:
        if dp[idx][t1] != -1:
            return dp[idx][t1]

        dp[idx][t1] = 0    
        dp[idx][t1] = dp[idx][t1] + dfs(n, lens, idx +1)
        sum1 = dp[idx][t1]


    elif t2 >= 1 and t2 <= 26:
        if dp[idx][t2] != -1:
            return dp[idx][t2]
        dp[idx][t2] = 0
        if idx + 2 <= len:
            dp[idx][t2] = dp[idx][t2] + dfs(n, lens, idx +2)
            sum2 = dp[idx][t2]

            return sum1 + sum2









if __name__ == '__main__': 

    dp = [[-1]*27 for _ in range(5001)]
    t = int(sys.stdin.readline())
    n = str(t) 
    
    lens = len(n)
    result = dfs(n, lens, 0)


    print(result)

