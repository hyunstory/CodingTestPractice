/*
2020년 12월 24일
이현승

가장 긴 트리의 지름 구하는 알고리즘

백준 예제 1967

원리, 트리가 있으면, cost 기준으로 가장 거리가 먼 두 노드의 거리를 구하면 된다.

구하는 방법은
1. root부터 시작해서 모든 거리(dist)를 구한다.
2. 거리가 가장 먼 dist의 노드 번호를 구한다.
3. 거리가 가장 먼 dist의 노드 기준으로 다시 모든 노드의 거리(dist)를 구한다.
4. dist중에 가장 큰 값인 것인 가장 긴 트리의 지름이다.


*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

// 구조체 Edge 간선 생성
struct Edge{
    int to; // 향하는 방향
    int cost; // 가중치
    Edge(int to, int cost): to(to), cost(cost){} // 생성자. 이 생성자를 사용하면 vector에 추가할 때 쉽다. 외워두자.

};

vector<Edge> a[10001]; // 정점과 간선의 정보를 알려주는 벡터
bool check[10001]; // bfs에서 방문했는지 검사
int dist[10001]; // 특정 노드 기준으로부터의 모든 정점의 가중치 누적합

void bfs(int start){
    memset(check, false, sizeof(check)); // bfs를 들어 올 때마다, check와 dist함수를 초기호 해준다.
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
                dist[y.to] = dist[x] + y.cost; // 가중치 누적합 구해주기

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

        // 양방향 간선으로 이어주기

        a[u].push_back(Edge(v, cost));
        a[v].push_back(Edge(u, cost));

        
    }

    // 1번, root부터 시작
    bfs(1);

    int start = 1;

    // 가중치 누적합이 제일 큰 노드 번호를 구한다.
    for (int i = 2; i <= n; i++){
        if (dist[start] < dist[i]){
            start = i;
        }
    }
    
    // 가중치 누접학이 제일 큰 노드부터 bfs를 돌면서 dist 가중치 누적합을 구한다.
    bfs(start);

    int ans = dist[1];
    
    // 가중치 누적 합중에서 가장 큰 값을 구한다.
    for (int i = 2; i <= n; i++){
        if (ans < dist[i]){
            ans = dist[i];
        }
    }

    // 가장 큰 누적합이 트리의 지름이다.
    cout << ans << '\n';
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}