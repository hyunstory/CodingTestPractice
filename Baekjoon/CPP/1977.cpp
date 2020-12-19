#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct kruskal{
    int from;
    int to;
    int cost;

}KS;

#define MAX 10001

int parent[MAX];

int v, e;

vector<KS>edge;

bool comp(KS ks1, KS ks2){
    return ks1.cost < ks2.cost;
}

int find(int u){
    if (u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
}

bool merge(int u, int v){
    u = find(u);
    v = find(v);

    if (u == v) return false;

    parent[u] = v;

    return true;
}

void solution(){

    cin >> v >> e;

    for (int i = 0; i < e; i++){
        KS ks;

        cin >> ks.from >> ks.to >> ks.cost;

        edge.push_back(ks);
        
    }

    for (int i = 0; i < v; i++){
        parent[i] = i;
    }

    sort(edge.begin(), edge.end(), comp);

    int result = 0;

    for (int i = 0; i < edge.size(); i++){
        if (merge(edge[i].from, edge[i].to)){
            result += edge[i].cost;
        }
    }

    cout << result << '\n';




}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}