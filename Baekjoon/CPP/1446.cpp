#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;
int n, d;
vector<pair<int, int>> v[MAX];
vector<bool> check(MAX);
vector<int> dist(MAX);

void solution(){

    cin >> n >> d;


    // 지름길 말고 한방에 가는 방법도 혹시 몰라서 넣는다.

    v[0].push_back({d, d});

    for (int i = 0; i < n; i++){
        int from, to, cost;

        cin >> from >> to >> cost;

        if (to > d) continue;

        v[from].push_back({to,cost});
        v[to].push_back({d, d-to});
        
    }
    fill(dist.begin(), dist.end(), __INT_MAX__);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // cost, 정점

    pq.push({0, 0});

    dist[0] = 0;
    check[0] = true;

    while(!pq.empty()){

        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++){
            int Next = v[cur][i].first;
            int nCost = v[cur][i].second;

            

            if (dist[Next] > cost + nCost){
                dist[Next] = cost + nCost;
                pq.push({dist[Next], Next});
            }
            
            
        }
    }

   // for (int i = 0; i <= d; i++){
     //   cout << dist[i] << '\n';

    //}
    cout << dist[d] << '\n';


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}