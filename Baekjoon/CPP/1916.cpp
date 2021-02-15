#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m, start, endd;
vector<pair<int, int> >node[1001];

int route[1001];

void solution(){

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int from, to, cost;

        cin >> from >> to >> cost;

        node[from].push_back({to, cost});
    }
    
    cin >> start >> endd;

    
    for (int i = 0; i <= n; i++) route[i] = __INT_MAX__;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;

    pq.push({ 0, start });

    route[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        for (auto v: node[cur]){
            int next = v.first;
            int nCost = v.second;

            if (route[next] > cost + nCost){
                route[next] = cost + nCost;
                pq.push({route[next], next});
            }
        }
    }

    cout << route[endd] << '\n';
    

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}