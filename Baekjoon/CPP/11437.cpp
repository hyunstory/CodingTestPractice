#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


const int MAX = 120000;



int n, m;

vector<int> node[MAX];
bool check[MAX];
int parent[MAX];
int depth[MAX];

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
        int a, b;

        cin >> a >> b;

        node[a].push_back(b);
        node[b].push_back(a);

    }


    queue<int> q;
    check[1] = true;
    depth[1] = 0;
    parent[1] = 0;
    q.push(1);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for (int v : node[x]){
            if (!check[v]){
                depth[v] = depth[x] + 1;
                check[v] = true;
                parent[v] = x;
                q.push(v);
            }
        }
    }

    cin >> m;

    while(m--){
        int a, b;

        cin >> a >> b;

        cout << lca(a, b) << '\n';
    }
    


    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}