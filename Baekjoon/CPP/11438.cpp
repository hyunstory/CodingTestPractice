#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

const int MAX = 100111;

vector<int> a[MAX];

int parent[MAX];
bool check[MAX];
int depth[MAX];
int p[MAX][17];




int lca(int u, int v){
    if (depth[u] < depth[v]){
        swap(u, v);
    }

    int log = 1;

    for (log = 1; (1 << log) <= depth[u]; log++);
    log -= 1;

    for (int i = log; i >= 0; i--){
        if (depth[u] - depth[v] >= (1 << i)){
            u = p[u][i];
        }
    }

    if (u == v){
        return u;
    } else{
        for (int i = log; i >= 0; i--){
            if (p[u][i] != 0 && p[u][i] != p[v][i]){
                u = p[u][i];
                v = p[v][i];
            }
        }

        return parent[u]; // 결국 p[u][0]에서 끝난다. 
    }

}

void solution(){

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++){
        int u, v;

        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    depth[1] = 0;
    check[1] = true;
    queue<int> q;

    q.push(1);
    parent[1] = 0;

    while(!q.empty()){
        int x = q.front();

        q.pop();

        for (int y : a[x]){
            if (!check[y]){
                depth[y] = depth[x] + 1;
                check[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        p[i][0] = parent[i];
    }

    for (int j = 1; (1<<j) < n; j++){
        for (int i = 1; i <= n; i++){
            if (p[i][j-1] != 0 && p[i][j] == 0){ // p[i][j-1] 이 0이라면 계산을 아직 안했기 때문에 트리가 꼬임, p[i][j] != 0은 이미 계산했기 때문에 이중으로 계산할 필요가 없음.
                p[i][j] = p[p[i][j-1]][j-1];
            }
        }
    }

    int m;
    cin >> m;

    while(m--){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }




}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}