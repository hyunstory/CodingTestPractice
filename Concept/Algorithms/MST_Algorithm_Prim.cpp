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

프림은 한개의 정점부터 시작해서 간선을 연결하되 제일 작은 가중치부터 계산하기 때문에 우선순위 큐를 사용한다.(다익스트라 알고리즘과 비슷함)



*** 프림은 노드를 양방향으로 연결시켜줘야한다. 노드 기준으로 그 다음 값을 구하기 때문에 방향을 알지못함. 

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10001

// 갔던 정점은 다시 방문하지 않기
bool check[MAX];
vector<pair<int, int>> vc[MAX];

void prim(int start){

    
    check[start] = true;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    for (int i = 0; i < vc[start].size(); i++){

        int n = vc[start][i].first;
        int ncost = vc[start][i].second;

        pq.push({ncost, n});
    }

    int ans = 0;

    while(!pq.empty()){

        int cur = pq.top().second;
        int cost = pq.top().first;

        pq.pop();

        // 현재 있는 정점 위치 (다음 위치가 아님)
        if (check[cur]) continue; // 이미 최소 가중치 값을 구했다면 패스시킨다.

        check[cur] = true;

        ans += cost;

        for (int i = 0; i < vc[cur].size(); i++){

            // 해당 정점과 연결된 모든 간선을 pq에 넣어준다.
            
            int next = vc[cur][i].first;
            int nCost = vc[cur][i].second;

            pq.push({nCost, next});
        }
    }

    cout << ans << '\n';
}

void solution(){

    int v, e;

    cin >> v >> e;

    for (int i = 0; i < e; i++){
        int from, to, cost;

        cin >> from >> to >> cost;

        vc[from].push_back({to, cost});
        vc[to].push_back({from, cost});
        
    }

    prim(1);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}