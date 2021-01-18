#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

int n, m;

int map[51][51];
vector<pair<int,int>> vir;
int picked[11];
bool check[11];
int backup[51][51];

const int simulMAX = 2500;

int minV = __INT_MAX__;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void simul(){

    deque<pair<int, int>> q1;
    deque<pair<int, int>> q2;

    for (int i = 0; i < m; i++){
        int x = vir[picked[i]].first;
        int y = vir[picked[i]].second;

        map[x][y] = 2;
        q1.push_back({x,y});

    }
    int time = 0;  
    bool complete = true;

    while(1){
        time++;

        while(!q1.empty()){
            int x = q1.front().first;
            int y = q1.front().second;
            q1.pop_front();

            for (int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] != 0) continue;

                map[nx][ny] = 2;
                q2.push_back({nx, ny});
            }

        }
        q1 = q2;

        if (q2.empty()) {
            break;
        }

        q2.clear();
        

        
        
    }

    for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                if (map[i][j] == 0) {
                    complete = false;
                    break;
                }
               
            }
    if (!complete) time = simulMAX;
    minV = min(minV, time-1);


}
void dfs(int depth, int start, int vir_size){
    if (depth == m){
        simul();
        memcpy(map, backup, sizeof(backup));
        return;
    }

    for (int i = start; i < vir_size; i++){
        if (check[i]) continue;
        check[i] = true;
        picked[depth] = i;
        dfs(depth + 1, i + 1, vir_size);
        check[i] = false;
    }
}

void solution(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin >> map[i][j];

            if (map[i][j] == 2){
                vir.push_back({i, j});
                map[i][j] = 0;
            }
        }
    int vir_size = vir.size();
    memcpy(backup, map, sizeof(map));

    dfs(0, 0, vir_size);

    if (minV == simulMAX - 1) cout << -1 << '\n';
    else cout << minV << '\n';
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}