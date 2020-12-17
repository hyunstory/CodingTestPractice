#include <iostream>
#include <queue>
#include <vector>


using namespace std;

#define INF 2000000000
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

        vec[a].push_back(make_pair(b, c));

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