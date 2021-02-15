#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX = 11;

int people[MAX];
vector<int>node[MAX];
bool selected[MAX];
bool visit[MAX];

int n;

int ans = __INT_MAX__;


bool isConnected(vector<int> &v, bool flag){
    memset(visit, false, sizeof(visit));
    queue<int> q;
    visit[v[0]] = true;
    q.push(v[0]);
    int cnt = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for (auto value: node[x]){

            if (selected[value] != flag || visit[value]) continue;
            cnt++;
            visit[value] = true;
            q.push(value);
        }
    }

    if (v.size() == cnt) return true;
    else return false;
}

bool isOk(){
    vector<int> a;
    vector<int> b;
    
    for (int i = 1; i <= n; i++){
        if (selected[i]) a.push_back(i);
        else b.push_back(i);
    }

    if (a.empty() || b.empty()) return false;

    if (!isConnected(a, true)) return false;
    
    if (!isConnected(b, false)) return false;

    return true;


}
void calcu(){
    int a_sum = 0;
    int b_sum = 0;

    for (int i = 1; i <= n; i++){
        if (selected[i]) a_sum += people[i];
        else b_sum += people[i];
    }

    ans = min(ans, abs(a_sum - b_sum));


}

void dfs(int start, int depth){

    if (depth >= 1){
        if (isOk()){
            calcu();
        }
    }
    

    for (int i = start; i <= n; i++){
        if (selected[i]) continue;
        selected[i] = true;
        dfs(i + 1, depth + 1);
        selected[i] = false;
    }
}

void solution(){
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> people[i];
    }
    for (int i = 1; i <= n; i++){
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++){
            int tmp;
            cin >> tmp;
            node[i].push_back(tmp);
            node[tmp].push_back(i);
        }
    }

    dfs(1, 0);




    if (ans == __INT_MAX__) cout << -1 << '\n';
    else cout << ans << '\n';
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}