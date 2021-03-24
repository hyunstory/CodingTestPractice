#include <iostream>

using namespace std;

const int MAX = 26;
int s_x, s_y;

int n, m, dir;
char map[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void find(int x, int y){
    cout << x + 1 << ' ' << y + 1 << ' ';
    bool check[4] = {false, };

    for (int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (map[nx][ny] != '.'){
            if (k == 0 && (map[nx][ny] == '|' || map[nx][ny] == '+' 
                || map[nx][ny] == '1' || map[nx][ny] == '4'))
				check[k] = true;
			else if (k == 1 && (map[nx][ny] == '|' || map[nx][ny] == '+' 
                || map[nx][ny] == '2' || map[nx][ny] == '3'))
				check[k] = true;
			else if (k == 2 && (map[nx][ny] == '-' || map[nx][ny] == '+' 
                || map[nx][ny] == '1' || map[nx][ny] == '2'))
				check[k] = true;
			else if (k == 3 && (map[nx][ny] == '-' || map[nx][ny] == '+'
                || map[nx][ny] == '3' || map[nx][ny] == '4'))
				check[k] = true;
        }

    }

    if (check[0] && check[1] && check[2] && check[3]) cout << "+";
	else if (check[0] && check[1]) cout << "|";
	else if (check[2] && check[3]) cout << "-";
	else if (check[1] && check[3]) cout << "1";
	else if (check[0] && check[3]) cout << "2";
	else if (check[0] && check[2]) cout << "3";
	else if (check[1] && check[2]) cout << "4"; 
}
void go(int x, int y, int c_dir){

    if (map[x][y] == '.'){
        find(x, y);
        return;
    }

    int nx = x + dx[c_dir];
    int ny = y + dy[c_dir];

    if (c_dir == 0){
        if(map[nx][ny] == '|' || map[nx][ny] == '+') c_dir = 0;
        else if (map[nx][ny] == '1') c_dir = 3;
        else if (map[nx][ny] == '4') c_dir = 2;

    } else if (c_dir == 1){
        if(map[nx][ny] == '|' || map[nx][ny] == '+') c_dir = 1;
        else if (map[nx][ny] == '2') c_dir = 3;
        else if (map[nx][ny] == '3') c_dir = 2;
        
    } else if (c_dir == 2){
        if(map[nx][ny] == '-' || map[nx][ny] == '+') c_dir = 2;
        else if (map[nx][ny] == '1') c_dir = 1;
        else if (map[nx][ny] == '2') c_dir = 0;

    } else if (c_dir == 3){
        if(map[nx][ny] == '-' || map[nx][ny] == '+') c_dir = 3;
        else if (map[nx][ny] == '3') c_dir = 0;
        else if (map[nx][ny] == '4') c_dir = 1;

    }

    go(nx, ny, c_dir);

}
void firstDir(){
    for (int k = 0; k < 4; k++){
        int nx = s_x + dx[k];
        int ny = s_y + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if (map[nx][ny] != '.'){
            if (nx == s_x){
                if (ny == s_y - 1){
                    dir = 2;
                } else if (ny == s_y + 1){
                    dir = 3;
                }
            }else if (ny == s_y){
                if(nx == s_x -1){
                    dir = 0;
                } else if (nx == s_x + 1){
                    dir = 1;
                }
            }
        }
    }

}
void solution(){

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char temp;
            cin >> temp;
            if (temp == 'M'){
                s_x = i;
                s_y = j;
            }
            map[i][j] = temp;

        }
    }

    firstDir();
    go(s_x, s_y, dir);

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}