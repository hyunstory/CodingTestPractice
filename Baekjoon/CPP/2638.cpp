#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
bool check[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
void bfs(int i, int j){

    memset(check, false, sizeof(check));

    check[i][j] = true;
    queue<pair<int, int>> q;

    q.push({i,j});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny]) continue;

            if (map[nx][ny] == 0){
                check[nx][ny] = true;
                q.push({nx, ny});
            }

            else if (map[nx][ny] == 1 || map[nx][ny] == 2){
                map[nx][ny]++;

            }


        }
    }

}
void solution(){

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> map[i][j];

    int hours = 0;

    
    while(true){
    
        bfs(0, 0);

        int count = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if(map[i][j] ==1 ){
                    count++;
                }
                else if(map[i][j] == 2){
                    map[i][j] = 1;
                    count++;
                }
                else if(map[i][j] == 3){
                    map[i][j] = 0;
                }
            }

        hours++;

        if (count == 0){
            cout << hours << '\n';
            break;
        }
        


    }


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}