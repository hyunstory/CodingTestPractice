#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

char map[51][51];
int dist[51][51];

int n, m;
int maxV;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int i, int j){

    memset(dist, 0, sizeof(dist));

    queue<pair<int, int>> q;


    q.push({i,j});
    dist[i][j] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();


        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != 'L') continue;
            if (i == nx && j == ny) continue;

            if (!dist[nx][ny] || dist[ny][nx] > dist[x][y] + 1){ // 여기가 문제였음..최소거리를 구해야 하기 때문에..잘 인지하기.
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }

    }
    int temp = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            temp = max(temp, dist[i][j]);
        }

    return temp;
}

void solution(){



    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
        }


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){

            if (map[i][j] == 'L') {
                int res = bfs(i, j);
                maxV = max(maxV, res);
            }
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