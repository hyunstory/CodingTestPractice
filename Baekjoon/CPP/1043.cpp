#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
const int MAX = 51;

bool knew[MAX];
bool visit[MAX];
bool room[MAX];

vector<int> parti[MAX];
vector<int> member[MAX];
vector<int> knewGroup;
deque<int> truth;


void solution(){
    cin >> n >> m;

    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++){
        // 진실을 아는 사람
        int t;
        cin >> t;
        knew[t] = true;
        knewGroup.push_back(t);
        
    }

    for (int i = 1; i <= m; i++){
        cin >> cnt;
        for (int j = 0; j < cnt; j++){
            int t;
            cin >> t;

            parti[i].push_back(t);
            member[t].push_back(i);
        }
    }

    while(!knewGroup.empty()){
        int t = knewGroup.back();
        knewGroup.pop_back();

        truth.push_back(t);
        visit[t] = true;
        
    }

    while(!truth.empty()){
        int mem = truth.front();
        truth.pop_front();
        int mem_s = member[mem].size();
        for (int i = 0; i < mem_s; i++){
            int roomr = member[mem][i];

            for (int j = 0; j < parti[roomr].size(); j++){
                room[roomr] = true;
                if (visit[parti[roomr][j]]) continue;

                
                visit[parti[roomr][j]] = true;
                truth.push_back(parti[roomr][j]);
                
            }
        }
    }
    cnt = 0;

    for (int i = 1; i <= m; i++){
        if (!room[i]) cnt++; 
    }

    cout << cnt << '\n';


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}