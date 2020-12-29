#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Edge{
    int to;
    int cost;
    Edge(int to, int cost): to(to), cost(cost){}

};

vector<Edge> a[100001];
bool check[100001];
int dist[100001];

void bfs(int start){
    memset(check, false, sizeof(check));
    memset(dist, 0, sizeof(dist));

    check[start] = true;

    queue<int> q;

    q.push(start);

    while(!q.empty()){
        int x = q.front();

        q.pop();

        for (int i = 0; i < a[x].size(); i++){
            Edge &y = a[x][i];

            if (!check[y.to]){
                check[y.to] = true;
                dist[y.to] = dist[x] + y.cost;
                q.push(y.to);
            }
        }
    }
}

void solution(){
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        int u, v, cost;
        cin >> u;
        while(true){
            cin >> v;

            if (v == -1)break;

            cin >> cost;

            a[u].push_back(Edge(v, cost));
            a[v].push_back(Edge(u, cost));
            
        }
    }

    int start = 1;

    bfs(start);

    for (int i = 2; i <= n; i++){
        if (dist[start] < dist[i]){
            start = i;
        }
    }

    bfs(start);

    int ans = dist[1];

    for (int i = 2; i <= n; i++){
        if (ans < dist[i]){
            ans = dist[i];
        }
    }

    cout << ans << '\n';

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}