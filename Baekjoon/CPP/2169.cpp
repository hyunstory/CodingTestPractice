#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;

const int MAX = 1001;
const int MINF = -987654321;

int map[MAX][MAX];
long long dp[MAX][MAX][3]; // 0, 1, 2 (0은 아래, 1은 오른쪽, 2는 왼쪽)
bool check[MAX][MAX];


int dx[] = {1, 0, 0};
int dy[] = {0, 1, -1};

int maxV;

long long dfs(int x, int y, int dir){
    if (x == n && y == m){
        
        return map[x][y];
    }

    long long &ret = dp[x][y][dir];
    if (ret != -1) return ret;
    ret = MINF;
    check[x][y] = true;

    //long long ret = 0;

    for (int k = 0; k < 3; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 1 || nx > n || ny < 1 || ny > m || check[nx][ny]) continue;

        //check[nx][ny] = true;

        ret = max(ret, dfs(nx, ny, k) + map[x][y]);
    }
    check[x][y] = false;


    return ret;
    
    
    
}

void solution(){

    
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> map[i][j];
        }

    long long result = dfs(1, 1, 0);

    cout << result << '\n';
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}