#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int map[5][5];

bool check[5][5];

int maxV;

int dx[] = {-1, 1, 0, 1};
int dy[] = {0, 0, -1, 1};


void go(int x, int y, const int goal, int cnt){

    if (map[x][y] != goal) return;

    for (int k = 0; k < 4; k++){
        
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx > 4 || ny < 0 || ny > 4 || check[nx][ny]) continue;

        check[nx][ny] = true;

        go(nx, ny, goal, cnt + 1);

    }

    maxV = max(maxV, cnt);


}

void solution(){

    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int goal = map[i][j];
            memset(check, false, sizeof(check));
            go(i, j, goal, 0);
        }
    }
    
    if (maxV != 1) cout << maxV << '\n';
    else cout << -1 << '\n';


}
int main(){

    solution();

    return 0;
}