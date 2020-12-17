/*
2020년 12월 17일
이현승

사용할 수 있는 containers: priority_queue(min), set

다익스트라 알고리즘 코드 (최소경로 가중치 구하기) (M * logN) 
1. priority_queue, min heap 사용
2. set 사용, set은 자동 정렬이 되기 때문에 *s.begin()으로 접근


단방향 일 경우, 단방향만 간선을 만들어준다. 양방향 일 경우, 두 개의 방향 모두 간선을 만들어준다.

시작하는 정점을 pq(priority_queue)에 삽입 후,
제일 작은 값을 꺼내서 그 정점에 연결된 정점을 모두 for문을 통해 돌린다.
돌면서 현재 까지 구한 가중치와 next정점의 가중치를 더해서 next정점에 저장된 총 가중치보다 구한 가중치가 작다면
구한 가중치를 next정점에 대입한다. 
가중치가 최소가 된 next정점을 pq에 삽입한다. 

pq가 empty일 때까지 구한다.

pq에서 최솟값만 매번 가져오기 때문에, 누적 가중치 dist배열와 비교해서 최솟값이 아니면 지나친다. 

그래서 다익스트라 알고리즘은 항상 최소경로만 구할 수 있게 된다. 

그 정점들의 경로를 구하고 싶다면, 최소값을 찾았을 때 parent 배열에 부모에 대한 정보를 넣으면, 
시작점에서 종료점까지 거친 정점을 구할 수 있다. 
parent[i] = p;
p가 종점이 되도록 계속 넣는다. 




cf) O(N^2)이 있지만, min heap이 시간복잡도가 낮아서 min heap으로 설명, set의 원리는 min heap으로 설명하는 다익스트라와 비슷함. 

*/

#include <iostream>
#include <queue>
#include <vector>


using namespace std;

#define INF __INT_MAX__
#define NODE 20001

int v, e;

vector<pair<int,int>> vec[NODE];
int dist[NODE];

void solution(){
    cin >> v >> e;
    int start;
    cin >> start;

    for (int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        vec[a].push_back(make_pair(b, c)); // 단 방향일 때,
        // vec[b].push_back(make_pair(a, c)); // 양 방향일 때 주석 해제

    }
    for (int i = 1; i <= v; i++) dist[i] = INF;


    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, start));
    
    dist[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < vec[cur].size(); i++){
            int next = vec[cur][i].first;
            int ncost = vec[cur][i].second;

            if (dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    for (int i = 1; i <= v; i++){
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }


    


    
}
int main(){


    solution();

    return 0;
}