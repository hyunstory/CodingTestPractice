#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, t;

int dist[1001];

vector<pair<int,int>> edge[1001];
vector<pair<int, int>> list[1001]; // 가중치, 정점번호
void solution(){

    cin >> n >> m >> t;

    
    for (int j = 0; j < m; j++){
        int a,b,c;

        cin >> a >> b >> c;

        edge[a].push_back({b,c});

    }

    for (int start = 1; start <= n; start++){

        for (int i = 1; i <= n; i++) dist[i] = __INT_MAX__;


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> >pq;

        pq.push({0, start});

        while(!pq.empty()){

            int cost = pq.top().first;
            int vertex = pq.top().second;

            pq.pop();

            for (int k = 0; k < edge[vertex].size(); k++){
                int next = edge[vertex][k].first;
                int nCost = edge[vertex][k].second;

                if (dist[next] > nCost + cost){
                    dist[next] = nCost + cost;
                    pq.push({dist[next], k});
                }

                
            }

        }

    
    }

    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}