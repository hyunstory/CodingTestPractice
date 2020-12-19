/*
2020년 12월 19일
이현승

MST는 Minimum Spanning Tree의 약자로,
그래프에서 모든 정점을 연결하되, 사이클이 존재하지 않도록 모든 정점을 간선으로 연결하는 것을 의미한다.
이 때, 간선의 가중치 합을 최소로 연결해야한다.

연결된 그래프는 오직 1개만 나온다고 보장할 수 없다. 같은 가중치지만, 여러 경로가 나올 수 있다.

MST를 구현하는 방법중에는
1. Kruskal O(ElogE) -> 간선 개수가 작은 경우
2. 프림(Prim) O(ElogV) -> 간선의 개수가 많은 경우
두 가지 방법으로 풀 수 있다.

크루스칼로 풀게되면, 두 정점의 최상 부모를 찾아서, 그 부모가 같다면 싸이클이 생기게된것이고,
부모가 같이 않다면 사이클이 생성이 안된다.

가중치가 가장 작은 것부터 연결해주고, 사이클 검사를 해주기 때문에 간편하게 구현할 수있다.
대신, 간선 수가 너무 많다면, 프림 알고리즘(우선순위큐)로 푸는 것이 가장 알맞다!

*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// edge에 대한 정보 
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

    // 최상 부모가 같다면 싸이클이 생겼다는 의미이기 떄문에 false로 반환
    if (u == v) return false;

    // 그게 아니라면 최상부모 업데이트
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

    // 유니온 파인드를 사용하기 위해, 모든 정점의 부모를 자기 자신으로 초기화 한다. 유니온 파인드를 수행하고 나서 자기 자신이 값으로 나오는 것은 최고 부모이다. 
    for (int i = 0; i < v; i++){
        parent[i] = i;
    }


    // Kruskal에서 가중치가 가장 낮은 것부터 연결을 하기 때문에, 오름차순으로 정렬하기
    sort(edge.begin(), edge.end(), comp);

    int result = 0;

    // 가중치가 가장 작은 것부터 병합하기. 병할 할 때, 유니온 파인드를 사용하여 두개의 정점의 최상 부모가 같다면 싸이클이 생기게 된다. 같은 싸이클이기때문에 최상 부모가 같다.
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