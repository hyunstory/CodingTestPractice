#include <iostream>
#include <queue>

using namespace std;

const int MAX = 51;
const int range = 65;

int map[MAX][MAX];

bool check[range][MAX][MAX];
int start_x, start_y;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;

int bfs(int start_x, int start_y){

    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{start_x,start_y},{0, 0}}); // x,y값, cnt와 암호코드 a~f

    check[0][start_x][start_y] = true;

    while(!q.empty()){

        int x = q.front().first.first;
        int y= q.front().first.second;
        int cnt = q.front().second.first;
        int key = q.front().second.second;

        q.pop();

        if (map[x][y] == '1') return cnt;

        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !check[key][nx][ny] && map[nx][ny] != '#'){
                if (map[nx][ny] == '.' || map[nx][ny] == '1' || map[nx][ny] == '0'){
                    check[key][nx][ny] = true;
                    q.push({{nx,ny},{cnt + 1, key}});
                }

                else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f'){

                    int nKey = key | (1 << (int(map[nx][ny] - 'a')));
                    if (!check[nKey][nx][ny]){
                        check[nKey][nx][ny] = true;
                        check[key][nx][ny] = true;
                        q.push({{nx, ny},{cnt +1, nKey}});
                    }
                }

                else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F'){
                    if (key & 1 << (int(map[nx][ny]) - 'A')){
                        check[key][nx][ny] = true;
                        q.push({{nx,ny},{cnt+1, key}});
                    }
                }


            }
        }

    }

    return -1;
}

void solution(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char temp;
            cin >> temp;

            if (temp == '0'){
                start_x = i;
                start_y = j;
            }
            map[i][j] = temp;
        }

    int result = bfs(start_x, start_y);

    cout << result << '\n';


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}