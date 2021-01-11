#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> node[50001];

int dist[50001];

void solution(){

    int v, e;
    cin >> v >> e;


    for (int i = 0; i < e; i++){
        int a, b, c;

        cin >> a >> b >> c;

        node[a].push_back({b, c});
        node[b].push_back({a, c});

    }

    
    for (int i = 1; i <= 50000; i++) dist[i] = __INT_MAX__;

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    pq.push({0, 1}); // cost, 정점번호

    dist[1] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        for (int i = 0; i < node[cur].size();i++){
            int next = node[cur][i].first;
            int nCost = node[cur][i].second;

            if (dist[next] > cost + nCost){
                dist[next] = cost + nCost;
                pq.push({cost + nCost, next});
            }
        }

    }

    cout << dist[v] << '\n';

    

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}