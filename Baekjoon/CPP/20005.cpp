#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 1001;

char arr[MAX][MAX];

int damage[27];
int BH;
int b_x, b_y;
int n, m;
int p, result;
int check[MAX][MAX];
int arrive[27];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void go(){

    queue<pair<int, int> > q;
    q.push({ b_x, b_y });
    check[b_x][b_y] = true;

    while (BH > 0){
        int len = q.size();

        for (int i = 0; i < len; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if ('a' <= arr[x][y] && arr[x][y] <= 'z'){
                result++;
                arrive[arr[x][y] - 'a'] = true;
            }

            for (int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || arr[nx][ny] == 'X') continue;
                check[nx][ny] = true;
                q.push({nx,ny});

            }   
        }

        for (int i = 0; i < 27; i++){
            if (arrive[i]) BH -= damage[i];
        }

    }
}

void solution(){
    cin >> n >> m >> p;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'B'){
                b_x = i;
                b_y = j;
            }
        }
    }

    for (int i = 0; i < p; i++){
        char a;
        int d;
        cin >> a >> d;

        damage[i] = d;
    }

    cin >> BH;
    
    go();

    cout << result << '\n';

}
int main() {

	ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    solution();

	return 0;

}