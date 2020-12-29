#include <iostream>
#include <queue>
#include <cstring>

using namespace std;


int map[101][101];
int n, m;
int hours;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool check[101][101];

bool isBorder(int x, int y){

    for (int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 0) return true;
    }


    return false;
}

void bfs(int i, int j){

    memset(check, false, sizeof(check));
    
    
    queue<pair<int, int>> q;

    check[i][j] = true;
    q.push({i, j});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();


        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny]) continue;

            if (map[nx][ny] == 1){
                map[nx][ny] = 2;
            }
            else if (map[nx][ny] == 0){
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void solution(){

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> map[i][j];

    int prev = 0;
    int remain = 0;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if (map[i][j] == 1) remain++;
        }

    while(true){

        
        prev = remain;
        remain = 0;
        
        // 테두리 구하기 -> c로 표시하기 (1인 개수 카운트)
        bfs(0, 0);

        // 테두리 없애기
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (map[i][j] == 2) map[i][j] = 0;
                else if (map[i][j] == 1) remain++;
            }

         // + 1
        hours++;

        // 남은 개수 0인지 확인
        if (remain == 0){
            cout << hours << '\n' << prev << '\n';
            break;
        }


       

    }

    
}
int main(){

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);

    solution();

    return 0;
}