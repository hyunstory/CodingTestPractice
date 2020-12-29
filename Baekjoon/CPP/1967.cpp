#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

struct Edge{
    int to;
    int cost;
    Edge(int to, int cost): to(to), cost(cost){}

};

vector<Edge> a[10001];
bool check[10001];
int dist[10001];

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
                dist[y.to] = dist[x] + y.cost;

                check[y.to] = true;
                q.push(y.to);
            }
        }
    }
}
void solution(){

    int n;

    cin >> n;
    
    for (int i = 0; i < n-1; i++){
        int u, v, cost;

        cin >> u >> v >> cost;

        a[u].push_back(Edge(v, cost));
        a[v].push_back(Edge(u, cost));

        
    }

    bfs(1);

    int start = 1;

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