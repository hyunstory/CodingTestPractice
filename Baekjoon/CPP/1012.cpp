#include <iostream>
#include <cstring>

using namespace std;
int n, m;
int map[51][51];
int check[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y){

    for (int i = 0; i < 4; i++){

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if (!check[nx][ny] && map[nx][ny] == 1){
            check[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

void solution(){

    int t;
    

    cin >> t;

    while(t--){
        
        memset(map, 0, sizeof(map));
        memset(check, 0, sizeof(check));

        int k;
        int result = 0;

        cin >> m >> n >> k;

        for (int i = 0; i < k; i++){
            int a, b;
            cin >> b >> a;

            map[a][b] = 1;

        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (map[i][j] == 0 || check[i][j]) continue;

                check[i][j] = true;
                dfs(i, j);
                result++;
            }
        }

        cout << result << '\n';
        


    }

}
int main(){

    solution();

    return 0;
}