#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Ptn{
    int x;
    int y;
    int b;
    int cnt;
    bool afnn;
    
    Ptn(int x, int y, int b, int cnt, bool afnn): x(x), y(y), b(b), cnt(cnt), afnn(afnn){};
};

const int MAX = 1001;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


int a[MAX][MAX];
bool check[MAX][MAX][11];

int n, m, kkk;


int bfs(){

    
    queue<Ptn> q;
    check[1][1][0] = true;
    q.push(Ptn(1, 1, 0, 1, true));
    //dist[1][1] = 1;
    

    while(!q.empty()){

        int x = q.front().x;
        int y = q.front().y;
        int b = q.front().b;
        int cnt = q.front().cnt;
        bool afnn = q.front().afnn;

        q.pop();

        if (x == n && y == m){
            return cnt;
        }

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx > n || nx < 1 || ny > m || ny < 1) continue;

            
            if (a[nx][ny] == 0){
                if (check[nx][ny][b]) continue;

                check[nx][ny][b] = true;
                q.push(Ptn(nx, ny, b, cnt + 1, !afnn));
            } else if (a[nx][ny] == 1){
                if (b < kkk){
                    if (check[nx][ny][b + 1]) continue;

                    if (afnn){
                        check[nx][ny][b + 1] = true;
                        q.push(Ptn(nx, ny, b + 1, cnt + 1, !afnn));
                    }else{
                        q.push(Ptn(x, y, b, cnt + 1, !afnn));
                    }
                }
            }
        }
        
    }

    return -1;
}
void solution(){
    cin >> n >> m >> kkk;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%1d", &a[i][j]);
        }
    }

    cout << bfs() << '\n';
    

}
int main(){

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    solution();

    return 0;
}