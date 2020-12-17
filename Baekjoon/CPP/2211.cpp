#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 1001
#define INF __INT_MAX__

vector<pair<int, int>> net[MAX];

int n, m;
int from[MAX];
int dist[MAX];

void solution(){

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        net[a].push_back(make_pair(b, c)); // 양방향
        net[b].push_back(make_pair(a, c)); // 양방향
    }

    for (int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    dist[1] = 0;
    pq.push(make_pair(0, 1));

    while (!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        for (int i = 0; i < net[cur].size(); i++){
            int next = net[cur][i].first;
            int ncost = net[cur][i].second;

            if (dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                from[next] = cur;
                pq.push(make_pair(dist[next], next));
            }
        }

        

    }

    cout << n - 1 << '\n';

    for (int i = 2; i <= n; i++){
        cout << from[i] << ' ' << i << '\n';
    }
    

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}