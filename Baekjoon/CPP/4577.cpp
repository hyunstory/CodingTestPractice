#include <iostream>
#include <cstring>
#include <string>
#include <deque>

using namespace std;
const int MAX = 16;

char map[MAX][MAX];

int r, c;
int tCase = 1;
int cur_x, cur_y;
int goal;

deque<char> cmd;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dir(char d){
    if (d == 'U') return 0;
    else if (d == 'D') return 1;
    else if (d == 'L') return 2;
    else return 3;

}
bool move(char command){
    // 움직이면서 고쳐주자

    
    int d = dir(command);

    // 가고자하는 칸은?
    int nx = cur_x + dx[d];
    int ny = cur_y + dy[d];

    int t_x = cur_x;
    int t_y = cur_y;

    int g_x = nx + dx[d];
    int g_y = ny + dy[d];
    
    bool flag = false;
    if(map[cur_x][cur_y] == 'B' || map[cur_x][cur_y] == 'W') flag = true;

    if (!(map[nx][ny] == '#' || map[nx][ny] == 'b' || map[nx][ny] == 'B')){
        cur_x = nx;// 그대로 옮겨준다.
        cur_y = ny;
    }
    else if(map[nx][ny] == 'b'){
        if (map[g_x][g_y] == '.'){
            cur_x = nx;
            cur_y = ny;
            map[g_x][g_y] = 'b'; // 박스 옮겨주고, 
            map[nx][ny] = '.'; // 이전에 있던 박스 위치는 없애주고
        }
        else if (map[g_x][g_y] == '+'){
            cur_x = nx;
            cur_y = ny;
            map[g_x][g_y] = 'B';
            map[nx][ny] = '.';
            goal--;

        }

    }
    else if (map[nx][ny] == 'B'){
        if (map[g_x][g_y] == '.'){
            cur_x = nx;
            cur_y = ny;
            map[g_x][g_y] = 'b';
            map[nx][ny] = '+';
            goal++;
        }
        else if(map[g_x][g_y] == '+'){
            cur_x = nx;
            cur_y = ny;
            map[g_x][g_y] = 'B';
            map[nx][ny] = '+';
        }
    }

    if (flag) map[t_x][t_y] = '+';




    if (goal == 0) return true; // 다 채웠다면...
    
    return false;
    // 끝나야할 상황이면 return true;
}
void VerifyAndPrint(){

    cout << "Game " << tCase++ << ": ";

    if (goal == 0) cout << "complete" << '\n';
    else cout << "incomplete" << '\n';


    for(int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (i == cur_x && j == cur_y && map[i][j] == '+') cout << 'W'; // 비어있는 목표점 위에 사용자가 있다면 W
            else if (i == cur_x && j == cur_y) cout << 'w';
            else cout << map[i][j];

        }
        cout << '\n';
    }


}

void solution(){

    while(1){

        cin >> r >> c;

        if (r == 0 && c == 0) break; // 종료 조건

        // 초기화
        memset(map, 0, sizeof(map));
        cmd.clear();
        goal = 0;


        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cin >> map[i][j];

                if (map[i][j] == '+') goal++;
                else if (map[i][j] == 'w'){
                    cur_x = i;
                    cur_y = j;
                    map[i][j] = '.';
                }
                else if (map[i][j] == 'W'){
                    cur_x = i;
                    cur_y = j;
                    goal++;
                }
            }
        }

        string s;
        cin >> s;
        
        for (int i = 0; i < s.length(); i++){
            cmd.push_back(s[i]);
        }

        while(!cmd.empty()){
            char command = cmd.front();
            cmd.pop_front();

            //move
            if(move(command)) {
                break;
            }
        }

        VerifyAndPrint();


    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}