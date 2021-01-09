#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
long long map[501][501];
long long dp[501][501];

//int dist[501][501];

long long maxV = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

long long dfs(int x, int y){

    if (dp[x][y]) return dp[x][y];

    dp[x][y] = 1;

    for (int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n ||(map[x][y] >= map[nx][ny])) continue;
        
        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);

    }

    return dp[x][y];
}
void solution(){

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
        }

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            //memset(dist, 0, sizeof(dist));
            maxV = max(maxV, dfs(i, j));
            //cout << maxV << '\n';
        }

    cout << maxV << '\n';
    
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}