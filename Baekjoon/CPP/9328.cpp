#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

char map[101][101];
bool check[101][101][50];
set<string> visit;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int myKey;

int n, m;

bool isEnter(int i, int j){
    int v = map[i][j];

    if (v == '.') return true;

    else if (v >= 'A' && v <= 'Z'){
        if (myKey & (1 << (v - 'A'))) return true;
    }

    return false;
}

pair<int, int> findEnterance(){

    for (int i = 0; i < m; i++) {
        if(isEnter(0, i)) return {0, i};
    }

    for (int i = 0; i < n; i++){
        if(isEnter(i, 0)) return {i, 0};
    }

    for (int i = 0; i < m; i++){
        if(isEnter(n-1,i)) return {n-1, 0};
    }

    for (int i = 0; i < n; i++){
        if(isEnter(i, m-1)) return {i, m-1};
    }

    return {-1, -1};
}
int bfs(int i, int j, int myKey){

    int result = 0;

    queue<pair<int, int>> q;
    //check[i][j][myKey] = true;
    string t;
    t.append(to_string((char)i));
    t.append(to_string((char)j));
    t.append(to_string((char)myKey));

    visit.insert(t);

    q.push({i, j});

    while(!q.empty()){

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '*') continue;

            string tt;
            tt.append(to_string((char)nx));
            tt.append(to_string((char)ny));
            tt.append(to_string((char)myKey));


            if(visit.find(t) != visit.end()) continue;

            if (map[nx][ny] == '.'){
                //check[nx][ny][myKey] = true;
                visit.insert(tt);
                q.push({nx,ny});
            }
            else if(map[nx][ny] >= 'A' && map[nx][ny] <= 'Z'){
                if (myKey & (1 << (map[nx][ny] - 'A'))){
                    //check[nx][ny][myKey] = true;

                    visit.insert(tt);
                    q.push({nx,ny});
                }
            }
            else if(map[nx][ny] >= 'a' && map[nx][ny] <= 'z'){
                myKey = myKey | (1 << (map[nx][ny] - 'a'));

                t.clear();

                tt.append(to_string((char)nx));
                tt.append(to_string((char)ny));
                tt.append(to_string((char)myKey));
                //check[nx][ny][myKey] = true;
                visit.insert(tt);
                q.push({nx, ny});
            }
            else if(map[nx][ny] == '$'){
                result++;
                visit.insert(tt);
                q.push({nx, ny});
            } 



        }
    }

    return result;
}

void solution(){

    int testCase;

    cin >> testCase;

    while(testCase--){

        memset(map, 0, sizeof(map));
        memset(check, false, sizeof(check));
        myKey = 0;
        visit.clear();

        int start_x = -1, start_y = -1;

        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                cin >> map[i][j];
            }

        //getchar();

        string t;

        cin >> t;


        // 자신이 가지고 있는 키 구하기, 0이면 반환
        for (int i = 0; i < t.size(); i++){
            if(t[i] == '0') break;

            myKey = (myKey | (1 << (t[i] - 'a')));
            

        }
        int result = 0;

        pair<int, int> p = findEnterance();
        start_x = p.first;
        start_y = p.second;

        if (start_x != -1) result = bfs(start_x, start_y, myKey);

        cout << result << '\n';


    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}