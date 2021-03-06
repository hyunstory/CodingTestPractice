#include <iostream>
#include <queue>

using namespace std;

const int MAX = 51;

char a[MAX][MAX];

bool check[MAX][MAX][33];

int s_x;
int s_y;
int n, m;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct ppang{
    int x;
    int y;
    int key;
    int dist;

    ppang(int x, int y, int key, int dist): x(x), y(y), key(key), dist(dist){};
};

int bfs(){
    
    queue<ppang> q;

    q.push(ppang(s_x,s_y, 0, 0));
    check[s_x][s_y][0] = true;

    while(!q.empty()){

        int x = q.front().x;
        int y = q.front().y;
        int key = q.front().key;
        int dist = q.front().dist;
        q.pop();

        if (a[x][y] == '1') return dist;
        

        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny][key]) continue;

            char point = a[nx][ny];

            if (point == '.' || point == '1' || point == '0'){
                check[nx][ny][key] = true;
                q.push(ppang(nx, ny, key, dist + 1));

            } else if(point >= 'a' && point <= 'f'){
                int nKey = key | (1 << (point - 'a')); // ****주의!! 비트 연산 후에는 새로운 변수에 저장해야한다. 아래와 같이 같은 변수에 저장 시에 정답이 다르게 나온다??와이????도대체 왜??
                //key = (key | (1 << (point - 'a')));

                check[nx][ny][nKey] = true;
                q.push(ppang(nx, ny, nKey, dist + 1));

            } else if (point >= 'A' && point <= 'F'){
                if (key & (1 << (point - 'A'))){
                    check[nx][ny][key] = true;
                    q.push(ppang(nx, ny, key, dist + 1));
                }

            }

        }


    }

    return -1;

    
}

void solution(){



    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];

            char t = a[i][j];

            if (t == '0'){
                s_x = i;
                s_y = j;
                
            } 
        }
    }

    
    cout << bfs() << '\n';



}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}