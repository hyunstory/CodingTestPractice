#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n, m;
char map[21][21];

int minV = __INT_MAX__;

vector<pair<int,int>> coin;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};


struct Info{
    int x_1;
    int y_1;
    int x_2;
    int y_2;
    int cnt;

};

void solution(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
            if (map[i][j] == 'o') {
                coin.push_back({i, j});
                map[i][j] = '.';
            }
        }

    Info info;
    info.x_1 = coin[0].first;
    info.y_1 = coin[0].second;
    info.x_2 = coin[1].first;
    info.y_2 = coin[1].second;
    info.cnt = 1;



    deque<Info> q;
    q.push_back(info);
    

    while(!q.empty()){
        Info info = q.front();
        q.pop_front();

        for (int k = 0; k < 4; k++){
            int nx_1 = info.x_1 + dx[k];
            int ny_1 = info.y_1 + dy[k];
            int nx_2 = info.x_2 + dx[k];
            int ny_2 = info.y_2 + dy[k];
            int cnt = info.cnt;

            if (minV < cnt) continue;

            if (cnt > 10) {
                minV = min(minV, cnt);
                continue;
            }


            if (nx_1 >= 0 && nx_1 < n && ny_1 >= 0 && ny_1 < m && nx_2 >= 0 && nx_2 < n && ny_2 >= 0 && ny_2 < m){ // 전부 안에 있을 떄, // 1가지 검사 빠트려서 계속 틀렸습니다 나왔음 ㅠ 다음부터는 모듈화시키기!

                if (map[nx_1][ny_1] == '#'){
                    nx_1 = info.x_1;
                    ny_1 = info.y_1;

                }
                if(map[nx_2][ny_2] == '#'){
                    nx_2 = info.x_2;
                    ny_2 = info.y_2;
 
                }
                q.push_back({nx_1,ny_1,nx_2,ny_2,cnt+1});
                
            } else if((nx_1 < 0 || nx_1 >= n || ny_1 < 0 || ny_1 >= m) && !(nx_2 < 0 || nx_2 >= n || ny_2 < 0 || ny_2 >= m)){ // 1만 밖으로 나갔을 때

                minV = min(minV, cnt);

            } else if(!(nx_1 < 0 || nx_1 >= n || ny_1 < 0 || ny_1 >= m) && (nx_2 < 0 || nx_2 >= n || ny_2 < 0 || ny_2 >= m)){ // 2만 밖으로 나갔을 때
                minV = min(minV, cnt);

            }


        }
        
    }

    if (minV > 10) cout << -1 << '\n';
    else cout << minV << '\n';

    
    
    

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}