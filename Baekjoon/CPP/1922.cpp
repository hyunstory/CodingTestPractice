#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10002

typedef struct kruskal{
    int from;
    int to;
    int val;
}KS;
vector<KS> edge;

int parent[MAX];
int result;

int v, e;

bool comp(KS k1, KS k2){
    return k1.val < k2.val;
}

int find(int u){
    if (u == parent[u]) return u;

    return parent[u] = find(parent[u]);

}

bool merge(int u, int v){
    u = find(u);
    v = find(v);

    if (u == v) return false; // 싸이클이 존재하는지 검사

    parent[u] = v;
    return true;
}

void solution(){

    cin >> v >> e;

    for (int i = 1; i <= v; i++){
        parent[i] = i;
    }

    for (int i = 1; i <= e; i++){

        int a, b, c;
        cin >> a >> b >> c;
        KS ks;

        cin >> ks.from >> ks.to >> ks.val;
        edge.push_back(ks);


    }

    sort(edge.begin(), edge.end(), comp);

    
    for (int i = 0; i < e; i ++){
        if(merge(edge[i].from, edge[i].to)){
            result += edge[i].val;
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