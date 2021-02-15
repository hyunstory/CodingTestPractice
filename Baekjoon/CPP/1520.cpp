#include <iostream>
#include <cstring>

using namespace std;

int n, m;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int map[501][501];
long long dp[501][501];


long long dfs(int x, int y, int value){
    
    if(x == n - 1 && y == m - 1){
        return 1;
    }  

    long long &ret = dp[x][y];

    if (ret != -1) return ret;

    ret = 0;

    for (int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if (value <= map[nx][ny]) continue;

        ret += dfs(nx, ny, map[nx][ny]);
        
    }

    return ret;


}

void solution(){
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
        }   
    
    long long result = dfs(0, 0, map[0][0]);

    cout << result << '\n';
    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}