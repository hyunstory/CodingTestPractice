#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


const int MAX = 120000;



int n, m;

vector<pair<int, int>> node[MAX];
bool check[MAX];
int parent[MAX];
int depth[MAX];
int dist[MAX];

int lca(int a, int b){
    
    if (depth[a] < depth[b]){
        swap(a, b);
    }

    while(depth[a] != depth[b]){
        a = parent[a];
    }

    while(a != b){
        a = parent[a];
        b = parent[b];
    }

    return a;
}

void solution(){

    cin >> n;

    for (int i = 0; i < n-1; i++){
        int a, b, k;

        cin >> a >> b >> k;

        node[a].push_back(make_pair(b, k));
        node[b].push_back(make_pair(a, k));

    }


    queue<int> q;
    check[1] = true;
    depth[1] = 0;
    parent[1] = 0;
    q.push(1);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for (pair<int, int> v : node[x]){
            if (!check[v.first]){
                depth[v.first] = depth[x] + 1;
                dist[v.first] = dist[x] + v.second;
                check[v.first] = true;
                parent[v.first] = x;
                q.push(v.first);
            }
        }
    }

    cin >> m;

    while(m--){
        int a, b;

        cin >> a >> b;

        cout << dist[a] + dist[b] - 2*dist[lca(a, b)] << '\n';
    }
    


    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}